#include <iostream>
#include <cstring>
#include <iomanip>
#include "archivoInformes.h"
#include "archivoCliente.h"
#include "archivoPaquete.h"
#include "archivoGestionVenta.h"
#include "helpers.h"

using namespace std;

ArchivoInformes::ArchivoInformes() {}

int ArchivoInformes::extraerMes(const char* fecha) {
    if (strlen(fecha) < 10) return 0;
    char mesStr[3] = { fecha[3], fecha[4], '\0' };
    return atoi(mesStr);
}

void ArchivoInformes::clientesPorEstadoVenta(int estadoVenta) {
    cin.ignore();
    string pad = obtenerPad(61);
    ArchivoGestionVenta archVentas;
    ArchivoCliente archClientes;

    int cantVentas = archVentas.contarRegistros();
    bool encontrado = false;

    int cantClientes = archClientes.contarRegistros();
    bool* procesado = new bool[cantClientes + 120]();

    for (int i = 0; i < cantVentas; i++) {
        GestionVenta regVent = archVentas.leerRegistro(i);

        if (regVent.getEstado() && regVent.getEstadoVenta() == estadoVenta) {
            int idCli = regVent.getIdCliente();

            if (idCli > 0 && idCli <= cantClientes && !procesado[idCli]) {
                Cliente regCliente = archClientes.obtenerClientePorId(idCli);
                if (regCliente.getEstado()) {
                    regCliente.mostrarCliente();
                    cout << pad << "Asociado a la Venta ID: " << regVent.getIdVenta() << endl;
                    cout << pad << "-------------------------------------------------------------" << endl;
                    procesado[idCli] = true;
                    encontrado = true;
                }
            }
        }
    }
    delete[] procesado;

    if (!encontrado) {
        cout << endl << pad << "No se encontraron registros para este informe." << endl;
    }

    limpiarPantalla();
}

void ArchivoInformes::recaudacionPorDestino(const char* destino) {
    string pad = obtenerPad(61);
    ArchivoGestionVenta archVentas;
    ArchivoPaquete archPaquetes;

    int cantVentas = archVentas.contarRegistros();
    float recaudacionTotal = 0.0f;
    bool encontrado = false;

    for (int i = 0; i < cantVentas; i++) {
        GestionVenta regVent = archVentas.leerRegistro(i);

        if (regVent.getEstado() && regVent.getEstadoVenta() == 1) {
            Paquete regPaq = archPaquetes.obtenerPaquetePorId(regVent.getIdPaquete());

            if (strcasecmp(regPaq.getDestino(), destino) == 0) {
                recaudacionTotal += regVent.getTotal();
                encontrado = true;
            }
        }
    }

    if (encontrado) {
        cout << endl << pad << "Destino: " << destino << endl;
        cout << pad << "Recaudacion Total Confirmada: $" << fixed << setprecision(2) << recaudacionTotal << endl;
    } else {
        cout << endl << pad << "No hay recaudacion registrada o el destino no existe." << endl;
    }
    limpiarPantalla();
}

void ArchivoInformes::recordDestinoPorMes() {
    string pad = obtenerPad(61);
    ArchivoGestionVenta archVentas;
    ArchivoPaquete archPaquetes;

    int cantVentas = archVentas.contarRegistros();
    int cantPaquetes = archPaquetes.contarRegistros();

    const char* mesesNombres[] = { "", "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                                   "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

    bool huboAlgunaVentaAnual = false;

    for (int mes = 1; mes <= 12; mes++) {
        int maxUnidadesMes = 0;
        char destinoRecord[100] = "Sin ventas";
        bool huboVentasEnMes = false;

        for (int i = 0; i < cantPaquetes; i++) {
            Paquete regPaq = archPaquetes.leerRegistro(i);
            if (!regPaq.getEstado()) continue;

            int acumVentasDestinoEnMes = 0;

            for (int j = 0; j < cantVentas; j++) {
                GestionVenta regVent = archVentas.leerRegistro(j);
                if (regVent.getEstado() && regVent.getEstadoVenta() == 1) {
                    if (regVent.getIdPaquete() == regPaq.getIdPaquete() && extraerMes(regVent.getFechaVenta()) == mes) {
                        acumVentasDestinoEnMes += regVent.getCantidadCupos();
                    }
                }
            }

            if (acumVentasDestinoEnMes > maxUnidadesMes) {
                maxUnidadesMes = acumVentasDestinoEnMes;
                strcpy(destinoRecord, regPaq.getDestino());
                huboVentasEnMes = true;
                huboAlgunaVentaAnual = true;
            }
        }

        if (huboVentasEnMes) {
            cout << pad << "Mes: " << mesesNombres[mes] << endl;
            cout << pad << "Destino Record: " << destinoRecord << endl;
            cout << pad << "Cantidad de Cupos Vendidos: " << maxUnidadesMes << endl;
            cout << pad << "-------------------------------------------------------------" << endl;
        }
    }

    if(!huboAlgunaVentaAnual) {
        cout << endl << pad << "No se registran transacciones confirmadas en el historico." << endl;
    }

    limpiarPantalla();
}
