// Lesson8.cpp
// Author: Aidan Din
// Stores and prints integers in an array with pointers.

#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e;
	cout << "Input 5 integers:\n";
	cin >> a >> b >> c >> d >> e;

	int arr[5];
	int *ptr = &arr[0];
	*ptr = a;
	*(ptr + 1) = b;
	*(ptr + 2) = c;
	*(ptr + 3) = d;
	*(ptr + 4) = e;

	for (int i = 0; i < 5; i++) {
		cout << *(ptr + i) << ' ';
	}
	cout << endl;
}