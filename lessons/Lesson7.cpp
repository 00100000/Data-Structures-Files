// Lesson7.cpp
// Author: Aidan Din
// Calculates the circumference of a circle, the volume of a sphere, and the volume of a cylinder

#include <iostream>
#include <math.h>
using namespace std;

double circumference;

double volume(double r) {
	return 4 * M_PI * r * r * r / 3;
}
double volume(double r, double h) {
	return M_PI * r * r * h;
}
void circum(double r) {
	circumference = M_PI * 2 * r;
}
int main() {
	double r = 5, h = 10;
	circum(r);
	cout << "Circumference: " << circumference << "\n";
	cout << "Sphere Volume: " <<  volume(r) << "\n";
	cout << "Cylinder Volume: " << volume(r, h) << endl;
}