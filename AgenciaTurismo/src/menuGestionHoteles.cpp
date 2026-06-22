#include <iostream>
#include "menuGestionHoteles.h"
#include "archivoHotel.h"
#include "helpers.h"

using namespace std;

MenuGestionHoteles::MenuGestionHoteles() {}

void MenuGestionHoteles::mostrarOpciones() const {
    string pad = obtenerPad(61);

    cout << pad << "=============================================================" << endl;
    cout << pad << "               -> GESTION DE HOTELES                     " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               1. Agregar Hotel                      " << endl;
    cout << pad << "               2. Modificar Hotel                    " << endl;
    cout << pad << "               3. Eliminar Hotel                     " << endl;
    cout << pad << "               4. Consultas                                  " << endl;
    cout << pad << "               5. Listados                                   " << endl;
    cout << pad << "               0. Volver al menu principal                   " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               Seleccione una opcion: ";
}

void MenuGestionHoteles::procesarOpcion(int opcion) {
    int idAux;
    string pad = obtenerPad(61);

    switch (opcion) {
        case 1:
            cout << endl << pad << "--------------------- ALTA DE HOTEL -------------------------" << endl;
            _archivo.agregarHotel();
            break;

        case 2:
            cout << endl << pad << "----------------- HOTELES REGISTRADOS -----------------------" << endl;
            _archivo.listarHoteles();
            cout << endl << pad << "Ingrese el ID del hotel a modificar:";
            cin >> idAux;
            _archivo.modificarHotel(idAux);
            break;

        case 3:
            cout << endl << pad << "----------------- HOTELES REGISTRADOS -----------------------" << endl;
            _archivo.listarHoteles();
            cout << endl << pad << "Ingrese el ID del hotel a dar de baja: ";
            cin >> idAux;
            _archivo.eliminarHotel(idAux);
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
        cin.ignore();

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "          Ingrese el ID: ";
                cin >> id;
                cout << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarHotelByID(id);
                break;

            case 2:
                cout << endl << pad << "          Ingrese el nombre: ";
                cin.getline(nombre, 30);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarHotelesByNombre(nombre);
                break;

            case 3:
                cout << endl << pad << "          Ingrese el precio minimo: $";
                cin >> pMin;
                        cout << pad << "          Ingrese el precio maximo: $";
                cin >> pMax;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarHotelesByRangoPrecio(pMin, pMax);
                break;

            case 4:
                cout << endl << pad << "          Ingrese la estrellas del hotel: ";
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
                cout << pad << "               0. Volver al menu de excursiones" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;
        cin.ignore();

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "---------------- TODAS LOS HOTELES ACTIVOS -----------------" << endl;
                _archivo.listarHoteles();
                break;

            case 2:
                cout << endl << pad << "-------------- TODAS LOS HOTELES DADOS DE BAJA -------------" << endl;
                _archivo.listarHotelesDadosDeBaja();
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

