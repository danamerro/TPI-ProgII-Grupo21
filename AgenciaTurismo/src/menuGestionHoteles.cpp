#include <iostream>
#include "menuGestionHoteles.h"
#include "archivoHotel.h"
#include "helpers.h"

using namespace std;

MenuGestionHoteles::MenuGestionHoteles() {}

void MenuGestionHoteles::mostrarOpciones() const {
    string pad = obtenerPad(61);

    cout << pad << "=============================================================" << endl;
    cout << pad << "                     -> MENU DE HOTELES                     " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               1. Gestion Hotel" << endl;
    cout << pad << "               2. Listados" << endl;
    cout << pad << "               3. Consultas" << endl;
    cout << pad << "               0. Volver al menu principal" << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               Seleccione una opcion: ";
}


void MenuGestionHoteles::procesarOpcion(int opcion) {
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


void MenuGestionHoteles::subMenuGestion() {
    string pad = obtenerPad(61);
    int idAux;
    int subOpcion;

    do {
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                  -> GESTION DE HOTEL                      " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Agregar hotel" << endl;
                cout << pad << "               2. Modificar hotel" << endl;
                cout << pad << "               3. Eliminar hotel" << endl;
                cout << pad << "               0. Volver al menu de hotel" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;
        system("cls");

        switch (subOpcion) {
        case 1:
            cout << endl << pad << "--------------------- ALTA DE HOTEL -------------------------" << endl;
            _archivo.agregarHotel();
            break;

        case 2:
            cout << endl << pad << "----------------- MODIFICAR HOTEL -----------------------" << endl;
            _archivo.listarHoteles();
            cout << endl << pad << "Ingrese el ID del hotel a modificar: ";
            cin >> idAux;
            _archivo.modificarHotel(idAux);
            break;

        case 3:
            cout << endl << pad << "----------------- ELIMNAR HOTEL -----------------------" << endl;
            _archivo.listarHoteles();
            cout << endl << pad << "Ingrese el ID del hotel a dar de baja: ";
            cin >> idAux;
            _archivo.eliminarHotel(idAux);
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

void MenuGestionHoteles::subMenuConsultas() {
    int subOpcion;
    int id;
    char nombre[30];
    float pMin;
    float pMax;
    char estrella[30];
    string pad = obtenerPad(61);

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> CONSULTAS                            " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Buscar hotel por ID" << endl;
                cout << pad << "               2. Buscar por nombre" << endl;
                cout << pad << "               3. Buscar por precio" << endl;
                cout << pad << "               4. Buscar por estrellas" << endl;
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
                _archivo.mostrarHotelByID(id);
                cout << endl;
                cin.ignore();
                limpiarPantalla();
                break;

            case 2:
                cin.ignore();
                cout << endl << pad << " Ingrese el nombre: ";
                cin.getline(nombre, 30);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarHotelesByNombre(nombre);
                break;

            case 3:
                cout << endl << pad << " Ingrese el precio minimo: $";
                cin >> pMin;
                        cout << pad << " Ingrese el precio maximo: $";
                cin >> pMax;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarHotelesByRangoPrecio(pMin, pMax);
                break;

            case 4:
                cout << endl << pad << " Ingrese la estrellas del hotel: ";
                cin >> estrella;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarHotelesByEstrellas(estrella);
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


void MenuGestionHoteles::subMenuListados() {
    int subOpcion;
    string pad = obtenerPad(61);

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> LISTADOS                             " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Hoteles activos" << endl;
                cout << pad << "               2. Hoteles dados de baja" << endl;
                cout << pad << "               0. Volver al menu de hotel" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;

        system("cls");
        switch (subOpcion) {
            case 1:
                cout << endl << pad << "---------------------- HOTELES ACTIVOS ----------------------" << endl;
                _archivo.listarHoteles();
                cout << endl;
                cin.ignore();
                limpiarPantalla();
                break;

            case 2:
                cout << endl << pad << "-------------------- HOTELES DADOS DE BAJA ------------------" << endl;
                _archivo.listarHotelesDadosDeBaja();
                cout << endl;
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

