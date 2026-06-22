#include "traslado.h"
#include "helpers.h"

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

void Traslado::cargarDatosTraslado(){
    string pad = obtenerPad(61);
    cin.ignore();

    cout << endl << pad << "Ingrese origen: ";
    cin.getline(_origen, 20);

    cout << pad << "Ingrese destino: ";
    cin.getline(_destino, 20);

    _duracion = numeroValido( pad + "Ingrese duración (minutos): ");
    _precio = floatValido( pad + "Ingrese precio : $" );

    _estado = true;

}

void Traslado::mostrarTraslado() const{
    string pad = obtenerPad(61);

    cout << endl << pad << "ID traslado: " << _idTraslado << endl;
    cout << pad << "Origen: " << _origen << endl;
    cout << pad << "Destino: " << _destino << endl;
    cout << pad << "Duración: " << _duracion << endl;
    cout << pad << "Precio: $" << _precio << endl;
}
