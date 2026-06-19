#include "archivoHotel.h"

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
    if(posicion == -1){
        cout << "=========================================" << endl;
        cout << "           HOTEL NO ENCONTRADO           " << endl;
        cout << "=========================================" << endl;
        return;
    }

    Hotel reg = leerRegistro(posicion);

    reg.setEstado(false);

    if(modificarRegistro(reg, posicion)){
    cout << "         ===================" << endl;
    cout << "         = HOTEL ELIMINADO =" << endl;
    cout << "         ===================" << endl;
    }
}

void ArchivoHotel::mostrarHotelByID(int idHotel){
    int posicion = buscarRegistro(idHotel);

    if(posicion == -1){
        cout << "HOTEL NO ENCONTRADO" << endl;
        return;
    }
    Hotel reg = leerRegistro(posicion);

    if(reg.getEstado()){
        reg.mostrarHotel();
    }
    else{
        cout << "HOTEL ELIMINADO" << endl;
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
            cout << endl;
        }
      }
    } else {
        cout << "         ======================" << endl;
        cout << "         = SIN DATOS DE HOTEL =" << endl;
        cout << "         ======================" << endl;
    }
}

void ArchivoHotel::modificarHotel(int idHotel) {
    int posicion = buscarRegistro(idHotel);
    if(posicion == -1){
        cout << "HOTEL NO ENCONTRADO " << endl;
        return;
    }

    Hotel reg = leerRegistro(posicion);

    cout << "         ============================" << endl;
    cout << "         = INGRESE LOS NUEVOS DATOS =" << endl;
    cout << "         ============================" << endl;

    reg.cargarHotel();

    if(modificarRegistro(reg, posicion)){
        cout << "HOTEL MODIFICADO"<< endl;
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
        cout << endl << "HOTEL GUARDADO CORRECTAMENTE"<< endl;
    }
    else{
        cout << "ERROR AL GUARDAR HOTEL" << endl;
    }
}

bool ArchivoHotel::existeHotel(int idHotel){
    return buscarRegistro(idHotel) != -1;
}

void ArchivoHotel::mostrarHotelesByNombre(const char* nombre) {
    int cantidad = contarRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Hotel reg = leerRegistro(i);

        if (reg.getEstado() && strcasecmp(reg.getNombre(), nombre) == 0) {
            reg.mostrarHotel();
            cout << "-----------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron hoteles con el nombre: " << nombre << endl;
    }
}

void ArchivoHotel::mostrarHotelesByEstrellas(const char* estrellas) {
    int cantidad = contarRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Hotel reg = leerRegistro(i);

        if (reg.getEstado() && strcmp(reg.getEstrellas(), estrellas) == 0) {
            reg.mostrarHotel();
            cout << "-----------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron hoteles de " << estrellas << " estrellas." << endl;
    }
}

void ArchivoHotel::mostrarHotelesByRangoPrecio(float min, float max) {
    int cantidad = contarRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Hotel reg = leerRegistro(i);

        if (reg.getEstado() && reg.getCosto() >= min && reg.getCosto() <= max) {
            reg.mostrarHotel();
            cout << "-----------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron hoteles en el rango de precio: $" << min << " - $" << max << endl;
    }
}
