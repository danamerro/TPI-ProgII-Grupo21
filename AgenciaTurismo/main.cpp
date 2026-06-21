#include <iostream>
#include "menuInicio.h"
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Spanish");

    MenuInicio inicio;
    inicio.ejecutar();

    return 0;
}
