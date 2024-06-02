#include <iostream>
#include "biseccion.hpp"

int main() {
    // Definir la función no lineal a resolver (por ejemplo, f(x) = x^3 - x - 2)
    auto f = [](double x) { return x * x * x - x - 2; };

    // Crear un objeto Biseccion con una tolerancia y un máximo de iteraciones por defecto
    Biseccion solver;

    // Variables para almacenar los parámetros ingresados por el usuario
    double a, b, tolerancia;
    int maxIteraciones;

    // Mostrar el menú y solicitar los parámetros al usuario
    std::cout << "=== Método de Bisección ===" << std::endl;
    std::cout << "Ingrese el intervalo [a, b] para buscar la raíz:" << std::endl;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "Ingrese la tolerancia: ";
    std::cin >> tolerancia;
    std::cout << "Ingrese el máximo de iteraciones: ";
    std::cin >> maxIteraciones;

    try {
        // Actualizar los parámetros del solver con los valores ingresados por el usuario
        solver.setTolerance(tolerancia);
        solver.setMaxIterations(maxIteraciones);

        // Resolver la ecuación f(x) = 0 en el intervalo [a, b]
        double root = solver.solve(f, a, b);
        std::cout << "La raíz encontrada es: " << root << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}