#include <iostream>
#include "Grafo/ViajeGrafo.h"


int main() {
  ViajeGrafo* grafo = new ViajeGrafo();

    grafo->insertarCuidad("Buenos Aires");
    grafo->insertarCuidad("Rosario");
    grafo->insertarCuidad("Cordoba");
    grafo->insertarCuidad("Mendoza");
    grafo->insertarCuidad("San Juan");


    grafo->insertarViaje("Buenos Aires", "Cordoba", 5, 100);
    grafo->insertarViaje("Buenos Aires", "Mendoza", 6, 100);
    grafo->insertarViaje("Rosario", "Cordoba", 2, 100);
    grafo->insertarViaje("Rosario", "Mendoza", 3, 100);
    grafo->insertarViaje("Rosario", "Buenos Aires", 10, 100);
    grafo->insertarViaje("Cordoba", "Buenos Aires", 20, 100);


   grafo->dijktra("Buenos Aires");

    return 0;
}
