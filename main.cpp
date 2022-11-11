#include <iostream>
#include "Grafo/ViajeGrafo.h"


int main() {
  ViajeGrafo* grafo = new ViajeGrafo();

    grafo->insertarNodo("Buenos Aires");
    grafo->insertarNodo("Rosario");
    grafo->insertarNodo("Cordoba");
    grafo->insertarNodo("Mendoza");
    grafo->insertarNodo("San Juan");

    grafo->insertarConexion("Buenos Aires", "Rosario", 100, 100);
    grafo->insertarConexion("Buenos Aires", "Cordoba", 100, 100);
    grafo->insertarConexion("Buenos Aires", "Mendoza", 100, 100);
    grafo->insertarConexion("Rosario", "Cordoba", 100, 100);
    grafo->insertarConexion("Rosario", "Mendoza", 100, 100);
    grafo->insertarConexion("Rosario", "Buenos Aires", 100, 100);
    grafo->insertarConexion("Cordoba", "Buenos Aires", 100, 100);


    grafo->mostrarListaConexiones();

    grafo->eliminarConexion("Buenos Aires", "Rosario");
    cout << endl;
    cout<< "__________________________________"<<endl;

    grafo->mostrarListaConexiones();


  // este menu es para probar el grafo
  // se puede borrar
  // hay que implementar el menu de la consigna

  /*  while (opc != 8){

        cout << "1. Cargar un nuevo viaje" << endl;
        cout << "2. Insertar destino" << endl;
        cout << "3. Obtener tamaño" << endl;
        cout << "4. Eliminar viaje" << endl;
        cout << "5. Eliminar destino" << endl;
        cout << "6. Mostrar destinos" << endl;
        cout << "7. Eliminar todo" << endl;
        cout << "8. Salir" << endl;

        cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1: {
                string nombre;
                cout << "Ingrese el nombre del viaje: ";
                cin >> nombre;
                grafo->insertarNodo(nombre);
                break;
            }
            case 2:{
                if(grafo->estaVacio()){
                    cout << "No hay viajes cargados" << endl;
                }
                string origen, destino;
                int precio, distancia;
                cout << "Ingrese el origen: ";
                cin >> origen;
                cout << "Ingrese el destino: ";
                cin >> destino;
                cout << "Ingrese el precio: ";
                cin >> precio;
                cout << "Ingrese la distancia: ";
                cin >> distancia;

                grafo->insertarConexion(origen, destino, precio, distancia);
                break;
            }
            case 3:{
                int tamaño = grafo->obtenerTamanio();
                cout << "El tamaño es: " << tamaño << " destinos" <<endl;
                break;
            }
            case 4:{
                if(grafo->estaVacio()){
                    cout << "No hay viajes cargados" << endl;
                }
               grafo->mostrarListaAdyacencia();
                break;
            }
            case 5:{
                if(grafo->estaVacio()){
                    cout << "No hay viajes cargados" << endl;
                }
                string nombre;
                cout << "Ingrese el nombre del viaje: ";
                cin >> nombre;
                grafo->eliminarNodo(nombre);
                break;
            }
            case 6:{
                if(grafo->estaVacio()){
                    cout << "No hay viajes cargados" << endl;
                }
                grafo->mostrarListaConexiones();
                break;
            }
            case 7:{
                if (grafo->estaVacio()){
                    cout << "No hay viajes cargados" << endl;
                }
                grafo->eliminarGrafo();
                break;
            }
        }
        cin.get();
        cin.get();
    }*/
}
