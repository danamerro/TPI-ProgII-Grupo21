#include <iostream>
#include <cstring>
#include "menuGestionVentas.h"
#include "archivoGestionVenta.h"
#include "helpers.h"

using namespace std;

MenuGestionVentas::MenuGestionVentas() {}

void MenuGestionVentas::mostrarOpciones() const {
    string pad = obtenerPad(61);

    cout << pad << "=============================================================" << endl;
    cout << pad << "                     -> MENU DE VENTAS                       " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               1. Gestion Venta" << endl;
    cout << pad << "               2. Listados" << endl;
    cout << pad << "               3. Consultas" << endl;
    cout << pad << "               0. Volver al menu principal" << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               Seleccione una opcion: ";
}

void MenuGestionVentas::procesarOpcion(int opcion) {
    string pad = obtenerPad(61);

    switch (opcion) {
        case 1:
            subMenuGestion();
            break;
        case 2:
            subMenuListados();
            break;
        case 3:
            subMenuConsultas();
            break;
        default:
            cout << endl << pad << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
    }
}

void MenuGestionVentas::subMenuGestion() {
    string pad = obtenerPad(61);
    int subOpcion;
    int idAux;

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                   -> GESTION DE VENTA                       " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Agregar venta" << endl;
                cout << pad << "               2. Confirmar venta" << endl;
                cout << pad << "               3. Cancelar venta" << endl;
                cout << pad << "               0. Volver al menu de ventas" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "--------------------- ALTA DE VENTA -------------------------" << endl;
                _archivo.agregarVenta();
                break;
            case 2:
                cout << endl << pad << "-------------------- CONFIRMAR VENTA ------------------------" << endl;
                cout << endl << pad << "Ingrese el ID de la venta a confirmar: ";
                cin >> idAux;
                _archivo.confirmarVenta(idAux);
                break;
            case 3:
                cout << endl << pad << "-------------------- CANCELAR VENTA -------------------------" << endl;
                cout << endl << pad << "Ingrese el ID de la venta a cancelar: ";
                cin >> idAux;
                _archivo.cancelarVenta(idAux);
                break;
            case 0:
                break;
            default:
                cout << endl << pad << "Opcion invalida." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}

void MenuGestionVentas::subMenuListados() {
    string pad = obtenerPad(61);
    int subOpcion;

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> LISTADOS                             " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Listar todas las ventas" << endl;
                cout << pad << "               2. Listar ventas pendientes" << endl;
                cout << pad << "               3. Listar ventas confirmadas" << endl;
                cout << pad << "               4. Listar ventas canceladas" << endl;
                cout << pad << "               0. Volver al menu de ventas" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "-------------------- TODAS LAS VENTAS -----------------------" << endl;
                _archivo.listarVentas();
                break;
            case 2:
                cout << endl << pad << "-------------------- VENTAS PENDIENTES ----------------------" << endl;
                _archivo.listarTransaccionesPendientes();
                break;
            case 3:
                cout << endl << pad << "------------------- VENTAS CONFIRMADAS ----------------------" << endl;
                _archivo.listarTransaccionesFinalizadas();
                break;
            case 4:
                cout << endl << pad << "-------------------- VENTAS CANCELADAS ----------------------" << endl;
                _archivo.listarTransaccionesCanceladas();
                break;
            case 0:
                break;
            default:
                cout << endl << pad << "Opcion invalida." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}

void MenuGestionVentas::subMenuConsultas() {
    string pad = obtenerPad(61);
    int subOpcion;
    int idAux;
    char fecha[11];

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> CONSULTAS                            " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Por ID de venta" << endl;
                cout << pad << "               2. Por ID de cliente" << endl;
                cout << pad << "               3. Por ID de paquete" << endl;
                cout << pad << "               4. Por Fecha de venta" << endl;
                cout << pad << "               0. Volver al menu de ventas" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "          Ingrese el ID de la venta: ";
                cin >> idAux;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarVentaByID(idAux);
                break;
            case 2:
                cout << endl << pad << "          Ingrese el ID del cliente (0 para volver): ";
                cin >> idAux;
                if (idAux == 0) {
                    break;
                }
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarVentasByIdCliente(idAux);
                break;
            case 3:
                cout << endl << pad << "          Ingrese el ID del paquete (0 para volver): ";
                cin >> idAux;
                if (idAux == 0) {
                    break;
                }
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarVentasByIdPaquete(idAux);
                break;
            case 4:
                cin.ignore();
                cout << endl << pad << "          Ingrese la fecha de venta (dd/mm/yyyy) (0 para volver): ";
                cin.getline(fecha, 11);
                if (strcmp(fecha, "0") == 0) {
                    break;
                }
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarVentasByFechaVenta(fecha);
                break;
            case 0:
                break;
            default:
                cout << endl << pad << "Opcion invalida." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}
