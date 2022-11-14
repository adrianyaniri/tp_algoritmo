//
// Created by home on 13/11/22.
//

#ifndef ESTRUCTURASDATOS_TERMINALES_H
#define ESTRUCTURASDATOS_TERMINALES_H
#include <string>
#include <iostream>
#include <list>

using namespace std;


struct Terminal {
    string codigo;
    string nombre;
    float superficie;
    int cantidad_terminales;
    int destinos_nacionales;
    int destinos_internacionales;
};

class TablaHashTerminales {
    int tamano; /// tamaño de la tabla
    list<pair<int, Terminal> > *terminalesTabla; // se crea una lista de pares de enteros y terminales

public:
    // constructor
    bool estaVacia();
    void insertarTerminal(Terminal& terminal); // insertarTerminal un elemento en la tabla
    void eliminar(string codigo); // eliminar un elemento de la tabla
    void buscar(string codigo); // buscar un elemento en la tabla
    void imprimirTerminales(); // imprimirTerminales la tabla
    explicit TablaHashTerminales(int tamano);
    // funcion dipersion de los elementos


};



#endif //ESTRUCTURASDATOS_TERMINALES_H
