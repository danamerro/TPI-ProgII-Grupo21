#pragma once

class GestionVenta {
    private:
        int _idVenta;
        int _idCliente;
        int _idPaquete;
        char _fechaVenta[11];
        int _cantidadCupos;
        float _precioUnitario;
        float _total;
        int _estadoVenta;
        bool _estado;

    public:
        GestionVenta();

        int getIdVenta() const;
        void setIdVenta(int idVenta);

        int getIdCliente() const;
        void setIdCliente(int idCliente);

        int getIdPaquete() const;
        void setIdPaquete(int idPaquete);

        const char* getFechaVenta() const;
        void setFechaVenta(const char* fechaVenta);

        int getCantidadCupos() const;
        void setCantidadCupos(int cantidadCupos);

        float getPrecioUnitario() const;
        void setPrecioUnitario(float precioUnitario);

        float getTotal() const;
        void setTotal(float total);

        int getEstadoVenta() const;
        void setEstadoVenta(int estadoVenta);

        bool getEstado() const;
        void setEstado(bool estado);

        bool crearDatosVenta();
        void confirmarVenta();
        void cancelarVenta();
        float calcularTotal();
        void emitirTicket(const char* tipo, const char* fechaVuelo);
        void mostrarVenta() const;
};
