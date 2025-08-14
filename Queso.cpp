#include "pch.h"
#include "Queso.h"
#include "ExcepcionDimensionesInvalidas.h"
#include <iostream>
#include <iomanip>

Queso::Queso(const string& tipo, double costoBase, double costoUnitario, bool debug)
    : tipo(tipo), costoBase(costoBase), costoUnitario(costoUnitario),
    volumen(0.0), precio(0.0), debugMode(debug) {
}

Queso::~Queso() {}

void Queso::validarDimensionPositiva(double dimension, const string& nombreDimension) {
    if (dimension <= 0) {
        string error = "Error: " + nombreDimension + " debe ser mayor que cero. Valor recibido: " + to_string(dimension);
        if (debugMode) {
            cout << "[DEBUG ERROR] " << error << endl;
        }
        throw ExcepcionDimensionesInvalidas(error);
    }
}

double Queso::calcularPrecio() {
    double vol = calcularVolumen();
    precio = costoBase + (costoUnitario * vol);

    if (debugMode) {
        cout << "[DEBUG] Calculando precio para " << tipo << ":" << endl;
        cout << "[DEBUG] Volumen: " << vol << " unidades cúbicas" << endl;
        cout << "[DEBUG] Costo base: $" << costoBase << endl;
        cout << "[DEBUG] Costo unitario: $" << costoUnitario << "/unidad cúbica" << endl;
        cout << "[DEBUG] Precio final: $" << precio << endl << endl;
    }

    return precio;
}

void Queso::mostrarInfo() const {
    cout << "Tipo: " << tipo << endl;
    cout << "Dimensiones: " << obtenerDimensiones() << endl;
    cout << "Volumen: " << fixed << setprecision(2) << volumen << " unidades cúbicas" << endl;
    cout << "Precio: $" << fixed << setprecision(2) << precio << endl;
}

string Queso::getTipo() const { return tipo; }
double Queso::getCostoBase() const { return costoBase; }
double Queso::getCostoUnitario() const { return costoUnitario; }
double Queso::getVolumen() const { return volumen; }
double Queso::getPrecio() const { return precio; }
void Queso::setDebugMode(bool debug) { debugMode = debug; }