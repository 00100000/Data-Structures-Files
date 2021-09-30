// PointerFunctions.cpp
// Author: Aidan Din
// Converts numbers and strings to different bases

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
	for (int i = 0; i < s.length(); i++) {
		char c = s.at(i);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			*numVowels = *numVowels + 1;
		} else {
			*numConsonants = *numConsonants + 1;
		}
	}
}
// displays each element and their memory locations in an array
void arrayInfo(int* arrPtr, int length) {
	for (int i = 0; i < length; i++) {
		cout << "Index: " << i << " Element: " << *(arrPtr + i) << " Memory Address: " << (arrPtr + i) << "\n";
	}
	cout << flush;
}
int main() {
	return 0;
}