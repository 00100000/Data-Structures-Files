// Lesson13.cpp
// Author: Aidan Din
// Simulates rolling a pair of 6-sided dice 10,000 times

#include <iostream>
#include <array>
using namespace std;

int roll() {
	return static_cast<int>(rand() % 6) + static_cast<int>(rand() % 6);
}

int main() {
	array<int, 11> result;
	result.fill(0);

	int amt = 10000;
	for (int i = 0; i < amt; i++) result[roll()]++;
	for (int i = 0; i < 11; i++) {
		cout << "Rolled a " << i + 2 << " " << (double)result[i] / (amt / 100) << "% of the time\n";
	}
	cout << flush;
	return 0;
}