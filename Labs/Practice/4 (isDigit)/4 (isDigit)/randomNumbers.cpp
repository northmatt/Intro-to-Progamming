#include "randomNumbers.h"

void RandomNumber::run() {
	srand(time(0));
	
	cout << static_cast<double>(rand() % 100) / 100 << "\n";
	for (int i = 0; i < 50; i++)	{
		cout << static_cast<double>(rand() % 6) << "\n";
	}
}
