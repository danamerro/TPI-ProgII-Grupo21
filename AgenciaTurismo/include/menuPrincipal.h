#pragma once
#include "menu.h"

class MenuPrincipal : public Menu {
    protected:
        void mostrarOpciones() const override;
        void procesarOpcion(int opcion) override;
    public:
        MenuPrincipal();
};
