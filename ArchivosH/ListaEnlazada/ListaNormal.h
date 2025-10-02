//
// Created by juanp on 01/10/2025.
//

#ifndef EDD_PROYECTO1_202031101_LISTANORMAL_H
#define EDD_PROYECTO1_202031101_LISTANORMAL_H
#include "Lista.h"

class ListaNormal : public Lista
{
    public:
    ListaNormal();
    ~ListaNormal();
    void insertar(Libro libro) override;
};


#endif //EDD_PROYECTO1_202031101_LISTANORMAL_H