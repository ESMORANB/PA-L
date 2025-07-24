#include "pch.h"
#include "Circulo.h"
#include <iostream>
#include <cmath>

using namespace std;

Circulo::Circulo(float r) : radio(r) {}

float Circulo::calcularArea() {
    return 3.14159f * radio * radio;
}

float Circulo::calcularPerimetro() {
    return 2 * 3.14159f * radio;
}

void Circulo::dibujar() {
    cout << "Dibujando un circulo con radio: " << radio << endl;
}

void Circulo::dibujar(string color) {
    cout << "Dibujando un circulo de color " << color << endl;
}
