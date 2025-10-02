//
// Created by juanp on 28/09/2025.
//

#ifndef EDD_PROYECTO1_202031101_LISTA_H
#define EDD_PROYECTO1_202031101_LISTA_H
#include "../Nodos/Nodo.h"
#include "../Funciones/MedidorTiempo.h"
#include <string>


class Lista
{
    private:

    public:
        Nodo* primero;
        int size;
        Lista();
        virtual ~Lista();
        virtual void insertar(Libro libro) = 0;
        virtual void imprimir();
        Libro* buscarTitulo(std::string titulo);
        Libro* buscarISBN(std::string ISBN);

        virtual bool eliminar(std::string ISBN);
        bool estaVacia();
        Nodo* getPrimero() const;
    protected:
     //   bool eliminacionSecuencia(std::string ISBN);
        void insercion(Libro libro);
};


#endif //EDD_PROYECTO1_202031101_LISTA_H