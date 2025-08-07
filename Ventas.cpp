#include "pch.h"
#include "Ventas.h"
#include"Videojuego.h"
#include "Cliente.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


Ventas::Ventas(double p, string hc, string fv, int cv)
	: Videojuego(p), Cliente(hc), fechaVenta(fv), cantidadVendida(cv) {
}

Ventas::Ventas(const Videojuego& juego, const Cliente& cliente, string fv, int cv)
	: Videojuego(juego.getPrecio()), Cliente(cliente.getHistorialCompras()),
	fechaVenta(fv), cantidadVendida(cv) {
	copiarDatosVideojuego(juego);
	copiarDatosCliente(cliente);
}

string Ventas::getFechaVenta() const {
	return fechaVenta;
}

int Ventas::getCantidadVendida() const {
	return cantidadVendida;
}

void Ventas::setFechaVenta(const string& fv) {
	fechaVenta = fv;
}

void Ventas::setCantidadVendida(int cv) {
	cantidadVendida = cv;
}


void Ventas::copiarDatosVideojuego(const Videojuego& juego) {
	string titulo = juego.getTitulo();
	string genero = juego.getGenero();

	titulo.assign(titulo.begin(), titulo.end());
	genero.assign(genero.begin(), genero.end());
}

void Ventas::copiarDatosCliente(const Cliente& cliente) {
	string nombre = cliente.getNombre();
	string id = cliente.getID();
	string historial = cliente.getHistorialCompras();

	setHistorialCompras(historial);
}

void Ventas::mostrarInformacion() const {
	Videojuego::mostrarInformacion();
	Cliente::mostrarInformacion();
	cout << "Fecha de Venta: " << fechaVenta << endl;
	cout << "Cantidad Vendida: " << cantidadVendida << endl;
}

void Ventas::mostrarInformacionCliente() const {
	Cliente::mostrarInformacion();
	cout << "Fecha de Venta: " << fechaVenta << endl;
	cout << "Cantidad Vendida: " << cantidadVendida << endl;
}

void Ventas::mostrarResumenVenta() const {
	cout << "Fecha de Venta: " << fechaVenta << endl;
	cout << "Cantidad Vendida: " << cantidadVendida << endl;
	cout << "Precio Unitario: $" << getPrecio() << endl;
	cout << "Total de la Venta: $" << calcularIngresoVenta() << endl;
}

void Ventas::calcularIngresosTotales() const {
	if (cantidadVendida <= 0) {
		cout << "Cantidad vendida debe ser mayor que cero." << endl;
		return;
	}
	if (getPrecio() <= 0) {
		cout << "Precio del videojuego debe ser mayor que cero." << endl;
		return;
	}
	double ingresosTotales = getPrecio() * cantidadVendida;
	cout << "Ingresos Totales: $" << ingresosTotales << endl;
}

double Ventas::calcularIngresoVenta() const {
	if (cantidadVendida <= 0 || getPrecio() <= 0) {
		return 0.0;
	}
	return getPrecio() * cantidadVendida;
}