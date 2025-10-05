//
// Created by juanp on 23/09/2025.
//

#ifndef EDD_PROYECTO1_202031101_LIBRO_H
#define EDD_PROYECTO1_202031101_LIBRO_H
#include <string>

class Libro
{
private:
    std::string titulo;
    std::string ISBN;
    std::string genero;
    std::string fecha;
    std::string autor;
;
public:
    Libro();
    ~Libro();
    Libro(std::string titulo, std::string ISBN, std::string genero, std::string fecha, std::string autor);

    std::string getTitulo();
    std::string getISBN();
    std::string getGenero();
    std::string getFecha();
    std::string getAutor();

    void setTitulo(std::string titulo) ;
    void setISBN(std::string ISBN);
    void setGenero(std::string genero);
    void setFecha(std::string fecha);
    void setAutor(std::string autor);

    void imprimirInformacion();
    int conversionInt() const;
};


#endif //EDD_PROYECTO1_202031101_LIBRO_H