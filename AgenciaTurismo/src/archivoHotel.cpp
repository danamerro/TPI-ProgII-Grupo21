#include "archivoHotel.h"
#include "helpers.h"

#include <iostream>
#include <cstring>

using namespace std;

ArchivoHotel::ArchivoHotel(): Archivo<Hotel>("hoteles.dat"){}

int ArchivoHotel::buscarRegistro(int idHotel) {

    Hotel reg;

    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (reg.getIdHotel() == idHotel) {
            return i;
        }
    }

    return -1;
}

void ArchivoHotel::eliminarHotel(int idHotel){
    int posicion = buscarRegistro(idHotel);
    cin.ignore();

    if(posicion == -1){
        leyendaSSNoEncontrado("HOTEL", 2);
        limpiarPantalla();
        return;
    }

    Hotel reg = leerRegistro(posicion);

    reg.setEstado(false);

    if(modificarRegistro(reg, posicion)){
        leyendaSSEliminado("HOTEL", 2);
        limpiarPantalla();
    }
}

void ArchivoHotel::mostrarHotelByID(int idHotel){
    int posicion = buscarRegistro(idHotel);

    if(posicion == -1){
        leyendaSSNoEncontrado("HOTEL", 2);
        cin.ignore();
        limpiarPantalla();
        return;
    }
    Hotel reg = leerRegistro(posicion);

    if(reg.getEstado()){
        reg.mostrarHotel();
        cout << endl;
        cin.ignore();
        limpiarPantalla();
    }
    else{
        leyendaSSEliminado("HOTEL", 2);
        cin.ignore();
        limpiarPantalla();
    }
}

void ArchivoHotel::listarHoteles() {
    Hotel reg;

    int cantidad = contarRegistros();

    if(cantidad > 0 ) {
        for(int i = 0; i < cantidad;i++){
        reg = leerRegistro(i);

        if(reg.getEstado()){
            reg.mostrarHotel();
        }
      }
    } else {
        leyendaSSNoEncontrado("HOTEL", 2);
    }
}

void ArchivoHotel::modificarHotel(int idHotel) {
    int posicion = buscarRegistro(idHotel);

    if(posicion == -1){
        leyendaSSNoEncontrado("HOTEL", 2);
        cin.ignore();
        limpiarPantalla();
        return;
    }

    Hotel reg = leerRegistro(posicion);
    system("cls");

    leyendaingresoNuevosDatos();
    reg.cargarDatosHotel();

    if(modificarRegistro(reg, posicion)){
        leyendaSSModificado("HOTEL", 2);
        limpiarPantalla();
    }
}

void ArchivoHotel::agregarHotel(){
    Hotel reg;
    Hotel archivo;

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdHotel(1);
    } else {
        archivo = leerRegistro(cantidad - 1);
        reg.setIdHotel(archivo.getIdHotel() + 1);
    }

    reg.cargarDatosHotel();

    if(guardarRegistro(reg)){
        leyendaSSGuardado("HOTEL", 2);
        limpiarPantalla();
    }
    else{
        leyendaSSErrorAlGuardar("HOTEL");
        limpiarPantalla();
    }
}

bool ArchivoHotel::existeHotel(int idHotel){
    return buscarRegistro(idHotel) != -1;
}

void ArchivoHotel::mostrarHotelesByNombre(const char* nombre) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    if(cantidad > 0){
        for (int i = 0; i < cantidad; i++) {
            Hotel reg = leerRegistro(i);

            if (reg.getEstado() && strcasecmp(reg.getNombre(), nombre) == 0) {
                reg.mostrarHotel();
                cout << endl << pad << "-------------------------------------------------------------" << endl;
                encontrado = true;
            }
        }
    } else {
            leyendaSSNoEncontrado("HOTEL", 2);
    }

    if (!encontrado) {
        leyendaSSNoEncontrado("HOTEL", 2);
    }

    limpiarPantalla();
}

void ArchivoHotel::mostrarHotelesByEstrellas(const char* estrellas) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Hotel reg = leerRegistro(i);

        if (reg.getEstado() && strcmp(reg.getEstrellas(), estrellas) == 0) {
            reg.mostrarHotel();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << endl << pad << "No se encontraron hoteles de " << estrellas << " estrellas." << endl;
    }

    cin.ignore();
    limpiarPantalla();
}

void ArchivoHotel::mostrarHotelesByRangoPrecio(float min, float max) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Hotel reg = leerRegistro(i);

        if (reg.getEstado() && reg.getCosto() >= min && reg.getCosto() <= max) {
            reg.mostrarHotel();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << endl << pad << "No se encontraron hoteles en el rango de precio: $" << min << " - $" << max << endl;
    }

    cin.ignore();
    limpiarPantalla();
}

void ArchivoHotel::listarHotelesDadosDeBaja() {
    Hotel reg;
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        reg = leerRegistro(i);
        if (!reg.getEstado()) {
            reg.mostrarHotel();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No hay hoteles dados de baja en el sistema." << endl;
    }
}
