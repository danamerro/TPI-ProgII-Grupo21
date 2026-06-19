#include <iostream>
#include "menuGestionTraslados.h"

using namespace std;

MenuGestionTraslados::MenuGestionTraslados() {}

void MenuGestionTraslados::mostrarOpciones() const {
    cout << "=========================================" << endl;
    cout << "   -> GESTION DE TRASLADOS               " << endl;
    cout << "=========================================" << endl;
    cout << "1. Agregar un Traslado" << endl;
    cout << "2. Modificar un Traslado" << endl;
    cout << "3. Eliminar un Traslado" << endl;
    cout << "4. Consultas" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "=========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void MenuGestionTraslados::procesarOpcion(int opcion) {
    int idAux;

    switch (opcion) {
        case 1:
            cout << endl << "------- ALTA DE TRASLADO -------" << endl;
            _archivo.agregarTraslado();
            break;

        case 2:
            cout << "------ TRASLADOS REGISTRADOS ------ " << endl << endl;
            _archivo.listarTraslados();
            cout << "Ingrese el ID del traslado a modificar: ";
            cin >> idAux;
            cin.ignore();
            _archivo.modificarTraslado(idAux);
            break;

        case 3:
            cout << endl << "------ TRASLADOS REGISTRADOS ------" << endl << endl;
            _archivo.listarTraslados();
            cout << "Ingrese el ID del traslado a dar de baja: ";
            cin >> idAux;
            cin.ignore();
            _archivo.eliminarTraslado(idAux);
            break;

        case 4:
            subMenuConsultas();
            break;

        default:
            cout << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
    }
}

void MenuGestionTraslados::subMenuConsultas() {
    int subOpcion;

    do {
        cout << "-----------------------------------------" << endl;
        cout << "   --> CONSULTAS DE TRASLADOS            " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Listar todos los traslados activos" << endl;
        cout << "0. Volver al menu de traslados" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opcion: ";
        cin >> subOpcion;
        cin.ignore();

        switch (subOpcion) {
            case 1:
                cout << endl << "------ TODOS LOS TRASLADOS ACTIVOS ------" << endl;
                _archivo.listarTraslados();
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
