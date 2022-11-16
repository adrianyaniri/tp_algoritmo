//
// Created by home on 9/11/22.
//

#ifndef ESTRUCTURASDATOS_NODO_H
#define ESTRUCTURASDATOS_NODO_H

#include <iostream>
#include "../Grafo/NodoGrafo.h"


class Nodo {
public:
    Nodo(Viaje dato);

    Viaje dato;
    Nodo *siguiente;
};


#endif //ESTRUCTURASDATOS_NODO_H
