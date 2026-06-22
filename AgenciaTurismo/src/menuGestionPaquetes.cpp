#include <iostream>
#include "menuGestionPaquetes.h"
#include "helpers.h"

using namespace std;

MenuGestionPaquetes::MenuGestionPaquetes() {}

void MenuGestionPaquetes::mostrarOpciones() const {
     string pad = obtenerPad(61);

    cout << pad << "=============================================================" << endl;
    cout << pad << "               -> GESTION DE PAQUETES TURÍSTICOS             " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               1. Agregar Paquete                      " << endl;
    cout << pad << "               2. Modificar Paquete                    " << endl;
    cout << pad << "               3. Eliminar Paquete                     " << endl;
    cout << pad << "               4. Consultas                                  " << endl;
    cout << pad << "               5. Listados                                   " << endl;
    cout << pad << "               0. Volver al menu principal                   " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               Seleccione una opcion: ";
}

void MenuGestionPaquetes::procesarOpcion(int opcion) {
    string pad = obtenerPad(61);
    int id;

    switch (opcion) {
        case 1:
            cout << endl << pad << "--------------------- ALTA DE PAQUETE -----------------------" << endl;
            _archivo.agregarPaquete();
            break;

        case 2:
            cout << endl << pad << "------------------- PAQUETES REGISTRADOS --------------------" << endl << endl;
            _archivo.listarPaquetes();
            cout << endl << pad << "Ingrese el ID del hotel a modificar:";
            cin >> id;
            _archivo.modificarPaquete(id);
            break;

        case 3:
            cout << endl << pad << "----------------- PAQUETES REGISTRADOS -----------------------" << endl;
            _archivo.listarPaquetes();
            cout << endl << pad << "Ingrese el ID del paquete a dar de baja: ";
            cin >> id;
            _archivo.eliminarPaquete(id);
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

void MenuGestionPaquetes::subMenuConsultas() {
    string pad = obtenerPad(61);

    int subOpcion;
    int id;
    char nombre[30];
    float pMin;
    float pMax;
    char destino[30];
    int cupo;

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> CONSULTAS                            " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Buscar paquete por ID" << endl;
                cout << pad << "               2. Buscar por nombre" << endl;
                cout << pad << "               3. Buscar por precio" << endl;
                cout << pad << "               4. Buscar por cupo" << endl;
                cout << pad << "               5. Buscar por destino" << endl;
                cout << pad << "               0. Volver al menu de paquetes." << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;
        cin.ignore();

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "          Ingrese el ID: ";
                cin >> id;
                cout << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarPaqueteByID(id);
                break;

            case 2:
                cout << endl << pad << "          Ingrese el nombre: ";
                cin.getline(nombre, 30);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarPaquetesByNombre(nombre);
                break;

            case 3:
                cout << endl << pad << "          Ingrese el precio minimo: $";
                cin >> pMin;
                        cout << pad << "          Ingrese el precio maximo: $";
                cin >> pMax;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarPaquetesByPrecioRange(pMin, pMax);
                break;

            case 4:
                cout << endl << pad << "          Ingrese el cupo: ";
                cin >> cupo;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarPaquetesByCupo(cupo);
                break;

            case 5:
                cout << endl << pad << "          Ingrese el destino: ";
                cin.getline(destino, 30);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarPaquetesByDestino(destino);
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


void MenuGestionPaquetes::subMenuListados() {
    int subOpcion;
    string pad = obtenerPad(61);

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> LISTADOS                             " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Paquetes activos" << endl;
                cout << pad << "               2. Paquetes dados de baja" << endl;
                cout << pad << "               0. Volver al menu de excursiones" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;
        cin.ignore();

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "---------------- TODOS LOS PAQUETES ACTIVOS ----------------" << endl;
                _archivo.listarPaquetes();
                break;

            case 2:
                cout << endl << pad << "------------- TODOS LOS PAQUETES DADOS DE BAJA -------------" << endl;
                _archivo.listarPaquetesDadosDeBaja();
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

