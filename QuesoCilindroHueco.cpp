#include "pch.h"
#include "QuesoCilindroHueco.h"
#include <iostream>
#include "ExcepcionDimensionesInvalidas.h"

#define PI 3.14159265358979323846

QuesoCilindroHueco::QuesoCilindroHueco(double radioExterno, double radioInterno, double longitud,
    double costoBase, double costoUnitario, bool debug)
    : Queso("Cilindro Hueco", costoBase, costoUnitario, debug),
    radioExterno(radioExterno), radioInterno(radioInterno), longitud(longitud) {

    validarDimensionPositiva(radioExterno, "radio externo");
    validarDimensionPositiva(radioInterno, "radio interno");
    validarDimensionPositiva(longitud, "longitud del cilindro hueco");

    if (radioInterno >= radioExterno) {
        string error = "Error: El radio interno (" + to_string(radioInterno) +
            ") debe ser menor que el radio externo (" + to_string(radioExterno) + ")";
        if (debugMode) {
            cout << "[DEBUG ERROR] " << error << endl;
        }
        throw ExcepcionDimensionesInvalidas(error);
    }
}

double QuesoCilindroHueco::calcularVolumen() {
    volumen = PI * longitud * (radioExterno * radioExterno - radioInterno * radioInterno);

    if (debugMode) {
        cout << "[DEBUG] Calculando volumen de queso cilindro hueco:" << endl;
        cout << "[DEBUG] Fórmula: π × longitud × (radioExterno² - radioInterno²)" << endl;
        cout << "[DEBUG] Radio externo: " << radioExterno << ", Radio interno: " << radioInterno << endl;
        cout << "[DEBUG] Longitud: " << longitud << endl;
        cout << "[DEBUG] Volumen: " << PI << " × " << longitud << " × (" << radioExterno << "² - " << radioInterno << "²) = " << volumen << endl;
    }

    return volumen;
}

string QuesoCilindroHueco::obtenerDimensiones() const {
    return "Radio externo: " + to_string(radioExterno) +
        " unidades, Radio interno: " + to_string(radioInterno) +
        " unidades, Longitud: " + to_string(longitud) + " unidades";
}

double QuesoCilindroHueco::getRadioExterno() const { return radioExterno; }
double QuesoCilindroHueco::getRadioInterno() const { return radioInterno; }
double QuesoCilindroHueco::getLongitud() const { return longitud; }
