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
        //cout << "\n========================================" << endl;
        cout << "\n\n\t\t\tMenu de Terminales" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Terminales" << endl;
        cout << "\t2. Viajes" << endl;
        cout << "\t3. Salir" << endl;
        cout << "\n\tIngrese una opcion: ";

        cin >> opcion;
        switch (opcion) {
            case 1:
                menuTerminales();
                break;
            case 2:
                menuViajes();
                break;
            case 3:
                cout << "\tHasta luego!" << endl;
                exit(EXIT_SUCCESS);break;
            default:
                cout << "\tOpcion invalida" << endl;
                cout << "\n\tIngrese una opcion valida" << endl;
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
        //cout << "\n========================================" << endl;
        cout << "\n\n\t\t\tMenu de Viajes" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Mostrar viajes" << endl;
        cout << "\t2. Ingresar una nueva ciudad " << endl;
        cout << "\t3. Ingresar un nuevo viaje" << endl;
        cout << "\t4. Eliminar una ciudad" << endl;
        cout << "\t5. Eliminar viajes " << endl;
        cout << "\t7. Mostrar viajes de una ciudad a otra con un precio maximo y una duracion maxima" << endl;
        cout << "\t8. Salir" << endl;
        cout << "\tIngrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "\n\tViajes: " << endl;
                viajes.mostrarListaDestinos();
                break;
            case 2:
                cout << "\n\tIngrese la ciudad: ";
                cin >> ciudad;
                viajes.insertarCuidad(ciudad);
                cout << "\tNueva ciudad ingresada: " << ciudad << endl;
                break;
            case 3:
                cout << "\n\tIngrese el codigo de la ciudad origen " << endl;
                cin >> ciudadOrigen;
                cout << "\n\tIngrese el codigo de la ciudad destino " << endl;
                cin >> ciudadDestino;
                cout << "\n\tIngresar Precio " << endl;
                cin >> precio;
                cout << "\n\tIngresar distancia " << endl;
                cin >> distancia;
                viajes.insertarViaje(ciudadOrigen, ciudadDestino, precio, distancia);
                cout << "\n\tIngresar un nuevo viaje desde : "
                     << ciudadOrigen<< " hasta " << ciudadDestino << endl;
                break;
            case 4:
                cout << "\n\tIngresar el codigo de la ciudad a eliminar: ";
                cin >> ciudad;
                viajes.eliminarCiudad(ciudad);
                break;
            case 5:
                cout << "\n\tIngresar el codigo de la ciudad origen: ";
                cin >> ciudadOrigen;
                cout << "\tIngresar el codigo de la ciudad destino: ";
                cin >> ciudadDestino;
                viajes.eliminarConexion(ciudadOrigen, ciudadDestino);
                cout << "\tSe elimino el viaje desde : " << ciudadOrigen << " hasta " << ciudadDestino << endl;
                break;
            case 6:
                cout << "\n\tIngresar el codigo de la ciudad origen: ";
                cin >> ciudadOrigen;
                cout << "\tIngresar el codigo de la ciudad destino: ";
                cin >> ciudadDestino;
                viajes.Dijkstra(ciudadOrigen, ciudadDestino);
                cout << "\tMostar el camino mas corto de una ciudad a otra" << endl;
                break;
            case 8:
                cout << "\tHasta luego!" << endl;
                exit(EXIT_SUCCESS);break;
            default:
                cout << "\tOpcion invalida" << endl;
                cout << "\tIngrese una opcion valida" << endl;
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
        //cout << "\n========================================" << endl;
        cout << "\n\n\t\t\tMenu de Terminales" << endl;
        cout << "\t\t\t----------------" << endl;
        //cout << "========================================" << endl;
        cout << "\n\t1. Ver todas las terminales" << endl;
        cout << "\t2. Buscar terminal " << endl;
        cout << "\t3. Eliminar terminal" << endl;
        cout << "\t4. Insertar una nueva terminal" << endl;
        cout << "\t5. Volver al menu anterior" << endl;
        cout << "\t6. Salir" << endl;
        cout << "========================================" << endl;
        cout << "\n\tIngrese una opcion: " ;
        cin >> op;
        switch (op) {
            case 1:
                cout << "\tTerminales encontradas" << endl;
                cout << "-----------------------" << endl;
                terminales.mostrarTodasLasTerminales();
                cout << "-----------------------" << endl;
                break;
            case 2:
                cout << "\tIngresa el codigo de la terminal" << endl;
                cin >> terminal;
                terminales.buscarTerminal(terminal);
                if (terminal == "0")
                    cout <<"\tNo se encontro terminal con ese codigo \n" << terminal << endl;
                cout << "______________________________" << endl;
                cout << "\tTerminales encontradas" << endl;
                break;
            case 3:
                cout << "\tEliminar una Terminal" << endl;
                cout << "\tIngrese el codigo de la terminal a eliminar: " << endl;
                cin >> terminal;
                terminales.eliminarTerminal(terminal);
                cout << "\tSe elimino la terminal con codigo: " << terminal << endl;
                if (terminal == "0")
                    cout <<"\tNo se encontro terminal con ese codigo " << terminal << endl;
                cout << "______________________________" << endl;
                break;
            case 4:
                cout << "\tIngrese el codigo de la terminal" << endl;
                cin >> codigo;
                nuevaTerminal.codigo = codigo;
                cout << "\tIngrese el nombre de la terminal" << endl;
                cin >> nombre;
                nuevaTerminal.nombre = nombre;
                cout << "\tIngrese la ciudad de la terminal" << endl;
                cin >> ciudad;
                nuevaTerminal.ciudad = ciudad;
                cout << "\tIngrese el pais de la terminal" << endl;
                cin >> pais;
                nuevaTerminal.pais = pais;
                cout << "\tIngrese la superficie de la terminal" << endl;
                cin >> superficie;
                nuevaTerminal.superficie = superficie;
                cout << "\tIngrese la cantidad de terminales de la terminal" << endl;
                cin >> cantidad_terminales;
                nuevaTerminal.cantidad_terminales = cantidad_terminales;
                cout << "\tIngrese la cantidad de destinos nacionales de la terminal" << endl;
                cin >> destinos_nacionales;
                nuevaTerminal.destinos_nacionales = destinos_nacionales;
                cout << "I\tngrese la cantidad de destinos internacionales de la terminal" << endl;
                cin >> destinos_internacionales;
                nuevaTerminal.destinos_internacionales = destinos_internacionales;

                // Inserta la nueva terminal en la tabla hash
                terminales.insertarTerminal(nuevaTerminal);
                cout << "\tTerminal Cargada con exito!!!" << endl;
                terminales.mostarTerminal(nuevaTerminal);
                cout << "______________________________" << endl;
                break;
            case 5:
                cout << "\tVolver al menu anterior" << endl;
                break;
            case 6:
                cout << "\tHasta luego!!!!!!!" << endl;
                //Exit
                exit(EXIT_SUCCESS);
            default:
                cout << "\tOpcion invalida" << endl;
                break;
        }
        cin.ignore();
        cout << "\tPresione enter para continuar" << endl;
        cin.get();
    } while (op != 5);
}