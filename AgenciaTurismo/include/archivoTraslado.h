#pragma once

#include "traslado.h"


class ArchivoTraslado
{
    private:
        char _nombreArchivo[20];

        bool guardarRegistro(Traslado reg);
        Traslado leerRegistro(int posicion);
        int contarRegistros();
        int buscarRegistro(int idTraslado);
    public:
        ArchivoTraslado();

        void eliminarTraslado(int idTraslado);
        void mostrarTrasladoByID(int idTraslado);
        void listarTraslados();
        void modificarTraslado(int idTraslado);

        void agregarTraslado();
        bool existeTraslado(int idTraslado);
};
