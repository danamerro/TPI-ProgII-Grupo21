#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#include "archivoCliente.h"

ArchivoCliente::ArchivoCliente() {
    strcpy(_nombreArchivo, "clientes.dat");
}

// Métodos auxiliares internos

bool ArchivoCliente::guardarRegistro(Cliente reg) {

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "ab");

    if (pFile == nullptr) {
        return false;
    }

    bool escribio =
        fwrite(&reg, sizeof(Cliente), 1, pFile);

    fclose(pFile);

    return escribio;
}

Cliente ArchivoCliente::leerRegistro(int posicion) {

    Cliente reg;

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return reg;
    }

    fseek(
        pFile,
        sizeof(Cliente) * posicion,
        SEEK_SET
    );

    fread(
        &reg,
        sizeof(Cliente),
        1,
        pFile
    );

    fclose(pFile);

    return reg;
}

int ArchivoCliente::contarRegistros() {

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    int cantidad =
        ftell(pFile) / sizeof(Cliente);

    fclose(pFile);

    return cantidad;
}

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


// Métodos pactados por diagrama (paso3)

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

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb+");

    if (pFile == nullptr) {
        return;
    }

    fseek(
        pFile,
        sizeof(Cliente) * posicion,
        SEEK_SET
    );

    fwrite(
        &reg,
        sizeof(Cliente),
        1,
        pFile
    );

    fclose(pFile);

    cout << "CLIENTE MODIFICADO" << endl;
}

void ArchivoCliente::eliminarCliente(int idCliente) {

    int posicion = buscarRegistro(idCliente);

    if (posicion == -1) {

        cout << "CLIENTE NO ENCONTRADO" << endl;
        return;
    }

    Cliente reg = leerRegistro(posicion);

    reg.setEstado(false);

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb+");

    if (pFile == nullptr) {
        return;
    }

    fseek(
        pFile,
        sizeof(Cliente) * posicion,
        SEEK_SET
    );

    fwrite(
        &reg,
        sizeof(Cliente),
        1,
        pFile
    );

    fclose(pFile);

    cout << "CLIENTE ELIMINADO" << endl;
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

void ArchivoCliente::mostrarClienteById(int idCliente) {

    int posicion = buscarRegistro(idCliente);

    if (posicion == -1) {

        cout << "CLIENTE NO ENCONTRADO" << endl;
        return;
    }

    Cliente reg = leerRegistro(posicion);

    reg.mostrarCliente();
}

// Metodo agregados (utiles)

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
