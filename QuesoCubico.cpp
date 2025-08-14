#include "pch.h"
#include "QuesoCubico.h"
#include <iostream>

QuesoCubico::QuesoCubico(double longitud, double costoBase, double costoUnitario, bool debug)
    : Queso("C�bico", costoBase, costoUnitario, debug), longitud(longitud) {
    validarDimensionPositiva(longitud, "longitud del cubo");
}

double QuesoCubico::calcularVolumen() {
    volumen = longitud * longitud * longitud;

    if (debugMode) {
        cout << "[DEBUG] Calculando volumen de queso c�bico:" << endl;
        cout << "[DEBUG] F�rmula: longitud�" << endl;
        cout << "[DEBUG] Longitud: " << longitud << endl;
        cout << "[DEBUG] Volumen: " << longitud << "� = " << volumen << endl;
    }

    return volumen;
}

string QuesoCubico::obtenerDimensiones() const {
    return "Longitud: " + to_string(longitud) + " unidades";
}

double QuesoCubico::getLongitud() const { return longitud; }

