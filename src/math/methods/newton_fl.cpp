#include <cmath>

#include "newton_methods.h"

NewtonResult newton_fl(
    const Function& func, double d0, double lambda, double eps, int maxIter
) {
    NewtonResult R{};
    double d = d0;
    double deriv = func.df(d);
    double last_deriv = deriv; // último valor útil da derivada

    for (int iter = 1; iter <= maxIter; ++iter) {
        double fx = func.f(d);
        deriv = func.df(d);

        // Verifica se a derivada atual é confiável
        double FL;
        if (std::fabs(deriv) >= lambda) {
            FL = deriv;
            last_deriv = deriv; // guarda última derivada válida
        } else {
            FL = last_deriv;    // usa a última derivada confiável
        }

        // Atualiza a aproximação
        double d_next = d - fx / FL;

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

    // Se chegar aqui, não convergiu dentro do máximo de iterações
    R.root = d;
    R.fval = func.f(d);
    R.error = std::fabs(func.f(d));
    R.iterations = maxIter;
    R.converged = false;
    return R;
}