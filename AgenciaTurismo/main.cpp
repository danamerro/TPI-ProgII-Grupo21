#include <iostream>

using namespace std;

//#include "include/vuelo.h"
//#include "include/archivoVuelo.h"
#include "include/archivoExcursion.h"

int main()
{
    ArchivoExcursion archivoExcursion;

    int opcion;

    do {
        cout << endl;
        cout << "========= MENU EXCURSIONES =========" << endl;
        cout << "1. Agregar excursion" << endl;
        cout << "2. Listar excursiones" << endl;
        cout << "3. Mostrar excursion por ID" << endl;
        cout << "4. Modificar excursion" << endl;
        cout << "5. Eliminar excursion" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1:
                archivoExcursion.agregarExcursion();
                break;
            case 2:
                cout << "---------- LISTADO DE EXCURSIONES ----------" << endl;
                archivoExcursion.listarExcursiones();
                break;
            case 3: {
                int id;
                cout << "Ingrese ID de la excursion: ";
                cin >> id;
                archivoExcursion.mostrarExcursionByID(id);
                break;
            }
            case 4: {
                int id;
                cout << "Ingrese ID de la excursion a modificar: ";
                cin >> id;
                archivoExcursion.modificarExcursion(id);
                break;
            }
            case 5: {
                int id;
                cout << "Ingrese ID de la excursion a eliminar: ";
                cin >> id;
                archivoExcursion.eliminarExcursion(id);
                break;
            }
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }

    } while (opcion != 0);

    return 0;
}
