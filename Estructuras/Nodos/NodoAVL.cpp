//
// Created by juanp on 02/10/2025.
//

#include "../../ArchivosH/Nodos/NodoAVL.h"

NodoAVL::NodoAVL() {}

NodoAVL::NodoAVL(Libro libro) : libro(libro), izquierda(nullptr), derecha(nullptr), altura(1) {}

