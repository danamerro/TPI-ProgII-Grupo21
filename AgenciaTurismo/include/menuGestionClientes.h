#pragma once

class MenuGestionClientes {
    private:
        void mostrarOpciones() const;
        void subMenuListados();
        void subMenuConsultas();

    public:
        MenuGestionClientes();

        void ejecutar();
};
