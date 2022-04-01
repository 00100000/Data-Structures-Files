// Postfix.cpp
// Author: Aidan Din
// Evaluates postfix expressions with a stack

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

class Stack {
	private:
		int num;
		Stack* prev;

	public:
		Stack(int n, Stack* p) {
			num = n;
			prev = p;
		}
		Stack* push(Stack* p);
		Stack* pop();
		int peek();
};
Stack* Stack::push(Stack* p) {
	return p;
}
Stack* Stack::pop() {
	return this->prev;
}
int Stack::peek() {
	return this->num;
}

int eval(string s) {
	Stack* head = new Stack(-1, nullptr);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') continue;
		// if is number (including negative)
		if (s[i] > 47 && s[i] < 58 || (i < s.size() - 1 && s[i] == 45 && s[i + 1] != ' ')) {
			// get rest of number
			string num = "";
			for (int j = i; j < s.size() && s[j] != ' '; j++, i++) {
				if (s[j] == '-') {
					num += '-';
				} else {
					num += to_string(s[j] - 48);
				}
			}
			// add to stack
			head = head->push(new Stack(stoi(num), head));
		} else {
			int a = head->peek();
			head = head->pop();
			if (s[i] == '!') {
				int prod = 1;
				for (int i = 2; i <= a; i++) {
					prod *= i;
				}
				head = head->push(new Stack(prod, head));
			} else {
				int b = head->peek();
				head = head->pop();
				switch (s[i]) {
					case '+':
						head = head->push(new Stack(b + a, head));
						break;
					case '-':
						head = head->push(new Stack(b - a, head));
						break;
					case '*':
						head = head->push(new Stack(b * a, head));
						break;
					case '/':
						head = head->push(new Stack(b / a, head));
						break;
					case '^':
						head = head->push(new Stack(pow(b, a), head));
						break;
					case '%':
						head = head->push(new Stack(b % a, head));
						break;
				}
			}
		}
	}
	return head->peek();
};

int main() {
	string name;
	cout << "Enter the name of the file you'd like to read from:\n";
	cin >> name;

	ifstream infile(name);
	ofstream outfile("result.txt");

	string expr;
	for (int i = 1; getline(infile, expr); i++) {
		outfile << expr << ": " << eval(expr) << "\n";
	}

	cout << flush;
	return 0;
}
