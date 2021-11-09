// ComplexNumbers.cpp
// Author: Aidan Din
// Implements a Complex class with a variety of functions

#include <iostream>
#include <math.h>

class Complex {
	private:
		int a, b;
	public:
		Complex(int x, int y) {
			a = x;
			b = y;
		}
		Complex conjugate() {
			Complex ret(a, -b);
			return ret;
		}
		double norm() {
			return sqrt(abs(a * a + b * b));
		}
		double real() {
			return a;
		}
		double imag() {
			return b;
		}
		double dotProduct(Complex other) {
			return a * other.a + b * other.b;
		}
		Complex scalarProduct(double value) {
			Complex ret(a * value, b * value);
			return ret;
		}
		double angleBetween(Complex other) {

		}
};

int main() {
	return 0;
}