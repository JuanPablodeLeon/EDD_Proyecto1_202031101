//
// Created by juanp on 28/09/2025.
//

#include "../../ArchivosH/ListaEnlazada/Lista.h"

#include <iostream>
#include <ostream>

Lista::Lista()
{
    primero = nullptr;
    size = 0;
}

Lista::~Lista() {}

void Lista::insertar(Libro libro)
{
    Nodo* nuevo = new Nodo(libro);

    if (!primero)
    {
        primero = nuevo;
    }
    else
    {
        Nodo* actual = primero;
        while (actual->getSiguiente())
        {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
    }
    size++;
}

void Lista::imprimir()
{
    if (!primero)
    {
        std::cout << "Lista Vacia" << std::endl;
    }
    std::cout <<"||	Titulo	||	ISBN	||	Genero	||	Fecha	||	Autor	||"<< std::endl;
    Nodo* actual = primero;
    for (int i=0; i<size; i++)
    {
        actual->getLibro().imprimirInformacion();
        std::cout <<"-------------"<< std::endl;
        actual = actual->getSiguiente();
    }
}

Nodo* Lista::buscar(Libro libro)
{

    Nodo* actual = primero;

    while (actual)
    {
        if (actual->getLibro().getTitulo() == libro.getTitulo())
        {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}
