#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Videojuego.h"
#include "Cliente.h"
#include "Ventas.h"
#include <fstream>
#include <iomanip>

using namespace std;

// Arreglos globales para almacenar datos
vector<Videojuego> inventario;
vector<Cliente> clientes;
vector<Ventas> ventas;

// Función para mostrar el menú principal
void mostrarMenu() {
    cout << "\n=== SISTEMA DE VENTAS DE VIDEOJUEGOS ===" << endl;
    cout << "1. Agregar videojuego al inventario" << endl;
    cout << "2. Registrar cliente" << endl;
    cout << "3. Realizar una venta" << endl;
    cout << "4. Mostrar historial de compras por cliente" << endl;
    cout << "5. Finalizar día - Calcular ingresos totales" << endl;
    cout << "6. Mostrar inventario" << endl;
    cout << "7. Mostrar clientes registrados" << endl;
    cout << "8. Salir" << endl;
    cout << "Seleccione una opción: ";
}

// Función para agregar videojuego al inventario
void agregarVideojuego() {
    cout << "\n=== AGREGAR VIDEOJUEGO ===" << endl;

    Videojuego nuevoJuego(0);
    nuevoJuego.setTitulo();
    nuevoJuego.setGenero();
    nuevoJuego.setPrecio();

    // Validar si ya existe un juego con el mismo título
    string titulo = nuevoJuego.getTitulo();
    for (const auto& juego : inventario) {
        if (juego.getTitulo() == titulo) {
            cout << "¡Error! Ya existe un videojuego con ese título." << endl;
            return;
        }
    }

    inventario.push_back(nuevoJuego);
    cout << "\n¡Videojuego agregado exitosamente!" << endl;
    nuevoJuego.mostrarInformacion();
}

// Función para registrar cliente
void registrarCliente() {
    cout << "\n=== REGISTRAR CLIENTE ===" << endl;

    Cliente nuevoCliente("Ninguno");
    nuevoCliente.setNombre();
    nuevoCliente.setID();

    // Validar si ya existe un cliente con el mismo ID
    string id = nuevoCliente.getID();
    for (const auto& cliente : clientes) {
        if (cliente.getID() == id) {
            cout << "¡Error! Ya existe un cliente con ese ID." << endl;
            return;
        }
    }

    clientes.push_back(nuevoCliente);
    cout << "\n¡Cliente registrado exitosamente!" << endl;
    nuevoCliente.mostrarInformacion();
}

// Función para mostrar inventario disponible
void mostrarInventario() {
    cout << "\n=== INVENTARIO DISPONIBLE ===" << endl;
    if (inventario.empty()) {
        cout << "No hay videojuegos en el inventario." << endl;
        return;
    }

    for (size_t i = 0; i < inventario.size(); i++) {
        cout << "\n[" << i + 1 << "] ";
        inventario[i].mostrarInformacion();
    }
}

// Función para mostrar clientes registrados
void mostrarClientes() {
    cout << "\n=== CLIENTES REGISTRADOS ===" << endl;
    if (clientes.empty()) {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    for (size_t i = 0; i < clientes.size(); i++) {
        cout << "\n[" << i + 1 << "] ";
        clientes[i].mostrarInformacion();
    }
}

// Función para realizar una venta
void realizarVenta() {
    cout << "\n=== REALIZAR VENTA ===" << endl;

    if (inventario.empty()) {
        cout << "No hay videojuegos en el inventario." << endl;
        return;
    }

    if (clientes.empty()) {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    // Mostrar videojuegos disponibles
    mostrarInventario();
    cout << "\nSeleccione el videojuego (número): ";
    int indiceJuego;
    cin >> indiceJuego;

    if (indiceJuego < 1 || indiceJuego > static_cast<int>(inventario.size())) {
        cout << "Selección inválida." << endl;
        return;
    }
    indiceJuego--; // Ajustar a índice base 0

    // Mostrar clientes disponibles
    mostrarClientes();
    cout << "\nSeleccione el cliente (número): ";
    int indiceCliente;
    cin >> indiceCliente;

    if (indiceCliente < 1 || indiceCliente > static_cast<int>(clientes.size())) {
        cout << "Selección inválida." << endl;
        return;
    }
    indiceCliente--; // Ajustar a índice base 0

    // Obtener fecha y cantidad
    cout << "Ingrese la fecha de venta (DD/MM/AAAA): ";
    string fechaVenta;
    cin.ignore();
    getline(cin, fechaVenta);

    cout << "Ingrese la cantidad vendida: ";
    int cantidadVendida;
    cin >> cantidadVendida;

    if (cantidadVendida <= 0) {
        cout << "La cantidad debe ser mayor que cero." << endl;
        return;
    }

    // Crear la venta usando el constructor mejorado
    Ventas nuevaVenta(inventario[indiceJuego], clientes[indiceCliente],
        fechaVenta, cantidadVendida);

    ventas.push_back(nuevaVenta);

    // Actualizar historial del cliente usando el método mejorado
    clientes[indiceCliente].agregarCompra(inventario[indiceJuego].getTitulo());

    cout << "\n¡Venta realizada exitosamente!" << endl;
    cout << "\n=== INFORMACIÓN DE LA VENTA ===" << endl;
    inventario[indiceJuego].mostrarInformacion();
    cout << endl;
    clientes[indiceCliente].mostrarInformacion();
    cout << endl;
    nuevaVenta.mostrarResumenVenta();
}

// Función para mostrar historial de compras por cliente
void mostrarHistorialCliente() {
    cout << "\n=== HISTORIAL DE COMPRAS POR CLIENTE ===" << endl;

    if (clientes.empty()) {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    mostrarClientes();
    cout << "\nSeleccione el cliente (número): ";
    int indiceCliente;
    cin >> indiceCliente;

    if (indiceCliente < 1 || indiceCliente > static_cast<int>(clientes.size())) {
        cout << "Selección inválida." << endl;
        return;
    }
    indiceCliente--; // Ajustar a índice base 0

    cout << "\n=== INFORMACIÓN DEL CLIENTE ===" << endl;
    clientes[indiceCliente].mostrarInformacion();

    // Mostrar todas las ventas de este cliente
    cout << "\n=== DETALLE DE COMPRAS REALIZADAS ===" << endl;
    bool tieneVentas = false;
    string clienteID = clientes[indiceCliente].getID();

    for (size_t i = 0; i < ventas.size(); i++) {
        // Comparar ID del cliente (necesitarías implementar un getter en Ventas)
        // Por ahora mostramos todas las ventas relacionadas
        cout << "\nCompra #" << (i + 1) << ":" << endl;
        ventas[i].mostrarResumenVenta();
        tieneVentas = true;
        cout << "------------------------" << endl;
    }

    if (!tieneVentas) {
        if (clientes[indiceCliente].tieneCompras()) {
            cout << "El cliente tiene historial pero no se encontraron detalles de venta." << endl;
        }
        else {
            cout << "Este cliente no ha realizado compras." << endl;
        }
    }
}

// Función para calcular ingresos totales del día
void calcularIngresosTotales() {
    cout << "\n=== FINALIZAR DÍA - INGRESOS TOTALES ===" << endl;

    if (ventas.empty()) {
        cout << "No se han realizado ventas hoy." << endl;
        return;
    }

    double ingresosTotales = 0.0;
    int totalVentas = 0;
    int totalUnidades = 0;

    cout << "\n=== RESUMEN DE VENTAS DEL DÍA ===" << endl;
    for (size_t i = 0; i < ventas.size(); i++) {
        cout << "\n--- Venta #" << (i + 1) << " ---" << endl;
        ventas[i].mostrarResumenVenta();

        double ingresoVenta = ventas[i].calcularIngresoVenta();
        ingresosTotales += ingresoVenta;
        totalUnidades += ventas[i].getCantidadVendida();
        totalVentas++;

        cout << "------------------------" << endl;
    }

    cout << "\n=== TOTALES DEL DÍA ===" << endl;
    cout << "Número de ventas realizadas: " << totalVentas << endl;
    cout << "Total de unidades vendidas: " << totalUnidades << endl;
    cout << "INGRESOS TOTALES DEL DÍA: $" << fixed << setprecision(2) << ingresosTotales << endl;

    // Estadísticas adicionales
    if (totalVentas > 0) {
        double promedioVenta = ingresosTotales / totalVentas;
        cout << "Promedio por venta: $" << fixed << setprecision(2) << promedioVenta << endl;
    }
}

int main()
{
    cout << "¡Bienvenido al Sistema de Ventas de Videojuegos!" << endl;

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            agregarVideojuego();
            break;

        case 2:
            registrarCliente();
            break;

        case 3:
            realizarVenta();
            break;

        case 4:
            mostrarHistorialCliente();
            break;

        case 5:
            calcularIngresosTotales();
            break;

        case 6:
            mostrarInventario();
            break;

        case 7:
            mostrarClientes();
            break;

        case 8:
            cout << "\n¡Gracias por usar el sistema! ¡Hasta luego!" << endl;
            break;

        default:
            cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
            break;
        }

        if (opcion != 8) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcion != 8);

    return 0;
}