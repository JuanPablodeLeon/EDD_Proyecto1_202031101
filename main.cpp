#include <iostream>
#include "ArchivosH/ListaEnlazada/Lista.h"
#include "ArchivosH/Funciones/Menu.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
   /* Menu menu;
    menu.iniciar();*/
    Lista* lista = new Lista();

    lista->insertar(Libro("Cien anios de soledad", "978-8437604947", "Novela", "1967", "Gabriel García Márquez"));

    lista->insertar(Libro("1984", "978-0451524935", "Ciencia Ficción", "1949", "George Orwell"));
    lista->insertar(Libro("El Quijote", "978-8424113096", "Novela", "1605", "Miguel de Cervantes"));
    lista->insertar(Libro("Cien anios de soledad", "978-8437604947", "Novela", "1967", "Gabriel García Márquez"));

    lista->imprimir();

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}