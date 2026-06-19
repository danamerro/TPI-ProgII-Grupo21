#pragma once

class Vuelo
{
    private:
        int _idVuelo;
        int _duracion;
        float _costo;
        char _nombre[30];
        char _origen[30];
        char _destino[30];
        bool _estado;

    public:
        Vuelo();

        int getIdVuelo() const;
        void setIdVuelo(int valor);

        int getDuracion() const;
        void setDuracion(int valor);

        float getCosto() const;
        void setCosto(float valor);

        const char* getNombre()const;
        void setNombre(const char* valor);

        const char* getOrigen()const ;
        void setOrigen(const char* valor);

        const char* getDestino()const;
        void setDestino(const char* valor);

        bool getEstado() const;
        void setEstado(bool valor);

        void cargarDatosVuelo();
        void mostrarVuelo() const;


};

