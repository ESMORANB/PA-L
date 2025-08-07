#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Videojuego.h"
#include "Cliente.h"

using namespace std;
class Ventas : public Videojuego, public Cliente
{
protected:
	string fechaVenta;
	int cantidadVendida;

public:

	Ventas(double p, string hc, string fv, int cv);

	// Constructor copia para asignar datos espec�ficos de videojuego y cliente
	Ventas(const Videojuego& juego, const Cliente& cliente, string fv, int cv);

	string getFechaVenta() const;
	int getCantidadVendida() const;

	void setFechaVenta(const string& fv);
	void setCantidadVendida(int cv);


	// M�todos para copiar datos espec�ficos
	void copiarDatosVideojuego(const Videojuego& juego);
	void copiarDatosCliente(const Cliente& cliente);

	void mostrarInformacion() const override;
	void mostrarInformacionCliente() const;
	void mostrarResumenVenta() const;

	void calcularIngresosTotales() const;
	double calcularIngresoVenta() const;

};

