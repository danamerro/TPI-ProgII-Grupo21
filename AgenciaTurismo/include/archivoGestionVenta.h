#pragma once

#include "archivo.h"
#include "gestionVenta.h"

class ArchivoGestionVenta : public Archivo<GestionVenta> {
    private:
        int buscarRegistro(int idVenta);

    public:
        ArchivoGestionVenta();

        void mostrarVentaByID(int idVenta);
        void mostrarVentasByIdCliente(int idCliente);

        void listarVentas();
        void listarTransaccionesFinalizadas();
        void listarTransaccionesCanceladas();
        void listarTransaccionesPendientes();
        void agregarVenta();
        bool existeVenta(int idVenta);
        void confirmarVenta(int idVenta);
        void cancelarVenta(int idVenta);
};
