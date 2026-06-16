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

void ArchivoCliente::modificarCliente(int idCliente) {

    int posicion = buscarRegistro(idCliente);

    if (posicion == -1) {

        cout << "CLIENTE NO ENCONTRADO" << endl;
        return;
    }

    Cliente reg = leerRegistro(posicion);

    cout << endl;
    cout << "INGRESE LOS NUEVOS DATOS" << endl;
    cout << endl;

    reg.cargarCliente();

    if (modificarRegistro(reg, posicion)) {
        cout << "CLIENTE MODIFICADO" << endl;
    }
}

void ArchivoCliente::eliminarCliente(int idCliente) {

    int posicion = buscarRegistro(idCliente);

    if (posicion == -1) {

        cout << "CLIENTE NO ENCONTRADO" << endl;
        return;
    }

    Cliente reg = leerRegistro(posicion);

    reg.setEstado(false);

    if (modificarRegistro(reg, posicion)) {
        cout << "CLIENTE ELIMINADO" << endl;
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

void ArchivoCliente::agregarCliente() {

    Cliente reg;

    int id;
    cout << "Ingrese ID del cliente: ";
    cin >> id;

    if (existeCliente(id)){
        cout << "YA EXISTE UN CLIENTE CON ESE ID" << endl;
        return;
    }

    reg.setIdCliente(id);
    reg.cargarDatosCliente();

    if (guardarRegistro(reg)) {
        cout << "CLIENTE GUARDADO CORRECTAMENTE" << endl;
    }
    else {
        cout << "ERROR AL GUARDAR CLIENTE" << endl;
    }
}

bool ArchivoCliente::existeCliente(int idCliente) {

    return buscarRegistro(idCliente) != -1;
}
