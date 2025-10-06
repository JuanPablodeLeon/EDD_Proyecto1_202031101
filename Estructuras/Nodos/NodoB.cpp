//
// Created by juanp on 02/10/2025.
//

#include "../../ArchivosH/Nodos/NodoB.h"
#include <iostream>

#include "Nodo.h"

NodoB::NodoB(){}

NodoB::NodoB(int _t, bool _hoja)
{
    t = _t;
    hoja = _hoja;
    libros = new Libro[2 * t - 1];
    fechas = new int[2 * t - 1];
    C = new NodoB*[2 * t];
    n = 0;
}

int NodoB::findKey(int fecha)
{
    int idX = 0;
    while (idX < n && fechas[idX] < fecha)
    {
        ++idX;
    }
    return idX;
}

void NodoB::imprimir()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!hoja)
        {
            C[i]->imprimir();
        }
        libros[i].imprimirInformacion();
    }
    if (!hoja)
    {
        C[i]->imprimir();
    }
}

void NodoB::showRange(int low, int high)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!hoja)
        {
            C[i]->showRange(low, high);
        }
        if (fechas[i] >= low && fechas[i] <= high)
        {
            std::cout << fechas[i] << " ";
        }
    }
    if (!hoja)
    {
        C[i]->showRange(high, low);
    }
}

void NodoB::showRangeDetailed(int low, int high)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!hoja)
        {
            C[i]->showRangeDetailed(low, high);
        }
        if (fechas[i] >= low && fechas[i] <= high)
        {
            libros[i].imprimirInformacion();
        }
    }
    if (!hoja)
    {
        C[i]->showRangeDetailed(high, low);
    }
}

void NodoB::insertNonFull(Libro libro)
{
    int fechaInt = libro.conversionInt();
    int i = n - 1;

    if (hoja)
    {
        while (i >= 0 && fechas[i] > fechaInt)
        {
            libros[i+1] = libros[i];
            fechas[i+1] = fechas[i];
            i--;
        }
        libros[i+1] = libro;
        fechas[i+1] = fechaInt;
        n = n + 1;
    }
    else
    {
        while (i >= 0 && fechas[i] > fechaInt)
        {
            i--;
        }
        if (C[i+1]->n == 2 * t -1)
        {
            splitChild(i+1, C[i+1]);
            if (fechas[i+1] < fechaInt)
            {
                i++;
            }
        }
        C[i+1]->insertNonFull(libro);
    }
}

void NodoB::splitChild(int i, NodoB* y)
{
    NodoB *z = new NodoB(y->t, y->hoja);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++) {
        z->libros[j] = y->libros[j + t];
        z->fechas[j] = y->fechas[j + t];
    }

    if (!y->hoja) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--) {
        libros[j + 1] = libros[j];
        fechas[j + 1] = fechas[j];
    }

    libros[i] = y->libros[t - 1];
    fechas[i] = y->fechas[t - 1];
    n = n + 1;
}

void NodoB::remove(int fecha)
{
    int idx = findKey(fecha);

    if (idx < n && fechas[idx] == fecha) {
        if (hoja)
            removeFromLeaf(idx);
        else
            removeFromNonLeaf(idx);
    } else {
        if (hoja) {
            std::cout << "La fecha " << fecha << " no existe en el árbol\n";
            return;
        }

        bool flag = (idx == n);
        if (C[idx]->n < t)
            fill(idx);

        if (flag && idx > n)
            C[idx - 1]->remove(fecha);
        else
            C[idx]->remove(fecha);
    }
}

void NodoB::removeFromLeaf(int idX)
{
    for (int i = idX + 1; i < n; ++i) {
        libros[i - 1] = libros[i];
        fechas[i - 1] = fechas[i];
    }
    n--;
}

void NodoB::removeFromNonLeaf(int idX)
{
    int fecha = fechas[idX];
    Libro libro = libros[idX];

    if (C[idX]->n >= t) {
        int predFecha = getPredecessor(idX);
        Libro predLibro = libros[idX]; // En una implementación real, buscaríamos el libro
        fechas[idX] = predFecha;
        libros[idX] = predLibro;
        C[idX]->remove(predFecha);
    } else if (C[idX + 1]->n >= t) {
        int succFecha = getSuccessor(idX);
        Libro succLibro = libros[idX]; // En una implementación real, buscaríamos el libro
        fechas[idX] = succFecha;
        libros[idX] = succLibro;
        C[idX + 1]->remove(succFecha);
    } else {
        merge(idX);
        C[idX]->remove(fecha);
    }
}

int NodoB::getPredecessor(int idX)
{
    NodoB *cur = C[idX];
    while (!cur->hoja)
        cur = cur->C[cur->n];
    return cur->fechas[cur->n - 1];
}

int NodoB::getSuccessor(int idX)
{
    NodoB *cur = C[idX + 1];
    while (!cur->hoja)
        cur = cur->C[0];
    return cur->fechas[0];
}

void NodoB::fill(int idX)
{
    if (idX != 0 && C[idX - 1]->n >= t)
        borrowFromPrev(idX);
    else if (idX != n && C[idX + 1]->n >= t)
        borrowFromNext(idX);
    else {
        if (idX != n)
            merge(idX);
        else
            merge(idX - 1);
    }
}

void NodoB::borrowFromPrev(int idX)
{
    NodoB *child = C[idX];
    NodoB *sibling = C[idX - 1];

    for (int i = child->n - 1; i >= 0; --i) {
        child->libros[i + 1] = child->libros[i];
        child->fechas[i + 1] = child->fechas[i];
    }

    if (!child->hoja) {
        for (int i = child->n; i >= 0; --i)
            child->C[i + 1] = child->C[i];
    }

    child->libros[0] = libros[idX - 1];
    child->fechas[0] = fechas[idX - 1];

    if (!child->hoja)
        child->C[0] = sibling->C[sibling->n];

    libros[idX - 1] = sibling->libros[sibling->n - 1];
    fechas[idX - 1] = sibling->fechas[sibling->n - 1];

    child->n += 1;
    sibling->n -= 1;
}

void NodoB::borrowFromNext(int idX)
{
    NodoB *child = C[idX];
    NodoB *sibling = C[idX + 1];

    child->libros[child->n] = libros[idX];
    child->fechas[child->n] = fechas[idX];

    if (!child->hoja)
        child->C[child->n + 1] = sibling->C[0];

    libros[idX] = sibling->libros[0];
    fechas[idX] = sibling->fechas[0];

    for (int i = 1; i < sibling->n; ++i) {
        sibling->libros[i - 1] = sibling->libros[i];
        sibling->fechas[i - 1] = sibling->fechas[i];
    }

    if (!sibling->hoja) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->C[i - 1] = sibling->C[i];
    }

    child->n += 1;
    sibling->n -= 1;
}

void NodoB::merge(int idX)
{
    NodoB *child = C[idX];
    NodoB *sibling = C[idX + 1];

    child->libros[t - 1] = libros[idX];
    child->fechas[t - 1] = fechas[idX];

    for (int i = 0; i < sibling->n; ++i) {
        child->libros[i + t] = sibling->libros[i];
        child->fechas[i + t] = sibling->fechas[i];
    }

    if (!child->hoja) {
        for (int i = 0; i <= sibling->n; ++i)
            child->C[i + t] = sibling->C[i];
    }

    for (int i = idX + 1; i < n; ++i) {
        libros[i - 1] = libros[i];
        fechas[i - 1] = fechas[i];
    }

    for (int i = idX + 2; i <= n; ++i)
        C[i - 1] = C[i];

    child->n += sibling->n + 1;
    n--;
    delete sibling;
}

void NodoB::generateGraphivz(std::ofstream& file, int& nodeCount)
{
    int currentNode = nodeCount;

    file << "  node" << currentNode << " [label=\"";
    for (int i = 0; i < n; i++) {
        file << "<f" << i << "> |" << fechas[i] << "\\n" << libros[i].getTitulo().substr(0,10) << "...|";
    }
    file << "<f" << n << ">\"];" << std::endl;

    if (!hoja) {
        for (int i = 0; i <= n; i++) {
            nodeCount++;
            file << "  \"node" << currentNode << "\":f" << i << " -> \"node" << nodeCount << "\";" << std::endl;
            C[i]->generateGraphivz(file, nodeCount);
        }
    }
}
