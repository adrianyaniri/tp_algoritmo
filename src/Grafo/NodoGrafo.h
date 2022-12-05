//
// Created by home on 9/11/22.
//

#ifndef ESTRUCTURASDATOS_NODOGRAFO_H
#define ESTRUCTURASDATOS_NODOGRAFO_H


#include <string>
#include "Arista.h"

using namespace std;

struct Viaje{
    string origen;
    string destino;
    int duracion;
    int precio;
};


class NodoGrafo {

    friend class Grafo; // Para que Grafo pueda acceder a los atributos privados de NodoGrafo

public:
    // Constructor
    NodoGrafo(std::string nombre);

    NodoGrafo* sig;
    std::string nombre;
    Arista* arista;
};


#endif //ESTRUCTURASDATOS_NODOGRAFO_H
