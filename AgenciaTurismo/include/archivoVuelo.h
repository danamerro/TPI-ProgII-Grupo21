#pragma once

#include "vuelo.h"


class ArchivoVuelo
{
    private:
        char _nombreArchivo[20];

        bool guardarRegistro(Vuelo reg);
        Vuelo leerRegistro(int posicion);
        int contarRegistros();
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


