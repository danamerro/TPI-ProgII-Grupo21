#include <iostream>

using namespace std;

//#include "include/vuelo.h"
#include "include/archivoVuelo.h"
int main()
{
    //cout << "Hello world!" << endl;

    /*Vuelo vuelo;

    vuelo.cargarVuelo();
    cout << endl;
    cout << "----------DATOS DEL VUELO----------" << endl;
    vuelo.mostrarVuelo(); */

    ArchivoVuelo archivoVuelo;

    archivoVuelo.agregarVuelo();

    cout << endl;
    cout << "---------- LISTADO DE VUELOS ----------" << endl;
    archivoVuelo.listarVuelos();

    return 0;
}

