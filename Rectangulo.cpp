#include "pch.h"
#include "Figura.h"
#include "Rectangulo.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Rectangulo::Rectangulo(float b, float h) : base(b), altura(h) {}

float Rectangulo::calcularArea() {
    return base * altura;
}

float Rectangulo::calcularPerimetro() {
    return 2 * (base + altura);
}

void Rectangulo::dibujar() {
    cout << "Dibujando un rectangulo con base: " << base << " y altura: " << altura << endl;
}

void Rectangulo::dibujar(string color) {
    cout << "Dibujando un rectangulo de color " << color << endl;
}

void Rectangulo::dibujar(bool relleno) {
    if (relleno) {
        cout << "Dibujando un rectangulo relleno" << endl;
    }
    else {
        cout << "Dibujando un rectangulo sin relleno" << endl;
    }
}
