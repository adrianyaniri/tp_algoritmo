//
// Created by home on 9/11/22.
//

#include <iostream>
#include "ViajeGrafo.h"
using namespace std;

ViajeGrafo::ViajeGrafo() {
    primero = nullptr;
    tamanio = 0;
}

bool ViajeGrafo::estaVacio() {
    return primero == nullptr;
}


//Post: retorna el total de todos los nodos del grafo
int ViajeGrafo::obtenerTamanio() {
   return tamanio;
}

Vertice *ViajeGrafo::obtenerNodo(string nombre) {
    Vertice *aux = primero;  // aux apunta al primer vértice

    while (aux != nullptr) {
        if (aux->nombre == nombre) {
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}

void ViajeGrafo::insertarNodo(string nombre) {
    if(obtenerNodo(nombre) == nullptr){
        Vertice *nuevo = new Vertice(nombre);
        if(estaVacio())
            primero = nuevo;
        else{
            Vertice *aux = primero;
            while(aux->sig != nullptr)
                aux = aux->sig;
            aux->sig = nuevo;
        }
        tamanio++;
    }
    else{
        cout << "El viaje ya esta cargado " << endl;
    }

}

/*
 * Pre: Inserta una conexion entre el origen y el destino
 * @param origen: nombre del origen
 * @param destino: nombre del destino
 * @param precio: precio del viaje
 * @param distancia: distancia del viaje
 */
void ViajeGrafo::insertarConexion(string origen, string destino, int precio, int distancia) {

    Vertice* vOrigen = obtenerNodo(origen);
    Vertice* vDestino = obtenerNodo(destino);

    if(vOrigen == nullptr){
        cout << "Es lugar de origen no existe " << endl;   // Si alguno de los vértices no existe
    }
    if(vDestino == nullptr){
        cout << "Es lugar de destino no existe " << endl;
    }
    /*
     * Si el vértice primero no tiene aristas, se crea una nueva
     */
    if(vOrigen != nullptr && vDestino != nullptr){

        Arista* nueva = new Arista(vDestino, precio, distancia);

        /*
         * Si el vértice primero tiene aristas, se inserta al final de la lista
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
void ViajeGrafo::mostrarListaConexiones() {
    Vertice* actual= primero;


    // Recorre los vertices
    while(actual != nullptr){
        Arista* aux = actual->arista;
        cout << "Origen: " << actual->nombre << endl;

        // Recorre las aristas de cada vertice
        while (aux != nullptr){
            cout << " --> "  << "Destino: " << aux->destino->nombre << endl;
            cout << "Precio: $" << aux->precio << "   "<< "Distancia: " << aux->distancia<< "Kms" << endl;
            cout << endl;
            aux = aux->sig;
        }
        actual = actual->sig;
    }
}

/*
 * Post: Elinina un las conexiones de un nodo
 */
void ViajeGrafo::eliminarConexion(string origen, string destino) {

    Vertice* vOrigen = obtenerNodo(origen);
    Vertice* vDestino = obtenerNodo(destino);

    if (vOrigen == nullptr ){
        cout << "el origen no existe " << endl;
    }
    if( vDestino == nullptr){
        cout << "el destino no existe " << endl;
    }
    if (vOrigen != nullptr && vDestino != nullptr){

        if(vOrigen->arista->destino = vDestino){
            Arista* aux = vOrigen->arista;
            vOrigen->arista = vOrigen->arista->sig;
            cout << "Se eliminino " << origen << "-->" << destino  << endl;
            delete aux;
        }
        else{
            Arista* actual = vOrigen->arista;
            Arista* sig = actual->sig;;

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
 * Post: Elimina un vertice y todas sus aristas
 */
void ViajeGrafo::eliminarNodo(std::string nombre) {
    /*
     * Si es el primer nodo
     * 1. Elimina todas las aristas del nodo
     * 2. Elimina el nodo
     */
    if(primero->nombre == nombre){

         Vertice* aux = primero;
         primero = primero->sig;
         eliminarAristasVertice(aux);
        eliminarConexionesDestino(aux->nombre);
         cout << "Se elimino el vertice " << nombre << endl;
         delete aux;
         tamanio--;
    }
    /*
     * Si se quiere eliminar un nodo que no es el primero
     * 1. Elimina todas las aristas del nodo
     * 2. Ligar el nod anterior con el siguiente para no perder la referencia
     * 3. Elimina el nodo
     */
    else{
        // Recorre el grafo hasta encontrar el nodo
        Vertice* actual = primero;
        Vertice* aux = actual->sig;
        bool existe = false;    // Verifica si el nodo existe en el grafo -- default: false

        while(aux != nullptr){
            if(aux->nombre == nombre){
                eliminarAristasVertice(aux);
                eliminarConexionesDestino(aux->nombre);
                actual->sig = aux->sig;
                cout << "Se elimino el vertice " << nombre << endl;
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

//Post: Elimina todos los nodos del grafo
void ViajeGrafo::eliminarGrafo() {
    Vertice* actual = primero;

    while(primero != nullptr){
        actual = primero;
        primero = primero->sig;
        eliminarAristasVertice(actual);
        cout << "Se elimino el destino " << actual->nombre << endl;
        delete actual;
        tamanio--;
    }
}

// Elimina todas las conexiones de un nodo
void ViajeGrafo::eliminarAristasVertice(Vertice *nodo) {
    Arista* aux = nodo->arista;

    while(nodo->arista != nullptr){

        aux = nodo->arista; // aux apunta al nodo que se va a eliminar
        nodo->arista = nodo->arista->sig;   // Apunta a la siguiente connexion del nodo a eliminar
        cout << "Eliminando Nodo: " << nodo->nombre
             << "-->" << aux->destino->sig << "eliminado " << endl;
        delete aux;
    }
}
// Post: Elimina todas las conexiones que apuntan a un nodo
void ViajeGrafo::eliminarConexionesDestino(string destino) {
    Vertice* actual = primero;

    while (actual != nullptr){
        if(actual->nombre == destino)  // Si el nodo es el destino
            continue;
        // Si es la primera conexion a eliminar de la lista del destino
        if( actual->arista->destino->nombre == destino ){
            Arista* aux = actual->arista;
            actual->arista = actual->arista->sig;
            cout << "Eliminando arista: " << actual->nombre << "-->" << aux->destino->nombre << endl;
            delete aux;
        }
        else{
            Arista* actualArista = actual->arista;
            Arista* aristaSig = actualArista->sig;

            while (aristaSig != nullptr){
               if(aristaSig->destino->nombre == destino){
                   actualArista->sig = aristaSig->sig;
                   cout << "Eliminando arista: " << actual->nombre << "-->" << aristaSig->destino->nombre << endl;
                   delete aristaSig;
                   break;
               }
               actualArista = aristaSig;
               aristaSig = aristaSig->sig;
            }
        }
    }
}
