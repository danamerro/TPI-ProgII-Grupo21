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
    int idModificar;
    int posicion;
    bool idValido = false;

    if (cantidad == 0) {
        cout << endl << "--------------------------------------------------" << endl;
        cout << "No hay ningun paquete registrado en el sistema para modificar." << endl;
        cout << "--------------------------------------------------" << endl;
        return;
    }

    cout << endl << "==================================================" << endl;
    cout << "LISTA DE PAQUETES DISPONIBLES PARA MODIFICAR:" << endl;
    cout << "==================================================" << endl;
    listarPaquetes();
    cout << "==================================================" << endl;

    do {
        cout << "Ingrese el ID del paquete que desea modificar: ";
        cin >> idModificar;

        posicion = buscarRegistro(idModificar);

        if (posicion == -1) {
            cout << "El ID " << idModificar << " no corresponde a un paquete activo." << endl;
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

    cout << endl << "--- MODIFICANDO PAQUETE ID: " << idModificar << " ---" << endl;
    cout << "Ingrese los nuevos datos del paquete:" << endl << endl;

    reg.cargarPaquete();
    reg.setIdPaquete(idModificar);
    reg.setIdHotel( enlazarServicioGenerico("hotel", 1) );
    reg.setIdTraslado( enlazarServicioGenerico("traslado", 2) );
    reg.setIdExcursion( enlazarServicioGenerico("excursion", 3) );
    reg.setIdVuelo( enlazarServicioGenerico("vuelo", 4) );

    if (modificarRegistro(reg, posicion)) {
        cout << endl << "PAQUETE MODIFICADO CORRECTAMENTE EN EL SISTEMA" << endl;
    } else {
        cout << endl << "ERROR AL GUARDAR LOS CAMBIOS EN EL ARCHIVO" << endl;
    }
}

void ArchivoPaquete::agregarPaquete(){
    Paquete reg;
    int id;
    bool idValido = false;

    do {
        cout << "Ingrese ID del nuevo paquete: ";
        cin >> id;

        if (existePaquete(id)) {
            cout << "Ya existe un paquete registrado con el ID " << id << ". Intente con otro." << endl;
            cout << "--------------------------------------------------------------------------" << endl;
        } else {
            idValido = true;
        }
    } while (!idValido);

    reg.setIdPaquete(id);
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

void ArchivoPaquete::procesarAsistenciaServicio(const char* nombreServicio, int tipoServicio) {
    char respuesta;
    ArchivoHotel archivoHotel;
    ArchivoTraslado archivoTraslado;
    ArchivoExcursion archivoExcursion;
    ArchivoVuelo archivoVuelo;

    cout << "El ID ingresado no corresponde a ningun " << nombreServicio << " activo." << endl;
    cout << "¿Desea ver la lista de " << nombreServicio << "s registrados para buscarlo? (S/N): ";
    cin >> respuesta;

    if (respuesta == 'S' || respuesta == 's') {
        cout << endl << "--------------------------------------------------" << endl;
        cout << "Lista de " << nombreServicio << "s registrados:" << endl;
        cout << "--------------------------------------------------" << endl;

        switch (tipoServicio) {
            case 1:
                archivoHotel.listarHoteles();
                break;
            case 2:
                archivoTraslado.listarTraslados();
                break;
            case 3:
                archivoExcursion.listarExcursiones();
                break;
            case 4:
                archivoVuelo.listarVuelos();
                break;
        }
        cout << "--------------------------------------------------" << endl;
    } else {
        cout << "¿Desea dar de alta un nuevo " << nombreServicio << " ahora mismo? (S/N): ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            cout << endl;
            switch (tipoServicio) {
                case 1:
                    archivoHotel.agregarHotel();
                    break;
                case 2:
                    archivoTraslado.agregarTraslado();
                    break;
                case 3:
                    archivoExcursion.agregarExcursion();
                    break;
                case 4:
                    archivoVuelo.agregarVuelo();
                    break;
            }
            cout << endl << "--- CONTINUANDO CON LA CARGA DEL PAQUETE ---" << endl;
        }
    }
}

int ArchivoPaquete::enlazarServicioGenerico(const char* nombreServicio, int tipoServicio) {
    int idAux;
    bool idValido = false;
    char respuesta;

    ArchivoHotel archivoHotel;
    ArchivoTraslado archivoTraslado;
    ArchivoExcursion archivoExcursion;
    ArchivoVuelo archivoVuelo;

    do {
        int cantidad = obtenerCantidadRegistrosServicio(tipoServicio);

        if (cantidad == 0) {
            cout << endl << "--------------------------------------------------" << endl;
            cout << "No hay ningun " << nombreServicio << " registrado en el sistema." << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "¿Desea dar de alta un NUEVO " << nombreServicio << " ahora mismo? (S/N): ";
            cin >> respuesta;

            if (respuesta == 'S' || respuesta == 's') {
                cout << endl;
                switch (tipoServicio) {
                    case 1:
                        archivoHotel.agregarHotel();
                        break;
                    case 2:
                        archivoTraslado.agregarTraslado();
                        break;
                    case 3:
                        archivoExcursion.agregarExcursion();
                        break;
                    case 4:
                        archivoVuelo.agregarVuelo();
                        break;
                }
                cout << endl << "--- CONTINUANDO CON LA CARGA DEL PAQUETE ---" << endl;
            } else {
                cout << "Se asignara el ID 0 (sin servicio asociado)." << endl;
                return 0;
            }
        }

        cout << endl << "Ingrese ID del " << nombreServicio << " para el paquete: ";
        cin >> idAux;

        switch (tipoServicio) {
            case 1:
                if (archivoHotel.existeHotel(idAux))
                    idValido = true;
                break;
            case 2:
                if (archivoTraslado.existeTraslado(idAux))
                    idValido = true;
                break;
            case 3:
                if (archivoExcursion.existeExcursion(idAux))
                    idValido = true;
                break;
            case 4:
                if (archivoVuelo.existeVuelo(idAux))
                    idValido = true;
                break;
        }

        if (!idValido) {
            procesarAsistenciaServicio(nombreServicio, tipoServicio);
        }

    } while (!idValido);

    return idAux;
}
