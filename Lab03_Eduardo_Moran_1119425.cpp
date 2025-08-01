#include "pch.h"
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
#include "VehiculoElectrico.h"
#include "ScooterElectrico.h"
#include "BicicletaElectrica.h"
#include "Utils.h"

using namespace std;

int main() {
    cout << "SISTEMA DE SIMULACION DE VIAJES\n";
    cout << "===============================\n\n";

    // Crear vehículos
    ScooterElectrico patinete("Xiaomi", 50);
    BicicletaElectrica bici("Trek", 35);

    // Mostrar información inicial
    cout << "Estado inicial:\n";
    patinete.mostrarInformacion();
    bici.mostrarInformacion();
    cout << "\n";

    // Simular viajes
    cout << "Simulando viajes:\n";
    simularViaje(patinete, 20);  // Viaje exitoso
    simularViaje(bici, 15);      // Viaje exitoso
    simularViaje(patinete, 100); // Batería insuficiente

    // Mostrar estado final
    cout << "\nEstado final:\n";
    patinete.mostrarInformacion();
    bici.mostrarInformacion();

    return 0;
}