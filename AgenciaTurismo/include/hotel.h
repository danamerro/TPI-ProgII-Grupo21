#pragma once

class Hotel
{
    private:
        int _idHotel;
        float _costo;
        char _nombre[30];
        char _estrellas[30];
        char _direccion[30];
        char _descripcion[250];
        bool _estado;

    public:
        Hotel();

        int getIdHotel() const;
        void setIdHotel(int valor);

        const char* getNombre() const;
        void setNombre(const char* valor);

        const char* getEstrellas() const;
        void setEstrellas(const char* valor);

        const char* getDireccion() const;
        void setDireccion(const char* valor);

        float getCosto() const;
        void setCosto(float valor);

        const char* getDescripcion() const;
        void setDescripcion(const char* valor);

        bool getEstado() const;
        void setEstado(bool valor);

        void mostrarHotel() const;
        void cargarDatosHotel();


};
