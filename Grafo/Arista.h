//
// Created by home on 9/11/22.
//

#ifndef ESTRUCTURASDATOS_ARISTA_H
#define ESTRUCTURASDATOS_ARISTA_H

class Vertice;

class Arista {

    friend class Grafo; // Para que Grafo pueda acceder a los atributos privados de Arista
    public:
        // Constructor
        Arista(Vertice* destino,int precio, int distancia);

       Arista *sig;
       Vertice *destino;
       int distancia;
       int precio;
};


#endif //ESTRUCTURASDATOS_ARISTA_H
