// Lesson7_2.cpp
// Author: Aidan Din
// Accepts a nonnegative integer from the user and displays true in main if the integer is a perfect number.

#include <iostream>
using namespace std;

void isPerfect(int n, bool& perfect) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) sum += i;
	}
	if (sum == n) perfect = true;
}

int main() {
	int n;
	cout << "Input an integer:\n";
	cin >> n;
	bool perfect = false;
	isPerfect(n, perfect);
	cout << (perfect ? "true" : "false") << endl;
}