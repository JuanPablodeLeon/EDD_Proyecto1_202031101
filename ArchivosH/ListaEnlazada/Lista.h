//
// Created by juanp on 28/09/2025.
//

#ifndef EDD_PROYECTO1_202031101_LISTA_H
#define EDD_PROYECTO1_202031101_LISTA_H
#include "../Nodos/Nodo.h"
#include <string>


class Lista
{
    private:
        Nodo* primero;
        int size;
    public:
        Lista();
        virtual ~Lista();
        virtual void insertar(Libro libro) = 0;
        virtual void imprimir();
        //Nodo* buscar(Libro libro);

        virtual bool eliminar(std::string ISBN);
        bool estaVacia();
    protected:
        bool eliminacionSecuencia(std::string ISBN);
        void insercion(Libro libro);
};


#endif //EDD_PROYECTO1_202031101_LISTA_H