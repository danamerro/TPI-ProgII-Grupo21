#pragma once
#include "menu.h"
#include "archivoTraslado.h"

class MenuGestionTraslados : public Menu {
    private:
        ArchivoTraslado _archivo;
        void subMenuConsultas();
        void subMenuListados();

    protected:
        void mostrarOpciones() const override;
        void procesarOpcion(int opcion) override;

    public:
        MenuGestionTraslados();
};
