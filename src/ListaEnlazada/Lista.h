//
// Created by home on 9/11/22.
//

#ifndef ESTRUCTURASDATOS_LISTA_H
#define ESTRUCTURASDATOS_LISTA_H


#include "Nodo.h"

class Lista {

private:
    void insertar(Viaje dato, Nodo *nodo);
    void imprimir(Nodo *nodo);
    void eliminar(Nodo *nodo, Viaje dato);

public:
    int tamanio = 0;
    //Constructor
    Nodo *primero{};

    void insertar(Viaje dato);
    void eliminar(Viaje viaje);
    void imprimir();
    bool estaVacia();
    void imprimirListaCompleta();
};


#endif //ESTRUCTURASDATOS_LISTA_H
