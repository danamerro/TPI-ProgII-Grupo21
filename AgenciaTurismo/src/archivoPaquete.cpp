#include "archivoPaquete.h"

#include <iostream>
#include <cstring>

using namespace std;

ArchivoPaquete::ArchivoPaquete()
{
    strcpy(_nombreArchivo,"paquetes.dat");
}

bool ArchivoPaquete::guardarRegistro(Paquete reg){
    FILE *pFile;

    pFile = fopen(_nombreArchivo,"ab");

    if(pFile == nullptr){
        return false;
    }

    bool escribio = fwrite(&reg, sizeof(Paquete), 1, pFile);

    fclose(pFile);

    return escribio;
}

Paquete ArchivoPaquete::leerRegistro(int posicion) {

    Paquete reg;

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return reg;
    }

    fseek(
        pFile,
        sizeof(Paquete) * posicion,
        SEEK_SET
    );

    fread(
        &reg,
        sizeof(Paquete),
        1,
        pFile
    );

    fclose(pFile);

    return reg;
}

int ArchivoPaquete::contarRegistros() {

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb");

    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    int cantidad =
        ftell(pFile) / sizeof(Paquete);

    fclose(pFile);

    return cantidad;
}

int ArchivoPaquete::buscarRegistro(int idPaquete) {

    Paquete reg;

    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {

        reg = leerRegistro(i);

        if (reg.getIdPaquete() == idPaquete) {
            return i;
        }
    }

    return -1;
}


void ArchivoPaquete::eliminarPaquete(int idPaquete){
    int posicion = buscarRegistro(idPaquete);
    if(posicion == -1){
        cout << "PAQUETE NO ENCONTRADO" << endl;
        return;
    }

    Paquete reg = leerRegistro(posicion);

    reg.setEstado(false);

    FILE *pFile;

    pFile = fopen(_nombreArchivo, "rb+");

    if(pFile == nullptr){
        return;
    }

    fseek(
        pFile,
        sizeof(Paquete) * posicion,
        SEEK_SET
    );

    fwrite(
        &reg,
        sizeof(Paquete),
        1,
        pFile
    );

    fclose(pFile);

    cout << "PAQUETE ELIMINADO" << endl;

}

void ArchivoPaquete::mostrarPaqueteByID(int idPaquete){
    int posicion = buscarRegistro(idPaquete);

    if(posicion == -1){
        cout << "PAQUETE NO ENCONTRADO" << endl;
        return;
    }
    Paquete reg = leerRegistro(posicion);

    if(reg.getEstado()){
        reg.mostrarPaquete();
    }
    else{
        cout << "PAQUETE ELIMINADO" << endl;
    }



}

void ArchivoPaquete::listarPaquetes() {
    Paquete reg;

    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad;i++){
        reg = leerRegistro(i);

        if(reg.getEstado()){
            reg.mostrarPaquete();
            cout << endl;
        }
    }

}

void ArchivoPaquete::modificarPaquete(int idPaquete) {
    int posicion = buscarRegistro(idPaquete);
    if(posicion == -1){
        cout << "PAQUETE NO ENCONTRADO " << endl;
        return;
    }

    Paquete reg = leerRegistro(posicion);

    cout << endl;
    cout << "INGRESE LOS NUEVOS DATOS" << endl;
    cout << endl;

    reg.cargarPaquete();

    FILE *pFile;

    pFile = fopen(_nombreArchivo,"rb+");

    if(pFile == nullptr){
        return;
    }

    fseek(
          pFile,
          sizeof(Paquete) * posicion,
          SEEK_SET
          );

    fwrite(
           &reg,
          sizeof(Paquete),
           1,
          pFile
          );

  fclose(pFile);

  cout << "PAQUETE MODIFICADO"<< endl;
}

void ArchivoPaquete::agregarPaquete(){
    Paquete reg;

    int id;
    cout << "Ingrese ID del paquete: ";
    cin >> id;

    if(existePaquete(id)){
        cout << "YA EXISTE UN PAQUETE CON ESE ID" << endl;
        return;
    }

    reg.setIdPaquete(id);
    reg.cargarDatosPaquete();

    if(guardarRegistro(reg)){
        cout << "PAQUETE GUARDADO CORRECTAMENTE";
    }
    else{
        cout << "ERROR AL GUARDAR PAQUETE" << endl;
    }
}

bool ArchivoPaquete::existePaquete(int idPaquete){
    return buscarRegistro(idPaquete) != -1;
}
