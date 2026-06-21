#pragma once

#include "archivo.h"
#include "hotel.h"

class ArchivoHotel : public Archivo<Hotel> {
    private:
        int buscarRegistro(int idHotel);

    public:
        ArchivoHotel();

        void eliminarHotel(int idHotel);
        void mostrarHotelByID(int idHotel);
        void listarHoteles();
        void modificarHotel(int idHotel);
        void agregarHotel();
        bool existeHotel(int idHotel);
        void mostrarHotelesByNombre(const char* nombre);
        void mostrarHotelesByEstrellas(const char* estrellas);
        void mostrarHotelesByRangoPrecio(float min, float max);
        void listarHotelesDadosDeBaja();
};
