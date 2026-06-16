#pragma once
#include <iostream>
#include <cstring>

template <typename T>
class ArchivoBase {
    protected:
        char _nombreArchivo[30];

    public:
        ArchivoBase(const char* nombre) {
            std::strcpy(_nombreArchivo, nombre);
        }

        int contarRegistros() {
            FILE* pFile = std::fopen(_nombreArchivo, "rb");
            if (pFile == nullptr) return 0;
            std::fseek(pFile, 0, SEEK_END);
            int cantidad = std::ftell(pFile) / sizeof(T);
            std::fclose(pFile);
            return cantidad;
        }

        T leerRegistro(int posicion) {
            T reg;
            FILE* pFile = std::fopen(_nombreArchivo, "rb");
            if (pFile == nullptr) return reg;
            std::fseek(pFile, sizeof(T) * posicion, SEEK_SET);
            std::fread(&reg, sizeof(T), 1, pFile);
            std::fclose(pFile);
            return reg;
        }

        bool guardarRegistro(T reg) {
            FILE* pFile = std::fopen(_nombreArchivo, "ab");
            if (pFile == nullptr) return false;
            bool escribio = std::fwrite(&reg, sizeof(T), 1, pFile);
            std::fclose(pFile);
            return escribio;
        }
};
