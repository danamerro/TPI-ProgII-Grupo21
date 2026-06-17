#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#include "archivoGestionVenta.h"

ArchivoGestionVenta::ArchivoGestionVenta() : Archivo<GestionVenta>("ventas.dat"){}

int ArchivoGestionVenta::buscarRegistro(int idVenta) {

    GestionVenta reg;

    int cantidad =
        contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (
            reg.getIdVenta() == idVenta
        ) {
            return i;
        }
    }

    return -1;
}

void ArchivoGestionVenta::mostrarVentaByID(int idVenta) {

    int posicion =
        buscarRegistro(idVenta);

    if (posicion == -1) {

        cout
            << "VENTA NO ENCONTRADA"
            << endl;

        return;
    }

    GestionVenta reg =
        leerRegistro(posicion);

    reg.mostrarVenta();
}

void ArchivoGestionVenta::mostrarVentasByIdCliente(int idCliente) {

    int cantidad = contarRegistros();
    bool encontrada = false;

    for (int i = 0; i < cantidad; i++) {
        GestionVenta reg = leerRegistro(i);

        if (reg.getIdCliente() == idCliente) {
            reg.mostrarVenta();
            cout << endl;
            encontrada = true;
        }
    }

    if (!encontrada) {
        cout << "El cliente no tiene ventas registradas." << endl;
    }
}

void ArchivoGestionVenta::listarVentas() {

    GestionVenta reg;

    int cantidad =
        contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (reg.getEstado()) {

            reg.mostrarVenta();

            cout << endl;
        }
    }
}

void ArchivoGestionVenta::listarTransaccionesFinalizadas() {

    GestionVenta reg;

    int cantidad =
        contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (
            reg.getEstado() &&
            reg.getEstadoVenta() == 1
        ) {

            reg.mostrarVenta();

            cout << endl;
        }
    }
}

void ArchivoGestionVenta::listarTransaccionesCanceladas() {

    GestionVenta reg;

    int cantidad =
        contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (
            reg.getEstado() &&
            reg.getEstadoVenta() == 2
        ) {

            reg.mostrarVenta();

            cout << endl;
        }
    }
}

void ArchivoGestionVenta::listarTransaccionesPendientes() {

    GestionVenta reg;

    int cantidad =
        contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (
            reg.getEstado() &&
            reg.getEstadoVenta() == 0
        ) {

            reg.mostrarVenta();

            cout << endl;
        }
    }
}

void ArchivoGestionVenta::agregarVenta() {

    GestionVenta reg;

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdVenta(1);
    } else {
        GestionVenta ultima = leerRegistro(cantidad - 1);
        reg.setIdVenta(ultima.getIdVenta() + 1);
    }

    reg.crearDatosVenta();

    if (
        guardarRegistro(reg)
    ) {
        cout
            << "VENTA REGISTRADA (ID " << reg.getIdVenta() << ")"
            << endl;
    }
    else {
        cout
            << "ERROR AL GUARDAR"
            << endl;
    }
}

bool ArchivoGestionVenta::existeVenta(int idVenta) {

    return buscarRegistro(idVenta) != -1;
}

void ArchivoGestionVenta::confirmarVenta(int idVenta) {

    int posicion =
        buscarRegistro(idVenta);

    if (posicion == -1) {

        cout
            << "VENTA NO ENCONTRADA"
            << endl;

        return;
    }

    GestionVenta reg =
        leerRegistro(posicion);

    reg.confirmarVenta();

    if (modificarRegistro(reg, posicion)) {
        cout << "VENTA CONFIRMADA" << endl;
    }
}

void ArchivoGestionVenta::cancelarVenta(int idVenta) {

    int posicion =
        buscarRegistro(idVenta);

    if (posicion == -1) {

        cout
            << "VENTA NO ENCONTRADA"
            << endl;

        return;
    }

    GestionVenta reg =
        leerRegistro(posicion);

    reg.cancelarVenta();

    if (modificarRegistro(reg, posicion)) {
        cout << "VENTA CANCELADA" << endl;
    }
}
