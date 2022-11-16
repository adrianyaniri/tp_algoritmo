//
// Created by home on 16/11/22.
//

#include "Menu.h"
#include "../Hash/Terminales.h"
#include "../Datos/Carga.h"

#include <iostream>

using namespace std;



void menu () {
    TablaHashTerminales terminales(5000 );
    ViajeGrafo viajes;

    int opc = 0;
    while (opc != 6) {


        cout << "1. Dar de Alta una Terminal" << endl;
        cout << "2. Dar de Baja una Terminal" << endl;
        cout << "3. Obtener Terminales" << endl;
        cout << "4. Dar de Alta un Viaje" << endl;
        cout << "5. Buscar Combination mas Económica" << endl;
        cout << "6. Mostrar lista de viajes" << endl;
        cout << "7. Salir" << endl;

        cout << endl;
        cout << "Ingrese una opcion del menu: ";
        cin >> opc;


        switch (opc) {
            case 1: {
                //Terminal terminal;

                string codigo, nombre, ciudad, pais;
                double superficie;
                int cantidad_terminales, destinos_nacionales, destinos_internacionales;

                cout << "Ingrese el codigo de la Terminal: ";
                cin >> codigo;

                cout << "Ingrese el nombre de la Terminal: ";
                cin >> nombre;

                cout << "Ingrese la ciudad: ";
                cin >> ciudad;

                cout << "Ingrese el pais: ";
                cin >> pais;

                cout << "Ingrese la superficie: ";
                cin >> superficie;

                cout << "Ingrese la cantidad de terminales: ";
                cin >> cantidad_terminales;

                cout << "Ingrese la cantidad de destinos nacionales: ";
                cin >> destinos_nacionales;

                cout << "Ingrese la cantidad de destinos internacionales: ";
                cin >> destinos_internacionales;

                Terminal terminal = {codigo, nombre, ciudad, pais, superficie, cantidad_terminales, destinos_nacionales,
                                     destinos_internacionales};
                terminales.insertarTerminal(terminal);
                break;
            }
            case 2: {/*
                string codigoTerminal = cout << "Ingrese el codigo de la Terminal que desea eliminar:";
                cin >> codigoTerminal;
                terminales.eliminarTerminal(codigoTerminal);
            */
                break;
            }

            case 3: {
                leerYCargarTerminales(TERMINALES, terminales);
                terminales.imprimeTablaTerminales();

                break;
            }
            case 4: {


                string origen, destino;
                int id, duracion, precio;

                cout << "Ingrese el Origen: ";
                cin >> origen;

                cout << "Ingrese el Destino: ";
                cin >> destino;

                cout << "Ingrese la duracion: ";
                cin >> duracion;

                cout << "Ingrese el Precio: ";
                cin >> precio;

                Viaje viaje1 = {origen, destino, duracion, precio};

                viajes.insertarCuidad(viaje1.origen);

                viajes.insertarViaje(viaje1.origen, viaje1.destino, viaje1.precio, viaje1.duracion);

                break;
            }

            case 5: {

                viajes.mostrarListaDestinos();
                viajes.Dijkstra("COR", "RET");
                //viajes.Dijkstra("RE", "SCL");
                break;
            }
            case 6: {
                leerYCargarViajes(VIAJES, viajes);
                viajes.mostrarListaDestinos();
                break;
            }
            case 7: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
        }
        cin.get();
        cin.get();


    }
}