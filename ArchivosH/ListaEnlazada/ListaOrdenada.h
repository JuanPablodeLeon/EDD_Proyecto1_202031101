//
// Created by juanp on 01/10/2025.
//

#ifndef EDD_PROYECTO1_202031101_LISTAORDENADA_H
#define EDD_PROYECTO1_202031101_LISTAORDENADA_H
#include "Lista.h"


class ListaOrdenada : public Lista
{
    private:
        void insertarISBN(Libro libro);
        Nodo* obtenerPosicionNodo(int indice);
        std::string conversionISBN(std::string ISBN);
        Libro* busquedaISBN(std::string ISBN);
    public:
        ListaOrdenada();
        ~ListaOrdenada();
        void insertar(Libro libro) override;
        Libro* busquedaTiempo(std::string isbn);
        Libro* busquedaSinTiempo(std::string isbn);
};


#endif //EDD_PROYECTO1_202031101_LISTAORDENADA_H