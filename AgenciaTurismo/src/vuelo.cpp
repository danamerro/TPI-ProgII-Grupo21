#include "vuelo.h"
#include "helpers.h"

#include <iostream>
#include <cstring>

using namespace std;


Vuelo::Vuelo() {
    _idVuelo = 0;
    _duracion = 0;
    _costo = 0;

    strcpy(_nombre, "");
    strcpy(_origen, "");
    strcpy(_destino, "");
    strcpy(_fechaVuelo, "");

    _estado = true;
}

void Vuelo::setIdVuelo(int valor){
    _idVuelo = valor;
}

int Vuelo::getIdVuelo() const{
    return _idVuelo;
}

void Vuelo::setDuracion(int valor){
    _duracion = valor;
}

int Vuelo::getDuracion() const{
    return _duracion;
}

void Vuelo::setCosto(float valor){
    _costo = valor;
}

float Vuelo::getCosto() const{
    return _costo;
}

void Vuelo::setNombre(const char* valor){
    strcpy(_nombre,valor);
}

const char* Vuelo::getNombre() const{
    return _nombre;
}

void Vuelo::setOrigen(const char* valor){
    strcpy(_origen, valor);
}

const char* Vuelo::getOrigen() const{
    return _origen;
}

void Vuelo::setDestino(const char* valor){
    strcpy(_destino, valor);
}

const char* Vuelo::getDestino() const{
    return _destino;
}

const char* Vuelo::getFechaVuelo() const{
    return _fechaVuelo;
}

void Vuelo::setFechaVuelo(const char* valor){
    strcpy(_fechaVuelo, valor);
}

void Vuelo::setEstado(bool valor){
    _estado = valor;
}

bool Vuelo::getEstado() const{
    return _estado;
}

void Vuelo::cargarDatosVuelo(){
    string pad = obtenerPad(61);

    cin.ignore();

    cout << endl << pad << "Ingrese nombre: ";
    cin.getline(_nombre, 30);

    cout << pad << "Ingrese origen: ";
    cin.getline(_origen, 30);

    cout << pad << "Ingrese destino: ";
    cin.getline(_destino, 30);

    cout << pad << "Ingrese fecha de vuelo (dd/mm/yyyy): ";
    cin.getline(_fechaVuelo, 11);

    _duracion = numeroValido( pad + "Ingrese duración (minutos): ");
    _costo = floatValido( pad + "Ingrese precio : $");
    _estado = true;
}

void Vuelo::mostrarVuelo() const {

    string pad = obtenerPad(61);

    cout << endl << pad << "ID vuelo: " << _idVuelo << endl;
    cout << pad << "Nombre: " << _nombre << endl;
    cout << pad << "Origen: " << _origen << endl;
    cout << pad << "Destino: " << _destino << endl;
    cout << pad << "Duración: " << _duracion << endl;
    cout << pad << "Precio: $" << _costo << endl;
}
