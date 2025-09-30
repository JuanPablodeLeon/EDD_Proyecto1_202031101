//
// Created by juanp on 23/09/2025.
//

#include "../ArchivosH/Libro.h"

#include <iostream>
#include <ostream>

Libro::Libro() {}

Libro::~Libro() {}

Libro::Libro(std::string titulo, std::string ISBN, std::string genero, std::string fecha, std::string autor)
{
    this->titulo = titulo;
    this->ISBN = ISBN;
    this->genero = genero;
    this->fecha = fecha;
    this->autor = autor;
}

std::string Libro::getTitulo()
{
    return this->titulo;
}

std::string Libro::getISBN()
{
    return this->ISBN;
}

std::string Libro::getGenero()
{
    return this->genero;
}

std::string Libro::getFecha()
{
    return this->fecha;
}

std::string Libro::getAutor()
{
    return this->autor;
}

void Libro::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

void Libro::setISBN(std::string ISBN)
{
    this->ISBN = ISBN;
}

void Libro::setGenero(std::string genero)
{
    this->genero = genero;
}

void Libro::setFecha(std::string fecha)
{
    this->fecha = fecha;
}

void Libro::setAutor(std::string autor)
{
    this->autor = autor;
}

void Libro::imprimirInformacion()
{
    std::cout << "|| " << getTitulo() << "  || " << getISBN() << "  ||  " << getGenero() <<"  ||  " << getFecha() <<"  ||  " << getAutor() << "  ||" << std::endl;
   /* std::cout << "ISBN: " << getISBN() << std::endl;
    std::cout << "Genero: " << getGenero() << std::endl;
    std::cout << "Fecha: " << getFecha() << std::endl;
    std::cout << "Autor: " << getAutor() << std::endl;*/

}
