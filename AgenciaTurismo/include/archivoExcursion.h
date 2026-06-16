#pragma once
#include "archivo.h"
#include "excursion.h"


class ArchivoExcursion : public Archivo<Excursion> {
    private:
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
