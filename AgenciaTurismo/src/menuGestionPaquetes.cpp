#include <iostream>
#include "menuGestionPaquetes.h"

using namespace std;

MenuGestionPaquetes::MenuGestionPaquetes() {}

void MenuGestionPaquetes::mostrarOpciones() const {
    cout << "=========================================" << endl;
    cout << "   -> GESTIÓN DE PAQUETES TURÍSTICOS     " << endl;
    cout << "=========================================" << endl;
    cout << "1. Agregar paquete turístico" << endl;
    cout << "2. Modificar paquete turístico" << endl;
    cout << "3. Eliminar paquete turístico" << endl;
    cout << "4. Listar paquetes" << endl;
    cout << "5. Consultas" << endl;
    cout << "0. Volver al menú principal" << endl;
    cout << "=========================================" << endl;
    cout << "Seleccione una opción: ";
}

void MenuGestionPaquetes::procesarOpcion(int opcion) {
    int idAux;

    switch (opcion) {
        case 1:
            cout << endl << "----------- ALTA DE PAQUETE -------------" << endl << endl;
            _archivo.agregarPaquete();
            break;

        case 2:
            cout << endl << "----------- MODIFICAR PAQUETE -----------" << endl << endl;
            _archivo.modificarPaquete(0);
            break;

        case 3:
            cout << endl << "----------- ELIMINAR PAQUETE ------------" << endl << endl;
            cout << "Ingrese el ID del paquete a dar de baja: ";
            cin >> idAux;
            _archivo.eliminarPaquete(idAux);
            break;

        case 4:
            cout << endl << "------ LISTADO DE PAQUETES ------" << endl;
            _archivo.listarPaquetes();
            break;

        case 5:
            subMenuConsultasAvanzadas(); // Derivamos a nuestro submenú interno secundario
            break;

        default:
            cout << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
    }
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
