#pragma once
#include "menu.h"
#include "archivoPaquete.h"

class MenuGestionPaquetes : public Menu {
    private:
        ArchivoPaquete _archivo;
        void subMenuConsultasAvanzadas(); // Se queda como un método privado auxiliar propio

     protected:
        void mostrarOpciones() const override;
        void procesarOpcion(int opcion) override;

     public:
        MenuGestionPaquetes();
};
