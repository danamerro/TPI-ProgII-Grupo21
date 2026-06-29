#pragma once
#include "menu.h"
#include "archivoInformes.h"

class MenuInformes : public Menu {
    private:
        ArchivoInformes _archivo;

    protected:
        void mostrarOpciones() const override;
        void procesarOpcion(int opcion) override;

    public:
        MenuInformes();
};
