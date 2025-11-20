#include <iostream>
#include <iomanip>
#include "src/math/methods/newton_methods.h"
using namespace std;

int main() {
    double a3 = 1.0, a2 = 1.0;
    double d0 = 0.5, eps = 0.001, lambda = 0.05, h = 1e-5;
    int maxIter = 100;

    Function func(a3, a2);
    NewtonResult r_nat = newton_natural(func, d0, eps, maxIter);
    NewtonResult r_fl = newton_fl(func, d0, lambda, eps, maxIter);
    NewtonResult r_num = newton_numeric(func, d0, eps, h, maxIter);

    cout << "\n==== Resultado Final ====\n";
    
    cout << setw(35) 
            << "root" << setw(25) 
            << "f(root)" << setw(25) 
            << "error" << setw(25) 
            << "iterations" << setw(15) 
            << "converged" << endl;

    cout << left;
    cout << setw(31) << "Natural Newton" 
            << setw(22) << r_nat.root 
            << setw(27) << r_nat.fval 
            << setw(20) << r_nat.error 
            << setw(16) << r_nat.iterations 
            << setw(19) << (r_nat.converged ? "YES" : "NO") << endl;

    cout << setw(31) << "NEWTON-FL MODIFIED"
            << setw(22)<< r_fl.root
            << setw(27) << r_fl.fval
            << setw(20) << r_fl.error
            << setw(16)<< r_fl.iterations
            << setw(19)<< (r_fl.converged ? "YES" : "NO") << "\n";

    cout << setw(31) << "NUMERIC DERIVATIVE NEWTON"
            << setw(22) << r_num.root
            << setw(27) << r_num.fval
            << setw(20) << r_num.error
            << setw(16) << r_num.iterations
            << setw(19) << (r_num.converged ? "YES" : "NO") << '\n';
    return 0;
}