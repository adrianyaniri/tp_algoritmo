#include <iostream>
#include "Grafo/ViajeGrafo.h"


int main() {
  ViajeGrafo* grafo = new ViajeGrafo();

    grafo->insertarCuidad("Buenos Aires");
    grafo->insertarCuidad("Rosario");
    grafo->insertarCuidad("Cordoba");
    grafo->insertarCuidad("Mendoza");
    grafo->insertarCuidad("San Juan");

    grafo->insertarViaje("Buenos Aires", "Rosario", 100, 100);
    grafo->insertarViaje("Buenos Aires", "Cordoba", 100, 100);
    grafo->insertarViaje("Buenos Aires", "Mendoza", 100, 100);
    grafo->insertarViaje("Rosario", "Cordoba", 100, 100);
    grafo->insertarViaje("Rosario", "Mendoza", 100, 100);
    grafo->insertarViaje("Rosario", "Buenos Aires", 100, 100);
    grafo->insertarViaje("Cordoba", "Buenos Aires", 100, 100);


    grafo->insertarCuidad("Formosa");
    cout << grafo->obtenerTamanio();
    grafo->eliminarGrafo();

    return 0;
}
