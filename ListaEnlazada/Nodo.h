//
// Created by home on 9/11/22.
//

#ifndef ESTRUCTURASDATOS_NODO_H
#define ESTRUCTURASDATOS_NODO_H

#include <iostream>

typedef struct Dato{
    int id;
    char *origen;
    char *destino;
    int duracion;
    int precio;
} Viaje;

class Nodo {
public:
    Nodo(Dato dato);

    Dato dato;
    Nodo *siguiente;
};


#endif //ESTRUCTURASDATOS_NODO_H
