#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#include "archivoCliente.h"
#include "cliente.h"

ArchivoCliente::ArchivoCliente() : Archivo<Cliente>("clientes.dat"){}

int ArchivoCliente::buscarRegistro(int idCliente) {

    Cliente reg;

    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (reg.getIdCliente() == idCliente) {
            return i;
        }
    }

    return -1;
}

void ArchivoCliente::modificarCliente() {

    int cantidad = contarRegistros();
    int idModificar;
    int posicion;
    bool idValido = false;

    if (cantidad == 0) {
        cout << endl << "--------------------------------------------------" << endl;
        cout << "No hay ningun cliente registrado para modificar." << endl;
        cout << "--------------------------------------------------" << endl;
        return;
    }

    cout << endl << "==================================================" << endl;
    cout << "CLIENTES ACTIVOS DISPONIBLES PARA MODIFICAR:" << endl;
    cout << "==================================================" << endl;
    listarClientes();
    cout << "==================================================" << endl;

    do {
        cout << "Ingrese el ID del cliente a modificar (0 para volver): ";
        cin >> idModificar;

        if (idModificar == 0) {
            return;
        }

        posicion = buscarRegistro(idModificar);

        if (posicion == -1) {
            cout << "El ID " << idModificar << " no corresponde a un cliente registrado." << endl;
            cout << "--------------------------------------------------------------------------" << endl;
        } else {
            Cliente regAux = leerRegistro(posicion);
            if (!regAux.getEstado()) {
                cout << "Ese cliente fue dado de baja del sistema." << endl;
                cout << "--------------------------------------------------------------------------" << endl;
            } else {
                idValido = true;
            }
        }
    } while (!idValido);

    Cliente reg = leerRegistro(posicion);

    cout << endl << "--- MODIFICANDO CLIENTE ID: " << idModificar << " ---" << endl;
    cout << "Ingrese los nuevos datos:" << endl << endl;

    reg.cargarDatosCliente();

    if (modificarRegistro(reg, posicion)) {
        cout << endl << "CLIENTE MODIFICADO" << endl;
    }
}

void ArchivoCliente::eliminarCliente() {

    int cantidad = contarRegistros();
    int idEliminar;
    int posicion;
    bool idValido = false;

    if (cantidad == 0) {
        cout << endl << "--------------------------------------------------" << endl;
        cout << "No hay ningun cliente registrado para eliminar." << endl;
        cout << "--------------------------------------------------" << endl;
        return;
    }

    cout << endl << "==================================================" << endl;
    cout << "CLIENTES ACTIVOS DISPONIBLES PARA ELIMINAR:" << endl;
    cout << "==================================================" << endl;
    listarClientes();
    cout << "==================================================" << endl;

    do {
        cout << "Ingrese el ID del cliente a eliminar (0 para volver): ";
        cin >> idEliminar;

        if (idEliminar == 0) {
            return;
        }

        posicion = buscarRegistro(idEliminar);

        if (posicion == -1) {
            cout << "El ID " << idEliminar << " no corresponde a un cliente registrado." << endl;
            cout << "--------------------------------------------------------------------------" << endl;
        } else {
            Cliente regAux = leerRegistro(posicion);
            if (!regAux.getEstado()) {
                cout << "Ese cliente ya fue dado de baja del sistema." << endl;
                cout << "--------------------------------------------------------------------------" << endl;
            } else {
                idValido = true;
            }
        }
    } while (!idValido);

    Cliente reg = leerRegistro(posicion);

    reg.setEstado(false);

    if (modificarRegistro(reg, posicion)) {
        cout << endl << "CLIENTE ELIMINADO" << endl;
    }
}

void ArchivoCliente::listarClientes() {

    Cliente reg;

    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (reg.getEstado()) {

            reg.mostrarCliente();

            cout << endl;
        }
    }
}

void ArchivoCliente::listarClientesDadosDeBaja() {

    Cliente reg;

    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (!reg.getEstado()) {

            reg.mostrarCliente();

            cout << endl;
        }
    }
}

void ArchivoCliente::listarDirectorioContacto() {

    Cliente reg;

    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (reg.getEstado()) {

            reg.mostrarContacto();

            cout << endl;
        }
    }
}

void ArchivoCliente::mostrarClienteById(int idCliente) {

    int posicion = buscarRegistro(idCliente);

    if (posicion == -1) {

        cout << "CLIENTE NO ENCONTRADO" << endl;
        return;
    }

    Cliente reg = leerRegistro(posicion);

    reg.mostrarCliente();
}

void ArchivoCliente::mostrarClienteByDni(int dni) {

    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        Cliente reg = leerRegistro(i);

        if (reg.getDni() == dni) {
            reg.mostrarCliente();
            return;
        }
    }

    cout << "CLIENTE NO ENCONTRADO" << endl;
}

void ArchivoCliente::mostrarClienteByNombre(const char* nombre){
    int cantidad = contarRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Cliente reg = leerRegistro(i);

        if(strcasecmp(reg.getNombre(), nombre)==0){
            reg.mostrarCliente();
            cout << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
            cout << "CLIENTE NO ENCONTRADO" << endl;
        }

}

void ArchivoCliente::mostrarClienteByApellido(const char* apellido){
    int cantidad = contarRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Cliente reg = leerRegistro(i);

        if(strcasecmp(reg.getApellido(), apellido)==0){
            reg.mostrarCliente();
            cout << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
            cout << "CLIENTE NO ENCONTRADO" << endl;
        }

}

void ArchivoCliente::mostrarClienteByEmail(const char* email){
    int cantidad = contarRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Cliente reg = leerRegistro(i);

        if(strcasecmp(reg.getEmail(), email)==0){
            reg.mostrarCliente();
            cout << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
            cout << "CLIENTE NO ENCONTRADO" << endl;
        }

}

void ArchivoCliente::agregarCliente() {

    Cliente reg;

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdCliente(1);
    } else {
        Cliente ultimo = leerRegistro(cantidad - 1);
        reg.setIdCliente(ultimo.getIdCliente() + 1);
    }

    reg.cargarDatosCliente();

    if (guardarRegistro(reg)) {
        cout << "CLIENTE GUARDADO CORRECTAMENTE (ID " << reg.getIdCliente() << ")" << endl;
    }
    else {
        cout << "ERROR AL GUARDAR CLIENTE" << endl;
    }
}

bool ArchivoCliente::existeCliente(int idCliente) {

    return buscarRegistro(idCliente) != -1;
}
