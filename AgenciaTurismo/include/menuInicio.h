#pragma once
#include "menu.h"

class MenuInicio : public Menu {
    private:
        void acercaDe() const;
        void creditos() const;

    protected:
        void mostrarOpciones() const override;
        void procesarOpcion(int opcion) override;

    public:
        MenuInicio();
};
