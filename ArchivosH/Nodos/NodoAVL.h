//
// Created by juanp on 02/10/2025.
//

#ifndef EDD_PROYECTO1_202031101_NODOAVL_H
#define EDD_PROYECTO1_202031101_NODOAVL_H
#include "Libro.h"


class NodoAVL
{
public:
    Libro libro;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;

    NodoAVL();
    NodoAVL(Libro libro);
};


#endif //EDD_PROYECTO1_202031101_NODOAVL_H