#include "archivoExcursion.h"

#include <iostream>
#include <cstring>

using namespace std;

ArchivoExcursion::ArchivoExcursion()
{
    strcpy(_nombreArchivo,"excursiones.dat");
}

bool ArchivoExcursion::guardarRegistro(Excursion reg){
    FILE *pFile;

    pFile = fopen(_nombreArchivo,"ab");

    if(pFile == nullptr){
        return false;
    }

    bool escribio = fwrite(&reg, sizeof(Excursion), 1, pFile);

    fclose(pFile);

    return escribio;
}

Excursion ArchivoExcursion::leerRegistro(int posicion) {

    Excursion reg;

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return reg;
    }

    fseek(
        pFile,
        sizeof(Excursion) * posicion,
        SEEK_SET
    );

    fread(
        &reg,
        sizeof(Excursion),
        1,
        pFile
    );

    fclose(pFile);

    return reg;
}

int ArchivoExcursion::contarRegistros() {

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    int cantidad =
        ftell(pFile) / sizeof(Excursion);

    fclose(pFile);

    return cantidad;
}

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

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb+");

    if(pFile == nullptr){
        return;
    }

    fseek(
        pFile,
        sizeof(Excursion) * posicion,
        SEEK_SET
    );

    fwrite(
        &reg,
        sizeof(Excursion),
        1,
        pFile
    );

    fclose(pFile);

    cout << "EXCURSION ELIMINADA" << endl;

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

    reg.cargarExcursion();

    FILE *pFile;

    pFile = fopen(_nombreArchivo,"rb+");

    if(pFile == nullptr){
        return;
    }

    fseek(
          pFile,
          sizeof(Excursion) * posicion,
          SEEK_SET
          );

    fwrite(
           &reg,
          sizeof(Excursion),
           1,
          pFile
          );

  fclose(pFile);

  cout << "EXCURSION MODIFICADA"<< endl;
}

void ArchivoExcursion::agregarExcursion(){
    Excursion reg;
    reg.cargarExcursion();

    if(existeExcursion(reg.getIdExcursion())){
        cout << "YA EXISTE UNA EXCURSION CON ESE ID" << endl;
        return;
    }

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
