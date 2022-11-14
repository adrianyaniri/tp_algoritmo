#include <iostream>
#include "Grafo/ViajeGrafo.h"
#include "Hash/Terminales.h"


int main() {
    Terminal Ret = {"RETIRO", "Terminal Retiro Argentina", 100.10, 5, 100, 100};
    Terminal Eze = {"EZES", "Terminal Ezeiza Argentina", 100.10, 5, 100, 100};
    Terminal Mvd = {"MVD", "Terminal Montevideo Uruguay", 100.10, 5, 100, 100};
    Terminal Scl = {"SCL", "Terminal Santiago Chile", 100.10, 5, 100, 100};



 TablaHashTerminales terminales(50);
    terminales.insertarTerminal(Ret);
    terminales.insertarTerminal(Eze);
    terminales.insertarTerminal(Mvd);
    terminales.insertarTerminal(Scl);

    terminales.buscar("SCL");


    return 0;
}
