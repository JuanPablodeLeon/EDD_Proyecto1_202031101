//
// Created by juanp on 02/10/2025.
//

#include "../ArchivosH/Arboles/B.h"

B::B(){}

B::B(int _t)
{
    raiz = NULL;
    t = _t;
}

void B::insertar(Libro libro)
{
    int fechaInt = libro.conversionInt();
    
    if (raiz == NULL) {
        raiz = new NodoB(t, true);
        raiz->libros[0] = libro;
        raiz->fechas[0] = fechaInt;
        raiz->n = 1;
    } else {
        if (raiz->n == 2 * t - 1) {
            NodoB *s = new NodoB(t, false);
            s->C[0] = raiz;
            s->splitChild(0, raiz);
            
            int i = 0;
            if (s->fechas[0] < fechaInt)
                i++;
            s->C[i]->insertNonFull(libro);
            raiz = s;
        } else {
            raiz->insertNonFull(libro);
        }
    }
}

void B::eliminar(int fecha)
{
    if (!raiz) {
        std::cout << "El árbol está vacío\n";
        return;
    }
    
    raiz->remove(fecha);
    
    if (raiz->n == 0) {
        NodoB *tmp = raiz;
        if (raiz->hoja)
            raiz = NULL;
        else
            raiz = raiz->C[0];
        delete tmp;
    }
}

void B::imprimir()
{
    if (raiz != NULL) {
        std::cout << "=== LISTA COMPLETA DE LIBROS ===" << std::endl;
        raiz->imprimir();
    } else {
        std::cout << "El árbol está vacío" << std::endl;
    }
}

void B::showRange(int low, int high)
{
    if (raiz != NULL) {
        std::cout << "Libros en el rango de fechas [" << low << ", " << high << "]: ";
        raiz->showRange(low, high);
        std::cout << std::endl;
    } else {
        std::cout << "El árbol está vacío" << std::endl;
    }
}

void B::showRangeDetailed(int low, int high)
{
    if (raiz != NULL) {
        std::cout << "=== LIBROS EN EL RANGO [" << low << " - " << high << "] ===" << std::endl;
        raiz->showRangeDetailed(low, high);
    } else {
        std::cout << "El árbol está vacío" << std::endl;
    }
}

void B::generateGraphivzImage(const std::string& filename)
{
    if (raiz == NULL) {
        std::cout << "El árbol está vacío, no se puede generar imagen." << std::endl;
        return;
    }

    std::ofstream dotFile(filename + ".dot");
    if (!dotFile.is_open()) {
        std::cout << "Error al crear el archivo DOT." << std::endl;
        return;
    }

    dotFile << "digraph BTree {" << std::endl;
    dotFile << "  node [shape=record, height=.1];" << std::endl;
    dotFile << "  edge [arrowtail=dot, dir=both];" << std::endl;

    int nodeCount = 0;
    raiz->generateGraphivz(dotFile, nodeCount);

    dotFile << "}" << std::endl;
    dotFile.close();

    std::string command = "dot -Tpng " + filename + ".dot -o " + filename + ".png";
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "Imagen generada exitosamente: " << filename << ".png" << std::endl;
    } else {
        std::cout << "Error al generar la imagen. Asegúrate de tener Graphviz instalado." << std::endl;
    }
}

