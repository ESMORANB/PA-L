#pragma once
#include <string>
using namespace std;

const double PI = 3.14159265359;

class Queso {
protected:
    string tipo;
    double costoBase;
    double costoUnitario;
    double volumen;
    double precio;
    bool debugMode;

    void validarDimensionPositiva(double dimension, const string& nombreDimension);

public:
    Queso(const string& tipo, double costoBase, double costoUnitario, bool debug = false);
    virtual ~Queso();

    virtual double calcularVolumen() = 0;
    virtual string obtenerDimensiones() const = 0;
    virtual double calcularPrecio();
    virtual void mostrarInfo() const;

    // Getters
    string getTipo() const;
    double getCostoBase() const;
    double getCostoUnitario() const;
    double getVolumen() const;
    double getPrecio() const;

    void setDebugMode(bool debug);
};

