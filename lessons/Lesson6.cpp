// Lesson6.cpp
// Author: Aidan Din
// Adds corresponding elements in two same-sized arrays in reverse order

#include <iostream>
using namespace std;

int main() {
	int a[] = {1, 2, 3, 4};
	int b[] = {1, 2, 3, 4};
	int len = sizeof(a)/sizeof(a[0]);
	int c[len];
	for (int i = len - 1; i >= 0; i--) {
		c[len - 1 - i] = a[i] + b[i];
	}
	// print
	for (int i = 0; i < len; i++) cout << c[i] << " ";
	cout << endl;
}