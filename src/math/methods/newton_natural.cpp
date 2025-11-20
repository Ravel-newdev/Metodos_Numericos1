// NaturalNewton.cpp
#include <cmath>
#include <iostream>
#include "newton_methods.h"

NewtonResult newton_natural(
    const Function& func, double d0, double eps, int maxIter
) {
    NewtonResult R{};
    double x = d0, prev = x;
    R.converged = false;

    std::cout << "Analisando passos \n";
    for (int k = 1; k <= maxIter; ++k) {
        double fx = func.f(x);
        double dfx = func.df(x);

        // (evita divisão por zero para não dar problema)
        if (std::fabs(dfx) < 1e-10) {
            R.root = x;
            R.fval = fx;
            R.error = std::fabs(x - prev);
            R.iterations = k - 1;
            return R;
        }

        // passo de Newton Xk + 1
        double xnext = x - fx / dfx;
        // erro absoluto entre iterações |Xk + 1 - Xk|
        double err = std::fabs(xnext - x);
        
        std::cout << "root = " << x << '\n'
              << "f(root) = " << fx << '\n'
              << "error = " << err << '\n'
              << "iterations = " << k << '\n'
              << "\n";

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

    // Se chegar aqui, não convergiu dentro do máximo de 
    // iterações
    R.root = x;
    R.fval = func.f(x);
    R.error = std::fabs(x - prev);
    R.iterations = maxIter;
    R.converged = false;
    return R;
}