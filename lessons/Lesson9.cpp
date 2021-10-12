// Lesson9.cpp
// Author: Aidan Din
// Creates a circle class with different methods

#include <iostream>
#include <math.h>
using namespace std;

class Circle {
	double pi = M_PI;
	double circum, area;

	public:
		double radius;

		Circle(double r) {
			radius = r;
			circum = pi * 2 * r;
			area = pi * r * r;
		}

		int getCircum() {
			return circum;
		}

		int getArea() {
			return area;
		}
};

int main() {
	double a, b, c;
	cout << "Input the radius of 3 circles\n";
	cin >> a >> b >> c;
	Circle x(a);
	Circle y(b);
	Circle z(c);

	cout << "Circle 1\nRadius: " << x.radius << "\nCircumference: " << x.getCircum() << "\nArea: " << x.getArea() << "\n";
	cout << "Circle 2\nRadius: " << y.radius << "\nCircumference: " << y.getCircum() << "\nArea: " << y.getArea() << "\n";
	cout << "Circle 3\nRadius: " << z.radius << "\nCircumference: " << z.getCircum() << "\nArea: " << z.getArea() << "\n";
	cout << flush;
}