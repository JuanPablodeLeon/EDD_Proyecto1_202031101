//
// Created by juanp on 30/09/2025.
//

#include "../ArchivosH/Funciones/Funcionalidades.h"

#include <bits/atomic_wait.h>

Funcionalidades::Funcionalidades()
{
    listaSinOrdenar = new ListaNormal();
    listaOrdenada = new ListaOrdenada();
    listaTitulo = new AVL();
    listaFechas = new B(3);
}

Funcionalidades::~Funcionalidades()
{
    delete listaSinOrdenar;
    delete listaOrdenada;
    delete listaTitulo;
    delete listaFechas;
}


void Funcionalidades::textoMenu()
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

void Funcionalidades::menu()
{
    int opcion;
    do
    {
        textoMenu();
        std::cout <<"Ingrese Opcion a Escoger:  ";
        std::cin >> opcion;
        switch (opcion)
        {
        case 1://Cargar El CSv
                cargarCSV();
                break;

        /*------- Buscquedas --------*/
        case 2: //Titulo
            buscarTitulo();
            break;
        case 3:// ISBN
            buscarISBN();
            break;
        case 4: //Genero
            break;
        case 5: //Fecha
            buscarFecha();
            break;
        /*------- Fin Busquedas --------*/

        case 6: //Eliminaciones
            EliminarLibro();
            break;
        case 7: //Listado por Titulos (AVL inorder)
            ListarLibros();
            break;
        case 8: //Graficas
            break;
        case 0: //Salir del programa
            std::cout<<"Saliendo del Programa"<<std::endl;
            break;
        default:
            std::cout<<"Ingrese una opcion valida"<<std::endl;
        }
        if(opcion != 0)
        {
            std::cout<<"Enter para continuar.. \n";
            std::cin.ignore();
        }
    }
    while (opcion != 0);

}

void Funcionalidades::cargarCSV()
{
    std::cin.ignore();

    std::string filename;
    std::cout<< "Ingrese la ruta del Archivo CSV: ";
    std::getline(std::cin, filename);

    if (verificarComillas(filename))
    {
        filename = filename.substr(1, filename.length() - 2);
    }


    std::ifstream file(filename);
    if (!file.is_open()) //En caso de no poder cargar el archivo
    {
        std::cerr << "Error con el archvivo: "<<filename <<std::endl;
        return;
    }
    int librosValidos = 0;
    int librosNoValidos = 0;
    int librosRepetidos = 0;
    std::string line;


    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string titulo, isbn, genero, fecha, autor;

        if (std::getline(ss, titulo, ',') && std::getline(ss, isbn, ',') && std::getline(ss, genero, ',') && std::getline(ss, fecha, ',') && std::getline(ss, autor))
        {
        //MODIFICAR VERIFICACION SI LA COMILLA ESTA VACIA
            if (!titulo.empty() && !isbn.empty() && !genero.empty() && !fecha.empty() && !autor.empty())
            {
                if (verificarComillas(titulo) && verificarComillas(isbn) && verificarComillas(genero) && verificarComillas(fecha) && verificarComillas(autor))
                {
                    //Devuele el string sin las comillas
                    titulo = titulo.substr(1, titulo.length() - 2);
                    isbn = isbn.substr(1, isbn.length() - 2);
                    genero = genero.substr(1, genero.length() - 2);
                    fecha = fecha.substr(1, fecha.length() - 2);
                    autor = autor.substr(1, autor.length() - 2);

                    if (esFechaValida(fecha) && esISBNValida(isbn))
                    {
                        if (listaOrdenada->busquedaSinTiempo(isbn) == nullptr)
                        {
                            std::cout<<"Entra a agregar" << std::endl;
                            listaOrdenada->insertar(Libro(titulo, isbn,genero,fecha,autor));
                            listaSinOrdenar->insertar(Libro(titulo, isbn,genero,fecha,autor));
                            listaTitulo->insertar(Libro(titulo, isbn,genero,fecha,autor));
                            std::cout<<"Entra a agregar" << std::endl;
                            listaFechas->insertar(Libro(titulo, isbn,genero,fecha,autor));
                            librosValidos++;
                        }
                        else
                        {
                            librosRepetidos++;
                        }
                    }
                    else
                    {
                        librosNoValidos++;
                    }

                }
                else
                {
                    librosNoValidos++;
                }

            }
            else
            {
                librosNoValidos++;
            }
        }
        else
        {
            librosNoValidos++;
        }
    }
    file.close();

    std::cout<<"Libros Cargados a la Biblioteca"<< std::endl;
    std::cout <<"Libros Validos: "<< librosValidos <<std::endl;
    std::cout <<"Libros No Validos: "<< librosNoValidos <<std::endl;
    std::cout <<"Libros Repetidos: "<< librosRepetidos <<std::endl;
}

void Funcionalidades::buscarISBN()
{
    std::string ISBN;
    std::cout << "Ingrese ISBN a buscar:" << std::endl;
    std::getline(std::cin, ISBN);
    Libro* libroBuscado = listaOrdenada->busquedaTiempo(ISBN);
    Libro* libroBuscadoNormal = listaSinOrdenar->buscarISBN(ISBN);

    if (libroBuscado != nullptr && libroBuscadoNormal != nullptr)
    {

        std::cout << "Libro encontrado:" << std::endl;
        libroBuscado->imprimirInformacion();
    }
    else
    {
        std::cout << "Libro no encontrado" << std::endl;
    }
}

//Agregar Busqueda
void Funcionalidades::buscarTitulo()
{
    std::cin.ignore();
    std::string titulo;

    std::cout << "Ingrese el Titulo a Buscar: " << std::endl;

    std::getline(std::cin, titulo);

    Libro* TituloBuscado = listaSinOrdenar->buscarTitulo(titulo);
    Libro* TituloBuscadoAVL = listaTitulo->buscarLibro(titulo);

    if (TituloBuscadoAVL != nullptr && TituloBuscado != nullptr)
    {
        std::cout << "Libro encontrado:" << std::endl;
        TituloBuscadoAVL->imprimirInformacion();
    }
    else
    {
        std::cout<< "Libro no encontrado" << std::endl;
    }
}


bool Funcionalidades::esFechaValida(const std::string& fecha)
{
    int fechaSize = fecha.length();
    int cantNumeros = 0;
    for (int i = 0; i < fechaSize; i++)
    {
        if (std::isdigit(fecha[i]))
        {
            cantNumeros++;
        }
    }
    return (cantNumeros == fechaSize) ? true : false;
}

bool Funcionalidades::verificarComillas(const std::string& palabra)
{
    return (palabra[0] == 34 && palabra[palabra.size()-1] == 34) ? true : false;
}

bool Funcionalidades::esISBNValida(const std::string& isbn)
{
    std::string isbnLimpio;
    for (char c : isbn)
    {
        if (std::isdigit(c) || c == 'X' || c == 'x')
        {
            isbnLimpio += std::toupper(c);
        }
    }

    if (isbnLimpio.length() == 13)
    {
        if (isbnLimpio.substr(0,3) != "978" && isbnLimpio.substr(0,3) != "979")
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return true;
}

void Funcionalidades::ListarLibros()
{
   /* std::cout<<"---------------------------- NORMAL --------------------------"<<std::endl;
    listaSinOrdenar->imprimir();
    std::cout<<"---------------------------- Ordenado --------------------------"<<std::endl;
    listaOrdenada->imprimir();*/
    std::cout<<"---------------------------- Titulos --------------------------"<<std::endl;
    listaTitulo->imprimir();
}

int Funcionalidades::conversionInt(const std::string& fecha)
{
    return std::stoi(fecha);
}


void Funcionalidades::buscarFecha()
{
    std::cin.ignore();
    std::string fechaInicial;
    std::string fechaFinal;
    std::cout <<"Ingrese la Fecha Inicial"<< std::endl;
    std::cin >> fechaInicial;
    std::cout <<"Ingrese la Fecha FInal"<< std::endl;
    std::cin >> fechaFinal;

    if (esFechaValida(fechaInicial) && esFechaValida(fechaFinal))
    {
        int inicial = conversionInt(fechaInicial);
        int final = conversionInt(fechaFinal);

        listaFechas->showRangeDetailed(inicial, final);

        std::cout<<"Son Ambas fechas validas"<< std::endl;
    }
}

void Funcionalidades::EliminarLibro()
{
    std::cin.ignore();
    std::string LibroBuscar;
    std::cout <<"Ingrese el ISBN del libro"<< std::endl;
    std::getline(std::cin, LibroBuscar);

    Libro* libroEliminar = listaOrdenada->buscarISBN(LibroBuscar);
    if (libroEliminar != nullptr)
    {
        std::string refISBN = LibroBuscar;
        std::string refTitulo = libroEliminar->getTitulo();
        std::cout<<"El Libro a Eliminar es el Siguiente "<< std::endl;
        libroEliminar->imprimirInformacion();

        listaSinOrdenar->eliminar(refISBN);
        listaOrdenada->eliminar(LibroBuscar);
        //std::cout<<"|| "<< refISBN <<" || "<<refTitulo<< std::endl;
        listaTitulo->eliminar(refTitulo);
        //Agregar la eliminacion en B

        std::cout<<"Eliminado "<< std::endl;
    }
}
