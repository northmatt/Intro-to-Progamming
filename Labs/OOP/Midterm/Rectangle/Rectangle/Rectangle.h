#pragma once

#include <iostream>
using std::fmaxf;
using std::fminf;

class Rectangle {
public:
	Rectangle() {}
	Rectangle(float _width, float _length);
	~Rectangle() {}

	void SetWidth(float _width);
	void SetLength(float _length);

	float GetWidth();
	float GetLength();

	float Perimeter();
	float Area();
private:
	float width{ 1 };
	float length{ 1 };
};