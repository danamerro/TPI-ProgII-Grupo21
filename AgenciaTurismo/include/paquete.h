#pragma once

class Paquete
{
    private:
        int _idPaquete;
        float _precio;
        int _cupo;
        char _nombre[20];
        char _descripcion[20];
        char _destino[100];
        bool _estado;
        int _idHotel;
        int _idTraslado;
        int _idExcursion;
        int _idVuelo;

    public:
        Paquete();

        int getIdPaquete() const;
        void setIdPaquete(int valor);

        const char* getNombre() const;
        void setNombre(const char* valor);

        const char* getDescripcion() const;
        void setDescripcion(const char* valor);

        float getPrecio() const;
        void setPrecio(float valor);

        int getCupo() const;
        void setCupo(int valor);

        const char* getDestino() const;
        void setDestino(const char* valor);

        bool getEstado() const;
        void setEstado(bool valor);

        int getIdHotel() const;
        void setIdHotel(int valor);

        int getIdTraslado() const;
        void setIdTraslado(int valor);

        int getIdExcursion() const;
        void setIdExcursion(int valor);

        int getIdVuelo() const;
        void setIdVuelo(int valor);

        void cargarPaquete();
        void cargarDatosPaquete();
        void mostrarPaquete() const;


};
