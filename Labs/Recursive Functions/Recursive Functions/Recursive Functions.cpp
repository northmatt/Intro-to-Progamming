#include "Recursive Functions.h"

void Recursion::UsrInp() {
	unsigned int inp;
	while (true) {
		cout << "Num: ";
		cin >> inp;

		cout << "Number of digits: " << Count(inp) << "\n";
		cout << "Sum of digits: " << Sum(inp) << "\n";
		cout << "Is a prime number: " << isPrime(inp) << "\n";
		cout << "Factorial: " << factorial(inp) << "\n\n";
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
	//all prime number for the exception of 2/3 are a factor of 6 +/- 1
	//also for a multiple table for 24 as an example -- 24: 1,2,3,4,6,8,12,24
	//you dont need to go past the number sqrt(24) -> 4.9 -> 4 as you already seen 1,2,3,4 which are multiples of 24. 
	//So with that you already know about 6,8,12,24 existing
	unsigned int square = sqrt(num);

	if (num == 2 || num == 3)
		return true;
	else if (num % 2 == 0)
		return false;
	else if (num % 3 == 0)
		return false;

	return isPrime2(num, square, 5);
}

unsigned __int64 Recursion::factorial(unsigned __int64 num) {
	if (num == 1 || num > 100 /*stop stack overflow and 30! is already too large for unsigned int64*/)
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
