#pragma once

class MenuInicio {
    private:
        void mostrarPortada() const;
        void acercaDe() const;
        void creditos() const;

    public:
        MenuInicio();

        void ejecutar();
};
