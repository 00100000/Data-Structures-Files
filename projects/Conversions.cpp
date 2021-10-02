// Conversions.cpp
// Author: Aidan Din
// Converts numbers and strings to different bases

#include <iostream>
#include <cmath>
using namespace std;

// Converts numbers above 9 into their corresponding base 16 letters
char convert(int n) {
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
	return '0' + n;
}
// Converts base 16 numbers into their corresponding decimal values
// epic practical method overloading moment
int convert(char c) {
	switch (c) {
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
	}
	return int(c) - 48;
}
// Converts the argument integer from base 10 to the argument base (base <= 9)
string toBase(int decimal, int base) {
	string ret = "";
	while (decimal != 0) {
		// insert at start of ret
		ret.insert(0, 1, '0' + (decimal % base));
		decimal /= base;
	}
	return ret.size() > 0 ? ret : "0";
}
// Converts the argument integer from base 10 to base 16
string toBase16(int decimal) {
	string ret = "";
	while (decimal != 0) {
		ret.insert(0, 1, convert(decimal % 16));
		decimal /= 16;
	}
	return ret.size() > 0 ? ret : "0";
}
// Converts the argument string from the argument base to base 10 (base <= 9)
int toInteger(string number, int base) {
	int ret = 0;
	int num = stoi(number);
	for (int i = 0; num != 0; i++) {
		ret += num % 10 * pow(base, i);
		num /= 10;
	}
	return ret;
}
// Converts the argument string from base 16 to base 10
int toInteger16(string number) {
	int ret = 0;
	int len = number.length();
	for (int i = 0; i < len; i++) {
		ret += convert(number.at(i)) * pow(16, len - i - 1);
	}
	return ret;
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
	cout << endl;
	return 0;
}