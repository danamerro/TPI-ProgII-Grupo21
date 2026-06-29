#include "excursion.h"
#include "helpers.h"

#include <iostream>
#include <cstring>

using namespace std;


Excursion::Excursion() {
    _idExcursion = 0;
    _duracion = 0;
    _costo = 0;

    strcpy(_nombre, "");
    strcpy(_descripcion, "");

    _estado = true;
}

void Excursion::setIdExcursion(int valor){
    _idExcursion = valor;
}

int Excursion::getIdExcursion() const{
    return _idExcursion;
}

void Excursion::setDuracion(int valor){
    _duracion = valor;
}

int Excursion::getDuracion() const{
    return _duracion;
}

void Excursion::setCosto(float valor){
    _costo = valor;
}

float Excursion::getCosto() const{
    return _costo;
}

void Excursion::setNombre(const char* valor){
    strcpy(_nombre, valor);
}

const char* Excursion::getNombre() const{
    return _nombre;
}

void Excursion::setDescripcion(const char* valor){
    strcpy(_descripcion, valor);
}

const char* Excursion::getDescripcion() const{
    return _descripcion;
}

void Excursion::setEstado(bool valor){
    _estado = valor;
}

bool Excursion::getEstado() const{
    return _estado;
}

void Excursion::cargarDatosExcursion(){
    string pad = obtenerPad(61);

    cin.ignore();

    cout << endl << pad << "Ingrese nombre: ";
    cin.getline(_nombre, 30);

    cout << pad << "Ingrese la descripción: ";
    cin.getline(_descripcion, 60);

    _estado = true;

    _duracion = numeroValido( pad + "Ingrese la duración (minutos) :");
    _costo = floatValido( pad + "Ingrese el precio: $");
}

void Excursion::mostrarExcursion() const{
    string pad = obtenerPad(61);

    cout << endl << pad << "ID excursión: " << _idExcursion << endl;
    cout << pad << "Nombre: " << _nombre << endl;
    cout << pad << "Descripción: " << _descripcion << endl;
    cout << pad << "Duración: " << _duracion << endl;
    cout << pad << "Precio: $" << _costo << endl;
}
