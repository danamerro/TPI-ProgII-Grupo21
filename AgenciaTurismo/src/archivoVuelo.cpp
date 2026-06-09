#include "archivoVuelo.h"

#include <iostream>
#include <cstring>

using namespace std;

ArchivoVuelo::ArchivoVuelo()
{
    strcpy(_nombreArchivo,"vuelos.dat");
}

bool ArchivoVuelo::guardarRegistro(Vuelo reg){
    FILE *pFile;

    pFile = fopen(_nombreArchivo,"ab");

    if(pFile == nullptr){
        return false;
    }

    bool escribio = fwrite(&reg, sizeof(Vuelo), 1, pFile);

    fclose(pFile);

    return escribio;
}

Vuelo ArchivoVuelo::leerRegistro(int posicion) {

    Vuelo reg;

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return reg;
    }

    fseek(
        pFile,
        sizeof(Vuelo) * posicion,
        SEEK_SET
    );

    fread(
        &reg,
        sizeof(Vuelo),
        1,
        pFile
    );

    fclose(pFile);

    return reg;
}

int ArchivoVuelo::contarRegistros() {

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    int cantidad =
        ftell(pFile) / sizeof(Vuelo);

    fclose(pFile);

    return cantidad;
}

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

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb+");

    if(pFile == nullptr){
        return;
    }

    fseek(
        pFile,
        sizeof(Vuelo) * posicion,
        SEEK_SET
    );

    fwrite(
        &reg,
        sizeof(Vuelo),
        1,
        pFile
    );

    fclose(pFile);

    cout << "VUELO ELIMINADO" << endl;

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

    FILE *pFile;

    pFile = fopen(_nombreArchivo,"rb+");

    if(pFile == nullptr){
        return;
    }

    fseek(
          pFile,
          sizeof(Vuelo) * posicion,
          SEEK_SET
          );

    fwrite(
           &reg,
          sizeof(Vuelo),
           1,
          pFile
          );

  fclose(pFile);

  cout << "VUELO MODIFICADO"<< endl;
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



