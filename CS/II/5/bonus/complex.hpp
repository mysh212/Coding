#include"complex.h"
// #include<iostream>
using namespace std;

    Complex::Complex(double real = 0,double imag = 0):
        real(real), imag(imag) {};

    Complex Complex::add(Complex a) {
        return *this + a;
    }
    Complex Complex::multiply(Complex a) {
        return *this * a;
    }
    Complex Complex::divide(Complex a) {
        return *this / a;
    }
    Complex Complex::conjugate() {
        return *this | 1;
    }
    inline Complex Complex::operator=(Complex a) {
        return real = a.real,imag = a.imag,*this;
    }
    inline Complex Complex::operator+(Complex a) {
        return Complex(real + a.real,imag + a.imag);
    }
    inline Complex Complex::operator+(double a) {
        return Complex(real + a,imag);
    }
    inline Complex Complex::operator-(Complex a) {
        return Complex(real - a.real,imag - a.imag);
    }
    inline Complex Complex::operator-(double a) {
        return Complex(real - a,imag);
    }
    inline Complex Complex::operator*(Complex a) {
        return Complex(real * a.real - imag * a.imag,real * a.imag + imag * a.real);
    }
    inline Complex Complex::operator*(double a) {
        return Complex(real * a,imag * a);
    }
    inline Complex Complex::operator/(Complex a) {
        return (*this * (a | 1)) / a();
    }
    inline Complex Complex::operator/(double a) {
        return Complex(real / a,imag / a);
    }
    inline Complex Complex::operator|(bool a) {
        return Complex(real,(a ? -imag : imag));
    }
    inline double Complex::operator()() {
        return (real * real) + (imag * imag);
    }

    inline void Complex::print(ostream& out = std::cout) {
        if(imag == 0) cout<<real<<"";
        if(imag < 0) cout<<real<<"+("<<imag<<")i";
        if(imag > 0) cout<<real<<"+"<<imag<<"i";
        return;
    }

    inline ostream& operator<<(ostream& out,Complex x) {
        x.print(out);
        return out;
    }

    Complex::~Complex() {
        // delete &imag;
        // delete &real;
    }