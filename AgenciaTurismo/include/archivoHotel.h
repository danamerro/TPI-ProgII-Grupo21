#pragma once

#include "hotel.h"


class ArchivoHotel
{
    private:
        char _nombreArchivo[20];

        bool guardarRegistro(Hotel reg);
        Hotel leerRegistro(int posicion);
        int contarRegistros();
        int buscarRegistro(int idHotel);
    public:
        ArchivoHotel();

        void eliminarHotel(int idHotel);
        void mostrarHotelByID(int idHotel);
        void listarHoteles();
        void modificarHotel(int idHotel);

        void agregarHotel();
        bool existeHotel(int idHotel);
};
