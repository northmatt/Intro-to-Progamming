#include "Shapes.h"

int main() {
	Shapes shape0;
	Shapes shape1{ -4 };
	Shapes shape2{ 1, 6 };
	Shapes shape3{ 2, 3, 4 };
	Shapes shape4{ 3, 2, 5, 4 };
	Shapes shape5{ 2, 1, 3, 5, 4 };

	cout << endl;

	shape0.ProvideShapeInfo();
	shape1.ProvideShapeInfo();
	shape2.ProvideShapeInfo();
	shape3.ProvideShapeInfo();
	shape4.ProvideShapeInfo();
	shape5.ProvideShapeInfo();

	shape1.ModifyLength(&Shapes{ 10 });
	shape3.ModifyLength(&Shapes{ 1 });
	shape3.ModifyLength(&Shapes{ 1, 2, 3, 4, 5 });
	shape5.ModifyLength(&Shapes{ 1, 2, 3, 4, 5 });

	cout << endl;

	shape0.ProvideShapeInfo();
	shape1.ProvideShapeInfo();
	shape2.ProvideShapeInfo();
	shape3.ProvideShapeInfo();
	shape4.ProvideShapeInfo();
	shape5.ProvideShapeInfo();
}