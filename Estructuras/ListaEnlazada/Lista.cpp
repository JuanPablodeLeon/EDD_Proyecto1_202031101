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

Lista::~Lista()
{
    Nodo* actual = primero;
    while (actual != nullptr)
    {
        Nodo* temp = actual;
        actual = actual->getSiguiente();
        delete temp;
    }
}

void Lista::insercion(Libro libro)
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

/*Nodo* Lista::buscar(Libro libro)
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
}*/

bool Lista::eliminacionSecuencia(std::string ISBN)
{
    if (!primero)
    {
        return false;
    }

    //Si el Libro es el primero en la Lista
    if (primero->getLibro().getISBN() == ISBN)
    {
        Nodo* temp = primero;
        primero = primero->getSiguiente();
        delete temp;
        size--;
        return true;
    }

    //Sino se Encuentra primero en la lista
    Nodo* actual = primero;
    while (actual->getSiguiente() != nullptr)
    {
        if (actual->getSiguiente()->getLibro().getISBN() == ISBN)
        {
            Nodo* temp = actual->getSiguiente();
            actual->setSiguiente(temp->getSiguiente());
            delete temp;
            size--;
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

bool Lista::estaVacia()
{
    return size == 0;
}
