#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Shapes {
public:
	//create a enum for storing the type of shape
	enum class ShapeTypes {
		Circle, Square, Rectangle, Triangle, Diamond, Pentagon, Null
	};

	//create a struct for holding the shape info
	struct ShapeInfo {
		ShapeTypes shapeName{ ShapeTypes::Null };
		double sides[5]{ 0 };
	};

	Shapes();
	Shapes(double side1);
	Shapes(double side1, double side2);
	Shapes(double side1, double side2, double side3);
	Shapes(double side1, double side2, double side3, double side4);
	Shapes(double side1, double side2, double side3, double side4, double side5);
	~Shapes();

	void ProvideShapeInfo();
	void ModifyLength(Shapes *newShape);
private:
	ShapeInfo shape;
	bool showDeathMessage{ true };
};