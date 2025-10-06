//
// Created by juanp on 14/09/2025.
//

#ifndef EDD_PROYECTO1_202031101_ARBOL_AVL_H
#define EDD_PROYECTO1_202031101_ARBOL_AVL_H
#include <iostream>
//#include <ostream>
#include <algorithm>
#include <cctype>
#include "Nodos/NodoAVL.h"
#include "Funciones/MedidorTiempo.h"
class AVL
{
    private:
        NodoAVL* raiz;

        int altura(NodoAVL* nodo);
        int FactorEquilibrio(NodoAVL* nodo);
        NodoAVL* rotacionDerecha(NodoAVL* dato);
        NodoAVL* rotacionIzquierda(NodoAVL* dato);
        NodoAVL* insertar(NodoAVL* nodo, Libro libro);
        NodoAVL* valorMinimo(NodoAVL* nodo);
        NodoAVL* eliminar(NodoAVL* raiz, std::string titulo);
        void imprimirInOrder(NodoAVL* raiz);
        bool buscar(NodoAVL* raiz, std::string titulo);
        std::string conversionLowerCase(const std::string& string);
        Libro* busquedaLibroTitulo(NodoAVL* raiz, std::string titulo);

    public:

        AVL();
        void insertar(Libro libro);
        void eliminar(std::string titulo);
        bool buscar(std::string titulo);
        void imprimir();
        Libro* buscarLibro(std::string titulo);

};


#endif //EDD_PROYECTO1_202031101_ARBOL_AVL_H