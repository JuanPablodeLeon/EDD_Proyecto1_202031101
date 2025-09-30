cmake_minimum_required(VERSION 4.0)
project(EDD_Proyecto1_202031101)

set(CMAKE_CXX_STANDARD 20)

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
        Funciones/Menu.cpp
        ArchivosH/Funciones/Menu.h
        Funciones/CargaCSV.cpp
        ArchivosH/Funciones/CargaCSV.h
)
