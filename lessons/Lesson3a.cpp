// Lesson3a.cpp
// Author: Aidan Din
// Demonstrates the size of unsigned and normal integers are the same

#include <iostream>
using namespace std;

int main() {
	cout << "unsigned int size: " << sizeof(uint) << " bytes\n";
	cout << "int size: " << sizeof(int) << " bytes\n";
	cout << "long size: " << sizeof(long) << " bytes" << endl;
	return 0;
}