#include "archivoTraslado.h"
#include "helpers.h"

#include <iostream>
#include <cstring>

using namespace std;

ArchivoTraslado::ArchivoTraslado() : Archivo<Traslado>("traslados.dat"){}

int ArchivoTraslado::buscarRegistro(int idTraslado) {

    Traslado reg;

    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (reg.getIdTraslado() == idTraslado) {
            return i;
        }
    }

    return -1;
}

void ArchivoTraslado::eliminarTraslado(int idTraslado){
    int posicion = buscarRegistro(idTraslado);
    string pad = obtenerPad(61);

    if(posicion == -1){
        leyendaSSNoEncontrado("TRASLADO", 2);
        return;
    }

    Traslado reg = leerRegistro(posicion);
    reg.setEstado(false);

    if(modificarRegistro(reg, posicion)){
         leyendaSSEliminado("TRASLADO", 2);
    }

}

void ArchivoTraslado::mostrarTrasladoByID(int idTraslado){
    int posicion = buscarRegistro(idTraslado);
    string pad = obtenerPad(61);

    if(posicion == -1){
        leyendaSSNoEncontrado("TRASLADO", 2);
        return;
    }
    Traslado reg = leerRegistro(posicion);

    if(reg.getEstado()){
        reg.mostrarTraslado();
    }
    else{
        leyendaSSEliminado("TRASLADO", 2);
    }
}

void ArchivoTraslado::listarTraslados() {
    Traslado reg;

    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad;i++){
        reg = leerRegistro(i);

        if(reg.getEstado()){
            reg.mostrarTraslado();
        }
    }
}

void ArchivoTraslado::modificarTraslado(int idTraslado) {
    int posicion = buscarRegistro(idTraslado);
    string pad = obtenerPad(61);

    if(posicion == -1){
        leyendaSSNoEncontrado("TRASLADO", 2);
        return;
    }

    Traslado reg = leerRegistro(posicion);
    leyendaingresoNuevosDatos();

    reg.cargarDatosTraslado();

    if(modificarRegistro(reg, posicion)){
        leyendaSSModificado("TRASLADO", 2);
    }
}

void ArchivoTraslado::agregarTraslado(){
    Traslado reg;
    Traslado archivo;
    string pad = obtenerPad(61);

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdTraslado(1);
    } else {
        archivo = leerRegistro(cantidad - 1);
        reg.setIdTraslado(archivo.getIdTraslado() + 1);
    }

    reg.cargarDatosTraslado();

    if(guardarRegistro(reg)){
        leyendaSSGuardado("TRASLADO", 2);
    }
    else{
        leyendaSSErrorAlGuardar("TRASLADO");
    }
}

bool ArchivoTraslado::existeTraslado(int idTraslado){
    return buscarRegistro(idTraslado) != -1;
}

void ArchivoTraslado::mostrarTrasladosByOrigen(const char* origen) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Traslado reg = leerRegistro(i);
        if (reg.getEstado() && strcasecmp(reg.getOrigen(), origen) == 0) {
            reg.mostrarTraslado();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron traslados desde el origen: " << origen << endl;
    }
}

void ArchivoTraslado::mostrarTrasladosByDestino(const char* destino) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Traslado reg = leerRegistro(i);
        if (reg.getEstado() && strcasecmp(reg.getDestino(), destino) == 0) {
            reg.mostrarTraslado();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron traslados hacia el destino: " << destino << endl;
    }
}

void ArchivoTraslado::mostrarTrasladosByPrecioRange(float min, float max) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Traslado reg = leerRegistro(i);
        if (reg.getEstado() && reg.getPrecio() >= min && reg.getPrecio() <= max) {
            reg.mostrarTraslado();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron traslados en el rango: $" << min << " - $" << max << endl;
    }
}

void ArchivoTraslado::mostrarTrasladosByDuracion(int duracion) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Traslado reg = leerRegistro(i);
        if (reg.getEstado() && reg.getDuracion() == duracion) {
            reg.mostrarTraslado();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron traslados con una duracion de " << duracion << " minutos." << endl;
    }
}

void ArchivoTraslado::listarTrasladosDadosDeBaja() {
    Traslado reg;
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        reg = leerRegistro(i);
        if (!reg.getEstado()) {
            reg.mostrarTraslado();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No hay traslados dados de baja en el sistema." << endl;
    }
}
