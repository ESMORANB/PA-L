#pragma once
#include "Queso.h"

class QuesoCubico : public Queso {
private:
    double longitud;

public:
    QuesoCubico(double longitud, double costoBase = 10.0, double costoUnitario = 2.5, bool debug = false);
    double calcularVolumen() override;
    string obtenerDimensiones() const override;
    double getLongitud() const;
};


