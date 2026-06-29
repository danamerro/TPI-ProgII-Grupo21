#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#include "archivoGestionVenta.h"
#include "archivoCliente.h"
#include "archivoPaquete.h"
#include "archivoVuelo.h"
#include "helpers.h"

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
    string pad = obtenerPad(61);

    int posicion =
        buscarRegistro(idVenta);

    if (posicion == -1) {
        leyendaSSNoEncontrado("VENTA", 1);
        return;
    }

    GestionVenta reg =
        leerRegistro(posicion);

    reg.mostrarVenta();
}

void ArchivoGestionVenta::mostrarVentasByIdCliente(int idCliente) {
    string pad = obtenerPad(61);

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
        cout << endl << pad << "El cliente no tiene ventas registradas." << endl;
        cout << endl;
    }
}

void ArchivoGestionVenta::mostrarVentasByIdPaquete(int idPaquete) {
    string pad = obtenerPad(61);

    int cantidad = contarRegistros();
    bool encontrada = false;

    for (int i = 0; i < cantidad; i++) {
        GestionVenta reg = leerRegistro(i);

        if (reg.getIdPaquete() == idPaquete) {
            reg.mostrarVenta();
            cout << endl;
            encontrada = true;
        }
    }

    if (!encontrada) {
        cout << endl << pad << "No hay ventas registradas para ese paquete." << endl;
        cout << endl;
    }
}

void ArchivoGestionVenta::mostrarVentasByFechaVenta(const char* fecha) {
    string pad = obtenerPad(61);

    int cantidad = contarRegistros();
    bool encontrada = false;

    for (int i = 0; i < cantidad; i++) {
        GestionVenta reg = leerRegistro(i);

        if (strcmp(reg.getFechaVenta(), fecha) == 0) {
            reg.mostrarVenta();
            cout << endl;
            encontrada = true;
        }
    }

    if (!encontrada) {
        cout << endl << pad << "No hay ventas registradas en esa fecha." << endl;
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
    int ventaNoConfirmada = 0;

    int cantidad = contarRegistros();

    if(cantidad == 0 ){
        leyendaSSNoEncontrado("VENTAS", 3);
    } else {
        for (int i = 0; i < cantidad; i++) {

            reg = leerRegistro(i);

            if (reg.getEstado() && reg.getEstadoVenta() == 1) {

                reg.mostrarVenta();

                cout << endl;
            } else {
                ventaNoConfirmada ++;
            }
        }
        if(ventaNoConfirmada == 0){
            leyendaSSNoEncontrado("VENTA", 3);
        }
    }
}

void ArchivoGestionVenta::listarTransaccionesCanceladas() {

    GestionVenta reg;
    int ventaNoCanceladas = 0;

    int cantidad =
        contarRegistros();

    if(cantidad == 0 ){
        leyendaSSNoEncontrado("VENTAS", 3);
    } else {
        for (int i = 0; i < cantidad; i++) {

            reg = leerRegistro(i);

            if (
                reg.getEstado() &&
                reg.getEstadoVenta() == 2
            ) {

                reg.mostrarVenta();
                cout << endl;
            } else {
                ventaNoCanceladas++;
            }
        }
         if(ventaNoCanceladas == 0){
            leyendaSSNoEncontrado("VENTA", 3);
        }
    }
}

void ArchivoGestionVenta::listarTransaccionesPendientes() {

    GestionVenta reg;

    int ventasNoPendientes = 0;

    int cantidad =
        contarRegistros();

    if(cantidad == 0){
        leyendaSSNoEncontrado("VENTAS", 3);
    } else {

        for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if ( reg.getEstado() && reg.getEstadoVenta() == 0) {
            reg.mostrarVenta();
            cout << endl;
        } else {
            ventasNoPendientes ++;
        }
      }
      if(ventasNoPendientes == 0){
        leyendaSSNoEncontrado("VENTA", 3);
      }
    }
}

void ArchivoGestionVenta::agregarVenta() {

    GestionVenta reg;
    GestionVenta archivo;

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdVenta(1);
    } else {
        archivo = leerRegistro(cantidad - 1);
        reg.setIdVenta(archivo.getIdVenta() + 1);
    }

    string pad = obtenerPad(61);
    int verLista;
    int idCliente;
    int idPaquete;

    cout << endl << pad << "Conoce el ID del cliente?" << endl;
    cout << pad << "1. Si, ya lo tengo" << endl;
    cout << pad << "2. No, ver lista de clientes activos" << endl;
    cout << pad << "Opcion: ";
    cin >> verLista;

    if (verLista == 2) {
        ArchivoCliente archivoCliente;

        if (!archivoCliente.hayClientesActivos()) {
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            cout << pad << "        NO HAY CLIENTES ACTIVOS REGISTRADOS EN EL SISTEMA    " << endl;
            cout << pad << "-------------------------------------------------------------" << endl;
            cout << pad << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
            return;
        }

        cout << endl << pad << "------------------- CLIENTES ACTIVOS ------------------------" << endl;
        archivoCliente.listarClientes();
        cout << pad << "-------------------------------------------------------------" << endl;
    }

    cout << endl << pad << "Ingrese el ID del cliente (0 para volver): ";
    cin >> idCliente;
    if (idCliente == 0) {
        cout << endl << pad << "OPERACION CANCELADA." << endl;
        cout << pad << "Presione Enter para continuar...";
        cin.ignore();
        cin.get();
        return;
    }

    reg.setIdCliente(idCliente);

    cout << endl << pad << "Conoce el ID del paquete?" << endl;
    cout << pad << "1. Si, ya lo tengo" << endl;
    cout << pad << "2. No, ver lista de paquetes activos" << endl;
    cout << pad << "Opcion: ";
    cin >> verLista;

    if (verLista == 2) {
        ArchivoPaquete archivoPaquetes;
        cout << endl << pad << "------------------- PAQUETES ACTIVOS ------------------------" << endl;
        archivoPaquetes.listarPaquetes();
        cout << pad << "-------------------------------------------------------------" << endl;
    }

    cout << endl << pad << "Ingrese el ID del paquete: ";
    cin >> idPaquete;
    reg.setIdPaquete(idPaquete);

    reg.cargarDatosVenta();

    ArchivoPaquete archivoPaquete;
    ArchivoVuelo archivoVuelo;
    Paquete paq = archivoPaquete.obtenerPaquetePorId(reg.getIdPaquete());
    Vuelo   vue = archivoVuelo.obtenerVueloPorId(paq.getIdVuelo());

    reg.setPrecioUnitario(paq.getPrecio());
    reg.setTotal(reg.calcularTotal());

    if (guardarRegistro(reg)) {
        cout << endl;
        cout << pad << "=============================================================" << endl;
        cout << pad << "                VENTA REGISTRADA CORRECTAMENTE               " << endl;
        cout << pad << "=============================================================" << endl;

        ArchivoCliente archivoCli;
        Cliente cli = archivoCli.obtenerClientePorId(reg.getIdCliente());
        reg.emitirTicket("RESERVA", vue.getFechaVuelo(), cli, paq.getDestino());
    }
    else {
    cout << endl << pad << "=============================================================" << endl;
            cout << pad << "                ERROR AL GUARDAR LA VENTA                    "<< endl;
            cout << pad << "=============================================================" << endl;
    }
    cin.ignore();
    limpiarPantalla();
}

bool ArchivoGestionVenta::existeVenta(int idVenta) {

    return buscarRegistro(idVenta) != -1;
}

void ArchivoGestionVenta::confirmarVenta(int idVenta) {
    string pad = obtenerPad(61);

    int posicion =
        buscarRegistro(idVenta);

    if (posicion == -1) {
        leyendaSSNoEncontrado("VENTA", 1);
        cin.ignore();
        limpiarPantalla();
        return;
    }

    GestionVenta reg =
        leerRegistro(posicion);

    reg.confirmarVenta();

    if (modificarRegistro(reg, posicion)) {
    cout << endl << pad << "=============================================================" << endl;
            cout << pad << "                    VENTA CONFIRMADA                         "<< endl;
            cout << pad << "=============================================================" << endl;

        ArchivoPaquete archivoPaquete;
        ArchivoVuelo archivoVuelo;
        Paquete paq = archivoPaquete.obtenerPaquetePorId(reg.getIdPaquete());
        Vuelo   vue = archivoVuelo.obtenerVueloPorId(paq.getIdVuelo());
        ArchivoCliente archivoCli;
        Cliente cli = archivoCli.obtenerClientePorId(reg.getIdCliente());
        reg.emitirTicket("CONFIRMACION", vue.getFechaVuelo(), cli, paq.getDestino());
    }
    cin.ignore();
    limpiarPantalla();
}

void ArchivoGestionVenta::cancelarVenta(int idVenta) {
    string pad = obtenerPad(61);

    int posicion = buscarRegistro(idVenta);

    if (posicion == -1) {
        leyendaSSNoEncontrado("VENTA", 1);
        cin.ignore();
        limpiarPantalla();
        return;
    }

    GestionVenta reg = leerRegistro(posicion);

    reg.cancelarVenta();

    if (modificarRegistro(reg, posicion)) {
    cout << endl << pad << "=============================================================" << endl;
            cout << pad << "                    VENTA CANCELADA                          "<< endl;
            cout << pad << "=============================================================" << endl;
    }

    cin.ignore();
    limpiarPantalla();
}
