#pragma once
#include <exception>
#include <string>
using namespace std;

class ExcepcionDimensionesInvalidas : public exception {
private:
    string mensaje;
public:
    ExcepcionDimensionesInvalidas(const string& msg);
    const char* what() const noexcept override;
};