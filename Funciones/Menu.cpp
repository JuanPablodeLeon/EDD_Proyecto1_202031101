//
// Created by juanp on 29/09/2025.
//

#include "../ArchivosH/Funciones/Menu.h"

#include <iostream>
#include <ostream>

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::textoMenu()
{
    std::cout <<"---------------------------------------------"<< std::endl;
    std::cout <<"---------------------------------------------"<< std::endl;
    std::cout <<"---------------------------------------------"<< std::endl;
    std::cout <<"-----					-----"<< std::endl;
    std::cout <<"-----					-----"<< std::endl;
    std::cout <<"-----         BIBLIOTECA MAGICA         -----"<< std::endl;
    std::cout <<"-----					-----"<< std::endl;
    std::cout <<"-----					-----"<< std::endl;
    std::cout <<"-----	1. Cargar CSV			-----"<< std::endl;
    std::cout <<"-----					-----"<< std::endl;
    std::cout <<"-----	---	Busqueda 	---	-----"<< std::endl;
    std::cout <<"-----	2. Titulo			-----"<< std::endl;
    std::cout <<"-----	3. ISBN				-----"<< std::endl;
    std::cout <<"-----	4. Genero			-----"<< std::endl;
    std::cout <<"-----	5. Fecha			-----"<< std::endl;
    std::cout <<"-----					-----"<< std::endl;
    std::cout <<"-----	6. Eliminar Libro		-----"<< std::endl;
    std::cout <<"-----	7. Listar por Titulo		-----"<< std::endl;
    std::cout <<"-----	8. Graficar Arboles		-----"<< std::endl;
    std::cout <<"-----	0. Salir			-----"<< std::endl;
    std::cout <<"-----					-----"<< std::endl;
    std::cout <<"-----					-----"<< std::endl;
    std::cout <<"---------------------------------------------"<< std::endl;
    std::cout <<"---------------------------------------------"<< std::endl;
    std::cout <<"---------------------------------------------"<< std::endl;
}



void Menu::iniciar()
{
    textoMenu();
}
