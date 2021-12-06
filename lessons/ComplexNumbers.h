// ComplexNumbers.cpp
// Author: Aidan Din
// Implements a Complex class with a variety of functions

#ifndef COMPLEX_NUMBERS
#define COMPLEX_NUMBERS

#include <iostream>
#include <math.h>
using namespace std;

// formats a double to string properly for conversion
static string format(double d) {
	string s = to_string(abs(d));
	while (s.length() > 1 && (s.back() == '0' || s.back() == '.')) {
		s.pop_back();
	}
	return s;
}

class Complex {
	private:
		double a, b;
	public:
		Complex(double x, double y) {
			a = x;
			b = y;
		}
		// returns the conjugate of this Complex
		Complex conjugate() {
			return Complex(a, -b);
		}
		// returns the norm of this Complex
		double norm() {
			return sqrt(abs(a * a + b * b));
		}
		// returns the real part of this Complex
		double real() {
			return a;
		}
		// returns the imaginary part of this Complex
		double imag() {
			return b;
		}
		// returns the dot product of this Complex and another Complex
		double dotProduct(Complex other) {
			return a * other.a + b * other.b;
		}
		// returns the scalar product of this Complex and a value
		Complex scalarProduct(double value) {
			return Complex(a * value, b * value);
		}
		// returns the degree of the angle between this Complex and another Complex
		double angleBetween(Complex other) {
			return atan(b / a) - atan(other.b / other.a);
		}
		// adds this Complex to another Complex
		Complex operator + (Complex& c) {
			return Complex(a + c.a, b + c.b);
		}
		// subtract this Complex by another Complex
		Complex operator - (Complex& c) {
			return Complex(a - c.a, b - c.b);
		}
		// multiply this Complex with another Complex
		Complex operator * (Complex& c) {
			return Complex(a * c.a - b * c.b, a * c.b + b * c.a);
		}
		// divide this Complex by another Complex
		Complex operator / (Complex& c) {
			return Complex((a * c.a + b * c.b) / (c.a * c.a + c.b * c.b), (b * c.a - a * c.b) / (c.a * c.a + c.b * c.b));
		}
		// checks if two Complexes are equal
		bool operator == (Complex& c) {
			return a == c.a && b == c.b;
		}
		// writes this Complex to an output stream in a + bi form
		friend ostream& operator << (ostream& stream, Complex const& c) {
			string s = (c.a >= 0 ? "" : "- ") + format(c.a) + (c.b >= 0 ? " + " : " - ") + format(c.b) + "i";
			stream << s << endl;
			return stream;
		}
};

#endif