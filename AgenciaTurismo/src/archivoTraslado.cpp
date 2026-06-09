#include "archivoTraslado.h"

#include <iostream>
#include <cstring>

using namespace std;

ArchivoTraslado::ArchivoTraslado()
{
    strcpy(_nombreArchivo,"traslados.dat");
}

bool ArchivoTraslado::guardarRegistro(Traslado reg){
    FILE *pFile;

    pFile = fopen(_nombreArchivo,"ab");

    if(pFile == nullptr){
        return false;
    }

    bool escribio = fwrite(&reg, sizeof(Traslado), 1, pFile);

    fclose(pFile);

    return escribio;
}

Traslado ArchivoTraslado::leerRegistro(int posicion) {

    Traslado reg;

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return reg;
    }

    fseek(
        pFile,
        sizeof(Traslado) * posicion,
        SEEK_SET
    );

    fread(
        &reg,
        sizeof(Traslado),
        1,
        pFile
    );

    fclose(pFile);

    return reg;
}

int ArchivoTraslado::contarRegistros() {

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    int cantidad =
        ftell(pFile) / sizeof(Traslado);

    fclose(pFile);

    return cantidad;
}

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

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb+");

    if(pFile == nullptr){
        return;
    }

    fseek(
        pFile,
        sizeof(Traslado) * posicion,
        SEEK_SET
    );

    fwrite(
        &reg,
        sizeof(Traslado),
        1,
        pFile
    );

    fclose(pFile);

    cout << "TRASLADO ELIMINADO" << endl;

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

    reg.cargarTraslado();

    FILE *pFile;

    pFile = fopen(_nombreArchivo,"rb+");

    if(pFile == nullptr){
        return;
    }

    fseek(
          pFile,
          sizeof(Traslado) * posicion,
          SEEK_SET
          );

    fwrite(
           &reg,
          sizeof(Traslado),
           1,
          pFile
          );

  fclose(pFile);

  cout << "TRASLADO MODIFICADO"<< endl;
}

void ArchivoTraslado::agregarTraslado(){
    Traslado reg;
    reg.cargarTraslado();

    if(existeTraslado(reg.getIdTraslado())){
        cout << "YA EXISTE UN TRASLADO CON ESE ID" << endl;
        return;
    }

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
