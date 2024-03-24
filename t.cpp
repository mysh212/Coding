#include<bits/stdc++.h>
#include "test.cpp"
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

    inline void Complex::print() {
        if(imag == 0) cout<<real<<"";
        if(imag < 0) cout<<real<<"+("<<imag<<")i";
        if(imag > 0) cout<<real<<"+"<<imag<<"i";
        return;
    }
    // #include <iostream>
// #include <string>
// #include "complex.h"。
using namespace std;

int main(){

    // Construct 2 complex numbers
    Complex test1 =  Complex(1,2);
    Complex test2 =  Complex(3,4);
    cout << "test1: ";
    test1.print();
    cout << endl;
    cout << "test2: ";
    test2.print();
    cout << endl;

    Complex addition = test1.add(test2);
    cout <<"Add: ";
    addition.print();
    cout << endl;

    Complex multiplication = test1.multiply(test2);
    cout <<"Multiply: ";
    multiplication.print();
    cout << endl;

    Complex division = test1.divide(test2);
    cout <<"Divide: ";
    division.print();
    cout << endl;

    Complex conjugate_value = test1.conjugate();
    cout <<"Complex conjugate: ";
    conjugate_value.print();
    cout << endl;

    return 0;
}