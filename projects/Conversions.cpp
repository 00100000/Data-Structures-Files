// Conversions.cpp
// Author: Aidan Din
// Converts numbers and strings to different bases

#include <iostream>
using namespace std;

// Converts numbers above 9 into their corresponding base 16 letters
char letter(int n) {
	if (n < 10) return '0' + n;
	switch (n) {
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
	}
	return '~';
}
// Converts the argument integer from base 10 to the argument base (base <= 9)
string toBase(int decimal, int base) {
	string ret = "";
	while (decimal > 0) {
		// insert remainder to front
		// use '0' because insert() only inserts characters
		ret.insert(0, 1, '0' + decimal % base);
		decimal /= base;
	}
	return ret;
}
// Converts the argument integer from base 10 to base 16
string toBase16(int decimal) {
	string ret = "";
	while (decimal > 0) {
		ret.insert(0, 1, letter(decimal % 16));
		decimal /= 16;
	}
	return ret;
}
// Converts the argument string from the argument base to base 10 (base <= 9)
int toInteger(string number, int base) {
	return stoi(toBase(stoi(number), base));
}
// Converts the argument string from base 16 to base 10
int toInteger16(string number) {
	return stoi(toBase16(stoi(number)));
}
int main() {
	// User IO
	cout << "What would you like to do?\n1. Convert an integer from base 10 to a base under 10\n2. Convert an integer from base 10 to base 16\n3. Convert a string from a base under 10 to base 10\n4. Convert a string from base 16 to base 10\n";
	int choice;
	cin >> choice;

	int n, base;
	string s;
	if (choice <= 2) {
		cout << "Input the integer:\n";
		cin >> n;
	} else {
		cout << "Input the string:\n";
		cin >> s;
	}
	if (choice == 1 || choice == 3) {
		cout << "Input the base:\n";
		cin >> base;
	}
	// Invoke functions
	switch (choice) {
		case 1:
			cout << "To base " << base << ": " << toBase(n, base);
			break;
		case 2:
			cout << "To base 16: " << toBase16(n);
			break;
		case 3:
			cout << "To integer with base " << base << ": " << toInteger(s, base);
			break;
		case 4:
			cout << "To integer with base 16: " << toInteger16(s);
			break;
	}
	cout << flush;
	return 0;
}