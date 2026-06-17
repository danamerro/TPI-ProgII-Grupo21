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
    cout << "4. Mostrar venta por ID" << endl;
    cout << "5. Listar todas las ventas" << endl;
    cout << "6. Listar ventas pendientes" << endl;
    cout << "7. Listar ventas confirmadas" << endl;
    cout << "8. Listar ventas canceladas" << endl;
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
                cout << endl << "------ MOSTRAR VENTA POR ID ------" << endl;
                cout << "Ingrese el ID de la venta: ";
                cin >> idAux;
                archivo.mostrarVentaByID(idAux);
                break;

            case 5:
                cout << endl << "------ TODAS LAS VENTAS ------" << endl;
                archivo.listarVentas();
                break;

            case 6:
                cout << endl << "------ VENTAS PENDIENTES ------" << endl;
                archivo.listarTransaccionesPendientes();
                break;

            case 7:
                cout << endl << "------ VENTAS CONFIRMADAS ------" << endl;
                archivo.listarTransaccionesFinalizadas();
                break;

            case 8:
                cout << endl << "------ VENTAS CANCELADAS ------" << endl;
                archivo.listarTransaccionesCanceladas();
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
