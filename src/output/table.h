#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "../math/methods/newton_methods.h"

#define COLOR_RESET  "\x1b[0m"
#define COLOR_CYAN   "\x1b[36m"
#define COLOR_GREEN  "\x1b[32m"

class Table {
    private:
        const std::vector<std::string> names {
            "Natural Newton",
            "Modified Newton-FL",
            "Numeric Derivative Newton"
        };

        const std::vector<NewtonResult> resultados;
    public:
        Table(const NewtonResult& r1,
            const NewtonResult& r2,
            const NewtonResult& r3)
            : resultados{r1, r2, r3} {}


        void print() const {
            using std::cout;
            using std::setw;
            using std::left;

            cout << "\n"
                << COLOR_CYAN
                << "========================================\n"
                << "      COMPARATIVE TABLE OF NEWTON METHODS\n"
                << "========================================\n\n"
                << COLOR_RESET;

            cout << left
                << COLOR_CYAN
                << setw(25) << "method"
                << setw(18) << "root"
                << setw(18) << "f(root)"
                << setw(12) << "error"
                << setw(14) << "iterations"
                << setw(12) << "converged"
                << COLOR_RESET
                << "\n";

            for (std::size_t i = 0; i < resultados.size(); ++i) {
                const NewtonResult& R = resultados[i];

                cout << left
                    << COLOR_GREEN << setw(25) << names[i] << COLOR_RESET
                    << setw(18) << R.root
                    << setw(18) << R.fval
                    << setw(12) << R.error
                    << setw(14) << R.iterations
                    << setw(12) << (R.converged ? "yes" : "no")
                    << "\n";
            }

            for (std::size_t i = 0; i < resultados.size(); ++i) {
                const NewtonResult& R = resultados[i];

                cout << "\n"
                    << COLOR_CYAN
                    << "---------- HISTORY: " << names[i]
                    << " ----------\n"
                    << COLOR_RESET;

                cout << left
                    << COLOR_CYAN
                    << setw(12) << "iter"
                    << setw(18) << "x"
                    << setw(18) << "f(x)"
                    << setw(12) << "error"
                    << COLOR_RESET
                    << "\n";

                for (std::size_t k = 0; k < R.history.size(); ++k) {
                    const auto& rec = R.history[k];
                    cout << left
                        << setw(12) << (k + 1)
                        << setw(18) << rec.x
                        << setw(18) << rec.fx
                        << setw(12) << rec.error
                        << "\n";
                }
            }
        }
};

#endif