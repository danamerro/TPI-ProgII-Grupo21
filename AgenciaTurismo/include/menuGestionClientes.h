#pragma once
#include "menu.h"
#include "archivoCliente.h"

class MenuGestionClientes : public Menu {
    private:
        ArchivoCliente _archivo;
        void subMenuGestion();
        void subMenuListados();
        void subMenuConsultas();
    protected:
        void mostrarOpciones() const override;
        void procesarOpcion(int opcion) override;
    public:
        MenuGestionClientes();
};
