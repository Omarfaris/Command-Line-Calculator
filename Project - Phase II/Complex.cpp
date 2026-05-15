#include "Complex.h"

double real;
double imag;

Complex::Complex() {}

Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}

Complex Complex::add(const Complex& other) {
    double r = real + other.getReal();
    double i = imag + other.getImag();
    return Complex(r,i);
}

Complex Complex::sub(const Complex& other) {
    double r = real - other.getReal();
    double i = imag - other.getImag();
    return Complex(r,i);
}

Complex Complex::mul(const Complex& other) {
    double r = real * other.getReal() - imag * other.getImag();
    double i = real * other.getImag() + imag * other.getReal();
    return Complex(r,i);
}

Complex Complex::div(const Complex& other) {
    Complex thisComplex = Complex(real, imag);
    Complex dividend = thisComplex.mul(other.conjugate());
    double divisor = other.real*other.real + other.imag*other.imag;
    double r = dividend.getReal()/divisor;
    double i = dividend.getImag()/divisor;
    return Complex(r,i);
}

Complex Complex::conjugate() const {
    return Complex(real, -imag);
}

double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

double Complex::magnitude() const {
    return sqrt(real * real + imag * imag);
}