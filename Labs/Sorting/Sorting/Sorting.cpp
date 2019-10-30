#include "Sorting.h"

void SortS(string inArray[], const int size) {
	
}

void SortI(int inArray[], unsigned int size) {
	int* outArray;

	outArray = new (nothrow) int[size];

	if (outArray == nullptr)
		cout << "Memory couldn't be allocated";
	else {
		int least{ 0 }, largest{ 0 };
		unsigned int pos{ 0 };

		for (unsigned int i = 0; i < size; i++) {
			outArray[i] = i;
			if (inArray[i] >= largest)
				largest = inArray[i];
		}

		for (unsigned int y = 0; y < size; y++) {
			least = largest;

			for (unsigned int x = y; x < size; x++)
				if (inArray[x] < least) {
					least = inArray[x];
					pos = x;
				}

			outArray[y] = least;
			inArray[pos] = inArray[y];
		}

		for (unsigned int i = 0; i < size; i++)
			cout << outArray[i] << ", ";

		delete[] outArray;
	}
}

void SortC(const char *test[], unsigned int size) {
	const char* outArray;

	outArray = new (nothrow) char[3];
	/*
	if (outArray == nullptr)
		cout << "Memory couldn't be allocated";
	else {
		char least{ 0 }, largest{ 81 };
		unsigned int pos{ 0 };
		
		for (unsigned int i = 0; i < size; i++) {
			outArray[i] = 65;
		}
		
		for (unsigned int y = 0; y < size; y++) {
			least = largest;

			for (unsigned int x = y; x < size; x++)
				if (inArray[x] < least) {
					least = inArray[x];
					pos = x;
				}

			outArray[y] = least;
			inArray[pos] = inArray[y];
		}
		
		for (unsigned int i = 0; i < size; i++)
			cout << outArray[i] << ", ";
		
		delete[] outArray;
	}
	*/
}