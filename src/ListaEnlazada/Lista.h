//
// Created by home on 9/11/22.
//

#ifndef ESTRUCTURASDATOS_LISTA_H
#define ESTRUCTURASDATOS_LISTA_H


#include "Nodo.h"

class Lista {

private:
    void insertar(Dato dato, Nodo *nodo);
    void imprimir(Nodo *nodo);
    void eliminar(Nodo *nodo, Dato dato);

public:
    int tamanio = 0;
    //Constructor
    Nodo *primero{};

    void insertar(Dato dato);
    void eliminar(Dato viaje);
    void imprimir();
    bool estaVacia();
    void imprimirListaCompleta();
};


#endif //ESTRUCTURASDATOS_LISTA_H
