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
    return suma * suma ;
}

// Funcion hash de colisiones Quadraticas probing
int funcionQuadraticas(string codigo, int i, int tamano){
    return (sumarAscii(codigo) + i + i*i) % tamano;
}

TablaHashTerminales::TablaHashTerminales(int tamano) {
   if(esPrimo(tamano))
       this->tamano = tamano;
   else
       this->tamano = siguientePrimo(tamano);

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
    int posicion = sumarAscii(codigoTerminal);

    //Si la posicion es mayor al tamaño de la tabla se le asigna el resto de la division
    if(posicion > tamano){
        posicion = posicion % tamano;
    }

    // si la posicion ya está ocupada le aplica la funcion de colision
    if(!terminalesTabla[posicion].empty()){
        int i = 1;
        while(!terminalesTabla[funcionQuadraticas(codigoTerminal, i, tamano)].empty()){
            i++;
        }
        posicion = funcionQuadraticas(codigoTerminal, i, tamano);
    }


    terminalesTabla[posicion].emplace_back(posicion, terminal);
}


//Funcion para buscar en la tabla hash un elmento
void TablaHashTerminales::buscar(string codigo) {
 Terminal terminal;
 codigo = terminal.codigo;
 int posicion = sumarAscii(codigo);

 // Buscar en la posicion de la tabla
  for( auto it = terminalesTabla[posicion].begin(); it != terminalesTabla[posicion].end(); it++){
      if(it->second.codigo == codigo){
          cout << "Codigo: " << it->second.codigo << endl;
          cout << "Nombre: " << it->second.nombre << endl;
          cout << "Superficie: " << it->second.superficie << endl;
          cout << "Cantidad de terminales: " << it->second.cantidad_terminales << endl;
          cout << "Destinos nacionales: " << it->second.destinos_nacionales << endl;
          cout << "Destinos internacionales: " << it->second.destinos_internacionales << endl;
      }
      cout << "No se encontro el elemento" << endl;
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
 void TablaHashTerminales::eliminar(string codigo) {

}


