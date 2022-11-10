//
// Created by home on 9/11/22.
//

#ifndef ESTRUCTURASDATOS_VERTICE_H
#define ESTRUCTURASDATOS_VERTICE_H


#include <string>


// Clase
class Arista;

class Vertice {
    Arista* ady;

    friend class Grafo; // Para que Grafo pueda acceder a los atributos privados de Vertice

public:
    // Constructor
    Vertice(std::string nombre);

    Vertice* sig;
    std::string nombre;
};


#endif //ESTRUCTURASDATOS_VERTICE_H
