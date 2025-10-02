//
// Created by juanp on 02/10/2025.
//

#include "../ArchivosH/Funciones/MedidorTiempo.h"

MedidorTiempo::MedidorTiempo(const std::string& nombre) : nombreFuncion(nombre), enEjecucion(false)
{
    if (!nombre.empty())
    {
        comenzar(nombre);
    }
}

MedidorTiempo::~MedidorTiempo()
{
    if (enEjecucion)
    {
        detener();
    }
}

void MedidorTiempo::comenzar(const std::string& nombre)
{
    nombreFuncion = nombre;
    inicio = std::chrono::high_resolution_clock::now();
    enEjecucion = true;
}

void MedidorTiempo::detener()
{
    if (!enEjecucion) return;

    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);

    std::cout << nombreFuncion << " | Tiempo: "<<duracion.count()<<" microsegundos"<<std::endl;
    enEjecucion = false;
}

long long MedidorTiempo::obtenerMicrosegundos() const
{
    if (enEjecucion)
    {
        auto fin = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
    }
    return 0;
}

void MedidorTiempo::imprimirResultado() const
{
    if (enEjecucion)
    {
        auto fin = std::chrono::high_resolution_clock::now();
        auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
        std::cout << nombreFuncion << " | Tiempo: "<<duracion.count()<<" microsegundos"<<std::endl;
    }
}