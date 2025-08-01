#include "pch.h"
#include "Utils.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void simularViaje(ScooterElectrico& vehiculo, double distancia) {
    try {
        cout << "\n--- Simulando viaje con scooter ---" << endl;
        vehiculo.verificarSeguridad();

        if (vehiculo.calcularAutonomia() >= distancia) {
            double bateriaConsumida = distancia / 0.8; // Asumiendo 0.8 km por %
            vehiculo.setBateria(vehiculo.getBateria() - bateriaConsumida);
            cout << "Viaje exitoso de " << distancia << " km." << endl;
        }
        else {
            cout << "Autonomía insuficiente para el viaje de " << distancia << " km." << endl;
        }
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void simularViaje(BicicletaElectrica& vehiculo, double distancia) {
    cout << "\n--- Simulando viaje con bicicleta ---" << endl;
    vehiculo.verificarSeguridad();
    vehiculo.conducir(distancia);
}