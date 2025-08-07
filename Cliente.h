#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Cliente
{
protected:
	vector<char> nombre;
	vector<char> ID;
	string historialCompras;

public:
	Cliente(string hc);

	Cliente(const Cliente& otro);

	string getNombre() const;
	string getID() const;
	string getHistorialCompras() const;

	void setNombre();
	void setNombre(const string& n);
	void setID();
	void setID(const string& id);
	void setHistorialCompras(const string& hc);

	// Métodos de utilidad
	void mostrarInformacion() const;
	void agregarCompra(const string& nombreVideojuego);
	bool tieneCompras() const;

	// Operador de asignación
	Cliente& operator=(const Cliente& otro);

};

