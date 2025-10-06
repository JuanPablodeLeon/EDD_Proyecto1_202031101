//
// Created by juanp on 02/10/2025.
//

#ifndef EDD_PROYECTO1_202031101_B_H
#define EDD_PROYECTO1_202031101_B_H
#include "NodoB.h"


class B
{
    NodoB *raiz;
    int t;
    public:

    B();
    B(int _t);
    void insertar(Libro libro);
    void eliminar(int fecha);
    void imprimir();
    void showRange(int low, int high);
    void showRangeDetailed(int low, int high);
    void generateGraphivzImage(const std::string& filename="arbol_B_Fechas");

};


#endif //EDD_PROYECTO1_202031101_B_H