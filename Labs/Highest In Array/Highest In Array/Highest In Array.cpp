// Highest In Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::endl;

int findHighest(int theArray[], int size) {
	int max{ 0 };

	for (int i = 0; i < size; i++)
		if (theArray[i] > max)
			max = theArray[i];

	return max;
}

int main()
{
	int randArray[] { 9, 72, 12, 41, 42, 21, 8 };

	cout << findHighest(randArray, sizeof(randArray) / sizeof(*randArray)) << endl;
}