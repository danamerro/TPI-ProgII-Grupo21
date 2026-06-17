#pragma once

class MenuGestionClientes {
    private:
        void mostrarOpciones() const;
        void subMenuConsultas();

    public:
        MenuGestionClientes();

        void ejecutar();
};
