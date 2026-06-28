#include <iostream>
#include <cstring>

using namespace std;

#include "gestionVenta.h"
#include "cliente.h"
#include "helpers.h"

GestionVenta::GestionVenta() {

    _idVenta = 0;
    _idCliente = 0;
    _idPaquete = 0;

    strcpy(_fechaVenta, "");

    _cantidadCupos = 0;
    _precioUnitario = 0;
    _total = 0;
    _estadoVenta = 0;
    _estado = true;
}

int GestionVenta::getIdVenta() const {
    return _idVenta;
}

void GestionVenta::setIdVenta(int idVenta) {
    _idVenta = idVenta;
}

int GestionVenta::getIdCliente() const {
    return _idCliente;
}

void GestionVenta::setIdCliente(int idCliente) {
    _idCliente = idCliente;
}

int GestionVenta::getIdPaquete() const {
    return _idPaquete;
}

void GestionVenta::setIdPaquete(int idPaquete) {
    _idPaquete = idPaquete;
}

const char* GestionVenta::getFechaVenta() const {
    return _fechaVenta;
}

void GestionVenta::setFechaVenta(const char* fechaVenta) {
    strcpy(_fechaVenta, fechaVenta);
}

int GestionVenta::getCantidadCupos() const {
    return _cantidadCupos;
}

void GestionVenta::setCantidadCupos(int cantidadCupos) {
    _cantidadCupos = cantidadCupos;
}

float GestionVenta::getPrecioUnitario() const {
    return _precioUnitario;
}

void GestionVenta::setPrecioUnitario(float precioUnitario) {
    _precioUnitario = precioUnitario;
}

float GestionVenta::getTotal() const {
    return _total;
}

void GestionVenta::setTotal(float total) {
    _total = total;
}

int GestionVenta::getEstadoVenta() const {
    return _estadoVenta;
}

void GestionVenta::setEstadoVenta(int estadoVenta) {
    _estadoVenta = estadoVenta;
}

bool GestionVenta::getEstado() const {
    return _estado;
}

void GestionVenta::setEstado(bool estado) {
    _estado = estado;
}

float GestionVenta::calcularTotal() {
    return _cantidadCupos * _precioUnitario;
}

void GestionVenta::cargarDatosVenta() {
    string pad = obtenerPad(61);

    cin.ignore();
    cout << pad << "Ingrese Fecha Venta (dd/mm/yyyy): ";
    cin.getline(_fechaVenta, 11);

    cout << pad << "Ingrese Cantidad de Cupos(personas que van a viajar): ";
    cin >> _cantidadCupos;

    setEstadoVenta(0);
    setEstado(true);
}

void GestionVenta::confirmarVenta() {
    setEstadoVenta(1);
}

void GestionVenta::cancelarVenta() {
    setEstadoVenta(2);
}

void GestionVenta::emitirTicket(const char* tipo, const char* fechaVuelo, Cliente cliente, const char* destino) {
    string pad = obtenerPad(61);

    cout << endl;
    cout << pad << "=============================================================" << endl;
    cout << pad << "                      TICKET DE " << tipo << endl;
    cout << pad << "=============================================================" << endl;
    cout << endl;

    cout << pad << "-- DATOS DEL CLIENTE --" << endl;
    cout << pad << "Cliente:  " << cliente.getNombre() << " " << cliente.getApellido() << endl;
    cout << pad << "Telefono: " << cliente.getTelefono() << endl;
    cout << pad << "Email:    " << cliente.getEmail() << endl;
    cout << endl;

    cout << pad << "-- DATOS DEL VIAJE --" << endl;
    cout << pad << "Destino:     " << destino << endl;
    cout << pad << "Fecha Venta: " << _fechaVenta << endl;
    cout << pad << "Fecha Vuelo: " << fechaVuelo << endl;
    cout << endl;

    cout << pad << "-- DETALLE --" << endl;
    cout << pad << "Cantidad Cupos:  " << _cantidadCupos << endl;
    cout << pad << "Precio Unitario: $" << _precioUnitario << endl;
    cout << pad << "Total: " << _cantidadCupos << " x $" << _precioUnitario << " = $" << _total << endl;

    cout << pad << "=============================================================" << endl;
    cout << endl;
}

void GestionVenta::mostrarVenta() const {
    string pad = obtenerPad(61);

    string estadoTexto;
    if (getEstadoVenta() == 0) {
        estadoTexto = "Pendiente";
    } else if (_estadoVenta == 1) {
        estadoTexto = "Confirmada";
    } else if (_estadoVenta == 2) {
        estadoTexto = "Cancelada";
    } else {
        estadoTexto = "Desconocido";
    }

    cout << endl << pad << "ID Venta: " << _idVenta << endl;
    cout << pad << "ID Cliente: " << _idCliente << endl;
    cout << pad << "ID Paquete: " << _idPaquete << endl;
    cout << pad << "Fecha Venta: " << _fechaVenta << endl;
    cout << pad << "Cantidad Cupos: " << _cantidadCupos << endl;
    cout << pad << "Precio Unitario: $" << _precioUnitario << endl;
    cout << pad << "Total: $" << _total << endl;
    cout << pad << "Estado de la venta: " << estadoTexto << endl;
}
