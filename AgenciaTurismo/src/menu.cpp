#include <iostream>
#include "menu.h"

using namespace std;

Menu::Menu() {}
Menu::~Menu() {}

void Menu::ejecutar() {

    int opcion;
    do {
        mostrarOpciones();
        cin >> opcion;

        if (opcion == 0) {
            cout << "Saliendo del sistema..." << endl;
        } else {
            procesarOpcion(opcion);
        }
        cout << endl;
    } while (opcion != 0);
}
