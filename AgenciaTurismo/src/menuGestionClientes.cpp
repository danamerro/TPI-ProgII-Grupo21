#include <iostream>
#include "menuGestionClientes.h"
#include "archivoCliente.h"

using namespace std;

MenuGestionClientes::MenuGestionClientes() {}

void MenuGestionClientes::mostrarOpciones() const {
    cout << "=========================================" << endl;
    cout << "   -> GESTION DE CLIENTES                " << endl;
    cout << "=========================================" << endl;
    cout << "1. Agregar cliente" << endl;
    cout << "2. Modificar cliente" << endl;
    cout << "3. Eliminar cliente" << endl;
    cout << "4. Listar clientes activos" << endl;
    cout << "5. Listar clientes dados de baja" << endl;
    cout << "6. Directorio de contacto" << endl;
    cout << "7. Consultas" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "=========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void MenuGestionClientes::ejecutar() {
    ArchivoCliente archivo;
    int opcion;
    int idAux;

    do {
        mostrarOpciones();
        cin >> opcion;

        switch (opcion) {
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

            case 4:
                cout << endl << "------ CLIENTES ACTIVOS ------" << endl;
                archivo.listarClientes();
                break;

            case 5:
                cout << endl << "------ CLIENTES DADOS DE BAJA ------" << endl;
                archivo.listarClientesDadosDeBaja();
                break;

            case 6:
                cout << endl << "------ DIRECTORIO DE CONTACTO ------" << endl;
                archivo.listarDirectorioContacto();
                break;

            case 7:
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

void MenuGestionClientes::subMenuConsultas() {
    int subOpcion;
    int idAux;
    char nombre[20];
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
                char nombre[20];
                cin.ignore();
                cout << "Ingrese nombre del cliente a consultar: ";
                cin.getline(nombre, 20);
                archivo.mostrarClienteByNombre(nombre);
                break;
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                cout << endl << "...falta agregar" << endl;
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
