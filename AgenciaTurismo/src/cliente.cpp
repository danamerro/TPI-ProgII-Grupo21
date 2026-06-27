#include <iostream>
#include <cstring>

using namespace std;

#include "cliente.h"
#include "helpers.h"

Cliente::Cliente() {
    _idCliente = 0;
    _dni = 0;
    _telefono = 0;

    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_direccion, "");
    strcpy(_email, "");

    _estado = true;
}

void Cliente::setIdCliente(int valor){
    _idCliente = valor;
}

int Cliente::getIdCliente() const{
    return _idCliente;
}

void Cliente::setDni(int valor){
    _dni = valor;
}

int Cliente::getDni() const{
    return _dni;
}

void Cliente::setNombre(const char* valor){
    strcpy(_nombre, valor);
}

const char* Cliente::getNombre() const{
    return _nombre;
}

void Cliente::setApellido(const char* valor){
    strcpy(_apellido, valor);
}

const char* Cliente::getApellido() const{
    return _apellido;
}

void Cliente::setTelefono(int valor){
    _telefono = valor;
}

int Cliente::getTelefono() const{
    return _telefono;
}

void Cliente::setDireccion(const char* valor){
    strcpy(_direccion, valor);
}

const char* Cliente::getDireccion() const{
    return _direccion;
}

void Cliente::setEmail(const char* valor){
    strcpy(_email, valor);
}

const char* Cliente::getEmail() const{
    return _email;
}

void Cliente::setEstado(bool valor){
    _estado = valor;
}

bool Cliente::getEstado() const{
    return _estado;
}

void Cliente::cargarDatosCliente(){
    string pad = obtenerPad(61);

    _dni = numeroValido(pad + "Ingrese dni del cliente: ");

    cout << pad << "Ingrese nombre del cliente: ";
    cin.getline(_nombre, 20);

    cout << pad << "Ingrese apellido del cliente: ";
    cin.getline(_apellido, 20);


    _telefono = floatValido(pad + "Ingrese telefono del cliente: ");

    cout << pad << "Ingrese direccion del cliente: ";
    cin.getline(_direccion, 50);

    cout << pad << "Ingrese email del cliente: ";
    cin.getline(_email, 20);

    setEstado(true);
}

void Cliente::mostrarCliente() const{
    string pad = obtenerPad(61);

    cout << endl << pad << "ID: " << _idCliente << endl;
    cout << pad << "DNI: " << _dni << endl;
    cout << pad << "Nombre: " << _nombre << endl;
    cout << pad << "Apellido: " << _apellido << endl;
    cout << pad << "Telefono: " << _telefono << endl;
    cout << pad << "Direccion: " << _direccion << endl;
    cout << pad << "Email: " << _email << endl;
}

void Cliente::mostrarContacto() const{
    string pad = obtenerPad(61);

    cout << endl << pad << "Nombre: " << _nombre << " " << _apellido << endl;
    cout << pad << "Telefono: " << _telefono << endl;
    cout << pad << "Email: " << _email << endl;
    cout << pad << "Direccion: " << _direccion << endl;
}
