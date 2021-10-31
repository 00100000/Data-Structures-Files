// Lesson11.cpp
// Author: Aidan Din
// Implements multiple inheritance with a variety of quadrilaterals

class Quadrilateral {
	// sides
	// a and b are adjacent, a and c are opposite.
	int a, b, c, d;

	public:
		Quadrilateral();
		Quadrilateral(int w, int x, int y, int z) {
			setSides(w, x, y, z);
		}
		int setSides(int w, int x, int y, int z) {
			a = w;
			b = x;
			c = y;
			d = z;
		}
		int perimeter() {
			return a + b + c + d;
		}
		int area() {}
};
class Kite : virtual public Quadrilateral {
	public:
		Kite();
		Kite(int x, int y) {
			Quadrilateral(x, x, y, y);
		}
};
class Trapezoid : virtual public Quadrilateral {
	public:
		Trapezoid();
		Trapezoid(int w, int x, int y, int z) {
			Quadrilateral(w, x, y, z);
		}
};
class Parallelogram : Trapezoid {
	public:
		Parallelogram();
		Parallelogram(int x, int y) {
			Trapezoid(x, y, x, y);
		}
};
class IsocelesTrapezoid : Trapezoid {
	public:
		IsocelesTrapezoid();
		IsocelesTrapezoid(int x, int y, int z) {
			Trapezoid(x, y, z, y);
		}
};
class Rhombus : Kite, Parallelogram {
	public:
		Rhombus();
		Rhombus(int x) {
			Kite(x, x);
		}
};
class Rectangle : IsocelesTrapezoid, Parallelogram {
	public:
		Rectangle();
		Rectangle(int x, int y) {
			Parallelogram(x, y);
		}
};
class Square : Rhombus, Rectangle {
	public:
		Square(int x) {
			Rhombus(x);
		}
};