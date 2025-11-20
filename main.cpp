#include <iostream>
#include "src/math/methods/newton_methods.h"

int main() {
    double a3 = 1.0, a2 = 1.0;
    double d0 = 0.5, eps = 0.001, lambda = 0.05, h = 1e-5;
    int maxIter = 100;

    Function func(a3, a2);

    std::cout << "\n\n==============================\n";
    std::cout << "      NATURAL NEWTON METHOD";
    std::cout << "\n==============================\n";

    NewtonResult r_nat = newton_natural(func, d0, eps, maxIter);

    std::cout << "\n--- RESULTADOS (Newton Natural) ---\n";
    std::cout << "root       = " << r_nat.root << '\n'
              << "f(root)    = " << r_nat.fval << '\n'
              << "error      = " << r_nat.error << '\n'
              << "iterations = " << r_nat.iterations << '\n'
              << "converged  = " << (r_nat.converged ? "YES" : "NO") << "\n";



    std::cout << "\n\n==============================\n";
    std::cout << "     NEWTON-FL MODIFIED METHOD";
    std::cout << "\n==============================\n";

    NewtonResult r_fl = newton_fl(func, d0, lambda, eps, maxIter);

    std::cout << "\n--- RESULTADOS (Newton-FL) ---\n";
    std::cout << "root       = " << r_fl.root << '\n'
              << "f(root)    = " << r_fl.fval << '\n'
              << "error      = " << r_fl.error << '\n'
              << "iterations = " << r_fl.iterations << '\n'
              << "converged  = " << (r_fl.converged ? "YES" : "NO") << "\n";



    std::cout << "\n\n==============================\n";
    std::cout << "  NEWTON METHOD w/ NUMERIC DERIVATIVE";
    std::cout << "\n==============================\n";

    NewtonResult r_num = newton_numeric(func, d0, eps, h, maxIter);

    std::cout << "\n--- RESULTADOS (Newton Numérico) ---\n";
    std::cout << "root       = " << r_num.root << '\n'
              << "f(root)    = " << r_num.fval << '\n'
              << "error      = " << r_num.error << '\n'
              << "iterations = " << r_num.iterations << '\n'
              << "converged  = " << (r_num.converged ? "YES" : "NO") << "\n";

    return 0;
}
