#include <iostream>
#include "menuGestionHoteles.h"
#include "archivoHotel.h"

using namespace std;

MenuGestionHoteles::MenuGestionHoteles() {}

void MenuGestionHoteles::mostrarOpciones() const {
    cout << "=========================================" << endl;
    cout << "   -> GESTION DE HOTELES                 " << endl;
    cout << "=========================================" << endl;
    cout << "1. Agregar nuevo Hotel" << endl;
    cout << "2. Modificar Hotel existente" << endl;
    cout << "3. Eliminar Hotel" << endl;
    cout << "4. Consultas" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "=========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void MenuGestionHoteles::procesarOpcion(int opcion) {
    int idAux;

    switch (opcion) {
        case 1:
            cout << endl << "------------- ALTA DE HOTEL -------------" << endl;
            _archivo.agregarHotel();
            break;

        case 2:
            cout << "---------- HOTELES REGISTRADOS ---------- "<< endl << endl;
            _archivo.listarHoteles();
            cout << "Ingrese el ID del hotel a modificar: ";
            cin >> idAux;
            _archivo.modificarHotel(idAux);
            break;

        case 3:
            cout << "---------- HOTELES REGISTRADOS ------------" << endl << endl;
            _archivo.listarHoteles();
            cout << "Ingrese el ID del hotel a dar de baja: ";
            cin >> idAux;
            _archivo.eliminarHotel(idAux);
            break;

        case 4:
            subMenuConsultas();
            break;

        default:
            cout << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
    }
}

void MenuGestionHoteles::subMenuConsultas() {
    int subOpcion;
    char filtroCadena[30];
    float precioMin, precioMax;

    do {
        cout << "--------------------------------------" << endl;
        cout << "       -->   CONSULTAS     " << endl;
        cout << "--------------------------------------" << endl;
        cout << "1. Listar todos los hoteles activos" << endl;
        cout << "2. Buscar hotel por nombre" << endl;
        cout << "3. Buscar hotel por estrellas" << endl;
        cout << "4. Buscar hotel por rango de precio" << endl;
        cout << "0. Volver al menu de hoteles" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << endl << "------ TODOS LOS HOTELES ACTIVOS ------" << endl;
                _archivo.listarHoteles();
                break;

            case 2:
                cin.ignore();
                cout << "Ingrese el nombre del hotel a buscar: ";
                cin.getline(filtroCadena, 30);
                cout << endl << "------ RESULTADOS ------" << endl;
                _archivo.mostrarHotelesByNombre(filtroCadena);
                break;

            case 3:
                cin.ignore();
                cout << "Ingrese el numero de estrellas del hotel: ";
                cin.getline(filtroCadena, 30);
                cout << endl << "------ RESULTADOS ------" << endl;
                _archivo.mostrarHotelesByEstrellas(filtroCadena);
                break;

            case 4:
                cout << "Ingrese el precio minimo: ";
                cin >> precioMin;
                cout << "Ingrese el precio maximo: ";
                cin >> precioMax;
                cout << endl << "------ RESULTADOS ------" << endl;
                _archivo.mostrarHotelesByRangoPrecio(precioMin, precioMax);
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
