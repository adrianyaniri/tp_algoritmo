//
// Created by home on 16/11/22.
//

#include "LeerTxt.h"
#include <iostream>
#include <fstream>
#include <sstream>

void leerTxtTerminal(string archivo, TablaHashTerminales &terminales){



}


void leer(string archivo, TablaHashTerminales &terminales) {
    Terminal terminal;
    string texto = archivo;
    ifstream file(texto.c_str());
    string line;
    if(file.is_open()){
        while(getline(file, line)){
            // leer y cargar en la tabla hash
            istringstream iss(line);
            iss >> terminal.codigo;
            iss >> terminal.nombre;
            iss >> terminal.ciudad;
            iss >> terminal.pais;
            iss >> terminal.superficie;
            iss >> terminal.cantidad_terminales;
            iss >> terminal.destinos_nacionales;
            iss >> terminal.destinos_internacionales;

            terminales.insertarTerminal(terminal);

        }
        file.close();
    }
    else
        cout << "No se pudo abrir el archivo" << endl;

}