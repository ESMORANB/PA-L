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

	// Constructor copia para asignar datos específicos de videojuego y cliente
	Ventas(const Videojuego& juego, const Cliente& cliente, string fv, int cv);

	string getFechaVenta() const;
	int getCantidadVendida() const;

	void setFechaVenta(const string& fv);
	void setCantidadVendida(int cv);


	// Métodos para copiar datos específicos
	void copiarDatosVideojuego(const Videojuego& juego);
	void copiarDatosCliente(const Cliente& cliente);

	void mostrarInformacion() const override;
	void mostrarInformacionCliente() const;
	void mostrarResumenVenta() const;

	void calcularIngresosTotales() const;
	double calcularIngresoVenta() const;

};

