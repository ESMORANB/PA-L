#include "pch.h"
#include "ScooterElectrico.h"
#include <iostream>
#include <stdexcept>
using namespace std;

ScooterElectrico::ScooterElectrico(const string& modelo, double bateria, double cargaMaxima, double autonomiaPorcentaje)
    : VehiculoElectrico(modelo, bateria, cargaMaxima), autonomiaPorcentaje(autonomiaPorcentaje) {
}

double ScooterElectrico::calcularAutonomia() {
    return bateria * autonomiaPorcentaje;
}

void ScooterElectrico::recargar(double cantidad) {
    if (cantidad > 0) {
        double nuevaCarga = bateria + cantidad;
        if (nuevaCarga > cargaMaxima) {
            bateria = cargaMaxima;
            cout << "Scooter " << modelo << " recargado al máximo (" << cargaMaxima << "%)" << endl;
        }
        else {
            bateria = nuevaCarga;
            cout << "Scooter " << modelo << " recargado. Nuevo nivel: " << bateria << "%" << endl;
        }
    }
}

void ScooterElectrico::verificarSeguridad() {
    if (bateria < 20.0) {
        throw runtime_error("Nivel de batería crítico en scooter " + modelo +
            " (" + to_string(bateria) + "%). No es seguro realizar el viaje.");
    }
    cout << "Verificación de seguridad del scooter " << modelo << " exitosa." << endl;
}

void ScooterElectrico::mostrarInformacion() {
    cout << "\n=== INFORMACIÓN DEL SCOOTER ELÉCTRICO ===" << endl;
    VehiculoElectrico::mostrarInformacion();
    cout << "Autonomía actual: " << calcularAutonomia() << " km" << endl;
    cout << "Autonomía por %: " << autonomiaPorcentaje << " km/%" << endl;
}
double ScooterElectrico::getBateria() const {
    return VehiculoElectrico::getBateria();
}

void ScooterElectrico::conducir(double distancia) {
    try {
        verificarSeguridad();
        if (calcularAutonomia() >= distancia) {
            double consumo = distancia / autonomiaPorcentaje;
            setBateria(getBateria() - consumo);
            cout << "Conduciendo scooter eléctrico " << distancia << " km." << endl;
        }
        else {
            cout << "Autonomía insuficiente para conducir " << distancia << " km." << endl;
        }
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}
