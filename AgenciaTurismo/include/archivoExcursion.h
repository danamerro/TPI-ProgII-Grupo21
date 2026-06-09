#pragma once

#include "excursion.h"


class ArchivoExcursion
{
    private:
        char _nombreArchivo[20];

        bool guardarRegistro(Excursion reg);
        Excursion leerRegistro(int posicion);
        int contarRegistros();
        int buscarRegistro(int idExcursion);
    public:
        ArchivoExcursion();

        void eliminarExcursion(int idExcursion);
        void mostrarExcursionByID(int idExcursion);
        void listarExcursiones();
        void modificarExcursion(int idExcursion);

        void agregarExcursion();
        bool existeExcursion(int idExcursion);
};
