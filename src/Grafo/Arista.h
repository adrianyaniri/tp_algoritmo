//
// Created by home on 9/11/22.
//

#ifndef ESTRUCTURASDATOS_ARISTA_H
#define ESTRUCTURASDATOS_ARISTA_H

class NodoGrafo;

class Arista {

    friend class Grafo; // Para que Grafo pueda acceder a los atributos privados de Arista
    public:
        // Constructor
        Arista(NodoGrafo* destino, int precio, int distancia);

       Arista *sig;
       NodoGrafo *destino;
       int distancia;
       int precio;
};


#endif //ESTRUCTURASDATOS_ARISTA_H
