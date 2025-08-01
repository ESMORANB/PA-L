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
            cout << "Scooter " << modelo << " recargado al m�ximo (" << cargaMaxima << "%)" << endl;
        }
        else {
            bateria = nuevaCarga;
            cout << "Scooter " << modelo << " recargado. Nuevo nivel: " << bateria << "%" << endl;
        }
    }
}

void ScooterElectrico::verificarSeguridad() {
    if (bateria < 20.0) {
        throw runtime_error("Nivel de bater�a cr�tico en scooter " + modelo +
            " (" + to_string(bateria) + "%). No es seguro realizar el viaje.");
    }
    cout << "Verificaci�n de seguridad del scooter " << modelo << " exitosa." << endl;
}

void ScooterElectrico::mostrarInformacion() {
    cout << "\n=== INFORMACI�N DEL SCOOTER EL�CTRICO ===" << endl;
    VehiculoElectrico::mostrarInformacion();
    cout << "Autonom�a actual: " << calcularAutonomia() << " km" << endl;
    cout << "Autonom�a por %: " << autonomiaPorcentaje << " km/%" << endl;
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
            cout << "Conduciendo scooter el�ctrico " << distancia << " km." << endl;
        }
        else {
            cout << "Autonom�a insuficiente para conducir " << distancia << " km." << endl;
        }
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}
