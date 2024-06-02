#ifndef BISECCION_HPP
#define BISECCION_HPP

#include <stdexcept>
#include <functional>

class Biseccion {
public:
    Biseccion(double tolerance = 1e-6, int maxIterations = 1000)
        : tolerance(tolerance), maxIterations(maxIterations) {}

    void setTolerance(double tol) {
        tolerance = tol;
    }

    void setMaxIterations(int maxIter) {
        maxIterations = maxIter;
    }

    double solve(const std::function<double(double)>& func, double a, double b) {
        if (func(a) * func(b) >= 0) {
            throw std::invalid_argument("f(a) and f(b) must have opposite signs.");
        }

        double c;
        for (int i = 0; i < maxIterations; ++i) {
            c = (a + b) / 2;
            if (func(c) == 0 || (b - a) / 2 < tolerance) {
                return c;
            }
            if (func(c) * func(a) > 0) {
                a = c;
            } else {
                b = c;
            }
        }
        throw std::runtime_error("Maximum iterations reached without convergence.");
    }

private:
    double tolerance;
    int maxIterations;
};

#endif // BISECCION_HPP