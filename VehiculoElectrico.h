#pragma once
#include <string>

using namespace std;

class VehiculoElectrico {
protected:
    std::string modelo;
    double bateria;
    double cargaMaxima;
public:
    VehiculoElectrico(std::string modelo, double bateria, double cargaMaxima);

    std::string getModelo() const;
    double getBateria() const;
    void setBateria(double nuevaBateria);

    virtual void mostrarInformacion();
    virtual double calcularAutonomia();
    double getCargaMaxima() const;


};

