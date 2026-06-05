#pragma once

class Cliente {

    private:
        int _idCliente;
        int _dni;
        char _nombre[20];
        char _apellido[20];
        int _telefono;
        char _direccion[50];
        char _email[20];
        bool _estado;

    public:
        Cliente();

        void setID(int valor);
        int getID() const;

        void setDni(int valor);
        int getDni() const;

        void setNombre(const char* valor);
        const char* getNombre() const;

        void setApellido(const char* valor);
        const char* getApellido() const;

        void setTelefono(int valor);
        int getTelefono() const;

        void setDireccion(const char* valor);
        const char* getDireccion() const;

        void setEmail(const char* valor);
        const char* getEmail() const;

        void setEstado(bool valor);
        bool getEstado() const;

        void cargarCliente();
        void mostrarCliente() const;
};
