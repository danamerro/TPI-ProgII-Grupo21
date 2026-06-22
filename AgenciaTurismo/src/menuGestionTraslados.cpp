#include <iostream>
#include "menuGestionTraslados.h"
#include "helpers.h"

using namespace std;

MenuGestionTraslados::MenuGestionTraslados() {}

void MenuGestionTraslados::mostrarOpciones() const {
    string pad = obtenerPad(61);

    cout << pad << "=============================================================" << endl;
    cout << pad << "               -> GESTION DE TRASLADOS                       " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               1. Agregar Traslado                      " << endl;
    cout << pad << "               2. Modificar Traslado                    " << endl;
    cout << pad << "               3. Eliminar Traslado                     " << endl;
    cout << pad << "               4. Consultas                                  " << endl;
    cout << pad << "               5. Listados                                   " << endl;
    cout << pad << "               0. Volver al menu principal                   " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               Seleccione una opcion: ";
}

void MenuGestionTraslados::procesarOpcion(int opcion) {
    int idAux;
    string pad = obtenerPad(61);

    switch (opcion) {
        case 1:
            cout << endl << pad << "------------------- ALTA DE TRASLADO  -----------------------" << endl;
            _archivo.agregarTraslado();
            break;

        case 2:
            cout << endl << pad << "------------------- TRASLADOS REGISTRADAS ------------------- " << endl << endl;
            _archivo.listarTraslados();
            cout << endl << pad << "Ingrese el ID del paquete a modificar:";
            cin >> idAux;
            _archivo.modificarTraslado(idAux);
            break;

        case 3:
            cout << endl << pad << "------------------- TRASLADOS REGISTRADAS ------------------- " << endl << endl;
            _archivo.listarTraslados();
            cout << endl << pad << "Ingrese el ID del traslado a eliminar:";
            cin >> idAux;
            _archivo.eliminarTraslado(idAux);
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

void MenuGestionTraslados::subMenuConsultas() {
    int subOpcion;
    int id;
    char origen[20];
    char destino[20];
    float pMin;
    float pMax;
    int duracion;
    string pad = obtenerPad(61);

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> CONSULTAS                            " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Buscar traslado por ID" << endl;
                cout << pad << "               2. Buscar por duración" << endl;
                cout << pad << "               3. Buscar por precio" << endl;
                cout << pad << "               4. Buscar por origen" << endl;
                cout << pad << "               5. Buscar por destino" << endl;
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
                _archivo.mostrarTrasladoByID(id);
                break;

            case 2:
                cout << endl << pad << "       Ingrese la duracion exacta a buscar (minutos): ";
                cin >> duracion;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarTrasladosByDuracion(duracion);
                break;

            case 3:
                cout << endl << pad << "          Ingrese el precio minimo: $";
                cin >> pMin;
                        cout << pad << "          Ingrese el precio maximo: $";
                cin >> pMax;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarTrasladosByPrecioRange(pMin, pMax);
                break;

            case 4:
                cout << endl << pad << "                     Ingrese el origen: ";
                cin.getline(origen, 20);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarTrasladosByOrigen(origen);
                break;

            case 5:
                cout << endl << pad << "                     Ingrese el destino: ";
                cin.getline(destino, 20);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarTrasladosByDestino(destino);
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


void MenuGestionTraslados::subMenuListados() {
    int subOpcion;
    string pad = obtenerPad(61);

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> LISTADOS                             " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Traslados activos" << endl;
                cout << pad << "               2. Traslados dados de baja" << endl;
                cout << pad << "               0. Volver al menu de excursiones" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;
        cin.ignore();

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "-------------- TODAS LOS TRASLADOS ACTIVAS -----------------" << endl;
                _archivo.listarTraslados();
                break;

            case 2:
                cout << endl << pad << "------------ TODOS LOS TRASLADOS DADAS DE BAJA -------------" << endl;
                _archivo.listarTrasladosDadosDeBaja();
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

