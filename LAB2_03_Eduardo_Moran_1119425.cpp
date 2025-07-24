#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "Figura.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"


using namespace std;
using namespace System;

int main()
{
	cout << "Figuras Geometricas" << endl << endl;

	Circulo circulo(2.5f);
	Rectangulo rectangulo(2.0f, 3.0f);
	Triangulo triangulo(3.0f, 4.0f, 5.0f);

	cout << "Ciculo:" << endl;
	circulo.dibujar();
	circulo.dibujar("verde");
	cout << "Area: " << circulo.calcularArea() << endl;
	cout << "Perimetro: " << circulo.calcularPerimetro() << endl << endl;

	cout << "Rectangulo:" << endl;
	rectangulo.dibujar();
	rectangulo.dibujar("rojo");
	rectangulo.dibujar(true); 
	rectangulo.dibujar(false);
	cout << "Area: " << rectangulo.calcularArea() << endl;
	cout << "Perimetro: " << rectangulo.calcularPerimetro() << endl << endl;

	cout << "Triangulo:" << endl;
	triangulo.dibujar();
	triangulo.dibujar("azul");
	triangulo.dibujar(2); 
	triangulo.dibujar(5);
	cout << "Area: " << triangulo.calcularArea() << endl;
	cout << "Perimetro: " << triangulo.calcularPerimetro() << endl << endl;



    return 0;
}
