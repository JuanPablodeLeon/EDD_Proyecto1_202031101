//
// Created by juanp on 30/09/2025.
//

#ifndef EDD_PROYECTO1_202031101_FUNCIONALIDADES_H
#define EDD_PROYECTO1_202031101_FUNCIONALIDADES_H
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <iomanip>
#include "../ArchivosH/ListaEnlazada/ListaNormal.h"
#include "../ArchivosH/ListaEnlazada/ListaOrdenada.h"
#include "../ArchivosH/Arboles/AVL.h"

class Funcionalidades
{
private:
    ListaNormal* listaSinOrdenar;
    ListaOrdenada* listaOrdenada;
    AVL* listaTitulo;
    void textoMenu();
    void cargarCSV();
    void buscarTitulo();
    void buscarISBN();
  //  void buscarGenero();
  //  void buscarFecha();
  //  void EliminarLibro();
    void ListarLibros();
  //  void GraficarArboles();

    bool esFechaValida(const std::string& fecha);
    bool verificarComillas(const std::string& palabra);
    bool esISBNValida(const std::string& isbn);
public:
    Funcionalidades();
    ~Funcionalidades();

    void menu();

};


#endif //EDD_PROYECTO1_202031101_FUNCIONALIDADES_H