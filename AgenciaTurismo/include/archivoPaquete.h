#pragma once

#include "paquete.h"


class ArchivoPaquete
{
    private:
        char _nombreArchivo[20];

        bool guardarRegistro(Paquete reg);
        Paquete leerRegistro(int posicion);
        int contarRegistros();
        int buscarRegistro(int idPaquete);
    public:
        ArchivoPaquete();

        void eliminarPaquete(int idPaquete);
        void mostrarPaqueteByID(int idPaquete);
        void listarPaquetes();
        void modificarPaquete(int idPaquete);

        void agregarPaquete();
        bool existePaquete(int idPaquete);
};
