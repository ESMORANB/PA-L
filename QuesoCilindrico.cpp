#include "pch.h"
#include "QuesoCilindrico.h"
#include <iostream>

QuesoCilindrico::QuesoCilindrico(double radio, double longitud, double costoBase, double costoUnitario, bool debug)
    : Queso("Cilíndrico", costoBase, costoUnitario, debug), radio(radio), longitud(longitud) {
    validarDimensionPositiva(radio, "radio del cilindro");
    validarDimensionPositiva(longitud, "longitud del cilindro");
}

double QuesoCilindrico::calcularVolumen() {
    volumen = PI * radio * radio * longitud;

    if (debugMode) {
        cout << "[DEBUG] Calculando volumen de queso cilíndrico:" << endl;
        cout << "[DEBUG] Fórmula: π × radio² × longitud" << endl;
        cout << "[DEBUG] Radio: " << radio << ", Longitud: " << longitud << endl;
        cout << "[DEBUG] Volumen: " << PI << " × " << radio << "² × " << longitud << " = " << volumen << endl;
    }

    return volumen;
}

string QuesoCilindrico::obtenerDimensiones() const {
    return "Radio: " + to_string(radio) + " unidades, Longitud: " + to_string(longitud) + " unidades";
}

double QuesoCilindrico::getRadio() const { return radio; }
double QuesoCilindrico::getLongitud() const { return longitud; }



