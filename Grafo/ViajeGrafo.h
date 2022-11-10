//
// Created by home on 9/11/22.
//

#ifndef ESTRUCTURASDATOS_VIAJEGRAFO_H
#define ESTRUCTURASDATOS_VIAJEGRAFO_H

#include "Vertice.h"
using namespace std;
#define MAX 100


int MatizAdyacencia[MAX][MAX];  // Matriz de adyacencia del grafo

class ViajeGrafo{

    Vertice *origen;
    int tamanio;

public:
    // Constructor
    ViajeGrafo();
    // Post: retorna true si el grafo está vacío, false en caso contrario
    bool estaVacio();

    // Post: retorna el número de vértices del grafo
    int obtenerTamanio();

    // Post: retorna el vértice con el nombre dado
    Vertice* obtenerVertice(string nombre);
    void insertarVertice(string nombre);

    // Post: Inserta una arista entre los vértices origen y destino
    void insertarArista(string origen,string destino, int precio, int distancia);

    //Post: Mostar lista de adyacencia
    void mostrarListaAdyacencia();

    //Post: Eliminar un vertice
    void eliminarVertice(string nombre);

    //Post: Eliminar una arista entre los vértices origen y destino
    void eliminarArista(string origen, string destino);

    //Post: Elimitar todos los vertices y aristas del grafo
    void eliminarGrafo();


};

#endif //ESTRUCTURASDATOS_VIAJEGRAFO_H
