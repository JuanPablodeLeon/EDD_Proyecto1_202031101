//
// Created by juanp on 14/09/2025.
//

#include "../ArchivosH/Arboles/AVL.h"



AVL::AVL(): raiz(nullptr){}

int AVL::altura(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return 0;
    }
    return nodo->altura;
}

int AVL::FactorEquilibrio(NodoAVL* nodo)
{
    if (nodo == nullptr)
    {
        return 0;
    }
    return altura(nodo->izquierda) - altura(nodo->derecha);
}

NodoAVL* AVL::rotacionDerecha(NodoAVL* dato)
{
    NodoAVL* nodo = dato->izquierda;
    NodoAVL* nodo1 = nodo->derecha;

    nodo->derecha = dato;
    dato->izquierda = nodo1;

    dato->altura = std::max(altura(dato->izquierda), altura(dato->derecha))+1;
    nodo->altura = std::max(altura(nodo->izquierda), altura(nodo->derecha))+1;

    return nodo;
}

NodoAVL* AVL::rotacionIzquierda(NodoAVL* dato)
{
    NodoAVL* nodo = dato->derecha;
    NodoAVL* nodo1 = nodo->izquierda;

    nodo->izquierda = dato;
    dato->derecha = nodo1;

    dato->altura = std::max(altura(dato->izquierda), altura(dato->derecha))+1;
    nodo->altura = std::max(altura(nodo->izquierda), altura(nodo->derecha))+1;

    return nodo;
}

NodoAVL* AVL::insertar(NodoAVL* nodo, Libro libro)
{
    if (nodo == nullptr)
    {
        return new NodoAVL(libro);
    }

    std::string libroLower = conversionLowerCase(libro.getTitulo());
    std::string NodoLower = conversionLowerCase(nodo->libro.getTitulo());


    if (libroLower < NodoLower )
    {
        nodo->izquierda = insertar(nodo->izquierda, libro);
    }
    else if (libroLower > NodoLower)
    {
        nodo->derecha = insertar(nodo->derecha, libro);
    }
    else
    {
        return nodo;
    }

    nodo->altura = 1 + std::max(altura(nodo->izquierda), altura(nodo->derecha));

    int balance = FactorEquilibrio(nodo);

    if (balance > 1 && libroLower < conversionLowerCase(nodo->izquierda->libro.getTitulo()))
    {
        return rotacionDerecha(nodo);
    }

    if (balance < -1 && libroLower > conversionLowerCase(nodo->derecha->libro.getTitulo()))
    {
        return rotacionIzquierda(nodo);
    }

    if (balance > 1 && libroLower > conversionLowerCase(nodo->izquierda->libro.getTitulo()))
    {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }

    if (balance < -1 && libroLower < conversionLowerCase(nodo->derecha->libro.getTitulo()))
    {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

NodoAVL* AVL::valorMinimo(NodoAVL* nodo)
{
    NodoAVL* temp = nodo;
    while (temp->izquierda != nullptr)
    {
        temp = temp->izquierda;
    }
    return temp;
}

NodoAVL* AVL::eliminar(NodoAVL* raiz, std::string titulo)
{
    if (raiz == nullptr)
            {
                return raiz;
            }

        std::string tituloLower = conversionLowerCase(titulo);
        std::string nodoLower = conversionLowerCase(raiz->libro.getTitulo());

            if (tituloLower < nodoLower)
            {
                raiz->izquierda = eliminar(raiz->izquierda, titulo);
            }
            else if (tituloLower > nodoLower)
            {
                raiz->derecha = eliminar(raiz->derecha, titulo);
            }
            else
            {
                if (raiz->izquierda == nullptr)
                {
                    NodoAVL* temp = raiz->derecha;
                    delete raiz;
                    return temp;
                }
                else if (raiz->derecha == nullptr)
                {
                    NodoAVL* temp = raiz->izquierda;
                    delete raiz;
                    return temp;

                }
                else
                {
                    NodoAVL* temp = valorMinimo(raiz->derecha);
                    raiz->libro = temp->libro;
                    raiz->derecha = eliminar(raiz->derecha, temp->libro.getTitulo());
                }

            }

            if (raiz == nullptr)
            {
                return raiz;
            }

            raiz->altura = 1 +std::max(altura(raiz->izquierda), altura(raiz->derecha));

            int balance = FactorEquilibrio(raiz);

            if (balance > 1 && FactorEquilibrio(raiz->izquierda) >= 0)
            {
                return rotacionDerecha(raiz);
            }

            if (balance > 1 && FactorEquilibrio(raiz->izquierda) < 0)
            {
                raiz->izquierda = rotacionIzquierda(raiz->izquierda);
                return rotacionDerecha(raiz);
            }

            if (balance < -1 && FactorEquilibrio(raiz->derecha) <= 0)
            {
                return rotacionIzquierda(raiz);
            }

            if (balance < -1 && FactorEquilibrio(raiz->derecha) > 0)
            {
                raiz->derecha = rotacionDerecha(raiz->derecha);
                return rotacionIzquierda(raiz);
            }

            return raiz;
}

void AVL::imprimirInOrder(NodoAVL* raiz)
{
    if (raiz != nullptr)
    {
        imprimirInOrder(raiz->izquierda);
        raiz->libro.imprimirInformacion();
        imprimirInOrder(raiz->derecha);
    }
}

bool AVL::buscar(NodoAVL* raiz, std::string titulo)
{
    if (raiz == nullptr)
    {
        return false;
    }
    if (raiz->libro.getTitulo() == titulo)
    {
        return true;
    }
    if (titulo < raiz->libro.getTitulo())
    {
        return buscar(raiz->izquierda, titulo);
    }
    return buscar(raiz->derecha, titulo);
}


Libro* AVL::busquedaLibroTitulo(NodoAVL* raiz, std::string titulo)
{
    if (raiz == nullptr)
    {
        return nullptr;
    }
    if (raiz->libro.getTitulo() == titulo)
    {
        return &(raiz->libro);
    }
    if (titulo < raiz->libro.getTitulo())
    {
        return busquedaLibroTitulo(raiz->izquierda, titulo);
    }
    return busquedaLibroTitulo(raiz->derecha, titulo);
}

Libro* AVL::buscarLibro(std::string titulo)
{
    MedidorTiempo timer("Busqueda Titulo Arbol AVL");
    return (busquedaLibroTitulo(raiz, titulo));
}

void AVL::insertar(Libro libro)
{
    raiz = insertar(raiz, libro);
}

void AVL::eliminar(std::string titulo)
{
    raiz = eliminar(raiz, titulo);
}

bool AVL::buscar(std::string titulo)
{
    return buscar(raiz,titulo);
}

void AVL::imprimir()
{
    imprimirInOrder(raiz);
    std::cout << std::endl;
}

std::string AVL::conversionLowerCase(const std::string& string)
{
    std::string resultado = string;
    std::transform(string.begin(), string.end(), resultado.begin(), ::tolower);
    return resultado;
}
