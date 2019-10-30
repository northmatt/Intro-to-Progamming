// Fibonacci Sequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;


int factorial(int num) {
	int nums{1};

	for (int currentNum = 1; currentNum <= num; currentNum++) {
		nums *= currentNum;
	}

	return nums;
}

int choose(int group, int size) {
	return factorial(group) / (factorial(group - size) * factorial(size));
}

int main() {
	string input;
	int numInterations{ 0 };
	int sum{ 0 };

	while (numInterations <= 0) {
		cout << "\nNumber: ";
		cin >> input;

		numInterations = atoi(input.c_str());
	}

	for (int currentNum = 1; currentNum <= numInterations; currentNum++) {
		for (int x = 0; x < ceil(currentNum / 2.f); x++) {
			//cout << "X: " << x << ", Y: " << numInterations - x - 1 << "\n";
			sum += choose(currentNum - x - 1, x);
		}

		cout << sum << "\n";
		sum = 0;
	}

	return 0;
}