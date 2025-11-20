#include <cmath>
#include "newton_methods.h"

NewtonResult newton_fl(
    const Function& func, double d0, double lambda, double eps, int maxIter
) {
    NewtonResult R{};
    double d = d0;
    double deriv = func.df(d);
    double last_deriv = deriv;

    for (int iter = 1; iter <= maxIter; ++iter) {
        double fx = func.f(d);
        deriv = func.df(d);

        double FL;
        if (std::fabs(deriv) >= lambda) {
            FL = deriv;
            last_deriv = deriv;
        } else {
            FL = last_deriv;
        }

        double d_next = d - fx / FL;

        R.history.push_back({d, fx, std::fabs(d_next - d)});

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