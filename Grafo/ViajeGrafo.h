//
// Created by home on 9/11/22.
//

#ifndef ESTRUCTURASDATOS_VIAJEGRAFO_H
#define ESTRUCTURASDATOS_VIAJEGRAFO_H

#include "Vertice.h"
using namespace std;

class ViajeGrafo{

    Vertice *primero;
    int tamanio;

public:
    // Constructor
    ViajeGrafo();
    // Post: retorna true si el grafo está vacío, false en caso contrario
    bool estaVacio();

    // Post: retorna el número de vértices del grafo
    int obtenerTamanio();

    // Post: retorna el vértice con el nombre dado
    Vertice* obtenerNodo(string nombre);
    void insertarCuidad(string nombre);

    // Post: Inserta una arista entre los vértices primero y destino
    void insertarViaje(string origen, string destino, int precio, int distancia);

    //Post: Mostar lista de adyacencia
    void mostrarListaViajes();

    //Post: Eliminar un vertice
    void eliminarNodo(string nombre);

    //Post: Eliminar una arista entre los vértices primero y destino
    void eliminarConexion(string origen, string destino);

    //Post: Elimitar todos los vertices y aristas del grafo
    void eliminarGrafo();

    /*
     * Pre: El grafo debe estar cargado
     * Post: Elimina todas las conexiones del nodo
     * @arg nodo: nodo a eliminar
     */

    static void eliminarAristasVertice(Vertice *nodo);
    /*
     * Post: Elimina las aristas destino del vertice
     * Eliminta todas las conexiones del vertice con los demas vertices
     * @arg destino: vertice destino
     */
    void eliminarConexionesDestino(string destino);

};

#endif //ESTRUCTURASDATOS_VIAJEGRAFO_H
