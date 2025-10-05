//
// Created by juanp on 02/10/2025.
//

#ifndef EDD_PROYECTO1_202031101_NODOB_H
#define EDD_PROYECTO1_202031101_NODOB_H
#include "Libro.h"
#include "B.h"
class NodoB
{
    Libro* libros;
    int* fechas;
    int t;
    NodoB** C;
    int n;
    bool hoja;

    public:
    NodoB();
    NodoB(int _t, bool _hoja);
    void imprimir();
    int findKey(int fecha);
    void insertNonFull(const Libro& libro);
    void splitChild(int i, NodoB* y);
    void remove(int fecha);
    void removeFromLeaf(int idX);
    void removeFromNonLeaf(int idX);
    int getPredecessor(int idX);
    int getSuccessor(int idX);
    void fill(int idX);
    void borrowFromPrev(int idX);
    void borrowFromNext(int idX);
    void merge(int idX);

    void showRange(int low, int high);
    void showRangeDetailed(int low, int high);

  //  void generateGraphivz(std::ofstream &file, int & nodeCount);

    friend class B;
};


#endif //EDD_PROYECTO1_202031101_NODOB_H