#include <iostream>
using namespace std;

#include "Complex.h"

void main ()
{
    // testing c'tors
    Complex c1 = Complex ();
    Complex c2 = Complex (3.0, 4.0);
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    // testing input operator
    cout << "enter complex number (e.g. \"1.5 3.5\"):" << endl;
    cin >> c1;
    cout << "c1: " << c1 << endl;

    // testing setter and getter methods
    c2.SetReal (5);
    cout << "c2: " << c2 << endl;
    double imag = c2.GetImag ();
    cout << "imaginary part of c2: " << imag << endl;

    // testing unary arithmetic operators
    Complex c3 = -c1;
    cout << "-c1: " << c3 << endl;

    // testing binary arithmetic operators
    c3 = c1 + c2;
    cout << "c1 + c2: " << c3 << endl;
    c3 = c1 - c2;
    cout << "c1 - c2: " << c3 << endl;
    c3 = c1 * c2;
    cout << "c1 * c2: " << c3 << endl;
    c3 = c1 / c2;
    cout << "c1 / c2: " << c3 << endl;

    // testing conversion constructor
    c3 = c1 + 5.0;
    cout << "c1 + 5.0: " << c3 << endl;
    c3 = 5 + c1;
    cout << "5 + c1: " << c3 << endl;
    c3 = 10.0;
    cout << "c3 = 10.0: " << c3 << endl;

    // testing conjunction operator
    cout << "c1: " << c1 << endl;
    c3 = !c1;
    cout << "!c1: " << c3 << endl;

    // testing copy c'tor
    Complex c4 (c1);
    cout << "c4: " << c4 << endl;

    // testing assignment operator
    c4 = c3;
    cout << "c4: " << c4 << endl;

	getchar();
}
