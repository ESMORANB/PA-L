#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class Figura
{
public:
    virtual void dibujar();
    virtual float calcularArea() = 0;
    virtual float calcularPerimetro() = 0;
};

