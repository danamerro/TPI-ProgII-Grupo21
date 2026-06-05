#pragma once

#include "gestionVenta.h"

class ArchivoGestionVenta {
    private:
        char _nombreArchivo[20];

        // Métodos auxiliares internos
        bool guardarRegistro(GestionVenta reg);
        GestionVenta leerRegistro(int posicion);
        int contarRegistros();
        int buscarRegistro(int idVenta);

    public:
        ArchivoGestionVenta();

        void mostrarVentaByID(int idVenta);
        void listarTransaccionesFinalizadas();
        void listarTransaccionesCanceladas();
        void listarTransaccionesPendientes();

        // Metodo agregados (utiles)
        void agregarVenta();
        void confirmarVenta(int idVenta);
        void cancelarVenta(int idVenta);
};
