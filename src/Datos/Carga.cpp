//
// Created by home on 16/11/22.
//

#include "Carga.h"
#include <iostream>
#include <sstream>

void leerYCargarTerminales(string archivo, TablaHashTerminales &terminales) {
    Terminal terminal;
    string texto = archivo;
    ifstream file(texto.c_str());
    string line;
    if(file.is_open()){
        while(getline(file, line)){
            // leerYCargarTerminales y cargar en la tabla hash
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


/*
 * Lee el archivo de viajes
 * @param archivo: nombre del archivo
 * @param viajes: Grafo de viajes
 * Cargo el grafo de viajes
 */
void leerYCargarViajes(string archivo, ViajeGrafo &viajes) {
    NodoGrafo* origen;
    Viaje viaje;

    string texto = archivo;
    ifstream file(texto.c_str());
    string line;

    if (file.is_open()){
        while(getline(file, line,'\n')){
            istringstream iss( line);
            iss >> viaje.origen;
            iss >> viaje.destino;
            iss >> viaje.duracion;
            iss >> viaje.precio;

            origen = new NodoGrafo(viaje.origen);
            viajes.insertarCuidad(origen->nombre);
            viajes.insertarCuidad(viaje.destino);
            viajes.insertarViaje(viaje.origen,viaje.destino,viaje.precio,viaje.duracion);
        }
    }
    else
        cout << "No se pudo abrir el archivo" << endl;
}