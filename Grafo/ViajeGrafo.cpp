//
// Created by home on 9/11/22.
//

#include <iostream>
#include "ViajeGrafo.h"
using namespace std;

ViajeGrafo::ViajeGrafo() {
    origen = nullptr;
    tamanio = 0;
}

bool ViajeGrafo::estaVacio() {
    return origen == nullptr;
}

int ViajeGrafo::obtenerTamanio() {
   return tamanio;
}

Vertice *ViajeGrafo::obtenerVertice(string nombre) {
    Vertice *aux = origen;  // aux apunta al primer vértice

    while (aux != nullptr) {
        if (aux->nombre == nombre) {
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}

void ViajeGrafo::insertarVertice(string nombre) {
    if(obtenerVertice(nombre) == nullptr){
        Vertice *nuevo = new Vertice(nombre);
        if(estaVacio())
            origen = nuevo;
        else{
            Vertice *aux = origen;
            while(aux->sig != nullptr)
                aux = aux->sig;
            aux->sig = nuevo;
        }
        tamanio++;
    }
    cout << "El viaje ya esta cargado " << endl;
}

void ViajeGrafo::insertarArista(string origen, string destino, int precio, int distancia) {
    

}

void ViajeGrafo::eliminarVertice(std::string nombre) {

}

void ViajeGrafo::mostrarListaAdyacencia() {

}

void ViajeGrafo::eliminarArista(string origen, string destino) {

}

void ViajeGrafo::eliminarGrafo() {

}
