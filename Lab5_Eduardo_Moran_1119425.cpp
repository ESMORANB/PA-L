#include "pch.h"
#include <iostream>
#include "Cliente.h"
#include "Factura.h"
#include "QuesoCubico.h"
#include "QuesoEsferico.h"
#include "QuesoCilindrico.h"
#include "QuesoCilindroHueco.h"
#include "ExcepcionDimensionesInvalidas.h"

using namespace std;

void mostrarMenu() {
    cout << "\n" << string(40, '=') << endl;
    cout << "    SISTEMA DE PEDIDOS DE QUESOS" << endl;
    cout << string(40, '=') << endl;
    cout << "1. Agregar Queso Cúbico" << endl;
    cout << "2. Agregar Queso Esférico" << endl;
    cout << "3. Agregar Queso Cilíndrico" << endl;
    cout << "4. Agregar Queso Cilindro Hueco" << endl;
    cout << "5. Mostrar Factura" << endl;
    cout << "6. Activar/Desactivar Modo Debug" << endl;
    cout << "7. Salir" << endl;
    cout << string(40, '-') << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    cout << "Bienvenido al Sistema de Gestión de Quesos Suizos" << endl;
    cout << string(50, '=') << endl;

    // Datos del cliente
    string nombre, direccion, telefono;
    cout << "\nIngrese los datos del cliente:" << endl;
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Dirección: ";
    getline(cin, direccion);
    cout << "Teléfono: ";
    getline(cin, telefono);

    Cliente cliente(nombre, direccion, telefono);
    Factura factura(cliente);

    bool debugMode = false;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        try {
            switch (opcion) {
            case 1: { // Queso Cúbico
                double longitud;
                cout << "Ingrese la longitud del cubo: ";
                cin >> longitud;

                QuesoCubico queso(longitud, 10.0, 2.5, debugMode);
                factura.agregarQueso(queso);
                cout << "Queso cúbico agregado exitosamente!" << endl;
                break;
            }
            case 2: { // Queso Esférico
                double radio;
                cout << "Ingrese el radio de la esfera: ";
                cin >> radio;

                QuesoEsferico queso(radio, 15.0, 3.0, debugMode);
                factura.agregarQueso(queso);
                cout << "Queso esférico agregado exitosamente!" << endl;
                break;
            }
            case 3: { // Queso Cilíndrico
                double radio, longitud;
                cout << "Ingrese el radio del cilindro: ";
                cin >> radio;
                cout << "Ingrese la longitud del cilindro: ";
                cin >> longitud;

                QuesoCilindrico queso(radio, longitud, 12.0, 2.8, debugMode);
                factura.agregarQueso(queso);
                cout << "Queso cilíndrico agregado exitosamente!" << endl;
                break;
            }
            case 4: { // Queso Cilindro Hueco
                double radioExterno, radioInterno, longitud;
                cout << "Ingrese el radio externo: ";
                cin >> radioExterno;
                cout << "Ingrese el radio interno: ";
                cin >> radioInterno;
                cout << "Ingrese la longitud: ";
                cin >> longitud;

                QuesoCilindroHueco queso(radioExterno, radioInterno, longitud, 18.0, 3.5, debugMode);
                factura.agregarQueso(queso);
                cout << "Queso cilindro hueco agregado exitosamente!" << endl;
                break;
            }
            case 5: { // Mostrar Factura
                factura.mostrarFactura();
                break;
            }
            case 6: { // Toggle Debug Mode
                debugMode = !debugMode;
                factura.setDebugMode(debugMode);
                cout << "Modo debug " << (debugMode ? "ACTIVADO" : "DESACTIVADO") << endl;
                break;
            }
            case 7: { // Salir
                cout << "\nMostrando factura final:" << endl;
                factura.mostrarFactura();
                cout << "\n¡Gracias por usar nuestro sistema!" << endl;
                break;
            }
            default: {
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
            }
            }
        }
        catch (const ExcepcionDimensionesInvalidas& e) {
            cout << "\nERROR: " << e.what() << endl;
            cout << "El queso no fue agregado a la factura." << endl;
        }
        catch (const exception& e) {
            cout << "\nError inesperado: " << e.what() << endl;
        }

        if (opcion != 7) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcion != 7);

    return 0;
}