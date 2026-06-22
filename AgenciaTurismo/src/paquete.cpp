#include "paquete.h"
#include "helpers.h"

#include <iostream>
#include <cstring>

using namespace std;


Paquete::Paquete() {
    _idPaquete = 0;
    _precio = 0;
    _cupo = 0;

    strcpy(_nombre, "");
    strcpy(_descripcion, "");
    strcpy(_destino, "");

    _estado = true;

    _idHotel = 0;
    _idTraslado = 0;
    _idExcursion = 0;
    _idVuelo = 0;
}

void Paquete::setIdPaquete(int valor){
    if(valor > 0 ){
       _idPaquete = valor;
    } else {
       _idPaquete = 0;
    }
}

int Paquete::getIdPaquete() const{
    return _idPaquete;
}

void Paquete::setNombre(const char* valor){
    strcpy(_nombre, valor);
}

const char* Paquete::getNombre() const{
    return _nombre;
}

void Paquete::setDescripcion(const char* valor){
    strcpy(_descripcion, valor);
}

const char* Paquete::getDescripcion() const{
    return _descripcion;
}

void Paquete::setPrecio(float valor){
    _precio = valor;
}

float Paquete::getPrecio() const{
    return _precio;
}

void Paquete::setCupo(int valor){
    _cupo = valor;
}

int Paquete::getCupo() const{
    return _cupo;
}

void Paquete::setDestino(const char* valor){
    strcpy(_destino, valor);
}

const char* Paquete::getDestino() const{
    return _destino;
}

void Paquete::setEstado(bool valor){
    _estado = valor;
}

bool Paquete::getEstado() const{
    return _estado;
}

void Paquete::setIdHotel(int valor){
    _idHotel = valor;
}

int Paquete::getIdHotel() const{
    return _idHotel;
}

void Paquete::setIdTraslado(int valor){
    _idTraslado = valor;
}

int Paquete::getIdTraslado() const{
    return _idTraslado;
}

void Paquete::setIdExcursion(int valor){
    _idExcursion = valor;
}

int Paquete::getIdExcursion() const{
    return _idExcursion;
}

void Paquete::setIdVuelo(int valor){
    _idVuelo = valor;
}

int Paquete::getIdVuelo() const{
    return _idVuelo;
}

void Paquete::cargarDatosPaquete(){
    string pad = obtenerPad(61);
    cin.ignore();

    cout << endl << pad << "Ingrese nombre del paquete: ";
    cin.getline(_nombre, 50);

    cout << pad << "Ingrese descripcion del paquete: ";
    cin.getline(_descripcion, 200);

    cout << pad << "Ingrese destino del paquete: ";
    cin.getline(_destino, 100);

    cout << pad <<"Ingrese precio del paquete: ";
    cin >> _precio;

    cout << pad << "Ingrese cupo del paquete: ";
    cin >> _cupo;

    cin.ignore();

    _estado = true;
}

void Paquete::mostrarPaquete() const{
    string pad = obtenerPad(61);

    cout << endl << pad << "ID paquete: " << _idPaquete << endl;
    cout << pad << "Nombre: " << _nombre << endl;
    cout << pad << "Descripcion: " << _descripcion << endl;
    cout << pad << "Precio: $" << _precio << endl;
    cout << pad << "Cupo: " << _cupo << endl;
    cout << pad << "Destino: " << _destino << endl;
    cout << pad << "ID hotel: " << _idHotel << endl;
    cout << pad << "ID traslado: " << _idTraslado << endl;
    cout << pad << "ID excursion: " << _idExcursion << endl;
    cout << pad << "ID vuelo: " << _idVuelo << endl;
}
