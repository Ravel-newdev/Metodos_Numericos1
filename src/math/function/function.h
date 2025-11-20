#ifndef FUNCTION_H
#define FUNCTION_h

class Function {
    public:
        double a3, a2;

        Function (double a3, double a2) : a3(a3), a2(a2) {}

        double f(double d) const {
            return a3 * d * d * d - 9.0 * a2 * d + 3.0;
        }

        /**
         * Como temos apenas uma equação que modela a corda,
         * não é necessário um sistema genérico de derivação
         * e manter apenas um único caso de derivação.
         * 
         * Portanto, a derivada fica no modo
         * 3a3d² - 9a2
         */
        double df(double d) const {
            return 3.0 * a3 * d * d - 9.0 * a2;
        }
};

#endif