#include <iostream>
#include <string>
#include "menuInicio.h"
#include "menuPrincipal.h"
#include "helpers.h"

using namespace std;

MenuInicio::MenuInicio() {}

void MenuInicio::mostrarOpciones() const {
    string pad = obtenerPad(61);
    system("cls");

    cout << pad << "*===========================================================*" << endl;
    cout << pad << "|                                                           |" << endl;
    cout << pad << "|                   L U N A   V I A J E S                   |" << endl;
    cout << pad << "|                                                           |" << endl;
    cout << pad << "|                     Agencia de Turismo                    |" << endl;
    cout << pad << "|                                                           |" << endl;
    cout << pad << "|              \"Tu proximo destino empieza aca\"             |" << endl;
    cout << pad << "|                                                           |" << endl;
    cout << pad << "*===========================================================*" << endl;
    cout << endl;
    cout << pad << "                   1. Ingresar al sistema" << endl;
    cout << pad << "                   2. Acerca de la agencia" << endl;
    cout << pad << "                   3. Creditos" << endl;
    cout << pad << "                   0. Salir" << endl;
    cout << endl;
    cout << pad << "                   Seleccione una opcion: ";
}


void MenuInicio::procesarOpcion(int opcion) {
    string pad = obtenerPad(61);
    system("cls");

    switch (opcion) {
        case 1: {
            MenuPrincipal menu;
            menu.ejecutar();
            break;
        }
        case 2:
            acercaDe();
            break;
        case 3:
            creditos();
            break;
        case 0:
            cout << pad << "-------------------------------------------------------------" << endl;
            cout << pad << "          Gracias por usar el sistema. Hasta luego!          " << endl;
            cout << pad << "-------------------------------------------------------------" << endl;
            break;
        default:
            cout << pad << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
    }
}

void MenuInicio::acercaDe() const {
    string pad = obtenerPad(61);
    system("cls");

    cout << pad << "-------------------------------------------------------------" << endl;
    cout << pad << "                  ACERCA DE LA AGENCIA" << endl;
    cout << pad << "-------------------------------------------------------------" << endl;
    cout << pad << "  Luna Viajes es una agencia de turismo dedicada a" << endl;
    cout << pad << "  organizar tu viaje de principio a fin: vuelos, hoteles," << endl;
    cout << pad << "  excursiones, traslados y paquetes completos pensados" << endl;
    cout << pad << "  para que solo te ocupes de disfrutar." << endl;
    cout << endl;
    cout << pad << "  Nombre:     Luna Viajes" << endl;
    cout << pad << "  Direccion:  Av. Siempreviva 742, CABA" << endl;
    cout << pad << "  Telefono:   (011) 4000-0000" << endl;
    cout << pad << "  Email:      contacto@lunaviajes.com" << endl;
    cout << pad << "  Horarios:   Lunes a Viernes de 9 a 18 hs" << endl;
    cout << pad << "-------------------------------------------------------------" << endl;

    cout << endl << pad << "Presione Enter para volver al menu...";
    cin.ignore();
    cin.get();
}

void MenuInicio::creditos() const {
    string pad = obtenerPad(61);
    system("cls");

    cout << pad << "-------------------------------------------------------------" << endl;
    cout << pad << "                       CREDITOS                       " << endl;
    cout << pad << "-------------------------------------------------------------" << endl;
    cout << pad << "  Trabajo Practico Integrador - Programacion II" << " - " <<  "\033[1m" << "Grupo 21" << "\033[0m" << endl;
    cout << endl;
    cout << pad << "  Integrantes:" << endl;
    cout << pad << "    * Canela Gabriela  33157 " << endl;
    cout << pad << "    * Erro Dana        32526" << endl;
    cout << endl;
    cout << pad << "  Tecnicatura Universitaria en Programacion - UTN" << endl;
    cout << pad << "-------------------------------------------------------------" << endl;
    cout << endl << pad << "Presione Enter para volver al menu...";
    cin.ignore();
    cin.get();
}
