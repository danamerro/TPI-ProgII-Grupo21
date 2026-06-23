#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#include "archivoCliente.h"
#include "cliente.h"
#include "helpers.h"

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

    string pad = obtenerPad(61);
    int cantidad = contarRegistros();
    int idModificar;
    int posicion;
    bool idValido = false;

    if (cantidad == 0) {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
        cout << pad << "        No hay ningun cliente registrado para modificar.     " << endl;
        cout << pad << "-------------------------------------------------------------" << endl;
        return;
    }

    cout << endl << pad << "=============================================================" << endl;
    cout << pad << "        CLIENTES ACTIVOS DISPONIBLES PARA MODIFICAR:         " << endl;
    cout << pad << "=============================================================" << endl;
    listarClientes();
    cout << pad << "=============================================================" << endl;

    do {
        cout << endl << pad << "Ingrese el ID del cliente a modificar (0 para volver): ";
        cin >> idModificar;

        if (idModificar == 0) {
            return;
        }

        posicion = buscarRegistro(idModificar);

        if (posicion == -1) {
            cout << pad << "El ID " << idModificar << " no corresponde a un cliente registrado." << endl;
            cout << pad << "-------------------------------------------------------------" << endl;
        } else {
            Cliente regAux = leerRegistro(posicion);
            if (!regAux.getEstado()) {
                cout << pad << "Ese cliente fue dado de baja del sistema." << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
            } else {
                idValido = true;
            }
        }
    } while (!idValido);

    Cliente reg = leerRegistro(posicion);

    leyendaingresoNuevosDatos();

    reg.cargarDatosCliente();

    if (modificarRegistro(reg, posicion)) {
        leyendaSSModificado("CLIENTE", 2);
    }
}

void ArchivoCliente::eliminarCliente() {

    string pad = obtenerPad(61);
    int cantidad = contarRegistros();
    int idEliminar;
    int posicion;
    bool idValido = false;

    if (cantidad == 0) {
        cout << endl << pad << "-------------------------------------------------------------" << endl;
        cout << pad << "        No hay ningun cliente registrado para eliminar.      " << endl;
        cout << pad << "-------------------------------------------------------------" << endl;
        return;
    }

    cout << endl << pad << "=============================================================" << endl;
    cout << pad << "        CLIENTES ACTIVOS DISPONIBLES PARA ELIMINAR:          " << endl;
    cout << pad << "=============================================================" << endl;
    listarClientes();
    cout << pad << "=============================================================" << endl;

    do {
        cout << endl << pad << "Ingrese el ID del cliente a eliminar (0 para volver): ";
        cin >> idEliminar;

        if (idEliminar == 0) {
            return;
        }

        posicion = buscarRegistro(idEliminar);

        if (posicion == -1) {
            cout << pad << "El ID " << idEliminar << " no corresponde a un cliente registrado." << endl;
            cout << pad << "-------------------------------------------------------------" << endl;
        } else {
            Cliente regAux = leerRegistro(posicion);
            if (!regAux.getEstado()) {
                cout << pad << "Ese cliente ya fue dado de baja del sistema." << endl;
                cout << pad << "-------------------------------------------------------------" << endl;
            } else {
                idValido = true;
            }
        }
    } while (!idValido);

    Cliente reg = leerRegistro(posicion);

    reg.setEstado(false);

    if (modificarRegistro(reg, posicion)) {
        leyendaSSEliminado("CLIENTE", 2);
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

    string pad = obtenerPad(61);
    int posicion = buscarRegistro(idCliente);

    if (posicion == -1) {

        cout << endl << pad << "CLIENTE NO ENCONTRADO" << endl;
        return;
    }

    Cliente reg = leerRegistro(posicion);

    reg.mostrarCliente();
}

void ArchivoCliente::mostrarClienteByDni(int dni) {

    string pad = obtenerPad(61);
    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        Cliente reg = leerRegistro(i);

        if (reg.getDni() == dni) {
            reg.mostrarCliente();
            return;
        }
    }

    cout << endl << pad << "CLIENTE NO ENCONTRADO" << endl;
}

void ArchivoCliente::mostrarClienteByNombre(const char* nombre){
    string pad = obtenerPad(61);
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
            cout << endl << pad << "CLIENTE NO ENCONTRADO" << endl;
        }

}

void ArchivoCliente::mostrarClienteByApellido(const char* apellido){
    string pad = obtenerPad(61);
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
            cout << endl << pad << "CLIENTE NO ENCONTRADO" << endl;
        }

}

void ArchivoCliente::mostrarClienteByEmail(const char* email){
    string pad = obtenerPad(61);
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
            cout << endl << pad << "CLIENTE NO ENCONTRADO" << endl;
        }

}

void ArchivoCliente::mostrarClienteByEstado(bool estado){
    string pad = obtenerPad(61);
    int cantidad = contarRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Cliente reg = leerRegistro(i);

        if(reg.getEstado()== estado){
            reg.mostrarCliente();
            cout << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
            cout << endl << pad << "CLIENTE NO ENCONTRADO" << endl;
        }

}

void ArchivoCliente::mostrarClienteByDireccion(const char* direccion){
    string pad = obtenerPad(61);
    int cantidad = contarRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Cliente reg = leerRegistro(i);

        if(strcasecmp(reg.getDireccion(), direccion)==0){
            reg.mostrarCliente();
            cout << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
            cout << endl << pad << "CLIENTE NO ENCONTRADO" << endl;
        }

}

void ArchivoCliente::mostrarClienteByTelefono(int telefono){
    string pad = obtenerPad(61);
    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        Cliente reg = leerRegistro(i);

        if(reg.getTelefono()== telefono){
            reg.mostrarCliente();
            return;
        }
    }
    cout << endl << pad << "CLIENTE NO ENCONTRADO" << endl;
}

void ArchivoCliente::agregarCliente() {

    string pad = obtenerPad(61);
    Cliente reg;
    Cliente archivo;

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdCliente(1);
    } else {
        archivo = leerRegistro(cantidad - 1);
        reg.setIdCliente(archivo.getIdCliente()+1);
    }

    reg.cargarDatosCliente();

    if (guardarRegistro(reg)) {
        leyendaSSGuardado("CLIENTE", 2);
        cout << pad << "Presione Enter para continuar...";
        cin.get();
    }
    else {
        leyendaSSErrorAlGuardar("CLIENTE");
        cin.get();
    }
}

bool ArchivoCliente::existeCliente(int idCliente) {

    return buscarRegistro(idCliente) != -1;
}

Cliente ArchivoCliente::obtenerClientePorId(int idCliente) {
    int pos = buscarRegistro(idCliente);
    if (pos == -1) {
        return Cliente();
    }
    return leerRegistro(pos);
}
