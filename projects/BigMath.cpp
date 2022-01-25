// BigMath.cpp
// Author: Aidan Din
// Implements math on large numbers with linked lists

#include <iostream>
using namespace std;

class BigMath {
	private:
		int digit;
		BigMath* next;
	public:
		BigMath(int d, BigMath* n) {
			digit = d;
			next = n;
		}
		BigMath(string s) {
			this->digit = s.at(s.size() - 1) - 48;
			BigMath* prev = this;
			for (int i = s.size() - 2; i >= 0; i--) {
				BigMath* temp = new BigMath(s.at(i) - 48, nullptr);
				prev->next = temp;
				prev = temp;
			}
		}
		BigMath operator + (BigMath b);
		BigMath operator - (BigMath b);
		friend ostream& operator << (ostream& stream, BigMath* b);
		BigMath* arith(BigMath* a, BigMath* b, bool add);
		BigMath* fix(BigMath* b);
		int getDigit();
		BigMath* getNext();
		void setDigit(int d);
		void setNext(BigMath* n);
};
// methods
BigMath BigMath::operator + (BigMath b) {
	return *fix(arith(this, &b, true));
}
BigMath BigMath::operator - (BigMath b) {
	return *fix(arith(this, &b, false));
}
// converts BigMath to a string and outputs it
ostream& operator << (ostream& stream, BigMath* b) {
	string s = "";
	while (b != nullptr) {
		s = to_string(b->digit) + s;
		if (b->next != nullptr && s.at(0) == '-') {
			s.erase(0, 1);
		}
		b = b->next;
	}
	if (s.compare("") == 0) s = "0";
	stream << s;
	return stream;
}
// helps add/subtract two BigMaths recursively
BigMath* BigMath::arith(BigMath* a, BigMath* b, bool add) {
	if (a == nullptr && b == nullptr) return nullptr;
	if (a == nullptr) a = new BigMath(0, nullptr);
	if (b == nullptr) b = new BigMath(0, nullptr);
	return new BigMath(a->digit + (add ? b->digit : -b->digit), arith(a->next, b->next, add));
}
// converts BigMath into a properly formatted base 10 number
BigMath* BigMath::fix(BigMath* b) {
	bool positive = true;
	// check if last non-zero digit in BigMath is negative or positive
	BigMath* end = b;
	while (end != nullptr) {
		if (end->digit != 0) {
			positive = end->digit > 0;
		}
		end = end->next;
	}

	BigMath* temp = b;
	int carry = 0;
	while (temp != nullptr) {
		temp->digit += carry;
		// make sure all digits are positive/negative
		if (positive && temp->digit < 0) {
			carry = temp->digit / 10 - 1;
			temp->digit %= 10;
			temp->digit += 10;
		} else if (!positive && temp->digit > 0) {
			carry = temp->digit / 10 + 1;
			temp->digit %= 10;
			temp->digit -= 10;
		} else {
			carry = temp->digit / 10;
		}
		// make sure all digits are an single-digit
		temp->digit %= 10;
		temp = temp->next;
	}
	// if an addition creates a new place larger number
	end = b;
	while (end->next != nullptr) end = end->next;
	if (positive && carry != 0) {
		BigMath* newTail = new BigMath(carry, nullptr);
		end->next = newTail;
	}
	// trim leading zeroes
	temp = b;
	end = b;
	while (temp != nullptr) {
		if (temp->digit != 0) {
			end = temp;
		}
		temp = temp->next;
	}
	end->next = nullptr;
	return b;
}
// setters/getters
int BigMath::getDigit() {
	return digit;
}
BigMath* BigMath::getNext() {
	return next;
}
void BigMath::setDigit(int d) {
	digit = d;
}
void BigMath::setNext(BigMath* n) {
	next = n;
}
int main() {
	bool repeat = false;
	do {
		// input
		int choice;
		cout << "What would you like to do?\n1. Add two big numbers\n2. Subtract two big numbers\n";
		cin >> choice;

		cout << "Enter the first and second number to perform this operation on respectively, separated by a space. (First +/- Second)\n";
		string first, second;
		cin >> first >> second;
		BigMath* a = new BigMath(first);
		BigMath* b = new BigMath(second);
		// output
		switch (choice) {
			case 1: {
				BigMath sum = *a + *b;
				cout << "Sum: " << &sum;
				break;
			}
			case 2: {
				BigMath diff = *a - *b;
				cout << "Difference: " << &diff;
				break;
			}
		}
		// re-run
		cout << "\nWould you like to run this program again?\n1 for yes, 0 for no\n";
		cin >> repeat;
	} while (repeat);
	cout << flush;
	return 0;
}