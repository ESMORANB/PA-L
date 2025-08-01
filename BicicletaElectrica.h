#pragma once
#include "VehiculoElectrico.h"
#include "Recargable.h"
#include "Seguridad.h"

class BicicletaElectrica : public VehiculoElectrico, public IRecargable, public ISeguridad {
private:
    static const double KM_POR_PORCENTAJE;

public:
    BicicletaElectrica(std::string modelo, double bateria, double cargaMaxima = 100.0);

 
    double calcularAutonomia() override;
    void mostrarInformacion() override;
    void recargar(double cantidad) override;
    void verificarSeguridad() override;

    void conducir(double distancia);

};

