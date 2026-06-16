#pragma once

#include "archivo.h"
#include "cliente.h"

class ArchivoCliente : public Archivo<Cliente> {
    private:
        int buscarRegistro(int idCliente);

    public:
        ArchivoCliente();

        void modificarCliente(int idCliente);
        void eliminarCliente(int idCliente);
        void listarClientes();
        void listarClientesDadosDeBaja();
        void listarDirectorioContacto();
        void mostrarClienteById(int idCliente);

        void agregarCliente();
        bool existeCliente(int idCliente);
};
