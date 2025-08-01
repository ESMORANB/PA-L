#include "pch.h"
#include "BicicletaElectrica.h"
#include <iostream>
using namespace std;

BicicletaElectrica::BicicletaElectrica(std::string modelo, double bateria, double cargaMaxima)
    : VehiculoElectrico(modelo, bateria, cargaMaxima) {}

void BicicletaElectrica::mostrarInformacion() {
    cout << "Bicicleta: " << getModelo() << ", Bateria: " << getBateria() << endl;
}

void BicicletaElectrica::conducir(double distancia) {
    double bateriaActual = getBateria();
    if (bateriaActual >= distancia) {
        setBateria(bateriaActual - distancia);
        cout << "Conduciendo bicicleta eléctrica " << distancia << " km." << endl;
    } else {
        cout << "Batería insuficiente para conducir " << distancia << " km." << endl;
    }
}
// Agregar al final de BicicletaElectrica.cpp:

const double BicicletaElectrica::KM_POR_PORCENTAJE = 0.5; // Definir la constante

double BicicletaElectrica::calcularAutonomia() {
    return getBateria() * KM_POR_PORCENTAJE;
}

void BicicletaElectrica::recargar(double cantidad) {
    if (cantidad > 0) {
        double nuevaCarga = getBateria() + cantidad;
        if (nuevaCarga > getCargaMaxima()) {
            setBateria(getCargaMaxima());
            cout << "Bicicleta " << getModelo() << " recargada al máximo (" << getCargaMaxima() << "%)" << endl;
        }
        else {
            setBateria(nuevaCarga);
            cout << "Bicicleta " << getModelo() << " recargada. Nuevo nivel: " << getBateria() << "%" << endl;
        }
    }
}

void BicicletaElectrica::verificarSeguridad() {
    if (getBateria() < 10.0) {
        cout << "Advertencia: Batería baja en bicicleta " << getModelo()
            << " (" << getBateria() << "%). Considere recargar." << endl;
    }
    else {
        cout << "Verificación de seguridad de la bicicleta " << getModelo() << " exitosa." << endl;
    }
}