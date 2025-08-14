
#include "pch.h"
#include "Factura.h"
#include <iostream>

Factura::Factura(const Cliente& cliente, bool debug)
    : cliente(cliente), total(0.0), debugMode(debug) {}

Factura::~Factura() {
    for (Queso* queso : quesos) {
        delete queso;
    }
}

void Factura::agregarQueso(Queso& queso) {
    quesos.push_back(&queso);
    total += queso.calcularPrecio();
}

void Factura::mostrarFactura() const {
    std::cout << "\n--- FACTURA ---\n";
    cliente.mostrarInfo();
    std::cout << "Quesos adquiridos: " << quesos.size() << std::endl;
    for (const Queso* queso : quesos) {
        queso->mostrarInfo();
        std::cout << std::endl;
    }
    std::cout << "Total a pagar: $" << total << std::endl;
}

void Factura::setDebugMode(bool debug) {
    debugMode = debug;
    for (Queso* queso : quesos) {
        queso->setDebugMode(debug);
    }
}

double Factura::getTotal() const { return total; }
int Factura::getCantidadQuesos() const { return static_cast<int>(quesos.size()); }