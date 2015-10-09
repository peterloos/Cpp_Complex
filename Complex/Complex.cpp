#include <iostream>
using namespace std;

#include "Complex.h"

// c'tors
Complex::Complex ()
{
    m_real = 0.0;
    m_imag = 0.0;
}

Complex::Complex (double real, double imag)
{
    m_real = real;
    m_imag = imag;
}

// conversion constructor
Complex::Complex (double real)
{
    m_real = real;
    m_imag = 0.0;
}

// unary arithmetic operators
Complex operator- (const Complex& c)
{
    return Complex (-c.m_real, -c.m_imag);
}

// binary arithmetic operators
Complex operator+ (const Complex& c1, const Complex& c2)
{
    Complex tmp = Complex (c1);
    tmp.m_real += c2.m_real;
    tmp.m_imag += c2.m_imag;
    return tmp;
}

Complex operator- (const Complex& c1, const Complex& c2)
{
    Complex tmp = Complex (c1);
    tmp.m_real -= c2.m_real;
    tmp.m_imag -= c2.m_imag;
    return tmp;
}

Complex operator* (const Complex& c1, const Complex& c2)
{
    double real = c1.m_real * c2.m_real - c1.m_imag * c2.m_imag;
    double imag = c1.m_real * c2.m_imag + c1.m_imag * c2.m_real;
    return Complex (real, imag);
}

Complex operator/ (const Complex& c1, const Complex& c2)
{
    double real =
        (c2.m_real * c1.m_real + c2.m_imag * c1.m_imag) /
        (c2.m_imag * c2.m_imag + c1.m_imag * c1.m_imag);

    double imag =
        (c2.m_real * c1.m_real - c2.m_imag * c1.m_imag) /
        (c2.m_imag * c2.m_imag + c1.m_imag * c1.m_imag);

    return Complex (real, imag);
}

// comparison operators
bool operator== (const Complex& c1, const Complex& c2)
{
    if (c1.m_real == c2.m_real && c1.m_imag == c2.m_imag)
        return true;

    return false;
}

bool operator!= (const Complex& c1, const Complex& c2)
{
    return !(c1 == c2);
}

// complex conjunction operator
Complex operator! (const Complex& c)
{
    return Complex (c.m_real, - c.m_imag);
}

// output operator
ostream& operator<< (ostream& os, const Complex& c)
{
    char* sign = (c.m_imag >= 0) ? "+" : "";
    os << "[" << c.m_real << sign << c.m_imag << "*i]";
    return os;
}

istream& operator>> (istream& is, Complex& c)
{
    is >> c.m_real >> c.m_imag;
    return is;
}
