//
// Created by juanp on 02/10/2025.
//

#ifndef EDD_PROYECTO1_202031101_MEDIDORTIEMPO_H
#define EDD_PROYECTO1_202031101_MEDIDORTIEMPO_H
#include <chrono>
#include <iostream>
#include <string>

class MedidorTiempo
{
private:
    std::chrono::high_resolution_clock::time_point inicio;
    std::string nombreFuncion;
    bool enEjecucion;
    public:
    MedidorTiempo(const std::string& nombre="");
    ~MedidorTiempo();

    void comenzar(const std::string& nombre="");
    void detener();
    long long obtenerMicrosegundos() const;
    void imprimirResultado() const;
};


#endif //EDD_PROYECTO1_202031101_MEDIDORTIEMPO_H