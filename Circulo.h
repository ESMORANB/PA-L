#pragma once  
#include "Figura.h"
#include <iostream>  
#include <string>

using namespace std;

class Circulo : public Figura
{
private:
    float radio;

public:
    Circulo(float r);
    float calcularArea() override;
    float calcularPerimetro() override;
    void dibujar() override;
    void dibujar(string color);
};