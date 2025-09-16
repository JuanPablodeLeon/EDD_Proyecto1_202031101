//
// Created by juanp on 16/09/2025.
//

#ifndef EDD_PROYECTO1_202031101_LISTAENLAZADASIMPLE_H
#define EDD_PROYECTO1_202031101_LISTAENLAZADASIMPLE_H
#include "../Nodo/Nodo.h"

template <typename T>
class ListaEnlazadaSimple
{
    private:
        Nodo<T> *primero = nullptr;
        int size = 0;
    public:
        ListaEnlazadaSimple();
        ~ListaEnlazadaSimple();
        T insertar(T valor);
        void obtenerLista();
        void imrimir();
        T busquedaSecuencial(T valor);
        T buscarPosicion(T valor);
        T eliminarDatoEspecifico(T valor);
};


#endif //EDD_PROYECTO1_202031101_LISTAENLAZADASIMPLE_H