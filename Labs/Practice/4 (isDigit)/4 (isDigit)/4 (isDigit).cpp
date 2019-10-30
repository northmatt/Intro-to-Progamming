// 4 (isDigit).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "isDigit.h"

bool IsDigit::isDigit(const char *test) {
	double num = atof(test);

	return num - int(num) != 0;
}

void IsDigit::run() {
	string input;
	cin >> input;

	cout << isDigit(input.c_str());
}