#include <cmath>
#include "newton_methods.h"

NewtonResult newton_natural(
    const Function& func, double d0, double eps, int maxIter
) {
    NewtonResult R{};
    double x = d0, prev = x;

    for (int k = 1; k <= maxIter; ++k) {
        double fx = func.f(x);
        double dfx = func.df(x);

        if (std::fabs(dfx) < 1e-10) {
            R.root = x;
            R.fval = fx;
            R.error = std::fabs(x - prev);
            R.iterations = k - 1;
            return R;
        }

        double xnext = x - fx / dfx;
        double err = std::fabs(xnext - x);

        // Histórico de iterações
        R.history.push_back({x, fx, err});

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