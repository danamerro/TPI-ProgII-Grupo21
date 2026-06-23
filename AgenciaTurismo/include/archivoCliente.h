#pragma once

#include "archivo.h"
#include "cliente.h"

class ArchivoCliente : public Archivo<Cliente> {
    private:
        int buscarRegistro(int idCliente);

    public:
        ArchivoCliente();

        void modificarCliente();
        void eliminarCliente();
        void listarClientes();
        void listarClientesDadosDeBaja();
        void listarDirectorioContacto();
        void mostrarClienteById(int idCliente);
        void mostrarClienteByDni(int dni);
        void mostrarClienteByNombre(const char* nombre);
        void mostrarClienteByApellido(const char* apellido);
        void mostrarClienteByEmail(const char* email);
        void mostrarClienteByEstado(bool estado);
        void mostrarClienteByTelefono(int telefono);
        void mostrarClienteByDireccion(const char* direccion);

        void agregarCliente();
        bool existeCliente(int idCliente);
        Cliente obtenerClientePorId(int idCliente);
};
