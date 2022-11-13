#include <iostream>
#include "Grafo/ViajeGrafo.h"


int main() {
  ViajeGrafo* grafo = new ViajeGrafo();

    grafo->insertarCuidad("BSAS");
    grafo->insertarCuidad("RO");
    grafo->insertarCuidad("COR");
    grafo->insertarCuidad("MEZ");
    grafo->insertarCuidad("SAL");

    grafo->insertarViaje("BSAS", "RO", 25, 100);
    grafo->insertarViaje("BSAS", "COR", 2, 200);
    grafo->insertarViaje("BSAS", "MEZ", 5000, 300);
    grafo->insertarViaje("BSAS", "SAL", 15, 400);
    grafo->insertarViaje("RO", "BSAS", 50, 500);
    grafo->insertarViaje("SAL", "RO", 300, 600);
    grafo->insertarViaje("COR", "MEZ", 3, 700);
    grafo->insertarViaje("MEZ", "BSAS", 4, 800);


    grafo->Dijkstra("BSAS", "MEZ");


    return 0;
}
