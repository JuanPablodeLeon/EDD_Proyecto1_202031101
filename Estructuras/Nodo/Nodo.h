//
// Created by juanp on 13/09/2025.
//

#ifndef EDD_PROYECTO1_202031101_NODO_H
#define EDD_PROYECTO1_202031101_NODO_H

template <typename T>
class Nodo
{
    private:
        T valor;
        Nodo<T> *siguiente;
    public:
   // Nodo();
        Nodo(T valor);

};

//
template <typename T>
Nodo<T>::Nodo(T valor)
{
    this->valor = valor;
    this->siguiente = nullptr;
}

#endif //EDD_PROYECTO1_202031101_NODO_H