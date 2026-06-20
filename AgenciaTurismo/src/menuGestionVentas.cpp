#include <iostream>
#include <cstring>
#include "menuGestionVentas.h"
#include "archivoGestionVenta.h"

using namespace std;

MenuGestionVentas::MenuGestionVentas() {}

void MenuGestionVentas::mostrarOpciones() const {
    cout << "=========================================" << endl;
    cout << "   -> GESTION DE VENTAS                  " << endl;
    cout << "=========================================" << endl;
    cout << "1. Gestion Venta" << endl;
    cout << "2. Listados" << endl;
    cout << "3. Consultas" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "=========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void MenuGestionVentas::ejecutar() {
    int opcion;

    do {
        mostrarOpciones();
        cin >> opcion;

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

void MenuGestionVentas::subMenuGestion() {
    int subOpcion;
    int idAux;
    ArchivoGestionVenta archivo;

    do {
        cout << "-----------------------------------------" << endl;
        cout << "   --> GESTION DE VENTA                  " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Agregar venta" << endl;
        cout << "2. Confirmar venta" << endl;
        cout << "3. Cancelar venta" << endl;
        cout << "0. Volver al menu de ventas" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
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
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
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
    char fecha[11];
    ArchivoGestionVenta archivo;

    do {
        cout << "-----------------------------------------" << endl;
        cout << "   --> CONSULTAS DE VENTAS               " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1.  Por ID" << endl;
        cout << "2.  Por ID de cliente" << endl;
        cout << "3.  Por ID de paquete" << endl;
        cout << "4.  Por Fecha de venta" << endl;
        cout << "0. Volver al menu de ventas" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << "Ingrese el ID de la venta: ";
                cin >> idAux;
                cout << "-----------------------------------------" << endl;
                archivo.mostrarVentaByID(idAux);
                cout << "-----------------------------------------" << endl;
                cout << "Proceso finalizado." << endl;
                cout << "Volviendo al subMenu Consultas..." << endl;
                break;
            case 2:
                cout << "Ingrese el ID del cliente (0 para volver): ";
                cin >> idAux;
                if (idAux == 0) {
                    break;
                }
                cout << endl;
                archivo.mostrarVentasByIdCliente(idAux);
                cout << "Proceso finalizado." << endl;
                cout << "Volviendo al subMenu Consultas..." << endl;
                break;
            case 3:
                cout << "Ingrese el ID del paquete (0 para volver): ";
                cin >> idAux;
                if (idAux == 0) {
                    break;
                }
                cout << endl;
                archivo.mostrarVentasByIdPaquete(idAux);
                cout << "Proceso finalizado." << endl;
                cout << "Volviendo al subMenu Consultas..." << endl;
                break;
            case 4:
                cin.ignore();
                cout << "Ingrese la fecha de venta (dd/mm/yyyy) (0 para volver): ";
                cin.getline(fecha, 11);
                if (strcmp(fecha, "0") == 0) {
                    break;
                }
                cout << endl;
                archivo.mostrarVentasByFechaVenta(fecha);
                cout << "Proceso finalizado." << endl;
                cout << "Volviendo al subMenu Consultas..." << endl;
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
