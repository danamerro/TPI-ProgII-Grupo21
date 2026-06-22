#include "hotel.h"
#include <iostream>
#include <cstring>
#include "helpers.h"

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

void Hotel::mostrarHotel() const{
    string pad = obtenerPad(61);

    cout << endl << pad << "ID Hotel: " << _idHotel << endl;
    cout << pad << "Nombre: " << _nombre << endl;
    cout << pad << "Estrellas: " << _estrellas << endl;
    cout << pad << "Direccion: " << _direccion << endl;
    cout << pad << "Descripcion: " << _descripcion << endl;
    cout << pad << "Precio: $" << _costo << endl;
}

void Hotel::cargarDatosHotel(){
    string pad = obtenerPad(61);

    cin.ignore();

    cout << endl << pad << "Ingrese nombre: ";
    cin.getline(_nombre, 30);

    cout << pad << "Ingrese las estrellas: ";
    cin.getline(_estrellas, 30);

    cout << pad << "Ingrese direccion: ";
    cin.getline(_direccion, 30);

    cout << pad << "Ingrese descripcion: ";
    cin.getline(_descripcion, 150);

    _costo = floatValido( pad + "Ingrese el precio: $");

    cin.ignore();

    _estado = true;

}
