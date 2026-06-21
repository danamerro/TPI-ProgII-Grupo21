#include "archivoVuelo.h"
#include "helpers.h"

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
        leyendaSSNoEncontrado("VUELO", 2);
        return;
    }

    Vuelo reg = leerRegistro(posicion);

    reg.setEstado(false);

    if(modificarRegistro(reg, posicion)){
        leyendaSSEliminado("VUELO", 2);
    }
}

void ArchivoVuelo::mostrarVueloByID(int idVuelo){
    int posicion = buscarRegistro(idVuelo);

    if(posicion == -1){
        leyendaSSNoEncontrado("VUELO", 2);
        return;
    }
    Vuelo reg = leerRegistro(posicion);

    if(reg.getEstado()){
        reg.mostrarVuelo();
    }
    else{
        leyendaSSEliminado("VUELO", 2);
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
        leyendaSSNoEncontrado("VUELO", 2);
        return;
    }

    Vuelo reg = leerRegistro(posicion);

    leyendaingresoNuevosDatos();
    reg.cargarDatosVuelo();

    if(modificarRegistro(reg, posicion)){
        leyendaSSModificado("VUELO", 2);
    }
}

void ArchivoVuelo::agregarVuelo(){
    Vuelo reg;
    Vuelo archivo;
    string pad = obtenerPad(61);

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdVuelo(1);
    } else {
        archivo = leerRegistro(cantidad - 1);
        reg.setIdVuelo(archivo.getIdVuelo() + 1);
    }

    reg.cargarDatosVuelo();

    if(guardarRegistro(reg)){
        leyendaSSGuardado("VUELO", 2);
    }
    else{
        leyendaSSErrorAlGuardar("VUELO");
    }
}

bool ArchivoVuelo::existeVuelo(int idVuelo){
    return buscarRegistro(idVuelo) != -1;
}

void ArchivoVuelo::mostrarVuelosByDestino(const char* destino) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Vuelo reg = leerRegistro(i);

        if (reg.getEstado() && strcasecmp(reg.getDestino(), destino) == 0) {
            reg.mostrarVuelo();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << endl << pad << "No se encontraron vuelos activos con destino a: " << destino << endl;
    }
}

void ArchivoVuelo::mostrarVuelosByOrigen(const char* origen) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Vuelo reg = leerRegistro(i);

        if (reg.getEstado() && strcasecmp(reg.getOrigen(), origen) == 0) {
            reg.mostrarVuelo();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << endl << pad << "No se encontraron vuelos activos con origen en: " << origen << endl;
    }
}

void ArchivoVuelo::mostrarVuelosByNombre(const char* nombre) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Vuelo reg = leerRegistro(i);
        if (reg.getEstado() && strcasecmp(reg.getNombre(), nombre) == 0) {
            reg.mostrarVuelo();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron vuelos con el nombre: " << nombre << endl;
    }
}

void ArchivoVuelo::mostrarVuelosByPrecioRange(float min, float max) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Vuelo reg = leerRegistro(i);
        if (reg.getEstado() && reg.getCosto() >= min && reg.getCosto() <= max) {
            reg.mostrarVuelo();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron vuelos en el rango: $" << min << " - $" << max << endl;
    }
}

void ArchivoVuelo::mostrarVuelosByDuracion(int duracion) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Vuelo reg = leerRegistro(i);
        if (reg.getEstado() && reg.getDuracion() == duracion) {
            reg.mostrarVuelo();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron vuelos con duracion de " << duracion << " minutos." << endl;
    }
}

void ArchivoVuelo::listarVuelosDadosDeBaja() {
    Vuelo reg;
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        reg = leerRegistro(i);
        if (!reg.getEstado()) {
            reg.mostrarVuelo();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No hay vuelos dados de baja en el sistema." << endl;
    }
}
