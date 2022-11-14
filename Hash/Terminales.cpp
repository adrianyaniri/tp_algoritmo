//
// Created by home on 13/11/22.
//

#include "Terminales.h"


TablaHashTerminales::TablaHashTerminales(int tamano) {
    this->tamano = tamano;
    terminalesTabla = new list<pair<int, Terminal> >[tamano];
}


bool TablaHashTerminales::estaVacia() {
    // recorre la tabla y si encuentra un elemento retorna false
    // Recorre la lista de pares de enteros y terminales
    int suma = 0;

    for (int i = 0; i < tamano; i++) {
        suma += terminalesTabla[i].size();  // se suma el tamaño de cada lista
    }
    if (!suma)
        return true;
     else
        return false;
}


// Crear una función hash para la tabla hash
// Chequear la dispercion de los elementos
int TablaHashTerminales::funcionHash(string codigo) const {
    int suma = 0;
    for (int i = 0; i < codigo.length(); i++) {
        suma += codigo[i];
    }
    return suma % tamano;
}



void TablaHashTerminales::insertarTerminal(Terminal& terminal) {
    string codigoTerminal = terminal.codigo;

    int clave = funcionHash(codigoTerminal);  // se calcula la clave
    terminalesTabla[clave].emplace_back(clave, terminal); // se inserta el par en la lista
    auto it = terminalesTabla[clave].begin();   // se crea un iterador para recorrer la lista

    bool encontrado;
    for(; it != terminalesTabla[clave].end(); it++) {
        if (it->first == clave) {
            encontrado = true;
            it->second = terminal;  // se actualiza el valor del elemento
            cout << "Elemento actualizado" << endl;
            break;
        }
    }
}

void TablaHashTerminales::buscar(string codigo) {
    Terminal terminal;
    terminal.codigo = codigo;
    int clave = funcionHash(codigo);  // se calcula la clave
    auto it = terminalesTabla[clave].begin();   // se crea un iterador para recorrer la lista

    bool encontrado;
    for(; it != terminalesTabla[clave].end(); it++) {
        if (it->first == clave) {
            encontrado = true;
            cout << "Elemento encontrado" << endl;
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



void TablaHashTerminales::imprimir() {
    for (int i = 0; i < tamano; i++) {
        if (terminalesTabla[i].empty())
            continue;
        auto it = terminalesTabla[i].begin();
        for (; it != terminalesTabla[i].end(); it++) {
            cout << "Clave: " << it->first << " Valor: " << it->second.codigo << endl;
        }
    }
}

void TablaHashTerminales::eliminar(string codigo) {
    int clave = funcionHash(codigo);  // se calcula la clave
    auto it = terminalesTabla[clave].begin();   // se crea un iterador para recorrer la lista

    bool encontrado;
    for(; it != terminalesTabla[clave].end(); it++) {
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

void TablaHashTerminales::funcionHash2() {
    // Funcion hash para la tabla hash
    // Chequear la dispercion de los elementos
    int suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma += terminalesTabla[i].size();  // se suma el tamaño de cada lista
    }
    cout << "Suma: " << suma << endl;

}

