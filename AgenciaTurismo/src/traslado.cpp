#include "traslado.h"

#include <iostream>
#include <cstring>

using namespace std;


Traslado::Traslado() {
    _idTraslado = 0;
    _duracion = 0;
    _precio = 0;

    strcpy(_origen, "");
    strcpy(_destino, "");

    _estado = true;
}

void Traslado::setIdTraslado(int valor){
    _idTraslado = valor;
}

int Traslado::getIdTraslado() const{
    return _idTraslado;
}

void Traslado::setDuracion(int valor){
    _duracion = valor;
}

int Traslado::getDuracion() const{
    return _duracion;
}

void Traslado::setPrecio(float valor){
    _precio = valor;
}

float Traslado::getPrecio() const{
    return _precio;
}

void Traslado::setOrigen(const char* valor){
    strcpy(_origen, valor);
}

const char* Traslado::getOrigen() const{
    return _origen;
}

void Traslado::setDestino(const char* valor){
    strcpy(_destino, valor);
}

const char* Traslado::getDestino() const{
    return _destino;
}

void Traslado::setEstado(bool valor){
    _estado = valor;
}

bool Traslado::getEstado() const{
    return _estado;
}

void Traslado::cargarTraslado(){
    cout << "Ingrese ID del traslado: ";
    cin >> _idTraslado;

    cout << "Ingrese duracion del traslado: ";
    cin >> _duracion;

    cout << "Ingrese precio del traslado: ";
    cin >> _precio;

    cin.ignore();

    cout << "Ingrese origen del traslado: ";
    cin.getline(_origen, 20);

    cout << "Ingrese destino del traslado: ";
    cin.getline(_destino, 20);

    _estado = true;
}

void Traslado::mostrarTraslado() const{
    if (_estado == true) {
        cout << "ID traslado: " << _idTraslado << endl;
        cout << "Duracion: " << _duracion << endl;
        cout << "Precio: " << _precio << endl;
        cout << "Origen: " << _origen << endl;
        cout << "Destino: " << _destino << endl;
        cout << "Estado: " << _estado << endl;
    }
}
