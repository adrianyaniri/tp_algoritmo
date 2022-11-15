#include "Hash/Terminales.h"


int main() {

    list<Terminal> lista;
    TablaHashTerminales terminales(5000 );

    Terminal Ret = {"RE", "Terminal Retiro Argentina", 100.10, 5, 100, 100};
    Terminal Eze = {"EZ", "Terminal Ezeiza Argentina", 100.10, 5, 100, 100};
    Terminal Mvd = {"MVD", "Terminal Montevideo Uruguay", 100.10, 5, 100, 100};
    Terminal Scl = {"SCL", "Terminal Santiago Chile", 100.10, 5, 100, 100};
    Terminal Fco = {"FCO", "Terminal Fco Argentina", 100.10, 5, 100, 100};
    Terminal Bue = {"BUE", "Terminal Bue Argentina", 100.10, 5, 100, 100};
    Terminal Re = {"ER", "Terminal Mza Argentina", 100.10, 5, 100, 100};

    terminales.insertarTerminal(Ret);
    terminales.insertarTerminal(Eze);
    terminales.insertarTerminal(Mvd);
    terminales.insertarTerminal(Scl);
    terminales.insertarTerminal(Fco);
    terminales.insertarTerminal(Bue);



    cout << "Tabla Hash Terminales" << endl;
    terminales.imprimeTabla();
    cout << "_________"<< endl;
    terminales.buscarTerminal("RE");
    cout << "_________"<< endl;
    terminales.eliminarTerminal("RE");
    cout << "_________"<< endl;
    cout << "Tabla Hash Terminales despues de eliminar" << endl;
    terminales.buscarTerminal("RE");


    return 0;
}