#pragma once

class Excursion
{
    private:
        int _idExcursion;
        int _duracion;
        float _costo;
        char _nombre[30];
        char _descripcion[60];
        bool _estado;

    public:
        Excursion();

        int getIdExcursion() const;
        void setIdExcursion(int valor);

        int getDuracion() const;
        void setDuracion(int valor);

        float getCosto() const;
        void setCosto(float valor);

        const char* getNombre() const;
        void setNombre(const char* valor);

        const char* getDescripcion() const;
        void setDescripcion(const char* valor);

        bool getEstado() const;
        void setEstado(bool valor);

        void cargarExcursion();
        void mostrarExcursion() const;


};
