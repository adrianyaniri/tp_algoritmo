//
// Created by home on 9/11/22.
//

#include "Arista.h"

Arista::Arista(NodoGrafo* _destino, int _precio, int _distancia) {
    precio = _precio;
    destino = _destino;
    distancia = _distancia;
    sig = nullptr;
}
