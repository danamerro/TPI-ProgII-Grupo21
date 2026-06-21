#include <iostream>
#include "menuGestionVuelos.h"
#include "archivoVuelo.h"

using namespace std;

MenuGestionVuelos::MenuGestionVuelos() {}

void MenuGestionVuelos::mostrarOpciones() const {
    cout << "=========================================" << endl;
    cout << "   -> GESTION DE VUELOS                  " << endl;
    cout << "=========================================" << endl;
    cout << "1. Agregar un Vuelo" << endl;
    cout << "2. Modificar un Vuelo" << endl;
    cout << "3. Eliminar un Vuelo" << endl;
    cout << "4. Consultas" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "=========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void MenuGestionVuelos::procesarOpcion(int opcion) {
    int idAux;

    switch (opcion) {
        case 1:
            cout << endl << "------- ALTA DE VUELO -------" << endl;
            _archivo.agregarVuelo();
            break;

        case 2:
            cout << "------ VUELOS REGISTRADOS ------ " << endl << endl;
            _archivo.listarVuelos();
            cout << "Ingrese el ID del vuelo a modificar: ";
            cin >> idAux;
            cin.ignore();
            _archivo.modificarVuelo(idAux);
            break;

        case 3:
            cout << endl << "------ VUELOS REGISTRADOS ------" << endl << endl;
            _archivo.listarVuelos();
            cout << "Ingrese el ID del vuelo a dar de baja: ";
            cin >> idAux;
            cin.ignore();
            _archivo.eliminarVuelo(idAux);
            break;

        case 4:
            subMenuConsultas();
            break;

        default:
            cout << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
    }
}

void MenuGestionVuelos::subMenuConsultas() {
    int subOpcion;
    char filtroTexto[30];

    do {
        cout << "-----------------------------------------" << endl;
        cout << "   --> CONSULTAS DE VUELOS               " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Listar todos los vuelos activos" << endl;
        cout << "2. Buscar vuelo por destino" << endl;
        cout << "3. Buscar vuelo por origen" << endl;
        cout << "0. Volver al menu de vuelos" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opcion: ";
        cin >> subOpcion;
        cin.ignore();

        switch (subOpcion) {
            case 1:
                cout << endl << "------ TODOS LOS VUELOS ACTIVOS ------" << endl;
                _archivo.listarVuelos();
                break;

            case 2:
                cout << "Ingrese el DESTINO a buscar: ";
                cin.getline(filtroTexto, 30);
                cout << endl << "------ RESULTADOS ------" << endl;
                _archivo.mostrarVuelosByDestino(filtroTexto);
                break;

            case 3:
                cout << "Ingrese el ORIGEN a buscar: ";
                cin.getline(filtroTexto, 30);
                cout << endl << "------ RESULTADOS ------" << endl;
                _archivo.mostrarVuelosByOrigen(filtroTexto);
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
