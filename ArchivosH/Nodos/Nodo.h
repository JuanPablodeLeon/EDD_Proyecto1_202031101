//
// Created by juanp on 28/09/2025.
//

#ifndef EDD_PROYECTO1_202031101_NODO_H
#define EDD_PROYECTO1_202031101_NODO_H
#include "../Libro.h"


class Nodo
{
protected:
    Libro libro;
    Nodo* siguiente;
public:
    Nodo();
    ~Nodo();
    Nodo(Libro libro);

    Nodo* getSiguiente() const;
    void setSiguiente(Nodo* siguiente);

    Libro& getLibro()
    {
        return this->libro;
    }

    const Libro& getLibro() const
    {
        return this->libro;
    }
};


#endif //EDD_PROYECTO1_202031101_NODO_H