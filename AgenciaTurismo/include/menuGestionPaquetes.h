#pragma once

class MenuGestionPaquetes {
    private:
        void mostrarOpciones() const;
        void subMenuConsultasAvanzadas();

    public:
        MenuGestionPaquetes();

        void ejecutar();
};
