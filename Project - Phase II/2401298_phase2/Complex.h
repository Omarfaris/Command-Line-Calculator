#include <cmath>

#ifndef ASSIGNMENTSCLION_COMPLEX_H
#define ASSIGNMENTSCLION_COMPLEX_H

class Complex {
        double real;
        double imag;

    public:
        Complex();

        Complex(double r, double i);

        Complex add(const Complex& other);
        Complex sub(const Complex& other);
        Complex mul(const Complex& other);
        Complex div(const Complex& other);
        Complex conjugate() const;

        double getReal() const;
        double getImag() const;

        double magnitude() const;
};


#endif //ASSIGNMENTSCLION_COMPLEX_H