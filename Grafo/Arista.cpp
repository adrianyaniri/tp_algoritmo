//
// Created by home on 9/11/22.
//

#include "Arista.h"

Arista::Arista(Vertice* _destino,int _precio, int _distancia) {
    precio = _precio;
    destino = _destino;
    distancia = _distancia;
    sig = nullptr;
    destino = nullptr;
}
