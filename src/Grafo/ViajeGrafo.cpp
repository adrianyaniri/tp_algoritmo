//
// Created by home on 9/11/22.
//

#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include "ViajeGrafo.h"


const int MAX = 100000000;

using namespace std;

ViajeGrafo::ViajeGrafo() {
    primero = nullptr;
    tamanio = 0;
}

bool ViajeGrafo::estaVacio() {
    return primero == nullptr;
}


//Post: retorna el total de todos los nodos del grafo
int ViajeGrafo::obtenerTamanio() const {
   return tamanio;
}

Vertice *ViajeGrafo::obtenerCiudad(const string& nombre) {
    Vertice *aux = primero;  // aux apunta al primer vértice

    while (aux != nullptr) {
        if (aux->nombre == nombre) {
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}
/*
 * Post: Inserta una ciudad (vertice) en el grafo
 * @arg nombre: nombre de la ciudad
 */

void ViajeGrafo::insertarCuidad(const string& nombre) {
    // Busca si la ciudad ya existe
    if(obtenerCiudad(nombre) == nullptr){
        Vertice *nuevo = new Vertice(nombre);

        // Si el grafo está vacío inserto el primer vértice
        if(estaVacio())
            primero = nuevo;

        // Si el grafo no está vacío inserto el vértice al final
        else{
            Vertice *aux = primero;
            while(aux->sig != nullptr)
                aux = aux->sig;
            aux->sig = nuevo;
        }
        tamanio++;
    }
    else{
        cout << "La ciudad ya esta cargada " << endl;
    }
}

/*
 * Pre: Inserta una conexion(arista) entre el origen y el destino
 * @param origen: nombre del origen
 * @param destino: nombre del destino
 * @param precio: precio del viaje
 * @param distancia: distancia del viaje
 */
void ViajeGrafo::insertarViaje(const string& origen, const string& destino, int precio, int distancia) {

    Vertice* vOrigen = obtenerCiudad(origen);
    Vertice* vDestino = obtenerCiudad(destino);

    if(vOrigen == nullptr){
        cout << "Es lugar de origen no existe " << endl;   // Si el origen no existe
    }
    if(vDestino == nullptr){
        cout << "Es lugar de destino no existe " << endl;  // Si el destino no existe
    }
    /*
     * Si existe el origen y el destino
     * Inserta un viaje (arista-conexion) entre el origen y el destino
     */
    if(vOrigen != nullptr && vDestino != nullptr){

        Arista* nueva = new Arista(vDestino, precio, distancia);

        /*
         * Si la ciudad (vertice) tiene viajes (conexiones-aristas), se inserta al final de la lista
         */
        if(vOrigen->arista == nullptr){
            vOrigen->arista = nueva;
        }
        /*
         * Si el vértice origen no tiene aristas, se inserta al principio de la lista
         */
        else{
            Arista* aux = vOrigen->arista;
            while(aux->sig != nullptr)
                aux = aux->sig;
            aux->sig = nueva;
        }
    }
}
/*
 * Post: Muestra la lista de adyacencia
 * Recorre los vertices del grafo y muestra las conexiones
 * Imprime el nombre del origen del nodo en que se está recorriendo
 * También imprime el destino, precio y distancia de cada connexion
 */
void ViajeGrafo::mostrarListaDestinos() {
    Vertice* actual= primero;


    // Recorre los vertices
    while(actual != nullptr){
        Arista* aux = actual->arista;
        cout << "Origen: " << actual->nombre << endl;

        // Recorre las aristas de cada vertice
        while (aux != nullptr){
            cout << "Destino: " << " --> "  << aux->destino->nombre << endl;
            cout << "Precio: $" << aux->precio << "   "<< "Distancia: " << aux->distancia<< "Kms" << endl;
            aux = aux->sig;
            cout << endl;
        }
        cout<< "*************"<< endl;
        actual = actual->sig;
    }
}

/*
 * Post: Elinina un las conexiones de una ciudad
 */
void ViajeGrafo::eliminarConexion(const string& origen, const string& destino) {

    Vertice* vOrigen = obtenerCiudad(origen);
    Vertice* vDestino = obtenerCiudad(destino);

    if (vOrigen == nullptr ){
        cout << "el origen no existe " << endl; // Si el origen no existe
    }
    if( vDestino == nullptr){
        cout << "el destino no existe " << endl;  // Si el destino no existe
    }
    if (vOrigen != nullptr && vDestino != nullptr){

        // Si es la primera conexion (viaje) a eliminar
        vOrigen->arista->destino = vDestino;
        if(vOrigen->arista->destino){
            Arista* aux = vOrigen->arista;
            vOrigen->arista = vOrigen->arista->sig;
            cout << "Se eliminino la conexion" << origen << " --> " << destino  << endl;
            delete aux;
        }

        // Si no es la primera conexion (viaje) a eliminar

        else{
            Arista* actual = vOrigen->arista;
            Arista* sig = actual->sig;;

            // Recorre hasta encontrar la conexion a eliminar (viaje)
            while (sig != nullptr){

                if(sig->destino == vDestino){
                    actual->sig = sig->sig;
                    cout << "Se eliminino " << origen << "-->" << destino  << endl;
                    delete sig;
                    break;
                }
                actual = sig;
                sig = sig->sig;
            }
        }
    }
}

/*
 * Post: Elimina una Ciudad (vertice) y todos sus viajes (aristas-conexiones)
 */
void ViajeGrafo::eliminarCiudad(const std::string& nombre) {
    /*
     * Si es la primera ciudad a eliminar del grafo
     * 1. Elimina todas las conexiones de la ciudad
     * 2. Elimina la ciudad
     */
    if(primero->nombre == nombre){

         Vertice* aux = primero;
         primero = primero->sig;
         eliminarConexionesCiudad(aux);
         eliminarConexionesDestino(aux->nombre);
         cout << "Se elimino la cuidad " << nombre << endl;
         delete aux;
         tamanio--;
    }
    /*
     * Si se quiere eliminar una ciudad que no es la primera
     * 1. Elimina todas las conexiones de la ciudad
     * 2. Ligar la ciudad anterior con el siguiente para no perder la referencia
     * 3. Elimina la ciudad
     */
    else{
        // Recorre el grafo hasta encontrar el nodo
        Vertice* actual = primero;
        Vertice* aux = actual->sig;
        bool existe = false;    // Verifica si la ciudad existe en el grafo -- default: false

        while(aux != nullptr){
            if(aux->nombre == nombre){

                actual->sig = aux->sig;actual->sig = aux->sig;
                eliminarConexionesCiudad(aux);
                eliminarConexionesDestino(aux->nombre);
                actual->sig = aux->sig;
                cout << "Se elimino el Nodo" << nombre << endl;
                delete aux;
                tamanio--;
                existe = true; // True cuando elimina el nodo
                break;

            }
            actual = actual->sig; // aux;
            aux = aux->sig;
        }
        if(!existe)
            cout << "El Nodo no existe" << endl;
    }
}

//Post: Elimina toda la cuidades (vertices) del grafo
void ViajeGrafo::eliminarGrafo() {
    Vertice* actual = primero;

    while(primero != nullptr){
        actual = primero;
        primero = primero->sig;
        eliminarConexionesCiudad(actual);

        cout << "Se elimino el destino " << actual->nombre << endl;
        delete actual;
        tamanio--;
    }
}

// Elimina todas las conexiones de una ciudad(vertice)
void ViajeGrafo::eliminarConexionesCiudad(Vertice *ciudad) {

    if(ciudad == nullptr)
        return;

    Arista* aux;

    while(ciudad->arista != nullptr){

        aux = ciudad->arista; // aux apunta al la conexion(viaje) a eliminar
        ciudad->arista = ciudad->arista->sig;   // Apunta a la siguiente connexion de la ciudad a eliminar
        cout << "Eliminan conexion  " << ciudad->nombre
             << "-->" << aux->destino->sig << " eliminado " << endl;
        delete aux;
    }
}
// Post: Elimina todas las conexiones que apuntan a una ciudad (vertice)
void ViajeGrafo::eliminarConexionesDestino(const string& destino) {

    Vertice* actual = primero;

    while (actual != nullptr){
        if(actual->nombre == destino || actual->arista == nullptr){
            actual = actual->sig;
            continue;
        }
        // Si es la primera conexion a eliminar de la lista del destino
        if( actual->arista->destino->nombre == destino ){

            Arista* aux = actual->arista;
            actual->arista = actual->arista->sig;
            cout << "Eliminando Conexion : " << actual->nombre << "-->" << destino << endl;
            delete aux;
        }
        else{
            Arista* actualArista = actual->arista;
            Arista* aristaSig = actualArista->sig;

            while (aristaSig != nullptr){

               if(aristaSig->destino->nombre == destino){

                   actualArista->sig = aristaSig->sig;
                   cout << "Eliminando conexion : " << actual->nombre << "-->" << destino << endl;
                   delete aristaSig;

               }
               actualArista = aristaSig;
               aristaSig = aristaSig->sig;
            }
        }
        actual = actual->sig;
    }
}

bool CostoMinimo(const pair<Vertice*, int>& a, const pair<Vertice*, int>& b) {
    return a.second < b.second;
}

void ViajeGrafo::Dijkstra(const string& origen, const string& destino)
{
    Vertice* vorigen = obtenerCiudad(origen);
    Vertice* vdestino = obtenerCiudad(destino);

    // Verifica si existe el origen y el destino
    if (vorigen == nullptr )
        cout << "La cuidad origen no existe" << endl;



    else
    {
        /*
         * 1. Crea una matriz de pares (Vertice, int) para almacenar los vertices
         * 2. Genera una matriz de pares (Vertice, bool) para almacenar los vertices visitados
         * 3. Genera una matriz de pares (Vertice, Vertice) para almacenar las rutas
         * 4. Crea una matriz de pares (Vertice, int) para almacenar las distancias
         */
        map<Vertice*, map<Vertice*, int>> matriz;
        map<Vertice*, bool> visitados;
        map<Vertice*, Vertice*> rutas;
        map<Vertice*, int> cola;
        map<Vertice*, int> distancias;

        Vertice* vi = primero;

        /*
         * 1. Inicializa la matriz de visitados en falso
         * 2. Inicializa la matriz de distancias en infinito
         * 3. Inicializa la matriz de rutas en nullptr
         * @param vi: Vertices(ciudad) actual
         * @param vj: Vertices(ciudad) destino
         */
        while (vi != nullptr)
        {
            visitados[vi] = false;
            rutas[vi] = nullptr;
            distancias[vi] = MAX;

            Vertice* vj = primero;

            while (vj != nullptr)
            {
                matriz[vi][vj] = MAX;
                vj = vj->sig;
            }

            Arista* aj = vi->arista;

            while (aj != nullptr)
            {
                matriz[vi][aj->destino] = aj->precio;
                aj = aj->sig;
            }

            vi = vi->sig;
        }

        distancias[vorigen] = 0;
        visitados[vorigen] = true;
        cola[vorigen] = distancias[vorigen];

        while (!cola.empty())
        {
            // Encuentra el vertice con el costo menor en la cola
            map<Vertice*, int>::iterator iter = min_element(cola.begin(), cola.end(), CostoMinimo);
            visitados[iter->first] = true;

            // Recorre todos los vertices(ciudades) que tiene como destino
            Arista* ai = iter->first->arista;       // Arista(destino primero de la lista) actual

            while (ai != nullptr)
            {
                // Si el vertice(ciudad) destino no ha sido visitado
                if (!visitados[ai->destino])
                {
                    // Si la distancia es menor a la distancia actual
                    if (distancias[ai->destino] > distancias[iter->first] + matriz[iter->first][ai->destino])
                    {
                        // Actualiza la distancia
                        distancias[ai->destino] = distancias[iter->first] + matriz[iter->first][ai->destino];
                        rutas[ai->destino] = iter->first;
                        cola[ai->destino] = distancias[ai->destino];
                    }
                }
                ai = ai->sig;
            }

            cola.erase(iter->first);
        }

        // Muestra todos los viajes con sus respectivos precios
        for (map<Vertice*, int>::iterator i = distancias.begin(); i != distancias.end(); i++)
            cout << i->first->nombre << ": " << i->second << endl;

        // Muestra el viaje con el menor costo y su precio
        for(map<Vertice*, Vertice*>::iterator i = rutas.begin(); i != rutas.end(); i++)
        {
            if (i->first == vdestino)
            {
                cout << "El viaje mas barato es: " << endl;
                cout << i->first->nombre << " <-- ";

                while (i->second != nullptr)
                {
                    cout << i->second->nombre << " <-- ";
                    i->second = rutas[i->second];
                }

                cout << endl << "Precio: " << distancias[vdestino] << endl;
                break;
            }
        }

    }
}
