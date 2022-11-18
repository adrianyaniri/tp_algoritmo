//
// Created by home on 13/11/22.
//

#include "Terminales.h"
#include "../FuncionesAux/funcionesAux.h"

const double FCARGA = 0.8;  // Factor de carga


TablaHashTerminales::TablaHashTerminales(int keys) {
    /*
     * Constructor de la clase TablaHashTerminales
     * @param keys: cantidad de claves a guardar
     * divido el total de claves por el factor de carga
     * y obtengo el tamaño de la tabla
     */
    int key = double(keys) / FCARGA;
    // Si el numero no es primo, se busca el siguiente primo
    if(esPrimo(key))
        tamano = key;
    else
        tamano = siguientePrimo(key);

    terminalesTabla = new list<pair<int, Terminal> >[tamano];
}

bool TablaHashTerminales::estaVacia() {
    /*
     * Verifica si la tabla esta vacia
     * @return: true si esta vacia, false si no
     */
    for(int i = 0; i < tamano; i++){
        if(!terminalesTabla[i].empty())
            return false;
    }
    return true;
}

void TablaHashTerminales::insertarTerminal(Terminal terminal) {
    /*
     * Inserta un elemento en la tabla
     * @param terminal: elemento a insertar
     */
    string codigo = terminal.codigo;    // Codigo de la terminal
    int key = funcionHash(codigo);      // posicion en la tabla hash donde se insertara - se usa la funcion hash


    if(!terminalesTabla[key].empty()) {  // Si la posicion no esta vacia, se busca la siguiente posicion libre
        while (!terminalesTabla[key].empty())
            key = funcionQuadraticas(codigo, key, tamano);  // Se usa la funcion quadraticas para colisiones
        terminalesTabla[key].emplace_back(key, terminal);
    }
}

void TablaHashTerminales::mostrarTodasLasTerminales() {
    /*
     * Imprime la tabla
     */
    for(int i = 0; i < tamano; i++){
        if(!terminalesTabla[i].empty()){
            cout << "Posicion: " << i << endl;
            for(auto it = terminalesTabla[i].begin(); it != terminalesTabla[i].end(); it++){
                cout << "Codigo: " << it->second.codigo << endl;
                cout << "Nombre: " << it->second.nombre << endl;
                cout << "Ciudad: " << it->second.ciudad << endl;
                cout << "Pais: " << it->second.pais << endl;
                cout << "Superficie: " << it->second.superficie << endl;
                cout << "Cantidad Terminales " << it->second.cantidad_terminales << endl;
                cout << "Destinos Nacionales: " << it->second.destinos_nacionales << endl;
                cout << "Destinos internacionales: " << it->second.destinos_internacionales << endl;
                cout << endl;
            }
        }
    }
}

void TablaHashTerminales::buscarTerminal(string codigo) {
    Terminal terminal;
    int key = funcionHash(codigo);
    key = funcionQuadraticas(codigo, key, tamano);
   if(!terminalesTabla[key].empty()){
         for(auto it = terminalesTabla[key].begin(); it != terminalesTabla[key].end(); it++){
             cout << "Posicion: " << key << endl;
              if(it->second.codigo == codigo){
                terminal = it->second;
                cout << "Codigo: " << terminal.codigo << endl;
                cout << "Nombre: " << terminal.nombre << endl;
                cout << "Ciudad: " << terminal.ciudad << endl;
                cout << "Pais: " << terminal.pais << endl;
                cout << "Superficie: " << terminal.superficie << endl;
                cout << "Cantidad Terminales " << terminal.cantidad_terminales << endl;
                cout << "Destinos Nacionales: " << terminal.destinos_nacionales << endl;
                cout << "Destinos internacionales: " << terminal.destinos_internacionales << endl;
                cout << endl;
              }
             break;
         }
   }
   else{
       cout << "No se encontro la terminal: "<< codigo << endl;
   }
}

/*
 * Elimina una terminal de la tabla
 * @param codigo: codigo de la terminal a eliminar
 */
void TablaHashTerminales::eliminarTerminal(string codigo) {
int key = funcionHash(codigo);
    key = funcionQuadraticas(codigo, key, tamano);
    // Si la posicion no esta vacia, se busca la siguiente posicion libre
    if(!terminalesTabla[key].empty()){
        // Se busca la terminal a eliminar
        for(auto it = terminalesTabla[key].begin(); it != terminalesTabla[key].end(); it++){
            if(it->second.codigo == codigo){
                terminalesTabla[key].erase(it);
                cout << "Terminal eliminada: "<< it->second.codigo << endl;
                break;
            }
        }
    }
    else{
        cout << "No se encontro la terminal: "<< codigo << endl;
    }
}
/*
 * Muestra un terminal
 * @param terminal: terminal a mostrar
 */
void TablaHashTerminales::mostarTerminal(Terminal terminal) {
    this->buscarTerminal(terminal.codigo);

}
