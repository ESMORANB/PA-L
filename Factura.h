#pragma once
#include "Cliente.h"
#include "Queso.h"
#include <vector>

class Factura {
private:
    Cliente cliente;
    vector<Queso*> quesos;
    double total;
    bool debugMode;

public:
    Factura(const Cliente& cliente, bool debug = false);
    ~Factura();

    void agregarQueso(Queso& queso);
    void mostrarFactura() const;
    void setDebugMode(bool debug);

    double getTotal() const;
    int getCantidadQuesos() const;
};

