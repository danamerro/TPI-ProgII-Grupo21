#include <iostream>
#include "menuInformes.h"
#include "helpers.h"

using namespace std;

MenuInformes::MenuInformes() {}

void MenuInformes::mostrarOpciones() const {
    string pad = obtenerPad(61);

    cout << pad << "=============================================================" << endl;
    cout << pad << "                     -> PANEL DE INFORMES                    " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "         1. Clientes con paquetes confirmados" << endl;
    cout << pad << "         2. Clientes con paquetes pendientes" << endl;
    cout << pad << "         3. Clientes con paquetes cancelados" << endl;
    cout << pad << "         4. Recaudacion de acuerdo al destino" << endl;
    cout << pad << "         5. Ventas record de destino por mes" << endl;
    cout << pad << "         0. Volver al menu principal" << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "         Seleccione una opcion: ";
}

void MenuInformes::procesarOpcion(int opcion) {
    string pad = obtenerPad(61);
    char destino[100];
    system("cls");

    switch (opcion) {
        case 1:
            cout << endl << pad << "--------- CLIENTES CON RESERVAS CONFIRMADAS ---------" << endl;
            _logicaInformes.clientesPorEstadoVenta(1);
            break;
        case 2:
            cout << endl << pad << "--------- CLIENTES CON RESERVAS PENDIENTES ---------" << endl;
            _logicaInformes.clientesPorEstadoVenta(0);
            break;
        case 3:
            cout << endl << pad << "--------- CLIENTES CON RESERVAS CANCELADAS ---------" << endl;
            _logicaInformes.clientesPorEstadoVenta(2);
            break;
        case 4: {
            cin.ignore();
            cout << endl << pad << "Ingrese el destino a consultar: ";
            cin.getline(destino, 100);
            _logicaInformes.recaudacionPorDestino(destino);
            break;
        }
        case 5:
            cin.ignore();
            cout << endl << pad << "------------ DESTINOS RECORD POR MES ------------" << endl;
            _logicaInformes.recordDestinoPorMes();
            break;
        case 0:
            break;
        default:
            cout << endl << pad << "Opcion incorrecta. Intente nuevamente." << endl;
            cin.ignore();
            limpiarPantalla();
            break;
    }
}

