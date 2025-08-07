#include "pch.h"
#include "Cliente.h"

using namespace std;

// Constructor
Cliente::Cliente(string hc) : historialCompras(hc) {}

// Constructor copia
Cliente::Cliente(const Cliente& otro)
	: nombre(otro.nombre), ID(otro.ID), historialCompras(otro.historialCompras) {
}

string Cliente::getNombre() const {
	return string(nombre.begin(), nombre.end());
}

string Cliente::getID() const {
	return string(ID.begin(), ID.end());
}

string Cliente::getHistorialCompras() const {
	return historialCompras;
}

void Cliente::setNombre() {
	cout << "Ingrese el nombre del cliente: ";
	string n;
	cin.ignore();
	getline(cin, n);
	nombre.assign(n.begin(), n.end());
}

void Cliente::setNombre(const string& n) {
	nombre.assign(n.begin(), n.end());
}

void Cliente::setID() {
	cout << "Ingrese el ID del cliente: ";
	string id;
	cin.ignore();
	getline(cin, id);
	ID.assign(id.begin(), id.end());
}

void Cliente::setID(const string& id) {
	ID.assign(id.begin(), id.end());
}

void Cliente::setHistorialCompras(const string& hc) {
	historialCompras = hc;
}

void Cliente::mostrarInformacion() const {
	cout << "Nombre: " << getNombre() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Historial de Compras: " << getHistorialCompras() << endl;
}

void Cliente::agregarCompra(const string& nombreVideojuego) {
	if (historialCompras == "Ninguno" || historialCompras.empty()) {
		historialCompras = nombreVideojuego;
	}
	else {
		historialCompras += ", " + nombreVideojuego;
	}
}

// Verificar si el cliente tiene compras
bool Cliente::tieneCompras() const {
	return historialCompras != "Ninguno" && !historialCompras.empty();
}

// Operador de asignación
Cliente& Cliente::operator=(const Cliente& otro) {
	if (this != &otro) {
		nombre = otro.nombre;
		ID = otro.ID;
		historialCompras = otro.historialCompras;
	}
	return *this;
}
