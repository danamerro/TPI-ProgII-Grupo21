#include <iostream>
#include "menuGestionClientes.h"
#include "archivoCliente.h"

using namespace std;

MenuGestionClientes::MenuGestionClientes() {}

void MenuGestionClientes::mostrarOpciones() const {
    cout << "=========================================" << endl;
    cout << "          GESTION DE CLIENTES                " << endl;
    cout << "=========================================" << endl;
    cout << "1. Gestion Cliente" << endl;
    cout << "2. Listados" << endl;
    cout << "3. Consultas" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "=========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void MenuGestionClientes::ejecutar() {
    int opcion;

    do {
        mostrarOpciones();
        cin >> opcion;

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
            case 0:
                cout << "Regresando al menu principal..." << endl;
                break;
            default:
                cout << "Opcion incorrecta. Intente nuevamente." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 0);
}

void MenuGestionClientes::subMenuGestion() {
    int subOpcion;
    ArchivoCliente archivo;

    do {
        cout << "-----------------------------------------" << endl;
        cout << "         GESTION DE CLIENTE                " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Agregar cliente" << endl;
        cout << "2. Modificar cliente" << endl;
        cout << "3. Eliminar cliente" << endl;
        cout << "0. Volver al menu de clientes" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << endl << "------- ALTA DE CLIENTE -------" << endl;
                archivo.agregarCliente();
                break;
            case 2:
                cout << endl << "------ MODIFICAR CLIENTE ------" << endl;
                archivo.modificarCliente();
                break;
            case 3:
                cout << endl << "------ ELIMINAR CLIENTE ------" << endl;
                archivo.eliminarCliente();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}

void MenuGestionClientes::subMenuListados() {
    int subOpcion;
    ArchivoCliente archivo;

    do {
        cout << "-----------------------------------------" << endl;
        cout << "   --> LISTADOS DE CLIENTES              " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Listar clientes activos" << endl;
        cout << "2. Listar clientes dados de baja" << endl;
        cout << "3. Directorio de contactos" << endl;
        cout << "0. Volver al menu de clientes" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << endl << "------ CLIENTES ACTIVOS ------" << endl;
                archivo.listarClientes();
                break;
            case 2:
                cout << endl << "------ CLIENTES DADOS DE BAJA ------" << endl;
                archivo.listarClientesDadosDeBaja();
                break;
            case 3:
                cout << endl << "------ DIRECTORIO DE CONTACTO ------" << endl;
                archivo.listarDirectorioContacto();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}

void MenuGestionClientes::subMenuConsultas() {
    int subOpcion;
    int idAux;
    char nombre[20];
    char apellido[20];
    char email[20];
    bool estado;
    char direccion[50];
    ArchivoCliente archivo;

    do {
        cout << "-----------------------------------------" << endl;
        cout << "   --> CONSULTAS DE CLIENTES             " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Buscar cliente por ID" << endl;
        cout << "2. Buscar por DNI" << endl;
        cout << "3. Buscar por nombre" << endl;
        cout << "4. Buscar por apellido" << endl;
        cout << "5. Buscar por mail" << endl;
        cout << "6. Buscar por estado" << endl;
        cout << "7. Buscar por telefono" << endl;
        cout << "8. Buscar por direccion" << endl;
        cout << "0. Volver al menu de clientes" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione una sub-opcion: ";
        cin >> subOpcion;

        switch (subOpcion) {
            case 1:
                cout << "Ingrese ID del cliente a consultar: ";
                cin >> idAux;
                archivo.mostrarClienteById(idAux);
                break;
            case 2:
                cout << "Ingrese DNI del cliente a consultar: ";
                cin >> idAux;
                archivo.mostrarClienteByDni(idAux);
                break;
            case 3:
                cin.ignore();
                cout << "Ingrese nombre del cliente a consultar: ";
                cin.getline(nombre, 20);
                archivo.mostrarClienteByNombre(nombre);
                break;
            case 4:
                cin.ignore();
                cout << "Ingrese apellido del cliente a consultar: ";
                cin.getline(apellido, 20);
                archivo.mostrarClienteByApellido(apellido);
                break;
            case 5:
                cin.ignore();
                cout << "Ingrese el email del cliente a consultar: ";
                cin.getline(email, 20);
                archivo.mostrarClienteByEmail(email);
                break;
            case 6:
                cout << "Ingrese el estado del cliente a consultar: " << endl;
                cout << "1 = Activo" << endl;
                cout << "0 = Dado de baja" << endl;
                cout << "Opcion: ";
                cin >> estado;
                cout << "-----------------------------------------" << endl;
                archivo.mostrarClienteByEstado(estado);
                break;
            case 7:
                cout << "Ingrese el telefono del cliente a consultar: ";
                cin >> idAux;
                archivo.mostrarClienteByTelefono(idAux);
                break;
            case 8:
                cin.ignore();
                cout << "Ingrese la direccion del cliente a consultar: ";
                cin.getline(direccion, 50);
                archivo.mostrarClienteByDireccion(direccion);
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        cout << endl;
    } while (subOpcion != 0);
}
