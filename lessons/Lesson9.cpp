// Lesson9.cpp
// Author: Aidan Din
// Creates a circle class with different methods

#include <iostream>
#include <math.h>
using namespace std;

class Circle {
	private:
		double pi = M_PI;
	public:
		double radius;
		double circum;
		double area;

		Circle(double r) {
			radius = r;
			circum = pi * 2 * r;
			area = pi * r * r;
		}
};

int main() {
	double a, b, c;
	cout << "Input the radius of 3 circles\n";
	cin >> a >> b >> c;
	Circle x(a);
	Circle y(b);
	Circle z(c);

	cout << "Circle 1\nRadius: " << x.radius << "\nCircumference: " << x.circum << "\nArea: " << x.area << "\n";
	cout << "Circle 2\nRadius: " << y.radius << "\nCircumference: " << y.circum << "\nArea: " << y.area << "\n";
	cout << "Circle 3\nRadius: " << z.radius << "\nCircumference: " << z.circum << "\nArea: " << z.area << "\n";
	cout << flush;
}