#include "archivoExcursion.h"
#include "helpers.h"

#include <iostream>
#include <cstring>

using namespace std;

ArchivoExcursion::ArchivoExcursion(): Archivo<Excursion>("excursiones.dat"){}

int ArchivoExcursion::buscarRegistro(int idExcursion) {

    Excursion reg;

    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (reg.getIdExcursion() == idExcursion) {
            return i;
        }
    }

    return -1;
}

void ArchivoExcursion::eliminarExcursion(int idExcursion){
    int posicion = buscarRegistro(idExcursion);
    string pad = obtenerPad(61);

    if(posicion == -1){
        leyendaSSNoEncontrado("EXCURSION", 1);
        return;
    }

    Excursion reg = leerRegistro(posicion);

    reg.setEstado(false);

    if(modificarRegistro(reg, posicion)){
        leyendaSSEliminado("EXCURSION", 1);
    }
}

void ArchivoExcursion::mostrarExcursionByID(int idExcursion){
    int posicion = buscarRegistro(idExcursion);
    string pad = obtenerPad(61);

    if(posicion == -1){
        leyendaSSNoEncontrado("EXCURSION", 1);
        return;
    }
    Excursion reg = leerRegistro(posicion);

    if(reg.getEstado()){
        reg.mostrarExcursion();
    }
    else{
        leyendaSSEliminado("EXCURSION", 1);
    }
}

void ArchivoExcursion::listarExcursiones() {
    Excursion reg;

    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad;i++){
        reg = leerRegistro(i);

        if(reg.getEstado()){
            reg.mostrarExcursion();
            cout << endl;
        }
    }

}

void ArchivoExcursion::modificarExcursion(int idExcursion) {
    int posicion = buscarRegistro(idExcursion);
    string pad = obtenerPad(61);

    if(posicion == -1){
        leyendaSSNoEncontrado("EXCURSION", 1);
        return;
    }

    Excursion reg = leerRegistro(posicion);

    leyendaingresoNuevosDatos();
    reg.cargarDatosExcursion();

    if(modificarRegistro(reg, posicion)){
        leyendaSSModificado("EXCURSION", 1);
    }
}

void ArchivoExcursion::agregarExcursion(){
    Excursion reg;
    Excursion archivo;
    string pad = obtenerPad(61);

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdExcursion(1);
    } else {
        archivo = leerRegistro(cantidad - 1);
        reg.setIdExcursion(archivo.getIdExcursion() + 1);
    }

    reg.cargarDatosExcursion();

    if(guardarRegistro(reg)){
      leyendaSSGuardado("EXCURSION", 1);
    }
    else{
       leyendaSSErrorAlGuardar("EXCURSION");
    }
}

bool ArchivoExcursion::existeExcursion(int idExcursion){
    return buscarRegistro(idExcursion) != -1;
}

void ArchivoExcursion::mostrarExcursionesByNombre(const char* nombre) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Excursion reg = leerRegistro(i);
        if (reg.getEstado() && strcasecmp(reg.getNombre(), nombre) == 0) {
            reg.mostrarExcursion();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron excursiones con el nombre: " << nombre << endl;
    }
}

void ArchivoExcursion::mostrarExcursionesByPrecioRange(float min, float max) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Excursion reg = leerRegistro(i);
        if (reg.getEstado() && reg.getCosto() > min && reg.getCosto() < max) {
            reg.mostrarExcursion();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron excursiones en el rango de precio: $" << min << " - $" << max << endl;
    }
}

void ArchivoExcursion::mostrarExcursionesByDuracion(int duracion) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Excursion reg = leerRegistro(i);
        if (reg.getEstado() && reg.getDuracion() == duracion) {
            reg.mostrarExcursion();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron excursiones con una duracion de " << duracion << " minutos." << endl;
    }
}

void ArchivoExcursion::listarExcursionesDadosDeBaja() {
    Excursion reg;
    int cantidad = contarRegistros();
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        reg = leerRegistro(i);
        if (!reg.getEstado()) {
            reg.mostrarExcursion();
            cout << endl;
        }
    }

    if (cantidad == 0) {
        cout << endl << pad << "No se encontraron excursiones dadas de baja." << endl;
    }
}
