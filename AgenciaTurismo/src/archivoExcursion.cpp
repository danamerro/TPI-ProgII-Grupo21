#include "archivoExcursion.h"

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
    if(posicion == -1){
        cout << "EXCURSION NO ENCONTRADA" << endl;
        return;
    }

    Excursion reg = leerRegistro(posicion);

    reg.setEstado(false);

    if(modificarRegistro(reg, posicion)){
        cout << "EXCURSION ELIMINADA" << endl;
    }
}

void ArchivoExcursion::mostrarExcursionByID(int idExcursion){
    int posicion = buscarRegistro(idExcursion);

    if(posicion == -1){
        cout << "EXCURSION NO ENCONTRADA" << endl;
        return;
    }
    Excursion reg = leerRegistro(posicion);

    if(reg.getEstado()){
        reg.mostrarExcursion();
    }
    else{
        cout << "EXCURSION ELIMINADA" << endl;
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
    if(posicion == -1){
        cout << "EXCURSION NO ENCONTRADA " << endl;
        return;
    }

    Excursion reg = leerRegistro(posicion);

    cout << endl;
    cout << "INGRESE LOS NUEVOS DATOS" << endl;
    cout << endl;

    reg.cargarDatosExcursion();

    if(modificarRegistro(reg, posicion)){
        cout << "EXCURSION MODIFICADA"<< endl;
    }
}

void ArchivoExcursion::agregarExcursion(){
    Excursion reg;
    Excursion archivo;

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdExcursion(1);
    } else {
        archivo = leerRegistro(cantidad - 1);
        reg.setIdExcursion(archivo.getIdExcursion() + 1);
    }

    reg.cargarDatosExcursion();

    if(guardarRegistro(reg)){
        cout << "EXCURSION GUARDADA CORRECTAMENTE";
    }
    else{
        cout << "ERROR AL GUARDAR EXCURSION" << endl;
    }
}

bool ArchivoExcursion::existeExcursion(int idExcursion){
    return buscarRegistro(idExcursion) != -1;
}
