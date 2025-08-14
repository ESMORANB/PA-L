#include "pch.h"
#include "QuesoEsferico.h"
#include <iostream>

// No definas PI aquí, ya está en Queso.h

QuesoEsferico::QuesoEsferico(double radio, double costoBase, double costoUnitario, bool debug)
    : Queso("Esférico", costoBase, costoUnitario, debug), radio(radio) {
    validarDimensionPositiva(radio, "radio de la esfera");
}

double QuesoEsferico::calcularVolumen() {
    volumen = (4.0 / 3.0) * PI * radio * radio * radio;

    if (debugMode) {
        std::cout << "[DEBUG] Calculando volumen de queso esférico:" << std::endl;
        std::cout << "[DEBUG] Fórmula: (4/3) × π × radio³" << std::endl;
        std::cout << "[DEBUG] Radio: " << radio << std::endl;
        std::cout << "[DEBUG] Volumen: (4/3) × " << PI << " × " << radio << "³ = " << volumen << std::endl;
    }

    return volumen;
}

std::string QuesoEsferico::obtenerDimensiones() const {
    return "Radio: " + std::to_string(radio) + " unidades";
}

double QuesoEsferico::getRadio() const { return radio; }


