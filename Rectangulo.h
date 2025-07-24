#pragma once
#include "Figura.h"
#include <iostream>
#include <string>

using namespace std;

class Rectangulo : public Figura
{
private:
    float base;
    float altura;

public:
    Rectangulo(float b, float h);
    float calcularArea() override;
    float calcularPerimetro() override;
    void dibujar() override;
    void dibujar(string color);
    void dibujar(bool relleno);
};

