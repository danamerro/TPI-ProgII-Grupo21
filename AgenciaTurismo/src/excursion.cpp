#include "excursion.h"

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

void Excursion::cargarExcursion(){
    cout << "Ingrese ID de la excursion: ";
    cin >> _idExcursion;

    cout << "Ingrese duracion de la excursion: ";
    cin >> _duracion;

    cout << "Ingrese costo de la excursion: ";
    cin >> _costo;

    cin.ignore();

    cout << "Ingrese nombre de la excursion: ";
    cin.getline(_nombre, 30);

    cout << "Ingrese descripcion de la excursion: ";
    cin.getline(_descripcion, 60);

    _estado = true;
}

void Excursion::mostrarExcursion() const{
    if (_estado == true) {
        cout << "ID excursion: " << _idExcursion << endl;
        cout << "Duracion: " << _duracion << endl;
        cout << "Costo: " << _costo << endl;
        cout << "Nombre: " << _nombre << endl;
        cout << "Descripcion: " << _descripcion << endl;
        cout << "Estado: " << _estado << endl;
    }
}
