#include <iostream>
#include "menuPrincipal.h"
#include "helpers.h"
#include "menuGestionClientes.h"
#include "menuGestionPaquetes.h"
#include "menuGestionVentas.h"
#include "menuGestionHoteles.h"
#include "menuGestionVuelos.h"
#include "menuGestionTraslados.h"
#include "menuGestionExcursiones.h"
#include "menuInformes.h"

using namespace std;

MenuPrincipal::MenuPrincipal() {}

void MenuPrincipal::mostrarOpciones() const {
    string pad = obtenerPad(61);

    cout << pad << "=============================================================" << endl;
    cout << pad << "                  AGENCIA DE TURISMO - MENU                  " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               1. Clientes" << endl;
    cout << pad << "               2. Paquetes" << endl;
    cout << pad << "               3. Ventas" << endl;
    cout << pad << "               4. Hoteles" << endl;
    cout << pad << "               5. Vuelos" << endl;
    cout << pad << "               6. Traslados" << endl;
    cout << pad << "               7. Excursiones" << endl;
    cout << pad << "               8. Informes" << endl;
    cout << pad << "               0. Volver a inicio" << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               Seleccione una opcion: ";
}

void MenuPrincipal::procesarOpcion(int opcion) {
    system("cls");

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
        case 5: {
            MenuGestionVuelos menuVuelos;
            menuVuelos.ejecutar();
            break;
        }
        case 6: {
            MenuGestionTraslados menuTraslados;
            menuTraslados.ejecutar();
            break;
        }
        case 7: {
            MenuGestionExcursiones menuExcursiones;
            menuExcursiones.ejecutar();
            break;
        }
        case 8: {
            MenuInformes menuInformes;
            menuInformes.ejecutar();
            break;
        }
        default:
            cout << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
    }
}
