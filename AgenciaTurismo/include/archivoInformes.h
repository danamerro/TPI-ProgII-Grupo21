#pragma once

class ArchivoInformes {
    private:
        int extraerMes(const char* fecha);

    public:
        ArchivoInformes();

        void clientesPorEstadoVenta(int estadoVenta);
        void recaudacionPorDestino(const char* destino);
        void recordDestinoPorMes();
};
