//
// Created by home on 14/11/22.
//

#include <iostream>
#include "funcionesAux.h"

using namespace std;



bool esPrimo(int numero){
    // Casos especiales
    if(numero == 0 || numero == 1 || numero == 4) return false;
    for(int x = 2; x < numero / 2; x++)
    {
        if(numero % x == 0)
            return false;
    }
    return true;
}

int siguientePrimo(int numero){
    int primo = numero;
    bool encontrado = false;
    while(!encontrado){
        primo++;
        if(esPrimo(primo)){
            encontrado = true;
        }
    }
    return primo;
}

// Sumar los valores ASCII de los caracteres de la clave
int sumarAscii(string cadena){
    int suma = 0;
    for(int i = 0; i < cadena.length(); i++){
        suma += cadena[i];
    }
    return suma * 128;
}

// Funcion hash de colisiones Quadraticas probing
int funcionQuadraticas(string codigo, int i, int tamano){
    int key = sumarAscii(codigo);
    return (key + i + i*i) % tamano;
}

int funcionHash(string codigo){
   int key = sumarAscii(codigo);
   return key ;
}
