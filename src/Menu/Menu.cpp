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

    ViajeGrafo viajes;
    leerYCargarViajes(VIAJES, viajes);

    string ciudad;
    string ciudadOrigen ;
    string ciudadDestino;

    int precio;
    int distancia;

    int opcion;
    do {
        cout << "\n========================================" << endl;
        cout << "Menu de Viajes" << endl;
        cout << "========================================" << endl;
        cout << "1. Mostrar viajes" << endl;
        cout << "2. Ingresar una nueva ciudad " << endl;
        cout << "3. Ingresar un nuevo viaje" << endl;
        cout << "4. Eliminar una ciudad" << endl;
        cout << "5. Eliminar viajes " << endl;
        cout << "7. Mostrar viajes de una ciudad a otra con un precio maximo y una duracion maxima" << endl;
        cout << "8. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
               cout << "Viajes: " << endl;
                viajes.mostrarListaDestinos();
                break;
            case 2:
                cout << "Ingrese la ciudad: ";
                cin >> ciudad;
                viajes.insertarCuidad(ciudad);
                cout << " Nueva ciudad ingresada: " << ciudad << endl;
                break;
            case 3:
                cout << "Ingrese el codigo de la ciudad origen " << endl;
                cin >> ciudadOrigen;
                cout << "Ingrese el codigo de la ciudad destino " << endl;
                cin >> ciudadDestino;
                cout << "Ingresar Precio " << endl;
                cin >> precio;
                cout << "Ingresar distancia " << endl;
                cin >> distancia;
                viajes.insertarViaje(ciudadOrigen, ciudadDestino, precio, distancia);
                cout << "Ingresar un nuevo viaje desde : "
                << ciudadOrigen<< " hasta " << ciudadDestino << endl;
                break;
            case 4:
                cout << "Ingresar el codigo de la ciudad a eliminar: ";
                cin >> ciudad;
                viajes.eliminarCiudad(ciudad);
                break;
            case 5:
                cout << "Ingresar el codigo de la ciudad origen: ";
                cin >> ciudadOrigen;
                cout << "Ingresar el codigo de la ciudad destino: ";
                cin >> ciudadDestino;
                viajes.eliminarConexion(ciudadOrigen, ciudadDestino);
                cout << "Se elimino el viaje desde : " << ciudadOrigen << " hasta " << ciudadDestino << endl;
                break;
            case 6:
                cout << "Ingresar el codigo de la ciudad origen: ";
                cin >> ciudadOrigen;
                cout << "Ingresar el codigo de la ciudad destino: ";
                cin >> ciudadDestino;
                viajes.Dijkstra(ciudadOrigen, ciudadDestino);
                cout << "Mostar el camino mas corto de una ciudad a otra" << endl;
                break;
            case 8:
                cout << "Hasta luego!" << endl;
                exit(EXIT_SUCCESS);break;
            default:
                cout << "Opcion invalida" << endl;
                cout << "Ingrese una opcion valida" << endl;
        }
    } while (opcion != 8);
}

void menuTerminales () {
    TablaHashTerminales terminales(5000 );
    leerYCargarTerminales(TERMINALES, terminales);

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
                cout << "Ingrese el codigo de la terminal a eliminar: " << endl;
                cin >> terminal;
                terminales.eliminarTerminal(terminal);
                cout << "Se elimino la terminal con codigo: " << terminal << endl;
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