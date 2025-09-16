//
// Created by juanp on 14/09/2025.
//

#ifndef EDD_PROYECTO1_202031101_PILA_H
#define EDD_PROYECTO1_202031101_PILA_H
#include <iostream>
#include <ostream>

#include "../Nodo/Nodo.h"

template <typename T>
class Pila
{
    private:
        Nodo<T> *primero;
        int size;
    public:
        Pila();
        ~Pila();
        void insertar(T dato);
        T extraer();
        T ver_cima();
        bool estaVacia();
        void imprimir();
        int obtenerSize();
};

//Constructor de la Pila
template <typename T>
Pila<T>::Pila()
{
    this->primero = nullptr;
    this->size = 0;
}

//Destructor de la Pila
template <typename T>
Pila<T>::~Pila()
{
    while (!estaVacia())
    {
        extraer();
    }
}

//Agregar elementos al Pila
template <typename T>
void Pila<T>::insertar(T dato)
{
    Nodo<T> *nuevo = new Nodo<T>(dato);
    nuevo->siguiente = primero;
    primero = nuevo;
    size++;
}

//Eliminar un elemento de la Pila
template <typename T>
T Pila<T>::extraer()
{
    if (primero == nullptr)
    {
        return T();
    }

    Nodo<T> *temp = primero;
    T valor_extraido = temp->valor;
    primero = primero->siguiente;
    delete temp;
    size--;
    return valor_extraido;
}

//Ver el elemento de la Cabeza
template <typename T>
T Pila<T>::ver_cima()
{
    if (primero == nullptr)
    {
        return T();
    }
    return primero->valor;
}

//Verificar si la pila cotiene elemento
template <typename T>
bool Pila<T>::estaVacia()
{
    return primero == nullptr;
}

//Saber el tanmaño de la Pila
template <typename T>
int Pila<T>::obtenerSize()
{
    return this->size;
}

//Mostrar elementos de la Pila
template <typename T>
void Pila<T>::imprimir()
{
    Nodo<T> *temp = primero;
    while (temp != nullptr)
    {
        std::cout << temp->valor << std::endl;
        temp = temp->siguiente;
    }
}

#endif //EDD_PROYECTO1_202031101_PILA_H