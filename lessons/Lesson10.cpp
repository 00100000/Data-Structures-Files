// Lesson10.cpp
// Author: Aidan Din
// Implements class inheritance with shapes

#include <iostream>
#include <math.h>
using namespace std;

class Shape {
	bool curve;

	public:
		bool getCurve() {
			return curve;
		}
		void setCurve(bool c) {
			curve = c;
		}
};

class Polygon : public Shape {
	int sides;

	public:
		int getSides() {
			return sides;
		}
		void setSides(int s) {
			sides = s;
		}
};

class Triangle : public Polygon {
	int first, second, third;

	public:
		Triangle(int a, int b, int c) {
			setCurve(false);
			setSides(3);
			first = a;
			second = b;
			third = c;
		}

		int getFirst() { return first; }
		int getSecond() { return second; }
		int getThird() { return third; }
		void setAngles(int a, int b, int c) {
			first = a;
			second = b;
			third = c;
		}
};

int main() {
	Triangle t = Triangle(3, 4, 5);

	cout << "This shape is curved: " << t.getCurve() << "\n";
	cout << "Number of sides: " << t.getSides() << "\n";
	cout << "Angle 1: " << t.getFirst() << "\n";
	cout << "Angle 2: " << t.getSecond() << "\n";
	cout << "Angle 3: " << t.getThird() << endl;

	return 0;
}