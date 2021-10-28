// Lesson11.cpp
// Author: Aidan Din
// Implements multiple inheritance with a variety of quadrilaterals

class Quadrilateral {
	// sides
	// a and b are adjacent, a and c are opposite.
	int a, b, c, d;
	// angles
	// e and g are opposite
	int e, f, g, h;

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
		int setAngles(w, x, y, z) {
			e = w;
			f = x;
			g = y;
			h = z;
		}
		int perimeter() {
			return a + b + c + d;
		}
		int area() {}
};
class Kite : Quadrilateral {
	Kite(int x, int y) {
		setSides(x, x, y, y);
	}
};
class Trapezoid : Quadrilateral {
	Trapezoid
};
class Parallelogram : Trapezoid {};
class IsocelesTrapezoid : Trapezoid {};
class Rhombus : Kite, Parallelogram {};
class Rectangle : IsocelesTrapezoid, Parallelogram {};
class Square : Rhombus, Rectangle {};

int main() {
	return 0;
}