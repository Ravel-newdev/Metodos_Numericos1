#include <cmath>

#include "newton_methods.h"

// Derivada por aproximação numérica
inline double numeric_derivative(const Function& func, double x, double h) {
    return (func.f(x + h) - func.f(x - h)) / (2.0 * h);
}

/**
 * O item muda a forma que calculamos a derivada. Não iremos
 * obter pela função df(), usaremos aproximação numérica por
 * diferença finita.
 * 
 * f'(x) ≈ (f(x+ h) - f(x-h))/2h
 */
NewtonResult newton_numeric(
    const Function& func, double d0, double eps, double h, int maxIter
) {
    NewtonResult R{};
    double x = d0, prev = x;
    R.converged = false;

    for (int k = 1; k <= maxIter; ++k) {
        double fx = func.f(x);
        double dfx = numeric_derivative(func, x, h);

        if (std::fabs(dfx) < 1e-14) {
            R.root = x;
            R.fval = fx;
            R.error = std::fabs(x - prev);
            R.iterations = k - 1;
            return R;
        }

        double xnext = x - fx / dfx;
        double err = std::fabs(xnext - x);

        prev = x;
        x = xnext;

        if (err < eps || std::fabs(fx) < eps) {
            R.root = x;
            R.fval = func.f(x);
            R.error = err;
            R.iterations = k;
            R.converged = true;
            return R;
        }
    }

    R.root = x;
    R.fval = func.f(x);
    R.error = std::fabs(x - prev);
    R.iterations = maxIter;
    R.converged = false;
    return R;
}