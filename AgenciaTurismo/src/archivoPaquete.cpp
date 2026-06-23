#include "archivoPaquete.h"
#include "archivoHotel.h"
#include "archivoTraslado.h"
#include "archivoExcursion.h"
#include "archivoVuelo.h"
#include "helpers.h"

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
        leyendaSSNoEncontrado("PAQUETE", 2);
        return;
    }

    Paquete reg = leerRegistro(posicion);

    reg.setEstado(false);

    if(modificarRegistro(reg, posicion)){
        leyendaSSEliminado("PAQUETE", 2);
    }
}

void ArchivoPaquete::mostrarPaqueteByID(int idPaquete){
    int posicion = buscarRegistro(idPaquete);

    if(posicion == -1){
        leyendaSSNoEncontrado("PAQUETE", 2);
        return;
    }
    Paquete reg = leerRegistro(posicion);

    if(reg.getEstado()){
        reg.mostrarPaquete();
    }
    else{
        leyendaSSEliminado("PAQUETE", 2);
    }
}

void ArchivoPaquete::listarPaquetes() {
    Paquete reg;

    int cantidad = contarRegistros();

    for(int i = 0; i < cantidad;i++){
        reg = leerRegistro(i);

        if(reg.getEstado()){
            reg.mostrarPaquete();
        }
    }
}

void ArchivoPaquete::modificarPaquete(int id) {
    string pad = obtenerPad(61);
    int cantidad = contarRegistros();
    int posicion;
    bool idValido = false;

    if (cantidad == 0) {
        leyendaSSNoEncontrado("PAQUETE", 2);
        return;
    }

    posicion = buscarRegistro(id);

    if (posicion == -1) {
        leyendaSSNoEncontrado("PAQUETE", 2);
    } else {
        Paquete regAux = leerRegistro(posicion);
        if (!regAux.getEstado()) {
            leyendaSSEliminado("PAQUETE", 2);
        }
    }

    Paquete reg = leerRegistro(posicion);
    cout << endl << pad << "------------- MODIFICANDO PAQUETE ID: " << id << "---------------------" << endl;
    cout << pad << "Ingrese los nuevos datos del paquete..." << endl;

    reg.cargarDatosPaquete();

    reg.setIdHotel( enlazarServicioGenerico("HOTEL", 1) );
    reg.setIdTraslado( enlazarServicioGenerico("TRASLADO", 2) );
    reg.setIdExcursion( enlazarServicioGenerico("EXCURSION", 3) );
    reg.setIdVuelo( enlazarServicioGenerico("VUELO", 4) );

    if (modificarRegistro(reg, posicion)) {
        leyendaSSGuardado("PAQUETE", 2);
    } else {
        leyendaSSErrorAlGuardar("PAQUETE");
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

    reg.setIdHotel( enlazarServicioGenerico("HOTEL", 1) );
    reg.setIdTraslado( enlazarServicioGenerico("TRASLADO", 2) );
    reg.setIdExcursion( enlazarServicioGenerico("EXCURSION", 3) );
    reg.setIdVuelo( enlazarServicioGenerico("VUELO", 4) );

    if(guardarRegistro(reg)){
        leyendaSSGuardado("PAQUETE", 2);
    }
    else{
        leyendaSSErrorAlGuardar("PAQUETE");
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
    string pad = obtenerPad(61);
    int id = 0;
    bool idValido = false;

    ArchivoHotel archivoHotel;
    ArchivoTraslado archivoTraslado;
    ArchivoExcursion archivoExcursion;
    ArchivoVuelo archivoVuelo;

    int cantidad = obtenerCantidadRegistrosServicio(tipoServicio);

    if (cantidad == 0) {
        cout << endl << pad << "No existe ningun " << nombreServicio << " registrado en el sistema." << endl;
        cout << pad << "Creando un nuevo " << nombreServicio << " automaticamente..." << endl;
        cout << endl << pad << "-------------------------------------------------------------" << endl;

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
        cout << endl << pad << "SE GUARDO CORRECTAMENTE EL " << nombreServicio << " CON ID: " << id << endl;
        return id;
    }

    cout << endl << pad << "----------------- LISTA DE "<< nombreServicio <<"-------------------------" << endl;
    switch (tipoServicio) {
        case 1: archivoHotel.listarHoteles(); break;
        case 2: archivoTraslado.listarTraslados(); break;
        case 3: archivoExcursion.listarExcursiones(); break;
        case 4: archivoVuelo.listarVuelos(); break;
    }

    cout << endl << pad << "-------------------------------------------------------------" << endl;
            cout << pad << "Si desea otro " << nombreServicio << " , cargar ingresando -1." << endl;

    do {
        cout << endl << pad << "Seleccione el ID del " << nombreServicio << " para agregar al paquete (-1 para nuevo): ";
        cin >> id;

        if (id == -1) {
            cout << endl << pad << "-------------------- ALTA DE NUEVO "<< nombreServicio << "------------------" << endl;
            switch (tipoServicio) {
                case 1: archivoHotel.agregarHotel(); id = archivoHotel.contarRegistros(); break;
                case 2: archivoTraslado.agregarTraslado(); id = archivoTraslado.contarRegistros(); break;
                case 3: archivoExcursion.agregarExcursion(); id = archivoExcursion.contarRegistros(); break;
                case 4: archivoVuelo.agregarVuelo(); id = archivoVuelo.contarRegistros(); break;
            }
            cout << endl << pad << "NUEVO " << nombreServicio << " CREADO Y ENLAZADO CON ID: " << id << endl;
            return id;
        }

        switch (tipoServicio) {
            case 1: idValido = archivoHotel.existeHotel(id); break;
            case 2: idValido = archivoTraslado.existeTraslado(id); break;
            case 3: idValido = archivoExcursion.existeExcursion(id); break;
            case 4: idValido = archivoVuelo.existeVuelo(id); break;
        }

        if (!idValido) {
            cout << endl << pad << "EL ID " << id << " NO PERTENECE A " << nombreServicio << " ACTIVO." << endl;
            cout << pad << "Seleccione uno de la lista:" << endl;
        }

    } while (!idValido);

    return id;
}

Paquete ArchivoPaquete::obtenerPaquetePorId(int idPaquete) {
    int posicion = buscarRegistro(idPaquete);
    if (posicion == -1) {
        return Paquete();
    }
    return leerRegistro(posicion);
}

void ArchivoPaquete::mostrarPaquetesByNombre(const char* nombre) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Paquete reg = leerRegistro(i);
        if (reg.getEstado() && strcasecmp(reg.getNombre(), nombre) == 0) {
            reg.mostrarPaquete();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron paquetes con el nombre: " << nombre << endl;
    }
}

void ArchivoPaquete::mostrarPaquetesByPrecioRange(float min, float max) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Paquete reg = leerRegistro(i);
        if (reg.getEstado() && reg.getPrecio() >= min && reg.getPrecio() <= max) {
            reg.mostrarPaquete();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron paquetes en el rango de precio: $" << min << " - $" << max << endl;
    }
}

void ArchivoPaquete::mostrarPaquetesByCupo(int cupo) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Paquete reg = leerRegistro(i);
        if (reg.getEstado() && reg.getCupo() == cupo) {
            reg.mostrarPaquete();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron paquetes con un cupo exacto de " << cupo << " lugares." << endl;
    }
}

void ArchivoPaquete::mostrarPaquetesByDestino(const char* destino) {
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        Paquete reg = leerRegistro(i);
        if (reg.getEstado() && strcasecmp(reg.getDestino(), destino) == 0) {
            reg.mostrarPaquete();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No se encontraron paquetes con destino a: " << destino << endl;
    }
}

void ArchivoPaquete::listarPaquetesDadosDeBaja() {
    Paquete reg;
    int cantidad = contarRegistros();
    bool encontrado = false;
    string pad = obtenerPad(61);

    for (int i = 0; i < cantidad; i++) {
        reg = leerRegistro(i);
        if (!reg.getEstado()) {
            reg.mostrarPaquete();
            cout << endl << pad << "-------------------------------------------------------------" << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << endl << pad << "No hay paquetes dados de baja en el sistema." << endl;
    }
}
