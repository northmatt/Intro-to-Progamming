#pragma once

#include <iostream>
#include <math.h>

struct Vec2 {
	double x;
	double y;

	double Mag() {
		return sqrt(x * x + y * y);
	}
};

Vec2 operator+(const Vec2 v1, const Vec2 v2) {
	return Vec2{ v1.x + v2.x, v1.y + v2.y };
}

Vec2 operator-(const Vec2 v1, const Vec2 v2) {
	return Vec2{ v1.x - v2.x, v1.y - v2.y };
}
//scale
Vec2 operator*(const double scale, const Vec2 v1) {
	return Vec2{ scale * v1.x , scale * v1.y };
}
//dot
double operator*(const Vec2 v1, const Vec2 v2) {
	return v1.x * v2.x + v1.y * v2.y;
}
//cross
Vec2 operator^(const Vec2 v1, const Vec2 v2) {
	return Vec2{ v1.x * v2.y - v1.y * v2.x, v1.y * v2.x - v1.x * v2.y };
}