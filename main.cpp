
#include "Hash/Terminales.h"


int main() {

    list<Terminal> lista;

    Terminal Ret = {"RE", "Terminal Retiro Argentina", 100.10, 5, 100, 100};
    Terminal Eze = {"EZ", "Terminal Ezeiza Argentina", 100.10, 5, 100, 100};
    Terminal Mvd = {"MVD", "Terminal Montevideo Uruguay", 100.10, 5, 100, 100};
    Terminal Scl = {"SCL", "Terminal Santiago Chile", 100.10, 5, 100, 100};
    Terminal Ret2 = {"ER", "Terminal Retiro Argentina", 100.10, 5, 100, 100};
    Terminal Fco = {"FCO", "Terminal Fco Argentina", 100.10, 5, 100, 100};


    TablaHashTerminales terminales(10000);

    terminales.insertarTerminal(Ret);
    terminales.insertarTerminal(Eze);
    terminales.insertarTerminal(Mvd);
    terminales.insertarTerminal(Scl);

    terminales.imprimirTerminales();


    return 0;
}
