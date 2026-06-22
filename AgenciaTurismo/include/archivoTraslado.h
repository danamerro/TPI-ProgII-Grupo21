#pragma once

#include "archivo.h"
#include "traslado.h"


class ArchivoTraslado : public Archivo<Traslado> {
    private:
        int buscarRegistro(int idTraslado);
    public:
        ArchivoTraslado();

        void eliminarTraslado(int idTraslado);
        void mostrarTrasladoByID(int idTraslado);
        void listarTraslados();
        void modificarTraslado(int idTraslado);

        void agregarTraslado();
        bool existeTraslado(int idTraslado);
        void mostrarTrasladosByOrigen(const char* origen);
        void mostrarTrasladosByDestino(const char* destino);
        void mostrarTrasladosByPrecioRange(float min, float max);
        void mostrarTrasladosByDuracion(int duracion);
        void listarTrasladosDadosDeBaja();
};
