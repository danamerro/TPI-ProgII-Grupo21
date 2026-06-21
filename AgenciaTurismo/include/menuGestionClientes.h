#pragma once

class MenuGestionClientes {
    private:
        void mostrarOpciones() const;
        void subMenuGestion();
        void subMenuListados();
        void subMenuConsultas();

    public:
        MenuGestionClientes();

        void ejecutar();
};
