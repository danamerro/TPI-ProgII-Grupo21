#pragma once

class MenuGestionVentas {
    private:
        void mostrarOpciones() const;
        void subMenuGestion();
        void subMenuListados();
        void subMenuConsultas();

    public:
        MenuGestionVentas();

        void ejecutar();
};
