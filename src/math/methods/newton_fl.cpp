#include <cmath>
#include <iostream>
#include <iomanip>
#include "newton_methods.h"
using namespace std;

// Cores ANSI
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_CYAN    "\033[36m"

NewtonResult newton_fl(
    const Function& func, double d0, double lambda, double eps, int maxIter
) {
    NewtonResult R{};
    double d = d0;
    double deriv = func.df(d);
    double last_deriv = deriv;

    std::cout << "\n\n==============================\n";
    std::cout << " NEWTON-FL MODIFIED METHOD";
    std::cout << "\n==============================\n";
    for (int iter = 1; iter <= maxIter; ++iter) {

        double fx = func.f(d);
        deriv = func.df(d);

        double FL;
        bool usingFL = false;

        if (std::fabs(deriv) >= lambda) {
            FL = deriv;
            last_deriv = deriv;
        } else {
            FL = last_deriv;
            usingFL = true;
        }

        double d_next = d - fx / FL;
        
        std::cout << left;
        std::cout << "root = " << setw(20) << d
              << "f(root) = " << setw(20) << func.f(d_next)
              << "error = " << setw(20) << std::fabs(d_next - d)
              << COLOR_CYAN << "Iteration " << iter << ":" << COLOR_RESET ;
        if (usingFL) {
            std::cout << COLOR_RED 
                      << " -> FL ativado! |f'(x)| < lambda, usando última derivada válida\n"
                      << COLOR_RESET;
        } else {
            std::cout << COLOR_GREEN 
                      << " -> Derivada normal utilizada\n"
                      << COLOR_RESET;
        }

        // Critério de parada
        if (std::fabs(d_next - d) < eps || std::fabs(fx) < eps) {
            R.root = d_next;
            R.fval = func.f(d_next);
            R.error = std::fabs(d_next - d);
            R.iterations = iter;
            R.converged = true;
            return R;
        }

        d = d_next;
    }

    R.root = d;
    R.fval = func.f(d);
    R.error = std::fabs(func.f(d));
    R.iterations = maxIter;
    R.converged = false;
    return R;
}
