#pragma once

class Traslado
{
    private:
        int _idTraslado;
        int _duracion;
        float _precio;
        char _origen[20];
        char _destino[20];
        bool _estado;

    public:
        Traslado();

        int getIdTraslado() const;
        void setIdTraslado(int valor);

        int getDuracion() const;
        void setDuracion(int valor);

        float getPrecio() const;
        void setPrecio(float valor);

        const char* getOrigen() const;
        void setOrigen(const char* valor);

        const char* getDestino() const;
        void setDestino(const char* valor);

        bool getEstado() const;
        void setEstado(bool valor);

        void cargarDatosTraslado();
        void mostrarTraslado() const;
};
