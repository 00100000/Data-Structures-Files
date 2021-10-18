// Lesson10.cpp
// Author: Aidan Din
// Implements class inheritance with shapes

#include <iostream>
#include <math.h>
using namespace std;

class Shape {
	bool hasCurve;

	public:
		Shape(bool c) {
			hasCurve = c;
		}
};

class Polygon : Shape {
	int sides;

	public:
		Polygon(int s) {
			sides = s;
		}
};

class Triangle : Polygon {
	int angles[3];

	public:
		Triangle(int a, int b, int c) {
			angles[0] = a;
			angles[1] = b;
			angles[3] = c;
		}
};

int main() {
	return 0;
}