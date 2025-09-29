//
// Created by juanp on 13/09/2025.
//

#ifndef EDD_PROYECTO1_202031101_COLA_H
#define EDD_PROYECTO1_202031101_COLA_H
#include <iostream>
#include <ostream>

#include "../Nodos/Nodo.h"

template <typename T>
class Cola
{
    private:
        Nodo<T> *primero;
        Nodo<T> *ultimo;
        int size;
    public:
        Cola();

    ~Cola();
        void insertar(T dato);
        T extraer();
        void imprimir();
        bool estaVacia();
        T verPrimero();
        int obtenerSize();


};

template <typename T>
Cola<T>::Cola()
{
    this->size = 0;
    this->primero = nullptr;
    this->ultimo = nullptr;
}
template <typename T>
Cola<T>::~Cola()
{
    while (!estaVacia())
    {
        extraer();
    }
}

//Agregar un elemento a la Cola
template <typename T>
void Cola<T>::insertar(T dato)
{
    //Modo para poder agregar el dato
    Nodo<T> *nuevo = new Nodo<T>;

//Si la cabeza esta vacio significa que la cola esta vacia
     if (ultimo == nullptr)
     {
         //Primero y Ultimo pasan a ser lo mismo
         primero = nuevo;
         ultimo = nuevo;
     }
     else
     {
         //Se van agregando elementos despues del primero
         ultimo->siguiente = nuevo;
         ultimo = nuevo;
     }
    size++; //Aumento de tamaño de la Cola
}

//Sacar un elemento de la Cola
template <typename T>
T Cola<T>::extraer()
{
    if (primero == nullptr)
    {
        return T();
    }

    //Nodo provicional para no perder la referencia
    Nodo<T> *temp = primero;
    T valor_extraido = temp->valor;
    primero = primero->siguiente;

    if (primero == nullptr)
    {
        ultimo = nullptr;
    }
    delete temp;
    size--;
    return valor_extraido;
}

//Mostrar los elementos de la Cola
template <typename T>
void Cola<T>::imprimir()
{
    Nodo<T> *temp = primero;
    while (temp != nullptr)
    {
        std::cout << temp->valor << std::endl;
        temp = temp->siguiente;
    }
}

//Verificar si la cola contiene Elementos
template <typename T>
bool Cola<T>::estaVacia()
{
    return primero == nullptr;
}

/*
 * Muestra el primer elemento de la Cola
 * No elimina el elemento
 */
template <typename T>
T Cola<T>::verPrimero()
{
    if (primero == nullptr)
    {
        return T();
    }
    return primero->valor;
}

//Saber el tamaño de la Cola
template <typename T>
int Cola<T>::obtenerSize()
{
    return this->size;
}

#endif //EDD_PROYECTO1_202031101_COLA_H