//
// Created by home on 9/11/22.
//

#ifndef ESTRUCTURASDATOS_VIAJEGRAFO_H
#define ESTRUCTURASDATOS_VIAJEGRAFO_H

#include "NodoGrafo.h"
using namespace std;

class ViajeGrafo {

    NodoGrafo *primero;
    int tamanio;

public:
    // Constructor
    ViajeGrafo();

    // Post: retorna true si el grafo está vacío, false en caso contrario
    bool estaVacio();

    // Post: retorna el número de vértices del grafo
    int obtenerTamanio() const;

    // Post: retorna el vértice con el nombre dado
    NodoGrafo *obtenerCiudad(const string &nombre);

    void insertarCuidad(const string &nombre);

    // Post: Inserta una arista entre los vértices primero y destino
    void insertarViaje(const string &origen, const string &destino, int precio, int distancia);

    //Post: Mostar lista de adyacencia
    void mostrarListaDestinos();

    //Post: Eliminar un vertice
    void eliminarCiudad(const string &nombre);

    //Post: Eliminar una arista entre los vértices primero y destino
    void eliminarConexion(const string &origen, const string &destino);

    //Post: Elimitar todos los vertices y aristas del grafo
    void eliminarGrafo();

    /*
     * Pre: El grafo debe estar cargado
     * Post: Elimina todas las conexiones de la ciudad
     * @arg ciudad: ciudad a eliminar
     */

    static void eliminarConexionesCiudad(NodoGrafo *ciudad);

    /*
     * Post: Elimina las aristas destino del vertice
     * Eliminta todas las conexiones del vertice con los demás vertices
     * @arg destino: vertice destino
     */
    void eliminarConexionesDestino(const string &destino);

    void Dijkstra(const string& origen, const string& destino);
};


#endif //ESTRUCTURASDATOS_VIAJEGRAFO_H
