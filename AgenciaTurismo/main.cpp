#include <iostream>
#include "menuGestionPaquetes.h"
#include <clocale>

using namespace std;

int main() {

    setlocale(LC_ALL, "Spanish");
    MenuGestionPaquetes menuPaquetes;

    menuPaquetes.ejecutar();

    return 0;
}
