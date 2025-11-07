#ifndef NEWTON_METHODS_H
#define NEWTON_METHODS_H

#include "../function/function.h"

/**
 * Estrutura base para exibir o quadro
 * de resultados. Armazena os dados
 * e serve como um record.
 */
struct NewtonResult {
    double root;
    double fval;
    double error;
    int iterations;
    bool converged;
};

// Declarações das funções de Newton
NewtonResult newton_natural(
    const Function& func, double d0, double eps, int maxIter
);

NewtonResult newton_fl(
    const Function& func, double d0, double lambda, double eps, int maxIter
);

NewtonResult newton_numeric(
    const Function& func, double d0, double eps, double h, int maxIter
);

#endif