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

    reg.cargarVuelo();

    if(modificarRegistro(reg, posicion)){
        cout << "VUELO MODIFICADO" << endl;
    }
}

void ArchivoVuelo::agregarVuelo(){
    Vuelo reg;

    int id;
    cout << "Ingrese ID del vuelo: ";
    cin >> id;

    if(existeVuelo(id)){
        cout << "YA EXISTE UN VUELO CON ESE ID" << endl;
        return;
    }

    reg.setIdVuelo(id);
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



