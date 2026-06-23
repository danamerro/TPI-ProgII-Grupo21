#include <iostream>
#include "menuGestionClientes.h"
#include "archivoCliente.h"
#include "helpers.h"

using namespace std;

MenuGestionClientes::MenuGestionClientes() {}

void MenuGestionClientes::mostrarOpciones() const {
    string pad = obtenerPad(61);

    cout << pad << "=============================================================" << endl;
    cout << pad << "                     -> MENU DE CLIENTES                     " << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               1. Gestion Cliente" << endl;
    cout << pad << "               2. Listados" << endl;
    cout << pad << "               3. Consultas" << endl;
    cout << pad << "               0. Volver al menu principal" << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "               Seleccione una opcion: ";
}

void MenuGestionClientes::procesarOpcion(int opcion) {
    string pad = obtenerPad(61);

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
        default:
            cout << endl << pad << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
    }
}

void MenuGestionClientes::subMenuGestion() {
    string pad = obtenerPad(61);
    int subOpcion;

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                  -> GESTION DE CLIENTE                      " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Agregar cliente" << endl;
                cout << pad << "               2. Modificar cliente" << endl;
                cout << pad << "               3. Eliminar cliente" << endl;
                cout << pad << "               0. Volver al menu de clientes" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "-------------------- ALTA DE CLIENTE ------------------------" << endl;
                _archivo.agregarCliente();
                break;
            case 2:
                cout << endl << pad << "------------------- MODIFICAR CLIENTE -----------------------" << endl;
                _archivo.modificarCliente();
                break;
            case 3:
                cout << endl << pad << "-------------------- ELIMINAR CLIENTE -----------------------" << endl;
                _archivo.eliminarCliente();
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

void MenuGestionClientes::subMenuListados() {
    string pad = obtenerPad(61);
    int subOpcion;

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> LISTADOS                             " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Clientes activos" << endl;
                cout << pad << "               2. Clientes dados de baja" << endl;
                cout << pad << "               3. Directorio de contactos" << endl;
                cout << pad << "               0. Volver al menu de clientes" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "------------------- CLIENTES ACTIVOS ------------------------" << endl;
                _archivo.listarClientes();
                break;
            case 2:
                cout << endl << pad << "---------------- CLIENTES DADOS DE BAJA ---------------------" << endl;
                _archivo.listarClientesDadosDeBaja();
                break;
            case 3:
                cout << endl << pad << "------------------ DIRECTORIO DE CONTACTO -------------------" << endl;
                _archivo.listarDirectorioContacto();
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

void MenuGestionClientes::subMenuConsultas() {
    string pad = obtenerPad(61);
    int subOpcion;
    int idAux;
    char nombre[20];
    char apellido[20];
    char email[20];
    bool estado;
    char direccion[50];

    do {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "                     -> CONSULTAS                            " << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               1. Buscar cliente por ID" << endl;
                cout << pad << "               2. Buscar por DNI" << endl;
                cout << pad << "               3. Buscar por nombre" << endl;
                cout << pad << "               4. Buscar por apellido" << endl;
                cout << pad << "               5. Buscar por mail" << endl;
                cout << pad << "               6. Buscar por estado" << endl;
                cout << pad << "               7. Buscar por telefono" << endl;
                cout << pad << "               8. Buscar por direccion" << endl;
                cout << pad << "               0. Volver al menu de clientes" << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
                cout << pad << "               Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << endl << pad << "          Ingrese ID del cliente a consultar: ";
                cin >> idAux;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarClienteById(idAux);
                break;
            case 2:
                cout << endl << pad << "          Ingrese DNI del cliente a consultar: ";
                cin >> idAux;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarClienteByDni(idAux);
                break;
            case 3:
                cin.ignore();
                cout << endl << pad << "          Ingrese nombre del cliente a consultar: ";
                cin.getline(nombre, 20);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarClienteByNombre(nombre);
                break;
            case 4:
                cin.ignore();
                cout << endl << pad << "          Ingrese apellido del cliente a consultar: ";
                cin.getline(apellido, 20);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarClienteByApellido(apellido);
                break;
            case 5:
                cin.ignore();
                cout << endl << pad << "          Ingrese el email del cliente a consultar: ";
                cin.getline(email, 20);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarClienteByEmail(email);
                break;
            case 6:
                cout << endl << pad << "          Ingrese el estado del cliente a consultar: " << endl;
                cout << pad << "          1 = Activo" << endl;
                cout << pad << "          0 = Dado de baja" << endl;
                cout << pad << "          Opcion: ";
                cin >> estado;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarClienteByEstado(estado);
                break;
            case 7:
                cout << endl << pad << "          Ingrese el telefono del cliente a consultar: ";
                cin >> idAux;
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarClienteByTelefono(idAux);
                break;
            case 8:
                cin.ignore();
                cout << endl << pad << "          Ingrese la direccion del cliente a consultar: ";
                cin.getline(direccion, 50);
                cout << endl << pad << "------------------------- RESULTADOS ------------------------" << endl;
                _archivo.mostrarClienteByDireccion(direccion);
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
