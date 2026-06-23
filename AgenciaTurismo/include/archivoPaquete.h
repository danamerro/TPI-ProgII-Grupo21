#pragma once

#include "archivo.h"
#include "paquete.h"


class ArchivoPaquete :public Archivo<Paquete>{
    private:
        int buscarRegistro(int idPaquete);
        int obtenerCantidadRegistrosServicio(int tipoServicio);
        void procesarAsistenciaServicio(const char* nombreServicio, int tipoServicio);
        int enlazarServicioGenerico(const char* nombreServicio, int tipoServicio);

    public:
        ArchivoPaquete();

        void eliminarPaquete(int idPaquete);
        void mostrarPaqueteByID(int idPaquete);
        void listarPaquetes();
        void modificarPaquete(int idPaquete);
        void agregarPaquete();
        bool existePaquete(int idPaquete);
        Paquete obtenerPaquetePorId(int idPaquete);
        void mostrarPaquetesByNombre(const char* nombre);
        void mostrarPaquetesByPrecioRange(float min, float max);
        void mostrarPaquetesByCupo(int cupo);
        void mostrarPaquetesByDestino(const char* destino);
        void listarPaquetesDadosDeBaja();
};
