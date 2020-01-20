// User Input.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	int nums[3];

	cout << "Give the numbers to add them all \n";

	for (int currentNum = 0; currentNum < size(nums); currentNum++) {
		cout << "Number " << currentNum + 1 << ": ";
		cin >> nums[currentNum];
	}

	cout << "\n Resultant: " << nums[0] + nums[1] + nums[2];
	return 0;
}