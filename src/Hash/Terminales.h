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
    string ciudad;
    string pais;
    double superficie;
    int cantidad_terminales;
    int destinos_nacionales;
    int destinos_internacionales;
};

class TablaHashTerminales {
    int tamano;
    list<pair<int, Terminal> > *terminalesTabla;
public:
    // Constructor
    TablaHashTerminales(int tamano);

    // Funciones
    bool estaVacia();
    void insertarTerminal(Terminal terminal);
    void mostrarTodasLasTerminales();
    void mostarTerminal(Terminal terminal);
    void buscarTerminal(string codigo);
    void eliminarTerminal(string codigo);

};



#endif //ESTRUCTURASDATOS_TERMINALES_H
