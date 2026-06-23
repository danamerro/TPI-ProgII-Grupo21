#include <iostream>
#include <cstring>

using namespace std;

#include "gestionVenta.h"
#include "cliente.h"

GestionVenta::GestionVenta() {

    _idVenta = 0;
    _idCliente = 0;
    _idPaquete = 0;

    strcpy(_fechaVenta, "");
    //strcpy(_fechaViaje, "");

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
/*
const char* GestionVenta::getFechaViaje() const {
    return _fechaViaje;
}

void GestionVenta::setFechaViaje(const char* fechaViaje) {
    strcpy(_fechaViaje, fechaViaje);
}
*/
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

    cin.ignore();
    cout << "Ingrese Fecha Venta (dd/mm/yyyy): ";
    cin.getline(_fechaVenta, 11);

    cout << "Ingrese Cantidad de Cupos(personas que van a viajar): ";
    cin >> _cantidadCupos;

    _estadoVenta = 0;
    // Pendiente a charlar, poder manejar los estados como:
    //0 = Pendiente
    //1 = Confirmada
    //2 = Cancelada

    _estado = true;
}

void GestionVenta::confirmarVenta() {
    _estadoVenta = 1;
}

void GestionVenta::cancelarVenta() {
    _estadoVenta = 2;
}

void GestionVenta::emitirTicket(const char* tipo, const char* fechaVuelo, Cliente cliente, const char* destino) {

    cout << endl;
    cout << "===================================" << endl;
    cout << "        TICKET DE " << tipo << endl;
    cout << "===================================" << endl;
    cout << endl;

    cout << "-- DATOS DEL CLIENTE --" << endl;
    cout << "Cliente:  " << cliente.getNombre() << " " << cliente.getApellido() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;
    cout << "Email:    " << cliente.getEmail() << endl;
    cout << endl;

    cout << "-- DATOS DEL VIAJE --" << endl;
    cout << "Destino:     " << destino << endl;
    cout << "Fecha Venta: " << _fechaVenta << endl;
    cout << "Fecha Vuelo: " << fechaVuelo << endl;
    cout << endl;

    cout << "-- DETALLE --" << endl;
    cout << "Cantidad Cupos:  " << _cantidadCupos << endl;
    cout << "Precio Unitario: $" << _precioUnitario << endl;
    cout << "Total: " << _cantidadCupos << " x $" << _precioUnitario << " = $" << _total << endl;

    cout << "===================================" << endl;
    cout << endl;
}

void GestionVenta::mostrarVenta() const {

    cout << "ID Venta: " << _idVenta << endl;
    cout << "ID Cliente: " << _idCliente << endl;
    cout << "ID Paquete: " << _idPaquete << endl;

    cout << "Fecha Venta: " << _fechaVenta << endl;

    //cout << "Fecha Viaje: " << _fechaViaje << endl;

    cout << "Cantidad Cupos: " << _cantidadCupos << endl;

    cout << "Precio Unitario: $" << _precioUnitario << endl;
    cout << "Total: $" << _total << endl;

    cout << "Estado Venta: " << _estadoVenta << endl;
    cout << "Estado: " << _estado << endl;
}
