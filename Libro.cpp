#include "pch.h"
#include "Libro.h"
#include <iostream>
#include <iomanip>
using namespace std;

Libro::Libro() {
    titulo = "";
    autor = "";
    isbn = "";
    precio = 0.0;
    anoPublicacion = 0;
    numeroPaginas = 0;
    disponibleTienda = false;
    genero = "";
}

Libro::Libro(string titulo, string autor, string isbn, double precio,
    int ano, int paginas, bool disponible, string genero) {
    this->titulo = titulo;
    this->autor = autor;
    this->isbn = isbn;
    this->precio = precio;
    this->anoPublicacion = ano;
    this->numeroPaginas = paginas;
    this->disponibleTienda = disponible;
    this->genero = genero;
}

// Métodos set
void Libro::setTitulo(string titulo) {
    this->titulo = titulo;
}

void Libro::setAutor(string autor) {
    this->autor = autor;
}

void Libro::setIsbn(string isbn) {
    this->isbn = isbn;
}

void Libro::setPrecio(double precio) {
    this->precio = precio;
}

void Libro::setAnoPublicacion(int ano) {
    this->anoPublicacion = ano;
}

void Libro::setNumeroPaginas(int paginas) {
    this->numeroPaginas = paginas;
}

void Libro::setDisponibleTienda(bool disponible) {
    this->disponibleTienda = disponible;
}

void Libro::setGenero(string genero) {
    this->genero = genero;
}

// Métodos get
string Libro::getTitulo() const {
    return titulo;
}

string Libro::getAutor() const {
    return autor;
}

string Libro::getIsbn() const {
    return isbn;
}

double Libro::getPrecio() const {
    return precio;
}

int Libro::getAnoPublicacion() const {
    return anoPublicacion;
}

int Libro::getNumeroPaginas() const {
    return numeroPaginas;
}

bool Libro::getDisponibleTienda() const {
    return disponibleTienda;
}

string Libro::getGenero() const {
    return genero;
}

// Método para mostrar información
void Libro::mostrarInfo() const {
    cout << "========================================" << endl;
    cout << "INFORMACIÓN DEL LIBRO" << endl;
    cout << "========================================" << endl;
    cout << "Título: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Precio: $" << fixed << setprecision(2) << precio << endl;
    cout << "Año de publicación: " << anoPublicacion << endl;
    cout << "Número de páginas: " << numeroPaginas << endl;
    cout << "Disponible en tienda: " << (disponibleTienda ? "Sí" : "No") << endl;
    cout << "Género: " << genero << endl;
    cout << "========================================" << endl;
}
