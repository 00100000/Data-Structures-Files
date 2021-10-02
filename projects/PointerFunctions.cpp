// PointerFunctions.cpp
// Author: Aidan Din
// Employs a variety of functions using pointers

#include <iostream>
using namespace std;

// swaps two ints using pointers
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
// counts the number of vowels and consonants in a string
void letterCount(string s, int* numVowels, int* numConsonants) {
	char* c = &s.at(0);
	for (int i = 0; i < s.length(); i++) {
		if (*c == 'A' || *c == 'E' || *c == 'I' || *c == 'O' || *c == 'U') {
			(*numVowels)++;
		} else {
			(*numConsonants)++;
		}
		*c++;
	}
}
// displays each element and their memory locations in an array
void arrayInfo(int* arrPtr, int length) {
	for (int i = 0; i < length; i++) {
		cout << *arrPtr << " " << arrPtr << "\n";
		*arrPtr++;
	}
	cout << endl;
}

int main() {
	int choice;
	cout << "What would you like to do?\n1. Swap the values of two integers\n2. Count the number of vowels and consonants in a string\n3. Enter an array and have all of the elements and their corresponding memory locations displayed\n";
	cin >> choice;
	// Invoke functions
	switch (choice) {
		case 1: {
			int a, b;
			cout << "Enter 2 integers:\n";
			cin >> a >> b;
			swap(&a, &b);
			cout << "a: " << a << " b: " << b << endl;
			break;
		}
		case 2: {
			string s;
			int vow = 0, cons = 0;
			cout << "Enter a string:\n";
			cin >> s;
			letterCount(s, &vow, &cons);
			cout << "Vowels: " << vow << " Consonants: " << cons << endl;
			break;
		}
		case 3: {
			int len;
			cout << "How many elements are going to be in your array?\n";
			cin >> len;
			int arr[len];
			cout << "Enter the elements of you array\n";
			for (int i = 0; i < len; i++) {
				cin >> arr[i];
			}
			arrayInfo(&arr[0], len);
			break;
		}
	}
	return 0;
}