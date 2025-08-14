#pragma once
#include <string>
using namespace std;

class Cliente {
private:
    string nombre;
    string direccion;
    string telefono;

public:
    Cliente();
    Cliente(const string& nombre, const string& direccion, const string& telefono);

    // Getters
    string getNombre() const;
    string getDireccion() const;
    string getTelefono() const;

    // Setters
    void setNombre(const string& nombre);
    void setDireccion(const string& direccion);
    void setTelefono(const string& telefono);

    void mostrarInfo() const;
};

