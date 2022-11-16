#include <fstream>
#include "Hash/Terminales.h"
#include "Datos/LeerTxt.h"
using namespace std;


int main() {

    list<Terminal> lista;
    TablaHashTerminales terminales(5000 );


    leer(TERMINALES, terminales);
    terminales.imprimeTabla();





    return 0;
}