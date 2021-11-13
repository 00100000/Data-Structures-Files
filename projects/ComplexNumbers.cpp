// ComplexNumbers.cpp
// Author: Aidan Din
// Implements a Complex class with a variety of functions

#include <iostream>
#include <math.h>
using namespace std;

class Complex {
	private:
		int a, b;
	public:
		Complex(int x, int y) {
			a = x;
			b = y;
		}
		// returns the conjugate of this Complex
		Complex conjugate() {
			Complex ret(a, -b);
			return ret;
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
			Complex ret(a * value, b * value);
			return ret;
		}
		// returns the degree of the angle between this Complex and another Complex
		double angleBetween(Complex other) {
			return atan(b / a) - atan(other.b / other.a);
		}
		// adds this Complex to another Complex
		Complex operator + (Complex& c) {
			Complex ret(a + c.a, b + c.b);
			return ret;
		}
		// subtract this Complex by another Complex
		Complex operator - (Complex& c) {
			Complex ret(a - c.a, b - c.b);
		}
		// multiply this Complex with another Complex
		Complex operator * (Complex& c) {
		}
		// divide this Complex by another Complex
		Complex operator / (Complex& c) {
		}
		// converts this Complex to a string in a + bi form
		operator string() const {
			return (a > 0 ? "" : "- ") + to_string(abs(a)) + (b > 0 ? " + " : " - ") + to_string(abs(b)) + "i";
		}
};

int main() {
	Complex one(4, 5);
	Complex two(6, 7);
	string oneString = one, twoString = two;

	cout << oneString << "\n";
	cout << twoString << "\n";

	Complex sum = one + two;
	string sumString = sum;
	cout << sumString << "\n";

	Complex diff = one - two;
	string diffString = diff;
	cout << diffString << "\n";

	Complex prod = one * two;
	string prodString = prod;
	cout << prodString << "\n";

	Complex quot = one / two;
	string quotString = quot;
	cout << quotString << "\n";
	cout << flush;
	return 0;
}