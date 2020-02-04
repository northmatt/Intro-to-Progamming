#include "Rectangle.h"

Rectangle::Rectangle(float _width, float _length) {
	SetWidth(_width);
	SetLength(_length);
}

void Rectangle::SetWidth(float _width) {
	width = fminf(20, fmaxf(0, _width));
}

void Rectangle::SetLength(float _length) {
	length = fminf(20, fmaxf(0, _length));
}

float Rectangle::GetWidth() {
	return width;
}

float Rectangle::GetLength() {
	return length;
}

float Rectangle::Perimeter() {
	return 2 * (width + length);
}

float Rectangle::Area() {
	return width * length;
}
