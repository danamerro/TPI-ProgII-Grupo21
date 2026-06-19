#include "archivoPaquete.h"
#include "archivoHotel.h"
#include "archivoTraslado.h"
#include "archivoExcursion.h"
#include "archivoVuelo.h"

#include <iostream>
#include <cstring>

using namespace std;

ArchivoPaquete::ArchivoPaquete() : Archivo<Paquete>("paquetes.dat"){}

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

    if(modificarRegistro(reg, posicion)){
        cout << "PAQUETE ELIMINADO" << endl;
    }
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
    int cantidad = contarRegistros();
    int id;
    int posicion;
    bool idValido = false;

    if (cantidad == 0) {
        cout << endl << "--------------------------------------------------" << endl;
        cout << "No hay ningun paquete registrado en el sistema para modificar." << endl;
        cout << "--------------------------------------------------" << endl; //
        return;
    }

    cout << endl << "==================================================" << endl;
    cout << "LISTA DE PAQUETES DISPONIBLES PARA MODIFICAR:" << endl;
    cout << "==================================================" << endl;
    listarPaquetes(); //
    cout << "==================================================" << endl;

    do {
        cout << "Ingrese el ID del paquete que desea modificar (0 para cancelar): ";
        cin >> id;

        if (id == 0) return;

        posicion = buscarRegistro(id);

        if (posicion == -1) {
            cout << "El ID " << id << " no corresponde a un paquete activo." << endl;
            cout << "--------------------------------------------------------------------------" << endl;
        } else {
            Paquete regAux = leerRegistro(posicion);
            if (!regAux.getEstado()) {
                cout << "Ese paquete fue eliminado del sistema." << endl;
                cout << "--------------------------------------------------------------------------" << endl;
            } else {
                idValido = true;
            }
        }
    } while (!idValido);

    Paquete reg = leerRegistro(posicion);

    cout << endl << "--- MODIFICANDO PAQUETE ID: " << id << " ---" << endl;
    cout << "Ingrese los nuevos datos del paquete:" << endl << endl;

    reg.cargarDatosPaquete();

    reg.setIdHotel( enlazarServicioGenerico("hotel", 1) );
    reg.setIdTraslado( enlazarServicioGenerico("traslado", 2) );
    reg.setIdExcursion( enlazarServicioGenerico("excursion", 3) );
    reg.setIdVuelo( enlazarServicioGenerico("vuelo", 4) );

    if (modificarRegistro(reg, posicion)) { //
        cout << endl << "PAQUETE MODIFICADO CORRECTAMENTE EN EL SISTEMA" << endl;
    } else {
        cout << endl << "ERROR AL GUARDAR LOS CAMBIOS EN EL ARCHIVO" << endl;
    }
}

void ArchivoPaquete::agregarPaquete(){
    Paquete reg;
    Paquete archivo;

    int cantidad = contarRegistros();

    if (cantidad == 0) {
        reg.setIdPaquete(1);
    } else {
        archivo = leerRegistro(cantidad - 1);
        reg.setIdPaquete(archivo.getIdPaquete() + 1);
    }

    reg.cargarDatosPaquete();

    reg.setIdHotel( enlazarServicioGenerico("hotel", 1) );
    reg.setIdTraslado( enlazarServicioGenerico("traslado", 2) );
    reg.setIdExcursion( enlazarServicioGenerico("excursion", 3) );
    reg.setIdVuelo( enlazarServicioGenerico("vuelo", 4) );

    if(guardarRegistro(reg)){
        cout << endl << "PAQUETE GUARDADO CORRECTAMENTE EN EL SISTEMA" << endl;
    }
    else{
        cout << endl << "ERROR AL GUARDAR PAQUETE" << endl;
    }
}

bool ArchivoPaquete::existePaquete(int idPaquete){
    return buscarRegistro(idPaquete) != -1;
}

int ArchivoPaquete::obtenerCantidadRegistrosServicio(int tipoServicio) {
    ArchivoHotel archivoHotel;
    ArchivoTraslado archivoTraslado;
    ArchivoExcursion archivoExcursion;
    ArchivoVuelo archivoVuelo;

    switch (tipoServicio) {
        case 1:
            return archivoHotel.contarRegistros();
        case 2:
            return archivoTraslado.contarRegistros();
        case 3:
            return archivoExcursion.contarRegistros();
        case 4:
            return archivoVuelo.contarRegistros();
        default: return 0;
    }
}

int ArchivoPaquete::enlazarServicioGenerico(const char* nombreServicio, int tipoServicio) {
    int id = 0;
    bool idValido = false;

    ArchivoHotel archivoHotel;
    ArchivoTraslado archivoTraslado;
    ArchivoExcursion archivoExcursion;
    ArchivoVuelo archivoVuelo;

    int cantidad = obtenerCantidadRegistrosServicio(tipoServicio);

    if (cantidad == 0) {
        cout << endl << "No existe ningun " << nombreServicio << " registrado en el sistema." << endl;
        cout << "Creando un nuevo " << nombreServicio << " automaticamente..." << endl;
        cout << "--------------------------------------------------" << endl;

        switch (tipoServicio) {
            case 1:
                archivoHotel.agregarHotel();
                id = archivoHotel.contarRegistros();
                break;
            case 2:
                archivoTraslado.agregarTraslado();
                id = archivoTraslado.contarRegistros();
                break;
            case 3:
                archivoExcursion.agregarExcursion();
                id = archivoExcursion.contarRegistros();
                break;
            case 4:
                archivoVuelo.agregarVuelo();
                id = archivoVuelo.contarRegistros();
                break;
        }
        cout << "Se guardo el servicio de " << nombreServicio << " con ID: " << id << endl;
        return id;
    }

    cout << endl << "==================================================" << endl;
    cout << " LISTA DE " << nombreServicio << "S DISPONIBLES:" << endl;
    cout << "==================================================" << endl;

    switch (tipoServicio) {
        case 1: archivoHotel.listarHoteles(); break;
        case 2: archivoTraslado.listarTraslados(); break;
        case 3: archivoExcursion.listarExcursiones(); break;
        case 4: archivoVuelo.listarVuelos(); break;
    }

    cout << "=========================================================" << endl;
    cout << "  Si desea otro " << nombreServicio << " puede cargar uno nuevo ingresando -1." << endl;
    cout << "=========================================================" << endl;

    do {
        cout << "Seleccione el ID del " << nombreServicio << " para agregar al paquete (-1 para nuevo): ";
        cin >> id;

        if (id == -1) {
            cout << endl << "--- ALTA DE NUEVO " << nombreServicio << " ---" << endl;
            switch (tipoServicio) {
                case 1: archivoHotel.agregarHotel(); id = archivoHotel.contarRegistros(); break;
                case 2: archivoTraslado.agregarTraslado(); id = archivoTraslado.contarRegistros(); break;
                case 3: archivoExcursion.agregarExcursion(); id = archivoExcursion.contarRegistros(); break;
                case 4: archivoVuelo.agregarVuelo(); id = archivoVuelo.contarRegistros(); break;
            }
            cout << "Nuevo " << nombreServicio << " creado y enlazado con ID: " << id << endl;
            return id;
        }

        switch (tipoServicio) {
            case 1: idValido = archivoHotel.existeHotel(id); break;
            case 2: idValido = archivoTraslado.existeTraslado(id); break;
            case 3: idValido = archivoExcursion.existeExcursion(id); break;
            case 4: idValido = archivoVuelo.existeVuelo(id); break;
        }

        if (!idValido) {
            cout << "El ID " << id << " no pertenece a un " << nombreServicio << " activo. Seleccione uno de la lista." << endl;
        }

    } while (!idValido);

    return id;
}
