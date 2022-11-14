//
// Created by home on 14/11/22.
//

#include "Menu.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void leerArchivo() {
    string linea;
    string nombreArchivo = "terminales.txt";
    ifstream archivo (nombreArchivo);

    getline(archivo, linea);
    cout << linea << endl;



}