#include "pch.h"
#include <iostream>
#include <string>
#include <limits>
#include "Libro.h"
using namespace std;

// Declaración de 5 punteros individuales para libros
Libro* libro1 = nullptr;
Libro* libro2 = nullptr;
Libro* libro3 = nullptr;
Libro* libro4 = nullptr;
Libro* libro5 = nullptr;

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "    SISTEMA DE GESTIÓN DE LIBROS" << endl;
    cout << "========================================" << endl;
    cout << "1. Registrar Libro" << endl;
    cout << "2. Ver información de Libro" << endl;
    cout << "3. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Seleccione una opción: ";
}

// Función para validar entrada numérica
int leerEntero() {
    int valor;
    while (!(cin >> valor)) {
        cout << "Error: Ingrese un número válido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(); // Limpiar el buffer
    return valor;
}

// Función para validar entrada double
double leerDouble() {
    double valor;
    while (!(cin >> valor)) {
        cout << "Error: Ingrese un número válido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(); // Limpiar el buffer
    return valor;
}

// Función para verificar si un ISBN ya existe
bool isbnExiste(const string& isbn) {
    if (libro1 != nullptr && libro1->getIsbn() == isbn) return true;
    if (libro2 != nullptr && libro2->getIsbn() == isbn) return true;
    if (libro3 != nullptr && libro3->getIsbn() == isbn) return true;
    if (libro4 != nullptr && libro4->getIsbn() == isbn) return true;
    if (libro5 != nullptr && libro5->getIsbn() == isbn) return true;
    return false;
}

// Función para encontrar un puntero libre
int encontrarEspacioLibre() {
    if (libro1 == nullptr) return 1;
    if (libro2 == nullptr) return 2;
    if (libro3 == nullptr) return 3;
    if (libro4 == nullptr) return 4;
    if (libro5 == nullptr) return 5;
    return -1; // No hay espacio
}

// Función para registrar un libro
void registrarLibro() {
    int punteroLibre = encontrarEspacioLibre();

    if (punteroLibre == -1) {
        cout << "\n¡No hay más espacio disponible para registrar libros!" << endl;
        cout << "Máximo 5 libros permitidos." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "      REGISTRO DE NUEVO LIBRO" << endl;
    cout << "========================================" << endl;

    string titulo, autor, isbn, genero;
    double precio;
    int ano, paginas;
    char disponible;
    bool esDisponible;

    cout << "Título: ";
    getline(cin, titulo);

    cout << "Autor: ";
    getline(cin, autor);

    // Validación de ISBN único
    do {
        cout << "ISBN: ";
        getline(cin, isbn);
        if (isbnExiste(isbn)) {
            cout << "Error: Ya existe un libro con este ISBN. Ingrese uno diferente." << endl;
        }
    } while (isbnExiste(isbn));

    cout << "Precio: $";
    precio = leerDouble();

    cout << "Año de publicación: ";
    ano = leerEntero();

    cout << "Número de páginas: ";
    paginas = leerEntero();

    do {
        cout << "¿Está disponible en tienda? (s/n): ";
        cin >> disponible;
        cin.ignore();
        disponible = tolower(disponible);
        if (disponible != 's' && disponible != 'n') {
            cout << "Error: Ingrese 's' para sí o 'n' para no." << endl;
        }
    } while (disponible != 's' && disponible != 'n');

    esDisponible = (disponible == 's');

    cout << "Género: ";
    getline(cin, genero);

    // Asignar a el puntero correspondiente
    switch (punteroLibre) {
    case 1:
        libro1 = new Libro(titulo, autor, isbn, precio, ano, paginas, esDisponible, genero);
        break;
    case 2:
        libro2 = new Libro(titulo, autor, isbn, precio, ano, paginas, esDisponible, genero);
        break;
    case 3:
        libro3 = new Libro(titulo, autor, isbn, precio, ano, paginas, esDisponible, genero);
        break;
    case 4:
        libro4 = new Libro(titulo, autor, isbn, precio, ano, paginas, esDisponible, genero);
        break;
    case 5:
        libro5 = new Libro(titulo, autor, isbn, precio, ano, paginas, esDisponible, genero);
        break;
    }

    cout << "\n¡Libro registrado exitosamente en el puntero " << punteroLibre << "!" << endl;
}

// Función para ver información de libros
void verInformacionLibros() {
    // Contar libros registrados
    int librosRegistrados = 0;
    if (libro1 != nullptr) librosRegistrados++;
    if (libro2 != nullptr) librosRegistrados++;
    if (libro3 != nullptr) librosRegistrados++;
    if (libro4 != nullptr) librosRegistrados++;
    if (libro5 != nullptr) librosRegistrados++;

    if (librosRegistrados == 0) {
        cout << "\nNo hay libros registrados." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "        LIBROS REGISTRADOS" << endl;
    cout << "========================================" << endl;

    // Mostrar lista de libros disponibles
    if (libro1 != nullptr) {
        cout << "1. " << libro1->getTitulo() << " - " << libro1->getAutor() << endl;
    }
    if (libro2 != nullptr) {
        cout << "2. " << libro2->getTitulo() << " - " << libro2->getAutor() << endl;
    }
    if (libro3 != nullptr) {
        cout << "3. " << libro3->getTitulo() << " - " << libro3->getAutor() << endl;
    }
    if (libro4 != nullptr) {
        cout << "4. " << libro4->getTitulo() << " - " << libro4->getAutor() << endl;
    }
    if (libro5 != nullptr) {
        cout << "5. " << libro5->getTitulo() << " - " << libro5->getAutor() << endl;
    }

    cout << "\nIngrese el número del libro que desea consultar (1-5): ";
    int seleccion = leerEntero();

    if (seleccion < 1 || seleccion > 5) {
        cout << "Error: Selección inválida." << endl;
        return;
    }

    Libro* libroSeleccionado = nullptr;
    switch (seleccion) {
    case 1:
        libroSeleccionado = libro1;
        break;
    case 2:
        libroSeleccionado = libro2;
        break;
    case 3:
        libroSeleccionado = libro3;
        break;
    case 4:
        libroSeleccionado = libro4;
        break;
    case 5:
        libroSeleccionado = libro5;
        break;
    }

    if (libroSeleccionado == nullptr) {
        cout << "Error: No hay un libro registrado en esa posición." << endl;
        return;
    }

    // Mostrar información completa del libro seleccionado
    cout << "\n";
    libroSeleccionado->mostrarInfo();
}

// Función para liberar memoria
void liberarMemoria() {
    if (libro1 != nullptr) {
        delete libro1;
        libro1 = nullptr;
    }
    if (libro2 != nullptr) {
        delete libro2;
        libro2 = nullptr;
    }
    if (libro3 != nullptr) {
        delete libro3;
        libro3 = nullptr;
    }
    if (libro4 != nullptr) {
        delete libro4;
        libro4 = nullptr;
    }
    if (libro5 != nullptr) {
        delete libro5;
        libro5 = nullptr;
    }
}

int main() {
    int opcion;

    cout << "========================================" << endl;
    cout << "  BIENVENIDO AL SISTEMA DE LIBROS" << endl;
    cout << "========================================" << endl;

    do {
        mostrarMenu();
        opcion = leerEntero();

        switch (opcion) {
        case 1:
            registrarLibro();
            break;
        case 2:
            verInformacionLibros();
            break;
        case 3:
            cout << "\n¡Gracias por usar el sistema! Liberando memoria..." << endl;
            liberarMemoria();
            cout << "¡Hasta luego!" << endl;
            break;
        default:
            cout << "\nOpción inválida. Por favor seleccione una opción del 1 al 3." << endl;
            break;
        }

        if (opcion != 3) {
            cout << "\nPresione Enter para continuar...";
            cin.get();
        }

    } while (opcion != 3);

    return 0;
}