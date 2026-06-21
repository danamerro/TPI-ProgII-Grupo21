#include <iostream>
#include <string>
#include <windows.h>
#include "helpers.h"

using namespace std;

std::string obtenerPad(int anchoElemento) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int anchoConsola = 80;

    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        anchoConsola = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }

    int margen = (anchoConsola - anchoElemento) / 2;

    if (margen < 0) {
        margen = 0;
    }

    return string(margen, ' ');
}

char genero(int numero) {
    if (numero == 1) {
        return 'A';
    }
    if (numero == 2) {
        return 'O';
    }
    return ' ';
}

void leyendaSSNoEncontrado(const std::string& servicio, int num) {
    string pad = obtenerPad(61);

    cout << endl << pad << "=============================================================" << endl;
            cout << pad << "                    "<< servicio <<" NO ENCONTRAD"<<genero(num)<< endl;
            cout << pad << "=============================================================" << endl;
}

void leyendaSSEliminado(const std::string& servicio, int num) {
    string pad = obtenerPad(61);

    cout << endl << pad << "=============================================================" << endl;
            cout << pad << "                    "<< servicio <<" ELIMINAD"<<genero(num)<< endl;
            cout << pad << "=============================================================" << endl;
}

void leyendaSSModificado(const std::string& servicio, int num) {
    string pad = obtenerPad(61);

    cout << endl << pad << "=============================================================" << endl;
            cout << pad << "                    "<< servicio <<" MODIFICAD"<<genero(num)<< endl;
            cout << pad << "=============================================================" << endl;
}

void leyendaingresoNuevosDatos() {
    string pad = obtenerPad(61);

    cout << endl << pad << "=============================================================" << endl;
            cout << pad << "                    INGRESE LOS NUEVOS DATOS                 " << endl;
            cout << pad << "=============================================================" << endl;
}

void leyendaSSGuardado(const std::string& servicio, int num) {
    string pad = obtenerPad(61);

    cout << endl << pad << "=============================================================" << endl;
            cout << pad << "               "<< servicio <<" GUARDAD"<<genero(num)<<" CORRECTAMENTE   " << endl;
            cout << pad << "=============================================================" << endl;
}


void leyendaSSErrorAlGuardar(const std::string& servicio) {
    string pad = obtenerPad(61);

    cout << endl << pad << "=============================================================" << endl;
            cout << pad << "              ERROR AL GUARDAR "<< servicio <<"              " << endl;
            cout << pad << "=============================================================" << endl;
}
