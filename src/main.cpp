#include <fstream>
#include "Hash/Terminales.h"
#include "Datos/Carga.h"

using namespace std;


int main() {

    TablaHashTerminales terminales(5000 );
    ViajeGrafo viajes;

    leerYCargarViajes(VIAJES, viajes);
    viajes.mostrarListaDestinos();

    viajes.Dijkstra("COR","RET");
    return 0;
}