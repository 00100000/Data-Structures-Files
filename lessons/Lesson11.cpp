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
		void setSides(int w, int x, int y, int z) {
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
		Kite();
		Kite(int x, int y) {
			setSides(x, x, y, y);
		}
};
class Trapezoid : virtual public Quadrilateral {
	public:
		Trapezoid();
		Trapezoid(int w, int x, int y, int z) {
			setSides(w, x, y, z);
		}
};
class Parallelogram : public Trapezoid {
	public:
		Parallelogram();
		Parallelogram(int x, int y) {
			setSides(x, y, x, y);
		}
};
class IsocelesTrapezoid : public Trapezoid {
	public:
		IsocelesTrapezoid();
		IsocelesTrapezoid(int x, int y, int z) {
			setSides(x, y, z, y);
		}
};
class Rhombus : public Kite, public Parallelogram {
	public:
		Rhombus();
		Rhombus(int x) {
			setSides(x, x, x, x);
		}
};
class Rectangle : IsocelesTrapezoid, Parallelogram {
	public:
		Rectangle();
		Rectangle(int x, int y) {
			setSides(x, y, x, y);
		}
};
class Square : Rhombus, Rectangle {
	public:
		Square(int x) {
			setSides(x, x, x, x);
		}
};