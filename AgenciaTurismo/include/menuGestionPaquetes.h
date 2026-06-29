#pragma once
#include "menu.h"
#include "archivoPaquete.h"

class MenuGestionPaquetes : public Menu {
    private:
        ArchivoPaquete _archivo;
        void subMenuGestion();
        void subMenuConsultas();
        void subMenuListados();

     protected:
        void mostrarOpciones() const override;
        void procesarOpcion(int opcion) override;

     public:
        MenuGestionPaquetes();
};
