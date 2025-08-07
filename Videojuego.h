#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Videojuego
{
protected:
	vector<char> titulo;
	vector<char> genero;
	double precio;

public:
	// Constructor
	Videojuego(double p);

	// Constructor copia
	Videojuego(const Videojuego& otro);

	// Getters
	string getTitulo() const;
	string getGenero() const;
	double getPrecio() const;

	// Setters interactivos
	void setTitulo();
	void setGenero();
	void setPrecio();

	// Setters directos
	void setTitulo(const string& t);
	void setGenero(const string& g);
	void setPrecio(double p);

	// Métodos de utilidad
	virtual void mostrarInformacion() const;
	bool esValido() const; // Verificar si el videojuego tiene datos válidos

	// Operador de asignación
	Videojuego& operator=(const Videojuego& otro);

};

