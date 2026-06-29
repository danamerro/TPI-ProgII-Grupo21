#include <iostream>
#include "menuGestionExcursiones.h"
#include "helpers.h"

using namespace std;

MenuGestionExcursiones::MenuGestionExcursiones() {}

void MenuGestionExcursiones::mostrarOpciones() const {
    string pad = obtenerPad(61);

    cout << pad << "=============================================================" << endl;
    cout << pad << "                     -> MENU DE EXCUSION                     " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               1. Gestion Excursion" << endl;
    cout << pad << "               2. Listados" << endl;
    cout << pad << "               3. Consultas" << endl;
    cout << pad << "               0. Volver al menu principal" << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               Seleccione una opcion: ";
}

void MenuGestionExcursiones::procesarOpcion(int opcion) {
    string pad = obtenerPad(61);
    system("cls");

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
        case 0 :
            break;
        default:
            cout << endl << pad << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
    }
}

void MenuGestionExcursiones::subMenuGestion() {
    string pad = obtenerPad(61);
    int idAux;
    int subOpcion;

    do {
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                  -> GESTION DE EXCURSIONES                      " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Agregar excursion" << endl;
                cout << pad << "               2. Modificar excursion" << endl;
                cout << pad << "               3. Eliminar excursion" << endl;
                cout << pad << "               0. Volver al menu de excursiones" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;
        system("cls");

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "-------------------- ALTA DE EXCURSIONES --------------------" << endl;
                 _archivo.agregarExcursion();
                break;
            case 2:
                cout << endl << pad << "------------------- MODIFICAR EXCURSIONES -------------------" << endl;
               _archivo.listarExcursiones();
                cout << endl << pad << "Ingrese el ID de la excursion a modificar:";
                cin >> idAux;
                _archivo.modificarExcursion(idAux);
                break;
            case 3:
                cout << endl << pad << "-------------------- ELIMINAR EXCURSIONES -------------------" << endl;
                 _archivo.listarExcursiones();
                cout << endl << pad << "Ingrese el ID de la excursion a dar de baja: ";
                cin >> idAux;
                _archivo.eliminarExcursion(idAux);
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
        system("cls");

        switch (subOpcion) {
            case 1:
                cout << endl << pad << " Ingrese el ID: ";
                cin >> id;
                cout << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarExcursionByID(id);
                break;

            case 2:
                cin.ignore();
                cout << endl << pad << " Ingrese el nombre: ";
                cin.getline(nombre, 30);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarExcursionesByNombre(nombre);
                cout << endl;
                limpiarPantalla();
                break;

            case 3:
                cout << endl << pad << " Ingrese el precio minimo: $";
                cin >> pMin;
                        cout << pad << " Ingrese el precio maximo: $";
                cin >> pMax;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarExcursionesByPrecioRange(pMin, pMax);
                break;

            case 4:
                cout << endl << pad << " Ingrese la duracion exacta a buscar (minutos): ";
                cin >> duracion;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarExcursionesByDuracion(duracion);
                cin.ignore();
                limpiarPantalla();
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
        system("cls");

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "----------------- EXCURSIONES ACTIVAS ----------------------" << endl;
                _archivo.listarExcursiones();
                cin.ignore();
                limpiarPantalla();
                break;

            case 2:
                cout << endl << pad << "--------------- EXCURSIONES DADOS DE BAJA ------------------" << endl;
                _archivo.listarExcursionesDadosDeBaja();
                cin.ignore();
                limpiarPantalla();
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
