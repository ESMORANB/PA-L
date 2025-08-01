#pragma once
#include <iostream>
#include <string>

using namespace std;

class IRecargable
{
	virtual void recargar(double cantidad) = 0;
};

