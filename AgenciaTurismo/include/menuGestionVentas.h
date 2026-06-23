#pragma once
#include "menu.h"
#include "archivoGestionVenta.h"

class MenuGestionVentas : public Menu {
    private:
        ArchivoGestionVenta _archivo;
        void subMenuGestion();
        void subMenuListados();
        void subMenuConsultas();
    protected:
        void mostrarOpciones() const override;
        void procesarOpcion(int opcion) override;
    public:
        MenuGestionVentas();
};
