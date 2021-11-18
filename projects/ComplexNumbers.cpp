// ComplexNumbers.cpp
// Author: Aidan Din
// Implements a Complex class with a variety of functions

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

string boolStr(bool b) {
	return b ? "true" : "false";
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
		// converts this Complex to a string in a + bi form
		operator string() const {
			return (a >= 0 ? "" : "- ") + format(a) + (b >= 0 ? " + " : " - ") + format(b) + "i";
		}
};

int main() {
	bool repeat = false;
	do {
		// input
		int choice;
		cout << "What would you like to do?\n1. Get the conjugate of a complex number\n2. Get the norm of a complex number\n3. Get the real part of a complex number\n4. Get the imaginary part of a complex number\n5. Get the scalar product of a complex number and a double\n6. Get the dot product of two complex numbers\n7. Get the angle between two complex numbers\n8. Add two complex numbers\n9. Subtract two complex numbers\n10. Multiply two complex numbers\n11. Divide two complex numbers.\n12. Check if two complex numbers are equal\n";
		cin >> choice;

		Complex one(0, 0), two(0, 0);
		double a, b;
		double v;
		if (choice <= 5) {
			cout << "Enter the real and imaginary parts of the complex number respectively, separated by a space.\n";
			cin >> a >> b;
			one = Complex(a, b);
		} else if (choice >= 6) {
			cout << "Enter the real and imaginary parts of the first complex number respectively, separated by a space.\n";
			cin >> a >> b;
			one = Complex(a, b);
			cout << "Enter the real and imaginary parts of the second complex number respectively, separated by a space.\n";
			cin >> a >> b;
			two = Complex(a, b);

		}
		if (choice == 5) {
			cout << "Enter the double you want to calculate the scalar product of the complex number with.\n";
			cin >> v;
		}
		// output
		string s;
		switch (choice) {
			case 1:
				s = one.conjugate();
				cout << "Conjugate: " << s;
				break;
			case 2:
				cout << "Norm: " << one.norm();
				break;
			case 3:
				cout << "Real: " << one.real();
				break;
			case 4:
				cout << "Imaginary: " << one.imag();
				break;
			case 5:
				s = one.scalarProduct(v);
				cout << "Scalar Product: " << s;
				break;
			case 6:
				cout << "Dot Product: " << format(one.dotProduct(two));
				break;
			case 7:
				s = one.angleBetween(two);
				cout << "Angle Between (Degrees): " << s;
				break;
			case 8:
				s = one + two;
				cout << "Sum: " << s;
				break;
			case 9:
				s = one - two;
				cout << "Difference: " << s;
				break;
			case 10:
				s = one * two;
				cout << "Product: " << s;
				break;
			case 11:
				s = one / two;
				cout << "Quotient: " << s;
				break;
			case 12:
				cout << "Equality: " << boolStr(one == two);
				break;
		}
		// re-run
		cout << "\nWould you like to run this program again?\n1 for yes, 0 for no\n";
		cin >> repeat;
	} while (repeat);
	cout << flush;
	return 0;
}