#include "pch.h"
#include "ExcepcionDimensionesInvalidas.h"

ExcepcionDimensionesInvalidas::ExcepcionDimensionesInvalidas(const string& msg) : mensaje(msg) {}

const char* ExcepcionDimensionesInvalidas::what() const noexcept {
    return mensaje.c_str();
}
