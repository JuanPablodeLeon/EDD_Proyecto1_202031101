//
// Created by juanp on 28/09/2025.
//

#include "../../ArchivosH/Nodos/Nodo.h"

Nodo::Nodo() {}

Nodo::~Nodo() {}

Nodo::Nodo(Libro libro)
{
    this->libro = libro;
    this->siguiente = nullptr;
}

Nodo* Nodo::getSiguiente() const
{
    return this->siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente)
{
    this->siguiente = siguiente;
}

Libro Nodo::getLibro() const
{
    return this->libro;
}
