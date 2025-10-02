//
// Created by juanp on 01/10/2025.
//

#include "../../ArchivosH/ListaEnlazada/ListaOrdenada.h"

#include <list>


ListaOrdenada::ListaOrdenada(): Lista(){}

ListaOrdenada::~ListaOrdenada() {}

void ListaOrdenada::insertar(Libro libro)
{
    insertarISBN(libro);
}

void ListaOrdenada::insertarISBN(Libro libro)
{
    Nodo* nuevo = new Nodo(libro);

    if (!primero)
    {
         primero = nuevo;
        size++;
        return;
    }

    std::string nuevoISBN = conversionISBN(libro.getISBN());

    std::string primerISBN = conversionISBN(primero->getLibro().getISBN());
    if (nuevoISBN < primerISBN)
    {
        nuevo->setSiguiente(primero);
        primero = nuevo;
        size++;
        return;
    }

    Nodo* actual = primero;
    while (actual->getSiguiente() != nullptr)
    {
        std::string actualSiguienteISBN = conversionISBN(actual->getSiguiente()->getLibro().getISBN());
        if (nuevoISBN < actualSiguienteISBN)
        {
            break;
        }
        actual = actual->getSiguiente();
    }

    nuevo->setSiguiente(actual->getSiguiente());
    actual->setSiguiente(nuevo);
    size++;
}

Libro* ListaOrdenada::busquedaISBN(std::string ISBN)
{
    MedidorTiempo timer("Busqueda ISBN Binario");
    if (!primero) return nullptr;

    std::string ISBNbuscado = conversionISBN(ISBN);
    int inicio = 0;
    int fin = size-1;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;
        Nodo* nodoMedio = obtenerPosicionNodo(medio);

        if (!nodoMedio) return nullptr;

        std::string ISBNmedio = conversionISBN(nodoMedio->getLibro().getISBN());

        if (ISBNbuscado == ISBNmedio)
        {
            return &(nodoMedio->getLibro());
        }
        else if (ISBNbuscado < ISBNmedio)
        {
            fin = medio-1;
        }
        else
        {
            inicio = medio+1;
        }
    }
    return nullptr;
}


std::string ListaOrdenada::conversionISBN(std::string ISBN)
{
    std::string nuevo;

    for (char c : ISBN)
    {
        if (c != '-')
        {
            nuevo += c;
        }
    }
    return nuevo;
}

Nodo* ListaOrdenada::obtenerPosicionNodo(int indice)
{
    if (indice < 0 || indice >= size) return nullptr;

    Nodo* actual = primero;
    for (int i = 0; i < indice && actual != nullptr; ++i)
    {
        actual = actual->getSiguiente();
    }
    return actual;
}