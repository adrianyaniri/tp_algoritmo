//
// Created by home on 9/11/22.
//

#include "NodoGrafo.h"
NodoGrafo::NodoGrafo(std::string _nombre) {
    nombre = _nombre;
    sig = nullptr;
    arista = nullptr;
}