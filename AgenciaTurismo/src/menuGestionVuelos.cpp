#include <iostream>
#include "menuGestionVuelos.h"
#include "archivoVuelo.h"
#include "helpers.h"

using namespace std;

MenuGestionVuelos::MenuGestionVuelos() {}

void MenuGestionVuelos::mostrarOpciones() const {
    string pad = obtenerPad(61);

    cout << pad << "=============================================================" << endl;
    cout << pad << "                     -> MENU DE VUELOS                     " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               1. Gestion Vuelos" << endl;
    cout << pad << "               2. Listados" << endl;
    cout << pad << "               3. Consultas" << endl;
    cout << pad << "               0. Volver al menu principal" << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               Seleccione una opcion: ";
}

void MenuGestionVuelos::procesarOpcion(int opcion) {
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

void MenuGestionVuelos::subMenuGestion() {
    string pad = obtenerPad(61);
    int subOpcion;
    int idAux;

    do {
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                  -> GESTION DE VUELOS                      " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Agregar vuelo" << endl;
                cout << pad << "               2. Modificar vuelo" << endl;
                cout << pad << "               3. Eliminar vuelo" << endl;
                cout << pad << "               0. Volver al menu de vuelo" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;
        system("cls");

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "-------------------- ALTA DE VUELO --------------------------" << endl;
                _archivo.agregarVuelo();
                break;
            case 2:
                cout << endl << pad << "------------------- MODIFICAR VUELO -------------------------" << endl;
                _archivo.listarVuelos();
                cout << endl << pad << "Ingrese el ID del vuelo a modificar:";
                cin >> idAux;
                _archivo.modificarVuelo(idAux);
                break;
            case 3:
                cout << endl << pad << "-------------------- ELIMINAR VUELO -------------------------" << endl;
                _archivo.listarVuelos();
                cout << endl << pad << "Ingrese el ID del vuelo a dar de baja:";
                cin >> idAux;
                _archivo.eliminarVuelo(idAux);
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

void MenuGestionVuelos::subMenuConsultas() {
    int subOpcion;
    int id;
    char origen[30];
    char destino[30];
    float pMin;
    float pMax;
    int duracion;
    char nombre[30];
    char fechaVuelo[11];
    string pad = obtenerPad(61);

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> CONSULTAS                            " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Buscar vuelo por ID" << endl;
                cout << pad << "               2. Buscar por nombre" << endl;
                cout << pad << "               3. Buscar por duración" << endl;
                cout << pad << "               4. Buscar por precio" << endl;
                cout << pad << "               5. Buscar por origen" << endl;
                cout << pad << "               6. Buscar por destino" << endl;
                cout << pad << "               7. Buscar por fecha de vuelo" << endl;
                cout << pad << "               0. Volver al menu de vuelo" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;
        system("cls");

        switch (subOpcion) {
            case 1:
                cout << endl << pad << " Ingrese el ID: ";
                cin >> id;
                cout << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarVueloByID(id);
                break;

            case 2:
                cin.ignore();
                cout << endl << pad << " Ingrese el nombre: ";
                cin.getline(nombre, 30);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarVuelosByNombre(nombre);
                break;

            case 3:
                cout << endl << pad << " Ingrese la duracion exacta a buscar (minutos): ";
                cin >> duracion;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarVuelosByDuracion(duracion);
                break;

            case 4:
                cout << endl << pad << " Ingrese el precio minimo: $";
                cin >> pMin;
                        cout << pad << " Ingrese el precio maximo: $";
                cin >> pMax;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarVuelosByPrecioRange(pMin, pMax);
                break;

            case 5:
                cin.ignore();
                cout << endl << pad << " Ingrese el origen: ";
                cin.getline(origen, 20);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarVuelosByOrigen(origen);
                break;

            case 6:
                cin.ignore();
                cout << endl << pad << " Ingrese el destino: ";
                cin.getline(destino, 20);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarVuelosByDestino(destino);
                break;

            case 7:
                cin.ignore();
                cout << endl << pad << " Ingrese la fecha de vuelo (dd/mm/yyyy): ";
                cin.getline(fechaVuelo, 11);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarVuelosByFechaVuelo(fechaVuelo);
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

void MenuGestionVuelos::subMenuListados() {
    int subOpcion;
    string pad = obtenerPad(61);

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> LISTADOS                             " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Vuelos activos" << endl;
                cout << pad << "               2. Vuelos dados de baja" << endl;
                cout << pad << "               0. Volver al menu de vuelo" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;
        system("cls");

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "--------------------- VUELOS ACTIVOS ------------------------" << endl;
                _archivo.listarVuelos();
                break;

            case 2:
                cout << endl << pad << "------------------ VUELOS DADOS DE BAJA ---------------------" << endl;
                _archivo.listarVuelosDadosDeBaja();
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
