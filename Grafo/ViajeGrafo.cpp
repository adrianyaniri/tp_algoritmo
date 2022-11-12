//
// Created by home on 9/11/22.
//

#include <iostream>
#include <map>
#include <limits>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include "ViajeGrafo.h"

using namespace std;

#define INFINITO 1000000000

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

//Post: Elimina todas la cuidades (vertices) del grafo
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

/*
 * Función auxiliar para obtener el costo minimo
 * Compara el costo de dos ciudades y retorna la ciudad con el costo minimo
 */

bool costoMinimo(const pair<Vertice*, int>& a, const pair<Vertice*, int>& b){
    return a.second < b.second;
}


// Post: Encuentra la ruta más corta entre dos ciudades (vertices)
void ViajeGrafo::reocorridoDijkstra(const string &origen) {

    //Obtiene la ciudad de origen donde se va a iniciar el recorrido
    Vertice* ciudadOrigen = obtenerCiudad(origen);

    //Válida que la ciudad de origen exista
    if(ciudadOrigen == nullptr){
        cout << "La ciudad de origen no existe" << endl;
        return;
    }
    else{
        /*
         * 1. Inicializa las distancias de todas las ciudades con un valor infinito
         * 2. Inicializa la distancia de la ciudad de origen con un valor de 0
         * Se utiliza map para crear la matriz para almacenar las distancias y los vertices visitados
         */
        map<Vertice*, map<Vertice*, int>> matriz;
        map<Vertice*, bool> visitados;   // Mapa para almacenar los vertices visitados
        map<Vertice*, Vertice*> rutas;  // Almacena las rutas de las ciudades
        map<Vertice*, int> distancias;  // Almacena las distancias de las ciudades
        map<Vertice* ,int> cola;  // Ciudades pendientes a visitar --Cambiar por una implementation de cola propia

        // Inicializa la matriz con los pesos y ciudades
        Vertice* actual = primero;

        while(actual != nullptr){

            // Recorre las Filas de la matriz
            visitados[actual] = false;      // Inicializa todas las ciudades como no visitadas
            rutas[actual] = nullptr;        // Inicializa todas las rutas como nulas
            distancias[actual] = INFINITO;   // Inicializa todas las distancias como infinito

            // Recorre las columnas de la matriz
             Vertice* aux = primero;

             while(aux != nullptr){

                 matriz[actual][aux] = INFINITO;  // Inicializa todas las distancias como infinito
                 aux = aux->sig;
             }
             // Recorre las conexiones de la ciudad actual para obtener los pesos
             Arista* arista = actual->arista;
                while(arista != nullptr){
                    matriz[actual][arista->destino] = arista->distancia;
                    arista = arista->sig;
                }
            actual = actual->sig;
        }
        distancias[ciudadOrigen] = 0;               // Inicializa la distancia de la ciudad de origen con un valor de 0
        visitados[ciudadOrigen] = true;             // Pone a la ciudad de origen como visitada
        cola[ciudadOrigen] = distancias[ciudadOrigen];         // Agrega la ciudad de origen a la cola de ciudades pendientes

        // Procesa la ciudad actual
        while(!cola.empty()){
            // Obtiene la ciudad con la distancia más corta
            map<Vertice*, int>::iterator it= min_element(cola.begin(), cola.end(), costoMinimo);
            visitados[it->first] = true;            // Pone la ciudad actual como visitada

            // Recorre las conexiones de la ciudad actual
            Arista* arista = it->first->arista;
            while (arista != nullptr){

                // Si la ciudad destino no ha sido visitada
                if(!visitados[arista->destino]){
                    if(distancias[arista->destino] > distancias[it->first] + matriz[it->first][arista->destino]){
                        distancias[arista->destino] = distancias[it->first] + matriz[it->first][arista->destino];
                        rutas[arista->destino] = it->first;
                        cola[arista->destino] = distancias[arista->destino];
                    }
                }
                arista = arista->sig;
            }
            cola.erase(it->first);
        }
        // Imprime las distancias de las ciudades
        for(map<Vertice*, int>::iterator it = distancias.begin(); it != distancias.end(); it++){
            cout << "Distancia de " << ciudadOrigen->nombre << " a " << it->first->nombre << " es " << it->second << endl;
        }
        cout << endl;

    }
}



