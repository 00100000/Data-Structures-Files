// Lesson5.cpp
// Author: Aidan Din
// Does bitwise stuff on two booleans

#include <iostream>
using namespace std;

int main() {
	bool a, b;
	cout << "Input two booleans\n";
	cin >> a >> b;
	bool temp = a & b;
	cout << "AND: " << temp << "\n";
	temp = a | b;
	cout << "OR: " << temp << "\n";
	temp = a ^ b;
	cout << "XOR: " << temp << "\n";
	temp = ~a;
	cout << "NOT a: " << temp << "\n";
	temp = ~b;
	cout << "NOT b: " << temp << endl;
	return 0;
}