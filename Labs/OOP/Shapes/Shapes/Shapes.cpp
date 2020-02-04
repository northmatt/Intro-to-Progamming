#include "Shapes.h"

//constructors for creating the shapes. Based on the input given it'll know which shape type to give it
Shapes::Shapes() {
	double sides[]{ 350.5 };
	shape = ShapeInfo{ ShapeTypes::Circle, { sides[0] } };
}

Shapes::Shapes(double side1) {
	double sides[]{ side1 };
	for (size_t i = 0; i < 1; i++)
		if (sides[i] <= 0) {
			cout << "side must be greater then 0\n";
			sides[i] = 1;
		}

	shape = ShapeInfo{ ShapeTypes::Square, { sides[0] } };
}

Shapes::Shapes(double side1, double side2) {
	double sides[]{ side1, side2 };
	for (size_t i = 0; i < 2; i++)
		if (sides[i] <= 0) {
			cout << "side must be greater then 0\n";
			sides[i] = 1;
		}

	shape = ShapeInfo{ ShapeTypes::Rectangle, { sides[0], sides[1] } };
}

Shapes::Shapes(double side1, double side2, double side3) {
	double sides[]{ side1, side2, side3 };
	for (size_t i = 0; i < 3; i++)
		if (sides[i] <= 0) {
			cout << "side must be greater then 0\n";
			sides[i] = 1;
		}

	shape = ShapeInfo{ ShapeTypes::Triangle, { sides[0], sides[1], sides[2] } };
}

Shapes::Shapes(double side1, double side2, double side3, double side4) {
	double sides[]{ side1, side2, side3, side4 };
	for (size_t i = 0; i < 4; i++)
		if (sides[i] <= 0) {
			cout << "side must be greater then 0\n";
			sides[i] = 1;
		}

	shape = ShapeInfo{ ShapeTypes::Diamond, { sides[0], sides[1], sides[2], sides[3] } };
}

Shapes::Shapes(double side1, double side2, double side3, double side4, double side5) {
	double sides[]{ side1, side2, side3, side4, side5 };
	for (size_t i = 0; i < 5; i++)
		if (sides[i] <= 0) {
			cout << "side must be greater then 0\n";
			sides[i] = 1;
		}

	shape = ShapeInfo{ ShapeTypes::Pentagon, { sides[0], sides[1], sides[2], sides[3], sides[4] } };
}

//deconstructor. Will show that it has been destroyed unless told otherwise
Shapes::~Shapes() {
	if (!showDeathMessage)
		return;

	switch (shape.shapeName) {
	case ShapeTypes::Circle:
		cout << "This Circle has been deleted succesfully\n";
		break;
	case ShapeTypes::Square:
		cout << "This Square has been deleted succesfully\n";
		break;
	case ShapeTypes::Rectangle:
		cout << "This Rectangle has been deleted succesfully\n";
		break;
	case ShapeTypes::Triangle:
		cout << "This Triangle has been deleted succesfully\n";
		break;
	case ShapeTypes::Diamond:
		cout << "This Diamond has been deleted succesfully\n";
		break;
	case ShapeTypes::Pentagon:
		cout << "This Pentagon has been deleted succesfully\n";
		break;
	case ShapeTypes::Null:
		cout << "This shape has been deleted succesfully\n";
		break;
	default:
		break;
	}
}

//a switch used based on the shape type to give the info of the shape
void Shapes::ProvideShapeInfo() {
	switch (shape.shapeName) {
	case ShapeTypes::Circle:
		cout << "Shape: Circle\nRadius: " + to_string(shape.sides[0]);
		break;
	case ShapeTypes::Square:
		cout << "Shape: Square\nSide Lengths: " + to_string(shape.sides[0]);
		break;
	case ShapeTypes::Rectangle:
		cout << "Shape: Rectangle\nSide Lengths: " + to_string(shape.sides[0]) + ", " + to_string(shape.sides[1]);
		break;
	case ShapeTypes::Triangle:
		cout << "Shape: Triangle\nSide Lengths: " + to_string(shape.sides[0]);
		for (size_t i = 0; i < 2; i++)
			cout << ", " + to_string(shape.sides[i + 1]);
		break;
	case ShapeTypes::Diamond:
		cout << "Shape: Diamond\nSide Lengths: " + to_string(shape.sides[0]);
		for (size_t i = 0; i < 3; i++)
			cout << ", " + to_string(shape.sides[i + 1]);
		break;
	case ShapeTypes::Pentagon:
		cout << "Shape: Pentagon\nSide Lengths: " + to_string(shape.sides[0]);
		for (size_t i = 0; i < 4; i++)
			cout << ", " + to_string(shape.sides[i + 1]);
		break;
	case ShapeTypes::Null:
		cout << "Shape has no info";
		break;
	default:
		break;
	}

	cout << endl << endl;
}

//checks the shape type of the input to the shape type of this object to see if they are the same. If so then change the side lengths
void Shapes::ModifyLength(Shapes *newShape) {
	newShape->showDeathMessage = false;

	switch (shape.shapeName) {
	case ShapeTypes::Circle:
		cout << "Circle";
		break;
	case ShapeTypes::Square:
		cout << "Square";
		break;
	case ShapeTypes::Rectangle:
		cout << "Rectangle";
		break;
	case ShapeTypes::Triangle:
		cout << "Triangle";
		break;
	case ShapeTypes::Diamond:
		cout << "Diamond";
		break;
	case ShapeTypes::Pentagon:
		cout << "Pentagon";
		break;
	case ShapeTypes::Null:
		cout << "shape";
		break;
	default:
		break;
	}

	if (shape.shapeName != newShape->shape.shapeName) {
		cout << " failed to be modified" << endl;
		return;
	}

	shape = newShape->shape;
	cout << " has been modified" << endl;
}
