#pragma once
#include "menu.h"
#include "archivoVuelo.h"

class MenuGestionVuelos : public Menu {
    private:
        ArchivoVuelo _archivo;
        void subMenuConsultas();
        void subMenuListados();

    protected:
        void mostrarOpciones() const override;
        void procesarOpcion(int opcion) override;

    public:
        MenuGestionVuelos();
};
