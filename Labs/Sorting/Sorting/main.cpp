#include <iostream>
#include <time.h>
#include "Sorting.h"

using std::cin;
using std::cout;
using std::endl;
using std::rand;

int main() {
	srand(time(0));

	int intTest[100]{ };
	for (int i = 0; i < sizeof(intTest) / sizeof(*intTest); i++)
		intTest[i] = rand() - RAND_MAX / 2;

	SortI(intTest, sizeof(intTest) / sizeof(*intTest));

	cout << "\n\n";

	char charTest[100]{ };
	for (int i = 0; i < sizeof(charTest) / sizeof(*charTest); i++)
		charTest[i] = 65 + rand() % 26;

	SortC(charTest, sizeof(charTest) / sizeof(*charTest));

	cout << "\n\n";

	string strTest[100]{ "" };
	unsigned int maxSize{ 10 };
	for (int y = 0; y < sizeof(strTest) / sizeof(*strTest); y++)
		for (unsigned int x = 0; x <= rand() % maxSize; x++)
			strTest[y] += 65 + rand() % 26;

	SortS(strTest, sizeof(strTest) / sizeof(*strTest));

	cout << endl;
}
