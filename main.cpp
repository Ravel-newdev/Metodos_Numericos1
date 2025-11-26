#include "src/output/table.h"

using namespace std;

int main() {
    auto a3 = 1.0;
    auto a2 = 0.01;   // MUITO pequeno -> raiz perto de 0
    auto d0 = 0.1;    // perto da região onde a derivada é quase zero
    auto lambda = 0.05;
    auto h = 1e-4;
    auto eps = 1e-4;
    int maxIter = 100;

    Function func(a3, a2);
    NewtonResult r_nat = newton_natural(func, d0, eps, maxIter);
    NewtonResult r_fl = newton_fl(func, d0, lambda, eps, maxIter);
    NewtonResult r_num = newton_numeric(func, d0, eps, h, maxIter);

    Table table(r_nat, r_fl, r_num);
    table.print();

    return 0;
}
