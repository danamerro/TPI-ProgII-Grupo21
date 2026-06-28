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
        cin.ignore();
        limpiarPantalla();
        return;
    }

    Vuelo reg = leerRegistro(posicion);

    reg.setEstado(false);

    if(modificarRegistro(reg, posicion)){
        leyendaSSEliminado("VUELO", 2);
    }
    cin.ignore();
    limpiarPantalla();
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
        cin.ignore();
        limpiarPantalla();
        return;
    }

    Vuelo reg = leerRegistro(posicion);
    system("cls");

    leyendaingresoNuevosDatos();
    reg.cargarDatosVuelo();

    if(modificarRegistro(reg, posicion)){
        leyendaSSModificado("VUELO", 2);
    }

    limpiarPantalla();
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

    limpiarPantalla();
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

    limpiarPantalla();
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

    limpiarPantalla();
}

Vuelo ArchivoVuelo::obtenerVueloPorId(int idVuelo) {
    int posicion = buscarRegistro(idVuelo);
    if (posicion == -1) {
        return Vuelo();
    }
    return leerRegistro(posicion);
}
void ArchivoVuelo::mostrarVuelosByNombre(const char* nombre) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    if(cantidad > 0 ){
        for (int i = 0; i < cantidad; i++) {
            Vuelo reg = leerRegistro(i);
            if (reg.getEstado() && strcasecmp(reg.getNombre(), nombre) == 0) {
                reg.mostrarVuelo();
                cout << endl << pad << "-------------------------------------------------------------" << endl;
                encontrado = true;
            }
        }
    } else {
        leyendaSSNoEncontrado("VUELO", 1);
    }

    if (!encontrado) {
        cout << endl << pad << "No se encontraron vuelos con el nombre: " << nombre << endl;
    }

    limpiarPantalla();
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
    cin.ignore();
    limpiarPantalla();
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
    cin.ignore();
    limpiarPantalla();
}

void ArchivoVuelo::mostrarVuelosByFechaVuelo(const char* fechaVuelo) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Vuelo reg = leerRegistro(i);
        if (reg.getEstado() && strcmp(reg.getFechaVuelo(), fechaVuelo) == 0) {
            reg.mostrarVuelo();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron vuelos con fecha: " << fechaVuelo << endl;
    }

    limpiarPantalla();
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

    cin.ignore();
    limpiarPantalla();
}
