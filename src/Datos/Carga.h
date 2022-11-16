//
// Created by home on 16/11/22.
//

#ifndef ESTRUCTURASDATOS_CARGA_H
#define ESTRUCTURASDATOS_CARGA_H


#include <iostream>
#include <fstream>
#include <string>
#include "../Hash/Terminales.h"
#include "../Grafo/ViajeGrafo.h"

using namespace std;

const string TERMINALES = "/home/home/CLionProjects/estructurasDatos/src/Datos/terminales.txt";
const string VIAJES = "/home/home/CLionProjects/estructurasDatos/src/Datos/viajes.txt";

// Lee el archivo de terminales

void leerYCargarTerminales(string archivo, TablaHashTerminales &terminales);
void leerYCargarViajes(string archivo, ViajeGrafo &viajes);


#endif //ESTRUCTURASDATOS_CARGA_H
