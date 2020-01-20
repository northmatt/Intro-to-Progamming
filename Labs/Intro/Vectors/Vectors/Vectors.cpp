// Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Vectors.h"

using std::cout;

int main() {
	Vec2 vector0{ 1, 3 };

	printf("(%f, %f)\n", vector0.x, vector0.y);
	printf("mag: %f\n", vector0.Mag());

	return 0;
}