// ParenthesesMatch.cpp
// Author: Aidan Din
// Checks if grouping symbols match with a linked list stack

#include <iostream>
#include <fstream>
using namespace std;

class ParenMatch {
	private:
		char symbol;
		ParenMatch* prev;

	public:
		string LEFT = "([{<";
		string RIGHT = ")]}>";

		ParenMatch(char c, ParenMatch* p) {
			symbol = c;
			prev = p;
		}
		bool checkParen(string s);
		ParenMatch* push(ParenMatch* p);
		ParenMatch* pop();
		char peek();
};
bool ParenMatch::checkParen(string s) {
	ParenMatch* head = new ParenMatch('.', nullptr);
	for (int i = 0; i < s.size(); i++) {
		// find type of character
		char l = '.', r = '.';
		for (int j = 0; j < head->LEFT.size(); j++) {
			if (s[i] == head->LEFT[j]) {
				l = s[i];
				break;
			}
		}
		for (int j = 0; j < head->RIGHT.size(); j++) {
			if (s[i] == head->RIGHT[j]) {
				r = s[i];
				break;
			}
		}
		// process in stack
		if (l != '.') {
			head = head->push(new ParenMatch(l, head));
		}
		if (r != '.') {
			// check if the index of the right character matches
			// the index of the top of the stack
			int rIndex = -1, pIndex = -1;
			for (int j = 0; j < head->RIGHT.size(); j++) {
				if (r == head->RIGHT[j]) {
					rIndex = j;
					break;
				}
			}
			for (int j = 0; j < head->LEFT.size(); j++) {
				if (head->peek() == head->LEFT[j]) {
					pIndex = j;
					break;
				}
			}
			if (rIndex == pIndex) {
				head = head->pop();
			} else {
				return false;
			}
		}
	}
	if (head->symbol != '.') return false;
	return true;
}
ParenMatch* ParenMatch::push(ParenMatch* p) {
	return p;
}
ParenMatch* ParenMatch::pop() {
	return this->prev;
}
char ParenMatch::peek() {
	return symbol;
}

int main() {
	string name;
	cout << "Enter the name of the file you'd like to read from:\n";
	cin >> name;

	ifstream infile(name);
	ofstream outfile("result.txt");

	string expr;
	ParenMatch* p = nullptr;
	for (int i = 1; infile >> expr; i++) {
		outfile << "Trial " << i << ": " << (p->checkParen(expr) ? "good!" : "BAD") << "\n";
	}

	cout << flush;
	return 0;
}
