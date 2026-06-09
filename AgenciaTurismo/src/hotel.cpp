#include "hotel.h"

#include <iostream>
#include <cstring>

using namespace std;


Hotel::Hotel() {
    _idHotel = 0;
    _costo = 0;

    strcpy(_nombre, "");
    strcpy(_estrellas, "");
    strcpy(_direccion, "");
    strcpy(_descripcion, "");

    _estado = true;
}

void Hotel::setIdHotel(int valor){
    _idHotel = valor;
}

int Hotel::getIdHotel() const{
    return _idHotel;
}

void Hotel::setNombre(const char* valor){
    strcpy(_nombre, valor);
}

const char* Hotel::getNombre() const{
    return _nombre;
}

void Hotel::setEstrellas(const char* valor){
    strcpy(_estrellas, valor);
}

const char* Hotel::getEstrellas() const{
    return _estrellas;
}

void Hotel::setDireccion(const char* valor){
    strcpy(_direccion, valor);
}

const char* Hotel::getDireccion() const{
    return _direccion;
}

void Hotel::setCosto(float valor){
    _costo = valor;
}

float Hotel::getCosto() const{
    return _costo;
}

void Hotel::setDescripcion(const char* valor){
    strcpy(_descripcion, valor);
}

const char* Hotel::getDescripcion() const{
    return _descripcion;
}

void Hotel::setEstado(bool valor){
    _estado = valor;
}

bool Hotel::getEstado() const{
    return _estado;
}

void Hotel::cargarHotel(){
    cout << "Ingrese ID del hotel: ";
    cin >> _idHotel;

    cout << "Ingrese costo del hotel: ";
    cin >> _costo;

    cin.ignore();

    cout << "Ingrese nombre del hotel: ";
    cin.getline(_nombre, 30);

    cout << "Ingrese estrellas del hotel: ";
    cin.getline(_estrellas, 30);

    cout << "Ingrese direccion del hotel: ";
    cin.getline(_direccion, 30);

    cout << "Ingrese descripcion del hotel: ";
    cin.getline(_descripcion, 250);

    _estado = true;
}

void Hotel::mostrarHotel() const{
    if (_estado == true) {
        cout << "ID hotel: " << _idHotel << endl;
        cout << "Nombre: " << _nombre << endl;
        cout << "Estrellas: " << _estrellas << endl;
        cout << "Direccion: " << _direccion << endl;
        cout << "Costo: " << _costo << endl;
        cout << "Descripcion: " << _descripcion << endl;
        cout << "Estado: " << _estado << endl;
    }
}

void Hotel::cargarDatosHotel(){
    cout << "Ingrese costo del hotel: ";
    cin >> _costo;

    cin.ignore();

    cout << "Ingrese nombre del hotel: ";
    cin.getline(_nombre, 30);

    cout << "Ingrese estrellas del hotel: ";
    cin.getline(_estrellas, 30);

    cout << "Ingrese direccion del hotel: ";
    cin.getline(_direccion, 30);

    cout << "Ingrese descripcion del hotel: ";
    cin.getline(_descripcion, 150);

    _estado = true;

}
