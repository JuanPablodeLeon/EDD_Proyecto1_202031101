//
// Created by juanp on 28/09/2025.
//

#ifndef EDD_PROYECTO1_202031101_LISTA_H
#define EDD_PROYECTO1_202031101_LISTA_H
#include "../Nodos/Nodo.h"

//Modificar para agregar ordenadamente y buscar serialmente y binario
class Lista
{
    private:
        Nodo* primero;
        int size;
    public:
        Lista();
        ~Lista();
        void insertar(Libro libro);
        void imprimir();
        Nodo* buscar(Libro libro);
};


#endif //EDD_PROYECTO1_202031101_LISTA_H