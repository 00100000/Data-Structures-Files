// Lesson4b.cpp
// Author: Aidan Din
// Takes in 3 Strings and puts them into rows and columns

#include <iostream>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	string row[3][3] = {
		{a, b, c},
		{a, b, c},
		{a, b, c},
	};
	string col[3][3] = {
		{a, a, a},
		{b, b, b},
		{c, c, c},
	};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << row[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << col[i][j] << " ";
		}
		cout << "\n";
	}
	cout << flush;
	return 0;
}