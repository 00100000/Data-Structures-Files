// Main function of the C++ program.

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include "ComplexNumbers.h"
using namespace std;

int main()
{
    Complex first = Complex(1, -1);
    Complex second = Complex(1, 1);
    cout << "First: " << first << endl;
    cout << "Second: " << second << endl;
    cout << "Angle between first and second: " << first.angleBetween(second) << endl;
	cout << "Angle between second and first: " << second.angleBetween(first) << endl;
    cout << "Sum: " << (first + second) << endl;
	cout << "Difference: " << (first - second) << endl;
	cout << "Product: " << (first * second) << endl;
	cout << "Quotient: " << (first / second) << endl;
	cout << "Norm of first: " << first.norm() << endl;
	cout << "Dot product: " << first.dotProduct(second) << endl;
	cout << "Scalar product: " << first.scalarProduct(2) << endl;
	Complex third = Complex(0.2, 1.3);
	Complex fourth = Complex(0.2, 1.3);
	cout << "Equality: " << (third == fourth) << endl;
	Complex fifth = Complex(0.19999999, 1.29999999);
	cout << "Close Enough Equality: " << (fourth == fifth) << endl;
}