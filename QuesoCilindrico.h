#pragma once
#include "Queso.h"

class QuesoCilindrico : public Queso {
private:
    double radio;
    double longitud;

public:
    QuesoCilindrico(double radio, double longitud, double costoBase = 12.0, double costoUnitario = 2.8, bool debug = false);
    double calcularVolumen() override;
    string obtenerDimensiones() const override;
    double getRadio() const;
    double getLongitud() const;
};

