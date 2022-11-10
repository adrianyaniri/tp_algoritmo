cmake_minimum_required(VERSION 3.23)
project(estructurasDatos)

set(CMAKE_CXX_STANDARD 14)

add_executable(estructurasDatos main.cpp ListaEnlazada/Nodo.cpp ListaEnlazada/Nodo.h ListaEnlazada/Lista.cpp ListaEnlazada/Lista.h Grafo/ViajeGrafo.h Grafo/ViajeGrafo.cpp Grafo/Vertice.cpp Grafo/Vertice.h Grafo/Arista.cpp Grafo/Arista.h)
