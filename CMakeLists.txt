cmake_minimum_required(VERSION 4.0)
project(EDD_Proyecto1_202031101)

set(CMAKE_CXX_STANDARD 20)

add_executable(EDD_Proyecto1_202031101 main.cpp
        Estructuras/Nodo/Nodo.h
        Estructuras/Pila/Pila.h
        Estructuras/Cola/Cola.h
        Estructuras/ListaEnlazada/ListaEnlazadaSimple.h
        Arboles/arbol_AVL.cpp
        ObjetosLibros/Libro.cpp
        ObjetosLibros/Libro.h)
