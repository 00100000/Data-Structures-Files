// Shapes.cpp
// Aidan Din
// Implements multiple inheritance with shapes

#include <iostream>
using namespace std;

class Output {
	public:
		void print();
};

class Polygon : Output {
	protected:
		int length;
		int width;

	public:
		Polygon() {
			length = 0;
			width = 0;
		}
		Polygon(int l, int w) {
			length = l;
			width = w;
		}
		// getters
		int getLength() {
			return length;
		}
		int getWidth() {
			return width;
		}
		// setters
		void setValues(int a, int b) {
			length = a;
			width = b;
		}
		void setLength(int l) {
			length = l;
		}
		void setWidth(int w) {
			width = w;
		}
		void print() {
			cout << "~ Information About This Polygon ~\nLength: " << getLength() << "\nWidth: " << getWidth();
		}
};

class Rectangle : public Polygon {
	public:
		Rectangle(int l, int w) {
			setValues(l, w);
		}
		float area() {
			return getLength() * getWidth();
		}
		void print() {
			cout << "~ Information About This Rectangle ~\nLength: " << getLength() << "\nWidth: " << getWidth() << "\nArea: " << area() << "\n";
		}
};

class Triangle : public Polygon {
	public:
		Triangle(int l, int w) {
			setValues(l, w);
		}
		float area() {
			return (float)(getLength() * getWidth()) / 2;
		}
		void print() {
			cout << "~ Information About This Triangle ~\nLength: " << getLength() << "\nWidth: " << getWidth() << "\nArea: " << area() << "\n";
		}
};


int main() {
	bool repeat = false;
	do {
		int choice;
		cout << "What polygon would you like to create?\n1. Rectangle\n2. Triangle\n";
		cin >> choice;

		int l, w;
		cout << "Enter the length and width of your polygon (space separated)\n";
		cin >> l >> w;

		switch (choice) {
			case 1: {
				Rectangle r(l, w);
				r.setValues(l, w);
				r.print();
				break;
			}
			case 2: {
				Triangle t(l, w);
				t.print();
				break;
			}
		}

		cout << "Would you like to run this program again?\n1 for yes, 0 for no\n";
		cin >> repeat;
	} while (repeat);
	cout << flush;
	return 0;
}