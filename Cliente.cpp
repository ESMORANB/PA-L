#include "pch.h"
#include "Cliente.h"
#include <iostream>

Cliente::Cliente() : nombre(""), direccion(""), telefono("") {}

Cliente::Cliente(const string& nombre, const string& direccion, const string& telefono)
    : nombre(nombre), direccion(direccion), telefono(telefono) {
}

string Cliente::getNombre() const { return nombre; }
string Cliente::getDireccion() const { return direccion; }
string Cliente::getTelefono() const { return telefono; }

void Cliente::setNombre(const string& nombre) { this->nombre = nombre; }
void Cliente::setDireccion(const string& direccion) { this->direccion = direccion; }
void Cliente::setTelefono(const string& telefono) { this->telefono = telefono; }

void Cliente::mostrarInfo() const {
    cout << "Cliente: " << nombre << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Teléfono: " << telefono << endl;
}
