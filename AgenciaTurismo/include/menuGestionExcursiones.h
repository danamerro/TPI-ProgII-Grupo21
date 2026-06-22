#pragma once
#include "menu.h"
#include "archivoExcursion.h"

class MenuGestionExcursiones : public Menu {
    private:
        ArchivoExcursion _archivo;
        void subMenuConsultas();
        void subMenuListados();

    protected:
        void mostrarOpciones() const override;
        void procesarOpcion(int opcion) override;

    public:
        MenuGestionExcursiones();
};
