#include "archivoVuelo.h"

#include <iostream>
#include <cstring>

using namespace std;

ArchivoVuelo::ArchivoVuelo() : Archivo<Vuelo>("vuelos.dat"){}

int ArchivoVuelo::buscarRegistro(int idVuelo) {

    Vuelo reg;

    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (reg.getIdVuelo() == idVuelo) {
            return i;
        }
    }

    return -1;
}


void ArchivoVuelo::eliminarVuelo(int idVuelo){
    int posicion = buscarRegistro(idVuelo);
    if(posicion == -1){
        cout << "VUELO NO ENCONTRADO" << endl;
        return;
    }

    Vuelo reg = leerRegistro(posicion);

    reg.setEstado(false);

    if(modificarRegistro(reg, posicion)){
        cout << "VUELO ELIMINADO" << endl;
    }
}

void ArchivoVuelo::mostrarVueloByID(int idVuelo){
    int posicion = buscarRegistro(idVuelo);

    if(posicion == -1){
        cout << "VUELO NO ENCONTRADO" << endl;
        return;
    }
    Vuelo reg = leerRegistro(posicion);

    if(reg.getEstado()){
        reg.mostrarVuelo();
    }
    else{
        cout << "VUELO ELIMINADO" << endl;
    }



}

void ArchivoVuelo::listarVuelos() {
    Vuelo reg;

    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad;i++){
        reg = leerRegistro(i);

        if(reg.getEstado()){
            reg.mostrarVuelo();
            cout << endl;
        }
    }
}

void ArchivoVuelo::modificarVuelo(int idVuelo) {
    int posicion = buscarRegistro(idVuelo);
    if(posicion == -1){
        cout << "VUELO NO ENCONTRADO " << endl;
        return;
    }

    Vuelo reg = leerRegistro(posicion);

    cout << endl;
    cout << "INGRESE LOS NUEVOS DATOS" << endl;
    cout << endl;

    reg.cargarDatosVuelo();

    if(modificarRegistro(reg, posicion)){
        cout << "VUELO MODIFICADO" << endl;
    }
}

void ArchivoVuelo::agregarVuelo(){
    Vuelo reg;
    Vuelo archivo;

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdVuelo(1);
    } else {
        archivo = leerRegistro(cantidad - 1);
        reg.setIdVuelo(archivo.getIdVuelo() + 1);
    }

    reg.cargarDatosVuelo();

    if(guardarRegistro(reg)){
        cout << "VUELO GUARDADO CORRECTAMENTE";
    }
    else{
        cout << "ERROR AL GUARDAR VUELO" << endl;
    }
}

bool ArchivoVuelo::existeVuelo(int idVuelo){
    return buscarRegistro(idVuelo) != -1;
}

void ArchivoVuelo::mostrarVuelosByDestino(const char* destino) {
    int cantidad = contarRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Vuelo reg = leerRegistro(i);

        if (reg.getEstado() && strcasecmp(reg.getDestino(), destino) == 0) {
            reg.mostrarVuelo();
            cout << "-----------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron vuelos activos con destino a: " << destino << endl;
    }
}

void ArchivoVuelo::mostrarVuelosByOrigen(const char* origen) {
    int cantidad = contarRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Vuelo reg = leerRegistro(i);

        if (reg.getEstado() && strcasecmp(reg.getOrigen(), origen) == 0) {
            reg.mostrarVuelo();
            cout << "-----------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron vuelos activos con origen en: " << origen << endl;
    }
}

Vuelo ArchivoVuelo::obtenerVueloPorId(int idVuelo) {
    int posicion = buscarRegistro(idVuelo);
    if (posicion == -1) {
        return Vuelo();
    }
    return leerRegistro(posicion);
}
