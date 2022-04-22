// Infix.cpp
// Author: Aidan Din
// Converts infix expressions to postfix and evaluates them

#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

map<char, int> precedence = {
	{'(', 0},
	{')', 0},
	{'+', 1},
	{'-', 1},
	{'*', 2},
	{'/', 2},
	{'%', 2},
	{'^', 3}
};

class Stack {
	private:
		string s;
		Stack* prev;

	public:
		Stack(string tempS, Stack* p) {
			s = tempS;
			prev = p;
		}
		Stack* push(string tempS);
		Stack* pop();
		string peek();
};
Stack* Stack::push(string tempS) {
	Stack* newHead = new Stack(tempS, this);
	return newHead;
}
Stack* Stack::pop() {
	return this->prev;
}
string Stack::peek() {
	return this->s;
}

bool isNumber(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') return true;
	}
	return false;
}

bool isLower(char c1, char c2) {
	return precedence[c1] <= precedence[c2];
}

string infixToPostfix(string infix) {
	string post = "";
	Stack* head = nullptr;

	istringstream str(infix);
	string token;
	while (str >> token) {
		// number
		if (isNumber(token)) {
			post += token + " ";
		// parentheses
		} else if (token[0] == '(') {
			head = head->push(token);
		} else if (token[0] == ')') {
			while (head != nullptr) {
				if (head->peek()[0] != '(') {
					post += head->peek() + " ";
					head = head->pop();
				} else {
					break;
				}
			}
			head = head->pop();
		// operator
		} else {
			while (head != nullptr && isLower(token[0], head->peek()[0])) {
				post += head->peek() + " ";
				head = head->pop();
			}
			head = head->push(token);
		}
	}
	// remaining operators
	while (head != nullptr) {
		post += head->peek() + " ";
		head = head->pop();
	}
	post.pop_back();
	return post;
}

int eval(string s) {
	Stack* head = nullptr;

	istringstream str(s);
	string token;
	while (str >> token) {
		if (isNumber(token)) {
			head = head->push(token);
		} else {
			int a = stoi(head->peek());
			head = head->pop();
			if (token[0] == '!') {
				int prod = 1;
				for (int i = 2; i <= a; i++) {
					prod *= i;
				}
				head = head->push(to_string(prod));
			} else {
				int b = stoi(head->peek());
				head = head->pop();
				switch (token[0]) {
					case '+':
						head = head->push(to_string(b + a));
						break;
					case '-':
						head = head->push(to_string(b - a));
						break;
					case '*':
						head = head->push(to_string(b * a));
						break;
					case '/':
						head = head->push(to_string(b / a));
						break;
					case '^':
						head = head->push(to_string(pow(b, a)));
						break;
					case '%':
						head = head->push(to_string(b % a));
						break;
				}
			}
		}
	}
	return stoi(head->peek());
}

int main() {
	string name;
	cout << "Enter the name of the file you'd like to read from:\n";
	cin >> name;

	ifstream infile(name);
	ofstream outfile("result.txt");

	string expr;
	for (int i = 1; getline(infile, expr); i++) {
		outfile << "Infix: " << expr << " | Postfix: " << infixToPostfix(expr) << " | Evaluate: " << eval(infixToPostfix(expr)) << "\n";
	}

	return 0;
}
