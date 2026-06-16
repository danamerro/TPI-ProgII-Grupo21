#pragma once

#include "archivo.h"
#include "vuelo.h"

class ArchivoVuelo : public Archivo<Vuelo> {
    private:
        int buscarRegistro(int idVuelo);
    public:
        ArchivoVuelo();

        void eliminarVuelo(int idVuelo);
        void mostrarVueloByID(int idVuelo);
        void listarVuelos();
        void modificarVuelo(int idVuelo);

        void agregarVuelo();
        bool existeVuelo(int idVuelo);
};


