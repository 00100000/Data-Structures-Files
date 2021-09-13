#include <iostream>
using namespace std;

int main() {
	string x, y, z;
	cin >> x >> y >> z;
	string row[3][3] = {
		{x, y, z},
		{x, y, z},
		{x, y, z},
	};
	string col[3][3] = {
		{x, x, x},
		{y, y, y},
		{z, z, z},
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