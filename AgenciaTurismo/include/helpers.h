#pragma once
#include <string>

std::string obtenerPad(int anchoElemento = 61);
char genero(int numero);
void leyendaSSNoEncontrado(const std::string& servicio, int num);
void leyendaSSEliminado(const std::string& servicio, int num);
void leyendaSSModificado(const std::string& servicio, int num);
void leyendaingresoNuevosDatos();
void leyendaSSGuardado(const std::string& servicio, int num);
void leyendaSSErrorAlGuardar(const std::string& servicio);
