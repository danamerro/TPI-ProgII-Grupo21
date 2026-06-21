#include <iostream>
#include "menuGestionExcursiones.h"
#include "helpers.h"

using namespace std;

MenuGestionExcursiones::MenuGestionExcursiones() {}

void MenuGestionExcursiones::mostrarOpciones() const {
    string pad = obtenerPad(61);

    cout << pad << "=============================================================" << endl;
    cout << pad << "               -> GESTION DE EXCURSIONES                     " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               1. Agregar Excursion                      " << endl;
    cout << pad << "               2. Modificar Excursion                    " << endl;
    cout << pad << "               3. Eliminar Excursion                     " << endl;
    cout << pad << "               4. Consultas                                  " << endl;
    cout << pad << "               5. Listados                                   " << endl;
    cout << pad << "               0. Volver al menu principal                   " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               Seleccione una opcion: ";
}

void MenuGestionExcursiones::procesarOpcion(int opcion) {
    int idAux;
    string pad = obtenerPad(61);

    switch (opcion) {
        case 1:
            cout << endl << pad << "------------------- ALTA DE EXCURSION -----------------------" << endl;
            _archivo.agregarExcursion();
            break;

        case 2:
            cout << endl << pad << "----------------- EXCURSIONES REGISTRADAS ------------------- " << endl << endl;
            _archivo.listarExcursiones();
            cout << endl << pad << "Ingrese el ID de la excursion a modificar:";
            cin >> idAux;
            _archivo.modificarExcursion(idAux);
            break;

        case 3:
            cout << endl << pad << "----------------- EXCURSIONES REGISTRADAS ------------------- " << endl << endl;
            _archivo.listarExcursiones();
            cout << endl << pad << "Ingrese el ID de la excursion a dar de baja: ";
            cin >> idAux;
            _archivo.eliminarExcursion(idAux);
            cin.ignore();
            break;

        case 4:
            subMenuConsultas();
            break;

        case 5:
            subMenuListados();
            break;

        default:
            cout << endl << pad << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
    }
}

void MenuGestionExcursiones::subMenuConsultas() {
    int subOpcion;
    int id;
    char nombre[30];
    float pMin;
    float pMax;
    int duracion;
    string pad = obtenerPad(61);

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> CONSULTAS                            " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Buscar excursiones por ID" << endl;
                cout << pad << "               2. Buscar por nombre" << endl;
                cout << pad << "               3. Buscar por precio" << endl;
                cout << pad << "               4. Buscar por duración" << endl;
                cout << pad << "               0. Volver al menu de excursiones" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;
        cin.ignore();

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "          Ingrese el ID: ";
                cin >> id;
                cout << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarExcursionByID(id);
                break;

            case 2:
                cout << endl << pad << "          Ingrese el nombre: ";
                cin.getline(nombre, 30);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarExcursionesByNombre(nombre);
                break;

            case 3:
                cout << endl << pad << "          Ingrese el precio minimo: $";
                cin >> pMin;
                        cout << pad << "          Ingrese el precio maximo: $";
                cin >> pMax;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarExcursionesByPrecioRange(pMin, pMax);
                break;

            case 4:
                cout << endl << pad << "       Ingrese la duracion exacta a buscar (minutos): ";
                cin >> duracion;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarExcursionesByDuracion(duracion);
                break;

            case 0:
                break;

            default:
               cout << endl << pad << "Opcion incorrecta. Intente nuevamente." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}

void MenuGestionExcursiones::subMenuListados() {
    int subOpcion;
    string pad = obtenerPad(61);

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> LISTADOS                             " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Excursiones activas" << endl;
                cout << pad << "               2. Excursiones dadas de baja" << endl;
                cout << pad << "               0. Volver al menu de excursiones" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;
        cin.ignore();

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "-------------- TODAS LAS EXCURSIONES ACTIVAS ---------------" << endl;
                _archivo.listarExcursiones();
                break;

            case 2:
                cout << endl << pad << "------------ TODAS LAS EXCURSIONES DADAS DE BAJA -----------" << endl;
                _archivo.listarExcursionesDadosDeBaja();
                break;

            case 0:
                break;

            default:
               cout << endl << pad << "Opcion incorrecta. Intente nuevamente." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}
