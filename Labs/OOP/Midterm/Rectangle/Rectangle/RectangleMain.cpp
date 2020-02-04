#include "Rectangle.h"

using std::cout;
using std::endl;

int main() {
	Rectangle a, b(4.0, 5.0), c(67.0, 888.0);

	cout << "a width:" << a.GetWidth() << endl
		<< "a length: " << a.GetLength() << endl
		<< "a area: " << a.Area() << endl
		<< "a perimeter: " << a.Perimeter() << endl << endl;

	cout << "b width:" << b.GetWidth() << endl
		<< "b length: " << b.GetLength() << endl
		<< "b area: " << b.Area() << endl
		<< "b perimeter: " << b.Perimeter() << endl << endl;

	cout << "c width:" << c.GetWidth() << endl
		<< "c length: " << c.GetLength() << endl
		<< "c area: " << c.Area() << endl
		<< "c perimeter: " << c.Perimeter() << endl << endl;
}