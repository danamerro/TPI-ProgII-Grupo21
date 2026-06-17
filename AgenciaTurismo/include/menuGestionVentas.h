#pragma once

class MenuGestionVentas {
    private:
        void mostrarOpciones() const;
        void subMenuListados();
        void subMenuConsultas();

    public:
        MenuGestionVentas();

        void ejecutar();
};
