#include <iostream>
#include "menuGestionVentas.h"
#include "archivoGestionVenta.h"

using namespace std;

MenuGestionVentas::MenuGestionVentas() {}

void MenuGestionVentas::mostrarOpciones() const {
    cout << "=========================================" << endl;
    cout << "   -> GESTION DE VENTAS                  " << endl;
    cout << "=========================================" << endl;
    cout << "1. Agregar venta" << endl;
    cout << "2. Confirmar venta" << endl;
    cout << "3. Cancelar venta" << endl;
    cout << "4. Listados" << endl;
    cout << "5. Consultas" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "=========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void MenuGestionVentas::ejecutar() {
    ArchivoGestionVenta archivo;
    int opcion;
    int idAux;

    do {
        mostrarOpciones();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << endl << "------- ALTA DE VENTA -------" << endl;
                archivo.agregarVenta();
                break;

            case 2:
                cout << endl << "------ CONFIRMAR VENTA ------" << endl;
                cout << "Ingrese el ID de la venta a confirmar: ";
                cin >> idAux;
                archivo.confirmarVenta(idAux);
                break;

            case 3:
                cout << endl << "------ CANCELAR VENTA ------" << endl;
                cout << "Ingrese el ID de la venta a cancelar: ";
                cin >> idAux;
                archivo.cancelarVenta(idAux);
                break;

            case 4:
                subMenuListados();
                break;

            case 5:
                subMenuConsultas();
                break;

            case 0:
                cout << "Regresando al menu principal..." << endl;
                break;

            default:
                cout << "Opcion incorrecta. Intente nuevamente." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 0);
}

void MenuGestionVentas::subMenuListados() {
    int subOpcion;
    ArchivoGestionVenta archivo;

    do {
        cout << "-----------------------------------------" << endl;
        cout << "   --> LISTADOS DE VENTAS                " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Listar todas las ventas" << endl;
        cout << "2. Listar ventas pendientes" << endl;
        cout << "3. Listar ventas confirmadas" << endl;
        cout << "4. Listar ventas canceladas" << endl;
        cout << "0. Volver al menu de ventas" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << endl << "------ TODAS LAS VENTAS ------" << endl;
                archivo.listarVentas();
                break;
            case 2:
                cout << endl << "------ VENTAS PENDIENTES ------" << endl;
                archivo.listarTransaccionesPendientes();
                break;
            case 3:
                cout << endl << "------ VENTAS CONFIRMADAS ------" << endl;
                archivo.listarTransaccionesFinalizadas();
                break;
            case 4:
                cout << endl << "------ VENTAS CANCELADAS ------" << endl;
                archivo.listarTransaccionesCanceladas();
                break;
            case 0:
                cout << "Regresando al menu de ventas..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}

void MenuGestionVentas::subMenuConsultas() {
    int subOpcion;
    int idAux;
    ArchivoGestionVenta archivo;

    do {
        cout << "-----------------------------------------" << endl;
        cout << "   --> CONSULTAS DE VENTAS               " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Buscar venta por ID" << endl;
        cout << "2. Buscar por ID de cliente" << endl;
        cout << "3. Buscar por ID de paquete" << endl;
        cout << "4. Buscar por fecha de venta" << endl;
        cout << "5. Buscar por fecha de viaje" << endl;
        cout << "0. Volver al menu de ventas" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << "Ingrese el ID de la venta: ";
                cin >> idAux;
                archivo.mostrarVentaByID(idAux);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                cout << endl << "...falta agregar" << endl;
                break;
            case 0:
                cout << "Regresando al menu de ventas..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}
