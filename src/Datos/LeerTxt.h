//
// Created by home on 16/11/22.
//

#ifndef ESTRUCTURASDATOS_LEERTXT_H
#define ESTRUCTURASDATOS_LEERTXT_H


#include <iostream>
#include <fstream>
#include <string>
#include "../Hash/Terminales.h"

using namespace std;

const string TERMINALES = "/home/home/CLionProjects/estructurasDatos/src/Datos/terminales.txt";
const string VIAJES = "/home/home/CLionProjects/estructurasDatos/src/Datos/viajes.txt";

// Lee el archivo de terminales
void leerTxtTerminal(string archivo, TablaHashTerminales &terminales);
void leer(string archivo, TablaHashTerminales &terminales);


#endif //ESTRUCTURASDATOS_LEERTXT_H
