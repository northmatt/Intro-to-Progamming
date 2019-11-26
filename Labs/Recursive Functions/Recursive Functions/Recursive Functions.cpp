#include "Recursive Functions.h"

void Recursion::UsrInp() {
	unsigned int inp;
	while (true) {
		cout << "Num: ";
		cin >> inp;

		cout << Count(inp) << "\n";
		cout << Sum(inp) << "\n";
		cout << isPrime(inp) << "\n";
		cout << factorial(inp) << "\n";
	}
}

unsigned int Recursion::Count(unsigned int num) {
	if (num < 10)
		return 1;

	return Count(num / 10) + 1;
}

unsigned int Recursion::Sum(unsigned int num) {
	if (num < 10)
		return num;

	unsigned int sizeDiv = pow(10, static_cast<unsigned int>(log10(num)));
	unsigned int temp = num / sizeDiv;

	return Sum(num - temp * sizeDiv) + temp;
}

bool Recursion::isPrime(unsigned int num) {
	unsigned int square = sqrt(num);

	if (num == 2 || num == 3)
		return true;
	else if (num % 2 == 0)
		return false;
	else if (num % 3 == 0)
		return false;

	return isPrime2(num, square, 5);
}

unsigned int Recursion::factorial(unsigned int num) {
	if (num == 1 || num > 4500 /*so that stack overflow wont happen*/)
		return 1;

	return num * factorial(num - 1);
}

bool Recursion::isPrime2(unsigned int num, unsigned int numCheck, unsigned int numCurrent) {
	if (numCurrent > numCheck)
		return true;

	if (num % numCurrent == 0)
		return false;

	return isPrime4(num, numCheck, numCurrent + 2);
}

bool Recursion::isPrime4(unsigned int num, unsigned int numCheck, unsigned int numCurrent) {
	if (numCurrent > numCheck)
		return true;

	if (num % numCurrent == 0)
		return false;

	return isPrime2(num, numCheck, numCurrent + 4);
}
