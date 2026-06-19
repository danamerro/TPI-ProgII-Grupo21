#include "archivoTraslado.h"

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
    if(posicion == -1){
        cout << "TRASLADO NO ENCONTRADO" << endl;
        return;
    }

    Traslado reg = leerRegistro(posicion);
    reg.setEstado(false);

    if(modificarRegistro(reg, posicion)){
        cout << "TRASLADO ELIMINADO" << endl;
    }

}

void ArchivoTraslado::mostrarTrasladoByID(int idTraslado){
    int posicion = buscarRegistro(idTraslado);

    if(posicion == -1){
        cout << "TRASLADO NO ENCONTRADO" << endl;
        return;
    }
    Traslado reg = leerRegistro(posicion);

    if(reg.getEstado()){
        reg.mostrarTraslado();
    }
    else{
        cout << "TRASLADO ELIMINADO" << endl;
    }
}

void ArchivoTraslado::listarTraslados() {
    Traslado reg;

    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad;i++){
        reg = leerRegistro(i);

        if(reg.getEstado()){
            reg.mostrarTraslado();
            cout << endl;
        }
    }
}

void ArchivoTraslado::modificarTraslado(int idTraslado) {
    int posicion = buscarRegistro(idTraslado);
    if(posicion == -1){
        cout << "TRASLADO NO ENCONTRADO " << endl;
        return;
    }

    Traslado reg = leerRegistro(posicion);

    cout << endl;
    cout << "INGRESE LOS NUEVOS DATOS" << endl;
    cout << endl;

    reg.cargarDatosTraslado();

    if(modificarRegistro(reg, posicion)){
        cout << "TRASLADO MODIFICADO" << endl;
    }
}

void ArchivoTraslado::agregarTraslado(){
    Traslado reg;
    Traslado archivo;

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdTraslado(1);
    } else {
        archivo = leerRegistro(cantidad - 1);
        reg.setIdTraslado(archivo.getIdTraslado() + 1);
    }

    reg.cargarDatosTraslado();

    if(guardarRegistro(reg)){
        cout << "TRASLADO GUARDADO CORRECTAMENTE";
    }
    else{
        cout << "ERROR AL GUARDAR TRASLADO" << endl;
    }
}

bool ArchivoTraslado::existeTraslado(int idTraslado){
    return buscarRegistro(idTraslado) != -1;
}
