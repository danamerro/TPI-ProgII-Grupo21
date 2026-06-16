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
        cout << "HOTEL NO ENCONTRADO" << endl;
        return;
    }

    Hotel reg = leerRegistro(posicion);

    reg.setEstado(false);

    if(modificarRegistro(reg, posicion)){
        cout << "HOTEL ELIMINADO" << endl;
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

    for(int i = 0; i < cantidad;i++){
        reg = leerRegistro(i);

        if(reg.getEstado()){
            reg.mostrarHotel();
            cout << endl;
        }
    }

}

void ArchivoHotel::modificarHotel(int idHotel) {
    int posicion = buscarRegistro(idHotel);
    if(posicion == -1){
        cout << "HOTEL NO ENCONTRADO " << endl;
        return;
    }

    Hotel reg = leerRegistro(posicion);

    cout << endl;
    cout << "INGRESE LOS NUEVOS DATOS" << endl;
    cout << endl;

    reg.cargarHotel();

    if(modificarRegistro(reg, posicion)){
        cout << "HOTEL MODIFICADO"<< endl;
    }
}

void ArchivoHotel::agregarHotel(){
    Hotel reg;

    int id;
    cout << "Ingrese ID del hotel: ";
    cin >> id;

    if(existeHotel(id)){
        cout << "YA EXISTE UN HOTEL CON ESE ID" << endl;
        return;
    }

    reg.setIdHotel(id);
    reg.cargarDatosHotel();

    if(guardarRegistro(reg)){
        cout << "HOTEL GUARDADO CORRECTAMENTE";
    }
    else{
        cout << "ERROR AL GUARDAR HOTEL" << endl;
    }
}

bool ArchivoHotel::existeHotel(int idHotel){
    return buscarRegistro(idHotel) != -1;
}
