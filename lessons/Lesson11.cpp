// Lesson11.cpp
// Author: Aidan Din
// Implements multiple inheritance with a variety of quadrilaterals

#include <iostream>
using namespace std;

class Quadrilateral {
	// sides
	// a and b are adjacent, a and c are opposite.
	int a, b, c, d;

	public:
		Quadrilateral() {}
		Quadrilateral(int w, int x, int y, int z) {
			setValues(w, x, y, z);
		}
		void setValues(int w, int x, int y, int z) {
			a = w;
			b = x;
			c = y;
			d = z;
		}
		int perimeter() {
			return a + b + c + d;
		}
};
class Kite : virtual public Quadrilateral {
	public:
		Kite() {}
		Kite(int x, int y) {
			setValues(x, x, y, y);
		}
};
class Trapezoid : virtual public Quadrilateral {
	public:
		Trapezoid() {}
		Trapezoid(int w, int x, int y, int z) {
			setValues(w, x, y, z);
		}
};
class Parallelogram : public Trapezoid {
	public:
		Parallelogram() {}
		Parallelogram(int x, int y) {
			setValues(x, y, x, y);
		}
};
class IsocelesTrapezoid : public Trapezoid {
	public:
		IsocelesTrapezoid() {}
		IsocelesTrapezoid(int x, int y, int z) {
			setValues(x, y, z, y);
		}
};
class Rhombus : public Kite, public Parallelogram {
	public:
		Rhombus() {}
		Rhombus(int x) {
			setValues(x, x, x, x);
		}
};
class Rectangle : public IsocelesTrapezoid, public Parallelogram {
	public:
		Rectangle() {}
		Rectangle(int x, int y) {
			setValues(x, y, x, y);
		}
};
class Square : public Rhombus, public Rectangle {
	public:
		Square(int x) {
			setValues(x, x, x, x);
		}
};

int main() {
	Square s(5);
	cout << s.perimeter() << endl;
}