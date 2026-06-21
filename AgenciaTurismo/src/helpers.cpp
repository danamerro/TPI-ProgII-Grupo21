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
