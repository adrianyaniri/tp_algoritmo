//
// Created by home on 9/11/22.
//

#include <iostream>
#include "Lista.h"

/*
 * Post: inserta un nuevo nodo al principio de la lista
 * @param dato: dato a insertar
 * @param nodo: nodo a insertarTerminal
 */
void Lista::insertar(Dato dato, Nodo *nodo) {
    if (nodo->siguiente == nullptr){
        nodo->siguiente = new Nodo(dato);

    } else {
        insertar(dato, nodo->siguiente);
    }
}

/*
 * Post: Imprime los datos del nodo actual
 * @param nodo: nodo a imprimir
 */
void Lista::imprimir(Nodo *nodo) {
    if( nodo != nullptr)
        std::cout<<
        "Origen: " << nodo->dato.origen << " " <<
        "Destino: " << nodo->dato.destino << " " <<
        "Duracion: " << nodo->dato.duracion << " hs" << " " <<
        "Precio: " << nodo->dato.precio << std::endl;
}

/*
 * Post: elimina el nodo de la lista
 * @param nodo: nodo a eliminar
 * @param dato: dato a eliminar
 */
void Lista::eliminar(Nodo *nodo, Dato dato) {
    if(nodo == nullptr)
        return;

    if (nodo->dato.id == dato.id && nodo == primero){
        Nodo *temp = primero;
        if (primero->siguiente != nullptr)
            primero = primero->siguiente;
            delete temp;

        } else {
            primero = nullptr;

        return;
    }
    if (nodo->siguiente != nullptr && nodo->siguiente->dato.id == dato.id){
        if (nodo->siguiente->dato.id == dato.id){
            Nodo *temp = nodo->siguiente;
            if(nodo->siguiente != nullptr){
                nodo->siguiente = nodo->siguiente->siguiente;
            }
            delete temp;
        };
    } else {
        eliminar(nodo->siguiente, dato);
    };
}


/*
 * Metodos publicos
 */

void Lista::insertar(Dato dato) {
    if (primero == nullptr)
        primero = new Nodo(dato);
    else
        insertar(dato, primero);
    tamanio++;
}

void Lista::eliminar(Dato viaje) {
    this->eliminar(primero, viaje);
    tamanio--;
}


void Lista::imprimir() {
    std::cout << "Lista de viajes"<< std::endl;
    imprimir(primero);

}

// Post: indica si la lista esta vacia
bool Lista::estaVacia()  {
    return primero == nullptr;
}

void Lista::imprimirListaCompleta() {
    Nodo *temp = primero;
    while (temp != nullptr){
        imprimir(temp);
        temp = temp->siguiente;
    }
}
