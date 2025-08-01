#include "pch.h"
#include "VehiculoElectrico.h"
#include <iostream>
using namespace std;

VehiculoElectrico::VehiculoElectrico(string modelo, double bateria, double cargaMaxima)
    : modelo(modelo), bateria(bateria), cargaMaxima(cargaMaxima) {}

void VehiculoElectrico::mostrarInformacion() {
    cout << "Informacion del Vehiculo Electrico:" << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Bateria: " << bateria << "%" << endl;
}
std::string VehiculoElectrico::getModelo() const { return modelo; }
double VehiculoElectrico::getBateria() const { return bateria; }
double VehiculoElectrico::getCargaMaxima() const { return cargaMaxima; }
void VehiculoElectrico::setBateria(double nuevaBateria) { bateria = nuevaBateria; }

double VehiculoElectrico::calcularAutonomia() {
    return bateria; 
}


