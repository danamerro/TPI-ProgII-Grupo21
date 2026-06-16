#include <iostream>
#include "menuGestionPaquetes.h"
#include "archivoPaquete.h"

using namespace std;

MenuGestionPaquetes::MenuGestionPaquetes() {}

void MenuGestionPaquetes::mostrarOpciones() const {
    cout << "=========================================" << endl;
    cout << "   -> GESTIÓN DE PAQUETES TURÍSTICOS     " << endl;
    cout << "=========================================" << endl;
    cout << "1. Agregar paquete turístico" << endl;
    cout << "2. Modificar paquete turístico" << endl;
    cout << "3. Eliminar paquete turístico" << endl;
    cout << "4. Listar todos los paquetes activos" << endl;
    cout << "5. Consultas y filtros avanzados" << endl;
    cout << "0. Volver al menú principal" << endl;
    cout << "=========================================" << endl;
    cout << "Seleccione una opción: ";
}

void MenuGestionPaquetes::ejecutar() {
    ArchivoPaquete archivo;
    int opcion;
    int idAux;

    do {
        mostrarOpciones();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << endl << "------- ALTA DE PAQUETE -------" << endl;
                archivo.agregarPaquete();
                break;

            case 2:
                cout << endl << "------ MODIFICAR PAQUETE ------" << endl;
                cout << "Ingrese el ID del paquete a modificar: ";
                cin >> idAux;
                archivo.modificarPaquete(idAux);
                break;

            case 3:
                cout << endl << "------ ELIMINAR PAQUETE ------" << endl;
                cout << "Ingrese el ID del paquete a dar de baja: ";
                cin >> idAux;
                archivo.eliminarPaquete(idAux);
                break;

            case 4:
                cout << endl << "------ LISTADO DE PAQUETES ------" << endl;
                archivo.listarPaquetes();
                break;

            case 5:
                subMenuConsultasAvanzadas();
                break;

            case 0:
                cout << "Regresando al menú general..." << endl;
                break;

            default:
                cout << "Opción incorrecta. Intente nuevamente." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 0);
}

void MenuGestionPaquetes::subMenuConsultasAvanzadas() {
    int subOpcion;
    int idAux;
    ArchivoPaquete archivo;

    do {
        cout << "-----------------------------------------" << endl;
        cout << "   --> CONSULTAS DE PAQUETES             " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Buscar paquete por ID" << endl;
        cout << "2. Listar paquetes cancelados" << endl;
        cout << "0. Volver al menú de paquetes" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opción: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << "Ingrese ID del paquete a consultar: ";
                cin >> idAux;
                archivo.mostrarPaqueteByID(idAux);
                break;
            case 2:
                cout << endl << "...falta agregar" << endl;
                break;
            case 0:
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}
