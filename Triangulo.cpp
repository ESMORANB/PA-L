#include "pch.h"
#include "Triangulo.h"
#include "Figura.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Triangulo::Triangulo(float l1, float l2, float l3) : lado1(l1), lado2(l2), lado3(l3) {}

float Triangulo::calcularArea() {
    float s = (lado1 + lado2 + lado3) / 2;
    return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
}

float Triangulo::calcularPerimetro() {
    return lado1 + lado2 + lado3;
}

void Triangulo::dibujar() {
    cout << "Dibujando un triangulo con lados: " << lado1 << ", " << lado2 << ", " << lado3 << endl;
}

void Triangulo::dibujar(string color) {
    cout << "Dibujando un triangulo de color " << color << endl;
}

void Triangulo::dibujar(int grosor) {
    cout << "Dibujando un triangulo con grosor " << grosor << endl;
}