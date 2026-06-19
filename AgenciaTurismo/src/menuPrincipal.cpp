#include <iostream>
#include "menuPrincipal.h"
#include "menuGestionClientes.h"
#include "menuGestionPaquetes.h"
#include "menuGestionVentas.h"
#include "menuGestionHoteles.h"

using namespace std;

MenuPrincipal::MenuPrincipal() {}

void MenuPrincipal::mostrarOpciones() const {
    cout << "=========================================" << endl;
    cout << "        AGENCIA DE TURISMO - MENU         " << endl;
    cout << "=========================================" << endl;
    cout << "1. Clientes" << endl;
    cout << "2. Paquetes" << endl;
    cout << "3. Ventas" << endl;
    cout << "4. Hoteles" << endl;
    cout << "5. Vuelos" << endl;
    cout << "6. Traslados" << endl;
    cout << "7. Excursiones" << endl;
    cout << "0. Salir" << endl;
    cout << "=========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void MenuPrincipal::ejecutar() {
    int opcion;

    do {
        mostrarOpciones();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                MenuGestionClientes menuClientes;
                menuClientes.ejecutar();
                break;
            }
            case 2: {
                MenuGestionPaquetes menuPaquetes;
                menuPaquetes.ejecutar();
                break;
            }
            case 3: {
                MenuGestionVentas menuVentas;
                menuVentas.ejecutar();
                break;
            }
            case 4: {
                MenuGestionHoteles menuHoteles;
                menuHoteles.ejecutar();
                break;
            }
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion incorrecta. Intente nuevamente." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 0);
}
