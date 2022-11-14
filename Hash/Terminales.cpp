//
// Created by home on 13/11/22.
//

#include "Terminales.h"

/*
 * funcion para determinar el siguiente primo
 */


/*
 * funcion axuliar para determinar si un numero es primo
 */
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
    return suma;
}



TablaHashTerminales::TablaHashTerminales(int tamano) {
    tamano = tamano;
    terminalesTabla = new list<pair<int, Terminal> >[tamano];
}

bool TablaHashTerminales::estaVacia() {
    // recorre la tabla y si encuentra un elemento retorna false
    // Recorre la lista de pares de enteros y terminales
    int suma = 0;

    for (int i = 0; i < tamano; i++) {
            suma += terminalesTabla[i].size();  // se suma el tamaño de cada lista
    }
    if (!suma) {
        cout << "La tabla esta vacia" << endl;
        cout << tamano << endl;
        return true;
    }else
        return false;
    }

/*
 * Funcion para convertir un string en un entero
 * @param codigo string a convertir
 * @return entero
 */

void TablaHashTerminales::insertarTerminal(Terminal &terminal) {
    string codigoTerminal = terminal.codigo;

    int clave = funcionHashDividir(codigoTerminal);  // se calcula la clave
    terminalesTabla[clave].emplace_back(clave, terminal); // se inserta el par en la lista
    auto it = terminalesTabla[clave].begin();   // se crea un iterador para recorrer la lista

    for (; it != terminalesTabla[clave].end(); it++) {
        if (it->first == clave) {
            it->second = terminal;// se actualiza el valor del elemento
            break;
        }
    }
}

void TablaHashTerminales::buscarTerminal(string codigo) {
    Terminal terminal;
    terminal.codigo = codigo;
    int clave = sumarAscii(codigo);  // se calcula la clave
    auto it = terminalesTabla[clave].begin();   // se crea un iterador para recorrer la lista

    bool encontrado;
    for (; it != terminalesTabla[clave].end(); it++) {
        if (it->first == clave) {
            encontrado = true;
            cout << "Terminal encontrada " << endl;
            cout << "Codigo: " << it->second.codigo << endl;
            cout << "Nombre: " << it->second.nombre << endl;
            cout << "Superficie: " << it->second.superficie << endl;
            cout << "Cantidad de terminales: " << it->second.cantidad_terminales << endl;
            cout << "Destinos nacionales: " << it->second.destinos_nacionales << endl;
            cout << "Destinos internacionales: " << it->second.destinos_internacionales << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "La terminal no fue encontrada" << endl;
    }
}
 void TablaHashTerminales::imprimirTerminales() {
    for (int i = 0; i < tamano; i++) {
        if (terminalesTabla[i].empty())
            continue;
        auto it = terminalesTabla[i].begin();
        for (; it != terminalesTabla[i].end(); it++) {
            cout << " ---------------------------------------------------------" << endl;
            cout << "Clave: " << it->first << " Codigo: " << it->second.codigo << endl;
            cout << " - Nombre: " << it->second.nombre << endl;
            cout << " - Superficie: " << it->second.superficie << endl;
            cout << " - Cantidad de terminales: " << it->second.cantidad_terminales << endl;
            cout << " - Destinos nacionales: " << it->second.destinos_nacionales << endl;
            cout << " - Destinos internacionales: " << it->second.destinos_internacionales << endl;
            cout << endl;
        }
    }
}
 void TablaHashTerminales::eliminarTerminal(string codigo) {
    int clave = sumarAscii(codigo);  // se calcula la clave
    auto it = terminalesTabla[clave].begin();   // se crea un iterador para recorrer la lista

    bool encontrado;
    for (; it != terminalesTabla[clave].end(); it++) {
        if (it->first == clave) {
            encontrado = true;
            terminalesTabla[clave].erase(it);
            cout << "Elemento eliminado" << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "La terminal no fue encontrada" << endl;
    }
}

 int TablaHashTerminales::funcionHashDividir(string codigo) {
    int clave = sumarAscii(codigo);
    return clave + 1 ;
}

