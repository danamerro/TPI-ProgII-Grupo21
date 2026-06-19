#pragma once

class Menu {
    protected:
        virtual void mostrarOpciones() const = 0;
        virtual void procesarOpcion(int opcion) = 0;

    public:
        Menu();
        virtual ~Menu();

        void ejecutar();
};
