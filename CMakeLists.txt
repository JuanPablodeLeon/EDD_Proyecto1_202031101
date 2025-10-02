cmake_minimum_required(VERSION 4.0)
project(EDD_Proyecto1_202031101)

set(CMAKE_CXX_STANDARD 20)

include_directories(ArchivosH)
include_directories(ArchivosH/Funciones)
include_directories(ArchivosH/ListaEnlazada)

add_executable(EDD_Proyecto1_202031101 main.cpp
        ArchivosH/Pila/Pila.h
        ArchivosH/Cola/Cola.h
        Arboles/arbol_AVL.cpp
        ObjetosLibros/Libro.cpp
        ArchivosH/Libro.h
        Estructuras/Nodos/Nodo.cpp
        ArchivosH/Nodos/Nodo.h
        Estructuras/ListaEnlazada/Lista.cpp
        ArchivosH/ListaEnlazada/Lista.h
        Funciones/Funcionalidades.cpp
        ArchivosH/Funciones/Funcionalidades.h
        Estructuras/ListaEnlazada/ListaNormal.cpp
        ArchivosH/ListaEnlazada/ListaNormal.h
        Estructuras/ListaEnlazada/ListaOrdenada.cpp
        ArchivosH/ListaEnlazada/ListaOrdenada.h
        Funciones/MedidorTiempo.cpp
        ArchivosH/Funciones/MedidorTiempo.h
)
