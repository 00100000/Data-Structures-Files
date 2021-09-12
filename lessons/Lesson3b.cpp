// Lesson3b.cpp
// Author: Aidan Din
// Calculates the area and circumference of a circle given the radius

#include <iostream>
using namespace std;

int main() {
	float radius;
	float pi = 3.1415;

	cout << "Input a radius:\n";
	cin >> radius;
	cout << "Area: " << pi * radius * radius << "\n";
	cout << "Circumference: " << pi * radius * 2 << endl;
	return 0;
}