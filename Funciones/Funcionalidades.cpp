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

        /*------- Busquedas --------*/
        case 2: //Titulo
            buscarTitulo();
            break;
        case 3:// ISBN
            buscarISBN();
            break;
        case 4: //Genero
            std::cout<<"Funcion No Valida"<<std::endl;
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

//Metodo para Poder Cargar y Leer un Archivo CSV
void Funcionalidades::cargarCSV()
{
    std::cin.ignore(); //Limpia buffer de entrada
    std::string filename; //variable para almacenar el nombre del archivo
    std::cout<< "Ingrese la ruta del Archivo CSV: ";
    std::getline(std::cin, filename);

    if (verificarComillas(filename))
    {
        filename = quitarComillas(filename); //Devuele la ruta sin comillas
    }

    std::ifstream file(filename);//Intenta abrir el archivo
    if (!file.is_open()) //En caso de no poder cargar el archivo
    {
        std::cerr << "Error con el archvivo: "<<filename <<std::endl;
        return;
    }

    //Contadores para los libros
    int librosValidos = 0;
    int librosNoValidos = 0;
    int librosRepetidos = 0;

    std::string line; //Almacena cada linea del archivo

    while (std::getline(file, line))//Lee linea por linea
    {
        std::stringstream ss(line);//Variable par aprocesar la linea
        std::string titulo, isbn, genero, fecha, autor; //Variables para los datos del libro

        //Lee los datos separados por comas
        if (std::getline(ss, titulo, ',') && std::getline(ss, isbn, ',') && std::getline(ss, genero, ',') && std::getline(ss, fecha, ',') && std::getline(ss, autor))
        {
        //MODIFICAR VERIFICACION SI LA COMILLA ESTA VACIA
            if (!titulo.empty() && !isbn.empty() && !genero.empty() && !fecha.empty() && !autor.empty()) //Verifica sino estan vacios los campos
            {
                //Verifica que todos los campos tengan comillas
                if (verificarComillas(titulo) && verificarComillas(isbn) && verificarComillas(genero) && verificarComillas(fecha) && verificarComillas(autor))
                {
                    //Devuele el string sin las comillas
                    titulo = quitarComillas(titulo);
                    isbn = quitarComillas(isbn);
                    genero = quitarComillas(genero);
                    fecha = quitarComillas(fecha);
                    autor = quitarComillas(autor);

                    if (esFechaValida(fecha) && esISBNValida(isbn)) //Verifica que la fecha sea real y el ISBN tenga formato valido
                    {
                        if (listaOrdenada->busquedaSinTiempo(isbn) == nullptr) //Si el ISBN es unico
                        {
                            //Insercion a las listas con datos Validos
                            listaOrdenada->insertar(Libro(titulo, isbn,genero,fecha,autor));
                            listaSinOrdenar->insertar(Libro(titulo, isbn,genero,fecha,autor));
                            listaTitulo->insertar(Libro(titulo, isbn,genero,fecha,autor));
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
    file.close();//Cierre del Archivo

    //Resumen de los Archivos Leidos
    std::cout<<"Libros Cargados a la Biblioteca"<< std::endl;
    std::cout <<"Libros Validos: "<< librosValidos <<std::endl;
    std::cout <<"Libros No Validos: "<< librosNoValidos <<std::endl;
    std::cout <<"Libros Repetidos: "<< librosRepetidos <<std::endl;
}

//Metodo Para buscar un Libro por su ISBN
void Funcionalidades::buscarISBN()
{
    std::cin.ignore();
    std::string ISBN;//Variable para el isbn ingresado por usuario
    std::cout << "Ingrese ISBN a buscar:" << std::endl;
    std::getline(std::cin, ISBN);

    Libro* libroBuscado = listaOrdenada->busquedaTiempo(ISBN); //Busqueda de Forma Binaria
    Libro* libroBuscadoNormal = listaSinOrdenar->buscarISBN(ISBN); //Busqueda de Forma Iterativa

    if (libroBuscado != nullptr && libroBuscadoNormal != nullptr) //Si encontro el libro en ambas listas
    {
        std::cout << "Libro encontrado:" << std::endl;
        libroBuscado->imprimirInformacion();//Muestra la informacion del libro si existe
    }
    else
    {
        std::cout << "Libro no encontrado" << std::endl;//Mensaje en caso de que no exista
    }
}

//Metodo para buscar un Libro por su Titulo
void Funcionalidades::buscarTitulo()
{
    std::cin.ignore();
    std::string titulo;//Variable que Almacena Titulo por el Usuario

    std::cout << "Ingrese el Titulo a Buscar: " << std::endl;

    std::getline(std::cin, titulo);

    Libro* TituloBuscado = listaSinOrdenar->buscarTitulo(titulo);//Busqueda de Forma Iterativa
    Libro* TituloBuscadoAVL = listaTitulo->buscarLibro(titulo); //Busqueda Binaria en Arbol AVL

    if (TituloBuscadoAVL != nullptr && TituloBuscado != nullptr)//Si el titulo existe en ambas listas
    {
        std::cout << "Libro encontrado:" << std::endl;
        TituloBuscadoAVL->imprimirInformacion(); //Informacion del Libro Existente
    }
    else
    {
        std::cout<< "Libro no encontrado" << std::endl;
    }
}

//Funcion para verificar si una Fecha es Valida
bool Funcionalidades::esFechaValida(const std::string& fecha)
{
    int fechaSize = fecha.length(); //La lonitud de la fecha
    int cantNumeros = 0;//Contador para saber numeros en la fecha
    for (int i = 0; i < fechaSize; i++)
    {
        if (std::isdigit(fecha[i]))//Si el char actual es un digito
        {
            cantNumeros++;//Aumenta el contador
        }
    }
    return (cantNumeros == fechaSize) ? true : false; //Devuelve True si cantNumeros es igual a la longitud de fechaSize
}

//Funcion para verificar si una palabra tiene comillas al Inicio y al Final
bool Funcionalidades::verificarComillas(const std::string& palabra)
{
    /*
     * Devuelve True si palabra empieza y termina con comiilas
     * 34 codigo ASCII para "
     */
    return (palabra[0] == 34 && palabra[palabra.size()-1] == 34) ? true : false;
}

//Funcion para ver si el ISBN tiene formato Valido
bool Funcionalidades::esISBNValida(const std::string& isbn)
{
    std::string isbnLimpio;//Variable para guardar el ISBN limpio
    for (char c : isbn)//itera sobre cada char del isbn
    {
        if (std::isdigit(c) || c == 'X' || c == 'x')//si es digito o una 'X'
        {
            isbnLimpio += std::toupper(c);//Lo hace mayuscula y concatena al isbnLimpio
        }
    }

    if (isbnLimpio.length() == 13)//Si isbnLimpio tiene longitud de 13
    {
        if (isbnLimpio.substr(0,3) != "978" && isbnLimpio.substr(0,3) != "979")//Verifica el prefijo
        {
            return false;//Sino es prefijo valido retorna falso
        }
    }
    else
    {
        return false;
    }
    return true;//Devuelve true si el isbn es valido
}

//Metodo para mostrar los libros de forma albatetica
void Funcionalidades::ListarLibros()
{
    std::cout<<"---------------------------- Titulos Alfabeticamente --------------------------"<<std::endl;
    listaTitulo->imprimir();
}

//Metodo para poder Buscar Libros en un Rango de Fechas
void Funcionalidades::buscarFecha()
{
    std::cin.ignore();

    std::string fechaInicial;
    std::string fechaFinal;
    std::cout <<"Ingrese la Fecha Inicial"<< std::endl;
    std::cin >> fechaInicial;
    std::cout <<"Ingrese la Fecha FInal"<< std::endl;
    std::cin >> fechaFinal;

    if (esFechaValida(fechaInicial) && esFechaValida(fechaFinal))//Si ambas fechas con Validas
    {
        //Covierte las fechas de String a Int
        int inicial = conversionInt(fechaInicial);
        int final = conversionInt(fechaFinal);

        if (final > inicial) //Si final es mayor que Inicial
        {
            listaFechas->showRangeDetailed(inicial, final);//Busqueda de rango de Fechas en arbol B
        }
        else
        {
            std::cout<<"La fecha Inicial no puede ser Mayor a la Final "<< std::endl;
        }
    }
    else
    {
        std::cout<<"Fechas Agregadas No Validas "<< std::endl; //Si las fechas no son validas
    }
}

//Metodo para Eliminar un Libro de Todas las Listas
void Funcionalidades::EliminarLibro()
{
    std::cin.ignore();
    std::string LibroBuscar;
    std::cout <<"Ingrese el ISBN del libro"<< std::endl;
    std::getline(std::cin, LibroBuscar);

    Libro* libroEliminar = listaOrdenada->busquedaSinTiempo(LibroBuscar);//busca el libro por su isbn
    if (libroEliminar != nullptr)//Si el libro existe
    {
        //Guardado de Referencias del Libro a Eliminar
        std::string refISBN = LibroBuscar;
        std::string refTitulo = libroEliminar->getTitulo();
        int refFecha = conversionInt(libroEliminar->getFecha());

        std::cout<<"El Libro a Eliminar es el Siguiente "<< std::endl;
        libroEliminar->imprimirInformacion();

        //Elimina el libro de todas las listas
        listaSinOrdenar->eliminar(refISBN);
        listaOrdenada->eliminar(LibroBuscar);
        listaTitulo->eliminar(refTitulo);
        listaFechas->eliminar(refFecha);

        std::cout<<"Eliminado "<< std::endl;
    }
}

//Metodo para poder mostrar de Forma grafica los Arboles B y AVL
void Funcionalidades::GraficarArboles()
{
    std::cout<<"===== Generacion de Graficos de Arboles ===== "<< std::endl;
    listaFechas->generateGraphivzImage();//arbol B
}

//Funcion para poder pasar un string a int
int Funcionalidades::conversionInt(const std::string& fecha)
{
    return std::stoi(fecha);//devuelve la fecha como int
}

//FUncion para poder quitar las comillas de un texto
std::string Funcionalidades::quitarComillas(const std::string& text)
{
    //devuelve el string sin la comilla la inicio y final
    return text.substr(1, text.length() - 2);
}
