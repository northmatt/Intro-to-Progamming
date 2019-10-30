#include <iostream>
#include <time.h>
#include "Sorting.h"

using std::cin;
using std::cout;
using std::endl;
using std::rand;

int main() {
	srand(time(0));
	//int sorting
	cout << "Before:\n";

	int intTest[100]{ };
	for (int i = 0; i < sizeof(intTest) / sizeof(*intTest); i++) {
		intTest[i] = rand() - RAND_MAX / 2;
		cout << intTest[i] << ", ";
	}

	cout << "\n\nAfter:\n";
	SortI(intTest, sizeof(intTest) / sizeof(*intTest));
	//char sorting
	cout << "\n\nBefore:\n";

	char charTest[100]{ };
	for (int i = 0; i < sizeof(charTest) / sizeof(*charTest); i++) {
		charTest[i] = 65 + rand() % 26;
		cout << charTest[i] << ", ";
	}

	cout << "\n\nAfter:\n";
	SortC(charTest, sizeof(charTest) / sizeof(*charTest));
	//string sorting
	cout << "\n\nBefore:\n";

	string strTest[100]{ "" };
	unsigned int maxSize{ 10 };
	for (int y = 0; y < sizeof(strTest) / sizeof(*strTest); y++) {
		for (unsigned int x = 0; x <= rand() % maxSize; x++)
			strTest[y] += 65 + rand() % 26;
		cout << strTest[y] << ", ";
	}

	cout << "\n\nAfter:\n";
	SortS(strTest, sizeof(strTest) / sizeof(*strTest));

	cout << endl;

	return 0;
}
