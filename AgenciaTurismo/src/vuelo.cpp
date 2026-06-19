#include "vuelo.h"

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

void Vuelo::setEstado(bool valor){
    _estado = valor;
}

bool Vuelo::getEstado() const{
    return _estado;
}

void Vuelo::cargarDatosVuelo(){

    cout << "Ingrese duracion del vuelo: ";
    cin >> _duracion;

    cout << "Ingrese costo del vuelo: ";
    cin >> _costo;

    cin.ignore();

    cout << "Ingrese nombre del vuelo: ";
    cin.getline(_nombre, 30);

    cout << "Ingrese origen del vuelo: ";
    cin.getline(_origen, 30);

    cout << "Ingrese destino del vuelo: ";
    cin.getline(_destino, 30);

    _estado = true;
}

void Vuelo::mostrarVuelo() const{
    if (_estado == true) {
        cout << "ID vuelo: " << _idVuelo << endl;
        cout << "Duracion: " << _duracion << endl;
        cout << "Costo: " << _costo << endl;
        cout << "Nombre: " << _nombre << endl;
        cout << "Origen: " << _origen << endl;
        cout << "Destino: " << _destino << endl;
        cout << "Estado: " << _estado << endl;
    }
}
