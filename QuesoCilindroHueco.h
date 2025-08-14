#pragma once
#include "Queso.h"

class QuesoCilindroHueco : public Queso {
private:
    double radioExterno;
    double radioInterno;
    double longitud;

public:
    QuesoCilindroHueco(double radioExterno, double radioInterno, double longitud,
        double costoBase = 18.0, double costoUnitario = 3.5, bool debug = false);
    double calcularVolumen() override;
    string obtenerDimensiones() const override;
    double getRadioExterno() const;
    double getRadioInterno() const;
    double getLongitud() const;
};


