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

int ViajeGrafo::obtenerTamanio() {
   return tamanio;
}

Vertice *ViajeGrafo::obtenerVertice(string nombre) {
    Vertice *aux = primero;  // aux apunta al primer vértice

    while (aux != nullptr) {
        if (aux->nombre == nombre) {
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}

void ViajeGrafo::insertarVertice(string nombre) {
    if(obtenerVertice(nombre) == nullptr){
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

void ViajeGrafo::insertarArista(string origen, string destino, int precio, int distancia) {

    Vertice* vOrigen = obtenerVertice(origen);
    Vertice* vDestino = obtenerVertice(destino);

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
         * Si el vértice origne no tiene aristas, se inserta al principio de la lista
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
 * Recorre los vertices y recorre las aristas de cada vertice
 * Imprime el nombre del vertice que se esta recorriendo
 * Tambien imprime el destino, precio y distancia de cada arista
 */
void ViajeGrafo::mostrarListaAdyacencia() {
    Vertice* actual= primero;


    // Recorre los vertices
    while(actual != nullptr){
        Arista* aux = actual->arista;

        // Recorre las aristas de cada vertice
        while (aux != nullptr){
            cout << "Origen: " << actual->nombre << " --> "  << "Destino: " << aux->destino->nombre << endl;
            cout << "Precio: $" << aux->precio << "   "<< "Distancia: " << aux->distancia<< "Kms" << endl;
            cout << endl;
            aux = aux->sig;
        }
        actual = actual->sig;
    }
}

/*
 * Post: Elinina un vertice y todas sus aristas
 */
void ViajeGrafo::eliminarArista(string origen, string destino) {

    Vertice* vOrigen = obtenerVertice(origen);
    Vertice* vDestino = obtenerVertice(destino);

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
void ViajeGrafo::eliminarVertice(std::string nombre) {
    /*
     * Si es el primer vertice
     * 1. Elimina todas las aristas del vertice
     * 2. Elimina el vertice
     */
    if(primero->nombre == nombre){

         Vertice* aux = primero;
         primero = primero->sig;
         eliminarAristasVertice(aux);
         eliminarAristasDestino(aux->nombre);
         cout << "Se elimino el vertice " << nombre << endl;
         delete aux;
         tamanio--;
    }
    /*
     * Si elima un vertice que no es el primero
     * 1. Elimina todas las aristas del vertice
     * 2. Ligar el vertice anterior con el siguiente para no perder la referencia
     * 3. Elimina el vertice
     */
    else{
        // Recorre el grafo hasta encontrar el vertice
        Vertice* actual = primero;
        Vertice* aux = actual->sig;
        bool existe = false;    // Indica false si el vertice no existe

        while(aux != nullptr){
            if(aux->nombre == nombre){
                eliminarAristasVertice(aux);
                eliminarAristasDestino(aux->nombre);
                actual->sig = aux->sig;
                cout << "Se elimino el vertice " << nombre << endl;
                delete aux;
                tamanio--;
                existe = true; // True cuando elimina el vertice
                break;
            }
            actual = actual->sig; // aux;
            aux = aux->sig;
        }
        if(!existe)
            cout << "El vertice no existe" << endl;
    }
}

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

// Elimina todos las arista del vertice
void ViajeGrafo::eliminarAristasVertice(Vertice *vertice) {
    Arista* aux = vertice->arista;

    while(vertice->arista != nullptr){

        aux = vertice->arista; // aux apunta al vertice que se va a eliminar
        vertice->arista = vertice->arista->sig;   // Apunta a la siguiente arista del vertice a eliminar
        cout << "Eliminando arista: " << vertice->nombre
        <<"-->" << aux->destino->sig << "eliminada "<< endl;
        delete aux;
    }
}

void ViajeGrafo::eliminarAristasDestino(string destino) {
    Vertice* actual = primero;

    while (actual != nullptr){
        if(actual->nombre == destino)  // Si el vertice es el destino
            continue;
        // Si es la primera arista a eliminar de la lista del destino
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
