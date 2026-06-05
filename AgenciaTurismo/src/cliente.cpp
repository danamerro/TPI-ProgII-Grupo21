#include <iostream>
#include <cstring>

using namespace std;

#include "cliente.h"

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

void Cliente::setID(int valor){
    _idCliente = valor;
}

int Cliente::getID() const{
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

void Cliente::cargarCliente(){

    cout<<"ID: ";
    cin>>_idCliente;

    cout<<"DNI: ";
    cin>>_dni;

    cin.ignore();

    cout<<"Nombre: ";
    cin.getline(_nombre,20);

    cout<<"Apellido: ";
    cin.getline(_apellido,20);

    cout<<"Telefono: ";
    cin>>_telefono;

    cin.ignore();

    cout<<"Direccion: ";
    cin.getline(_direccion,20);

    cout<<"Email: ";
    cin.getline(_email,20);

    _estado = true;
}

void Cliente::mostrarCliente() const{

    cout<<"ID: "<<_idCliente<<endl;
    cout<<"DNI: "<<_dni<<endl;
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Apellido: "<<_apellido<<endl;
    cout<<"Telefono: "<<_telefono<<endl;
    cout<<"Direccion: "<<_direccion<<endl;
    cout<<"Email: "<<_email<<endl;
}
