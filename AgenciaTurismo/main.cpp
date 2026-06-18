#include <iostream>
#include "menuPrincipal.h"
#include <clocale>

using namespace std;

int main() {

    setlocale(LC_ALL, "Spanish");

    MenuPrincipal menu;

    menu.ejecutar();

    return 0;
}
