#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Recargable.h"
#include "Seguridad.h"
#include "VehiculoElectrico.h"
using namespace std;

class ScooterElectrico : public VehiculoElectrico, public IRecargable, public ISeguridad
{
	protected:
		double autonomiaPorcentaje;
	public:


	ScooterElectrico(const std::string& modelo, double bateria, double cargaMaxima = 100, double autonomiaPorcentaje = 0.8);

	void mostrarInformacion() override;
	double calcularAutonomia() override;
	void recargar(double cantidad) override;
	void verificarSeguridad() override;

	double getBateria() const;
	void conducir(double distancia);


};


