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
        void mostrarVuelosByDestino(const char* destino);
        void mostrarVuelosByOrigen(const char* origen);
        void mostrarVuelosByNombre(const char* nombre);
        void mostrarVuelosByPrecioRange(float min, float max);
        void mostrarVuelosByDuracion(int duracion);
        void listarVuelosDadosDeBaja();
};


