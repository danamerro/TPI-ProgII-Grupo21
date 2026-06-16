#include "archivoHotel.h"

#include <iostream>
#include <cstring>

using namespace std;

ArchivoHotel::ArchivoHotel()
{
    strcpy(_nombreArchivo,"hoteles.dat");
}

bool ArchivoHotel::guardarRegistro(Hotel reg){
    FILE *pFile;

    pFile = fopen(_nombreArchivo,"ab");

    if(pFile == nullptr){
        return false;
    }

    bool escribio = fwrite(&reg, sizeof(Hotel), 1, pFile);

    fclose(pFile);

    return escribio;
}

Hotel ArchivoHotel::leerRegistro(int posicion) {

    Hotel reg;

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return reg;
    }

    fseek(
        pFile,
        sizeof(Hotel) * posicion,
        SEEK_SET
    );

    fread(
        &reg,
        sizeof(Hotel),
        1,
        pFile
    );

    fclose(pFile);

    return reg;
}

int ArchivoHotel::contarRegistros() {

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    int cantidad =
        ftell(pFile) / sizeof(Hotel);

    fclose(pFile);

    return cantidad;
}

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

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb+");

    if(pFile == nullptr){
        return;
    }

    fseek(
        pFile,
        sizeof(Hotel) * posicion,
        SEEK_SET
    );

    fwrite(
        &reg,
        sizeof(Hotel),
        1,
        pFile
    );

    fclose(pFile);

    cout << "HOTEL ELIMINADO" << endl;

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

    FILE *pFile;

    pFile = fopen(_nombreArchivo,"rb+");

    if(pFile == nullptr){
        return;
    }

    fseek(
          pFile,
          sizeof(Hotel) * posicion,
          SEEK_SET
          );

    fwrite(
           &reg,
          sizeof(Hotel),
           1,
          pFile
          );

  fclose(pFile);

  cout << "HOTEL MODIFICADO"<< endl;
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
