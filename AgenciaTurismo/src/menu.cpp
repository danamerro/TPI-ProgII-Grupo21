#include <iostream>
#include <windows.h>
#include "menu.h"
#include "helpers.h"

using namespace std;

Menu::Menu() {}
Menu::~Menu() {}

void Menu::ejecutar() {
    string pad = obtenerPad(61);

    system("cls");
    int opcion;
    do {
        mostrarOpciones();
        cin >> opcion;

        if (opcion == 0) {
            system("cls");
        } else {
            procesarOpcion(opcion);
        }
        cout << endl;
    } while (opcion != 0);
}
