#pragma once

#include "cliente.h"

class ArchivoCliente {
    private:
        char _nombreArchivo[20];

        // Métodos auxiliares internos
        bool guardarRegistro(Cliente reg);
        Cliente leerRegistro(int posicion);
        int contarRegistros();
        int buscarRegistro(int idCliente);

    public:
        ArchivoCliente();

        void modificarCliente(int idCliente);
        void eliminarCliente(int idCliente);
        void listarClientes();
        void listarClientesDadosDeBaja();
        void mostrarClienteById(int idCliente);

        // Metodo agregados (utiles)
        void agregarCliente();
        bool existeCliente(int idCliente);
};
