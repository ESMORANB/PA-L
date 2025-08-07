#include "pch.h"
#include "Videojuego.h"
using namespace std;

// Constructor
Videojuego::Videojuego(double p) : precio(p) {};

// Constructor copia
Videojuego::Videojuego(const Videojuego& otro)
	: titulo(otro.titulo), genero(otro.genero), precio(otro.precio) {
}

string Videojuego::getTitulo() const {
	return string(titulo.begin(), titulo.end());
}

string Videojuego::getGenero() const {
	return string(genero.begin(), genero.end());
}

double Videojuego::getPrecio() const {
	return precio;
}

void Videojuego::setTitulo() {
	cout << "Ingrese el titulo del videojuego: ";
	string t;
	cin.ignore();
	getline(cin, t);
	titulo.assign(t.begin(), t.end());
}

void Videojuego::setTitulo(const string& t) {
	titulo.assign(t.begin(), t.end());
}

void Videojuego::setGenero() {
	cout << "Ingrese el genero del videojuego: ";
	string g;
	cin.ignore();
	getline(cin, g);
	genero.assign(g.begin(), g.end());
}

void Videojuego::setGenero(const string& g) {
	genero.assign(g.begin(), g.end());
}

void Videojuego::setPrecio() {
	cout << "Ingrese el precio del videojuego: ";
	cin >> precio;
	if (precio < 0) {
		cout << "El precio no puede ser negativo. Se establecerá a 0." << endl;
		precio = 0;
	}
}

void Videojuego::setPrecio(double p) {
	if (p < 0) {
		cout << "El precio no puede ser negativo. Se establecerá a 0." << endl;
		precio = 0;
	}
	else {
		precio = p;
	}
}

void Videojuego::mostrarInformacion() const {
	cout << "Titulo: " << getTitulo() << endl;
	cout << "Genero: " << getGenero() << endl;
	cout << "Precio: $" << getPrecio() << endl;
}

bool Videojuego::esValido() const {
	return !titulo.empty() && !genero.empty() && precio >= 0;
}

Videojuego& Videojuego::operator=(const Videojuego& otro) {
	if (this != &otro) {
		titulo = otro.titulo;
		genero = otro.genero;
		precio = otro.precio;
	}
	return *this;
}