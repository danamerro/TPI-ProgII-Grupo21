#pragma once
#include "menu.h"
#include "archivoHotel.h"

class MenuGestionHoteles : public Menu {
    private:
        ArchivoHotel _archivo;
        void subMenuGestion();
        void subMenuListados();
        void subMenuConsultas();

    protected:
        void mostrarOpciones() const override;
        void procesarOpcion(int opcion) override;

    public:
        MenuGestionHoteles();
};
