#pragma once

bool cargarYValidar(int &variable, const char* mensajeError = "Ingrese solo numeros enteros.");

bool cargarYValidar(float &variable, const char* mensajeError = "Ingrese solo numeros.");

bool cargarYValidar(char* cadena, int tamano, const char* mensajeError = "Ingrese solo caracteres");
