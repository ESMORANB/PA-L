#pragma once
#include "Figura.h"
#include <iostream>
#include <string>

using namespace std;

class Triangulo : public Figura
{
private:
    float lado1, lado2, lado3;

public:
    Triangulo(float l1, float l2, float l3);
    float calcularArea() override;
    float calcularPerimetro() override;
    void dibujar() override;
    void dibujar(string color);
    void dibujar(int grosor);
};