#include <iostream>
#include "ListaEnlazada/Nodo.h"
#include "ListaEnlazada/Lista.h"

int main() {
    Dato viaje1 = {1, "Buenos Aires", "Cordoba", 3, 1000};
    Dato viaje2 = {2, "Buenos Aires", "Rosario", 2, 500};
    Dato viaje3 = {3, "Buenos Aires", "Mendoza", 4, 2000};
    Dato viaje4 = {4, "Buenos Aires", "Mar del Plata", 5, 3000};

    Lista *viajes = new Lista();

    viajes->insertar(viaje4);
    viajes->insertar(viaje1);
    viajes->insertar(viaje2);
    viajes->insertar(viaje3);

    viajes->imprimirListaCompleta();

    std::cout << "Tamanio de la lista: " << viajes->tamanio << std::endl;

   viajes->estaVacia();


   return 0;
}
