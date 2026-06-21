#include <iostream>
#include "menuGestionExcursiones.h"

using namespace std;

MenuGestionExcursiones::MenuGestionExcursiones() {}

void MenuGestionExcursiones::mostrarOpciones() const {
    cout << "=========================================" << endl;
    cout << "   -> GESTION DE EXCURSIONES             " << endl;
    cout << "=========================================" << endl;
    cout << "1. Agregar una Excursion" << endl;
    cout << "2. Modificar una Excursion" << endl;
    cout << "3. Eliminar una Excursion" << endl;
    cout << "4. Consultas" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "=========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void MenuGestionExcursiones::procesarOpcion(int opcion) {
    int idAux;

    switch (opcion) {
        case 1:
            cout << endl << "------- ALTA DE EXCURSION -------" << endl;
            _archivo.agregarExcursion();
            break;

        case 2:
            cout << "------ EXCURSIONES REGISTRADAS ------ " << endl << endl;
            _archivo.listarExcursiones();
            cout << "Ingrese el ID de la excursion a modificar: ";
            cin >> idAux;
            cin.ignore();
            _archivo.modificarExcursion(idAux);
            break;

        case 3:
            cout << endl << "------ EXCURSIONES REGISTRADAS ------" << endl << endl;
            _archivo.listarExcursiones();
            cout << "Ingrese el ID de la excursion a dar de baja: ";
            cin >> idAux;
            cin.ignore();
            _archivo.eliminarExcursion(idAux);
            break;

        case 4:
            subMenuConsultas();
            break;

        default:
            cout << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
    }
}

void MenuGestionExcursiones::subMenuConsultas() {
    int subOpcion;

    do {
        cout << "-----------------------------------------" << endl;
        cout << "   --> CONSULTAS DE EXCURSIONES          " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Listar todas las excursiones activas" << endl;
        cout << "0. Volver al menu de excursiones" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opcion: ";
        cin >> subOpcion;
        cin.ignore();

        switch (subOpcion) {
            case 1:
                cout << endl << "------ TODAS LAS EXCURSIONES ACTIVAS ------" << endl;
                _archivo.listarExcursiones();
                break;

            case 0:
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}
