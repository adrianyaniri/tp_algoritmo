//
// Created by home on 16/11/22.
//

#include "Menu.h"
#include "../Hash/Terminales.h"
#include "../Datos/Carga.h"

#include <iostream>
#

using namespace std;

void menuPrincipal() {
    int opcion;
    do {
        cout << "\n========================================" << endl;
        cout << "Menu de Terminales" << endl;
        cout << "========================================" << endl;
        cout << "1. Terminales" << endl;
        cout << "2. Viajes" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                menuTerminales();
                break;
            case 2:
                menuViajes();
                break;
            case 3:
                cout << "Hasta luego!" << endl;
                exit(EXIT_SUCCESS);break;
            default:
                cout << "Opcion invalida" << endl;
                cout << "Ingrese una opcion valida" << endl;
        }
    } while (opcion != 3);
}
void menuViajes (){
    cout << endl;
    cout << "1. Carga" << endl;
}

void menuTerminales () {
    TablaHashTerminales terminales(5000 );
    ViajeGrafo viajes;

    leerYCargarTerminales(TERMINALES, terminales);
    leerYCargarViajes(VIAJES, viajes);
    int op;
    std::string terminal;
    std::string ciudad;
    Terminal nuevaTerminal;
    string codigo;
    string nombre;
    string pais;
    double superficie;
    int cantidad_terminales, destinos_nacionales, destinos_internacionales;

    do {
        cout << "\n========================================" << endl;
        cout << "Menu de Terminales" << endl;
        cout << "========================================" << endl;
        cout << "1. Ver todas las terminales" << endl;
        cout << "2. Buscar terminal " << endl;
        cout << "3. Eliminar terminal" << endl;
        cout << "4. Insertar una nueva terminal" << endl;
        cout << "5. Volver al menu anterior" << endl;
        cout << "6. Salir" << endl;
        cout << "========================================" << endl;
        cout << "Ingrese una opcion: " ;
        cin >> op;
        switch (op) {
            case 1:
                cout << "Terminales encontradas" << endl;
                cout << "-----------------------" << endl;
                terminales.mostrarTodasLasTerminales();
                cout << "-----------------------" << endl;
               break;
            case 2:
                cout << "Ingresa el codigo de la terminal" << endl;
                cin >> terminal;
                terminales.buscarTerminal(terminal);
                if (terminal == "0")
                    cout <<"No se encontro terminal con ese codigo \n" << terminal << endl;
                cout << "______________________________" << endl;
                cout << "Terminales encontradas" << endl;
                break;
            case 3:
                cout << "Eliminar una Terminal" << endl;
                cin >> terminal;
                terminales.eliminarTerminal(terminal);
                if (terminal == "0")
                    cout <<"No se encontro terminal con ese codigo " << terminal << endl;
                cout << "______________________________" << endl;
                break;
            case 4:
                cout << "Ingrese el codigo de la terminal" << endl;
                cin >> codigo;
                nuevaTerminal.codigo = codigo;
                cout << "Ingrese el nombre de la terminal" << endl;
                cin >> nombre;
                nuevaTerminal.nombre = nombre;
                cout << "Ingrese la ciudad de la terminal" << endl;
                cin >> ciudad;
                nuevaTerminal.ciudad = ciudad;
                cout << "Ingrese el pais de la terminal" << endl;
                cin >> pais;
                nuevaTerminal.pais = pais;
                cout << "Ingrese la superficie de la terminal" << endl;
                cin >> superficie;
                nuevaTerminal.superficie = superficie;
                cout << "Ingrese la cantidad de terminales de la terminal" << endl;
                cin >> cantidad_terminales;
                nuevaTerminal.cantidad_terminales = cantidad_terminales;
                cout << "Ingrese la cantidad de destinos nacionales de la terminal" << endl;
                cin >> destinos_nacionales;
                nuevaTerminal.destinos_nacionales = destinos_nacionales;
                cout << "Ingrese la cantidad de destinos internacionales de la terminal" << endl;
                cin >> destinos_internacionales;
                nuevaTerminal.destinos_internacionales = destinos_internacionales;

                // Inserta la nueva terminal en la tabla hash
                terminales.insertarTerminal(nuevaTerminal);
                cout << "Terminal Cargada con exito!!!" << endl;
                terminales.mostarTerminal(nuevaTerminal);
                cout << "______________________________" << endl;
                break;
            case 5:
                cout << "Volver al menu anterior" << endl;
                break;
            case 6:
                cout << "Hasta luego!!!!!!!" << endl;
                //Exit
                exit(EXIT_SUCCESS);
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        cin.ignore();
        cout << "Presione enter para continuar" << endl;
        cin.get();
    } while (op != 5);
}