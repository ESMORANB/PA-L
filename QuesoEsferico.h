#pragma once
#include "Queso.h"

class QuesoEsferico : public Queso {
private:
    double radio;

public:
    QuesoEsferico(double radio, double costoBase = 15.0, double costoUnitario = 3.0, bool debug = false);
    double calcularVolumen() override;
    string obtenerDimensiones() const override;
    double getRadio() const;
};

