#include <iostream>

using namespace std;

#include "include/vuelo.h"
int main()
{
    //cout << "Hello world!" << endl;

    Vuelo vuelo;

    vuelo.cargarVuelo();
    cout << endl;
    cout << "----------DATOS DEL VUELO----------" << endl;
    vuelo.mostrarVuelo();

    return 0;
}
