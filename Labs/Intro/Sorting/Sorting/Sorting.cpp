#include "Sorting.h"

void SortS(string inArray[], unsigned int size) {
	string* outArray;

	outArray = new (nothrow) string[size];

	if (outArray == nullptr)
		cout << "Memory couldn't be allocated";
	else {
		unsigned int least{ 0 }, largest{ 0 }, pos{ 0 };

		for (unsigned int i = 0; i < size; i++) {
			outArray[i] = i;
			if (inArray[i].length() >= largest)
				largest = inArray[i].length();
		}

		for (unsigned int y = 0; y < size; y++) {
			least = largest;

			for (unsigned int x = y; x < size; x++)
				if (inArray[x].length() < least) {
					least = inArray[x].length();
					pos = x;
				}

			outArray[y] = inArray[pos];
			inArray[pos] = inArray[y];
		}

		for (unsigned int i = 0; i < size; i++)
			cout << outArray[i] << ", ";

		delete[] outArray;
	}
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

void SortC(char inArray[], unsigned int size) {
	char* outArray;

	outArray = new (nothrow) char[size];

	if (outArray == nullptr)
		cout << "Memory couldn't be allocated";
	else {
		
		char least{ 65 }, largest{ 90 };
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
}