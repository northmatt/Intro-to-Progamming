#include <iostream>
#include <time.h>
#include "Sorting.h"

using std::cin;
using std::cout;
using std::rand;

int main() {
	srand(time(0));

	int intTest[10]{ };
	for (int i = 0; i < sizeof(intTest) / sizeof(*intTest); i++)
		intTest[i] = rand() - RAND_MAX / 2;

	SortI(intTest, sizeof(intTest) / sizeof(*intTest));

	cout << "\n";

	const char *charTest[100]{ };
	for (int i = 0; i < sizeof(charTest) / sizeof(*charTest); i++)
		charTest[i] = static_cast<const int>(65 + rand() % 26);

	SortC(charTest, 0);
}
