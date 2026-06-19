#include <iostream>
#include "helpers.h"

using namespace std;

bool cargarYValidar(int &numero, const char* mensajeError) {
    char regNumero[100];

    while (cin.peek() == '\n' || cin.peek() == '\r') {
        cin.ignore();
    }

    cin.getline(regNumero, 100);

    if (regNumero[0] == '\0') {
        numero = -1;
        cout << mensajeError << endl;
        return false;
    }

    for (int i = 0; regNumero[i] != '\0'; i++) {
        if (!isdigit(regNumero[i])) {
            numero = -1;
            cout << mensajeError << endl;
            return false;
        }
    }

  //  numero = atoi(regNumero);
    return true;
}

bool cargarYValidar(float &precio, const char* mensajeError) {
    char regPrecio[100];

    while (cin.peek() == '\n' || cin.peek() == '\r') {
        cin.ignore();
    }

    cin.getline(bufferTemporal, 100);

    if (bufferTemporal[0] == '\0') {
        precio = -1.0f;
        cout << mensajeError << endl;
        return false;
    }

    int puntos = 0;
    for (int i = 0; bufferTemporal[i] != '\0'; i++) {
        // Permitimos un punto o coma decimal
        if (bufferTemporal[i] == '.' || bufferTemporal[i] == ',') {
            puntos++;
            continue;
        }
        if (!isdigit(bufferTemporal[i])) { // Cualquier otra cosa que no sea número es error
            precio = -1.0f;
            cout << mensajeError << endl;
            return false;
        }
    }

    // Si pusieron más de un punto (ej: 45.5.2) es inválido
    if (puntos > 1) {
        precio = -1.0f;
        cout << mensajeError << endl;
        return false;
    }

    // Reemplazamos la coma por punto si la usaron, para que atof no la descarte
    for (int i = 0; bufferTemporal[i] != '\0'; i++) {
        if (bufferTemporal[i] == ',') bufferTemporal[i] = '.';
    }

    // Transformamos el texto seguro a float
    precio = atof(bufferTemporal);
    return true;
}

bool cargarYValidar(char* cadena, int tamano, const char* mensajeError) {
    while (cin.peek() == '\n' || cin.peek() == '\r') {
        cin.ignore();
    }

    cin.getline(cadena, tamano);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << mensajeError << endl;
        return false;
    }
    return true;
}
