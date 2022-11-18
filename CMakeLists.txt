cmake_minimum_required(VERSION 3.23)
project(estructurasDatos)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        estructurasDatos src/main.cpp
        src/ListaEnlazada/Nodo.cpp
        src/ListaEnlazada/Nodo.h
        src/ListaEnlazada/Lista.cpp
        src/ListaEnlazada/Lista.h
        src/Grafo/ViajeGrafo.h
        src/Grafo/ViajeGrafo.cpp
        src/Grafo/NodoGrafo.cpp
        src/Grafo/NodoGrafo.h
        src/Grafo/Arista.cpp
        src/Grafo/Arista.h
        src/Hash/Terminales.cpp
        src/Hash/Terminales.h
        src/Menu/Menu.cpp
        src/Menu/Menu.h src/FuncionesAux/funcionesAux.cpp src/FuncionesAux/funcionesAux.h src/Datos/Carga.cpp src/Datos/Carga.h src/Menu/Menu.cpp src/Menu/Menu.h src/Constantes/Constates.h)
