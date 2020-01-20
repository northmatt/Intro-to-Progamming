#pragma once

#include <iostream>
#include <math.h>

using std::cout;
using std::cin;

class Recursion {
public:
	Recursion() { UsrInp(); }

	void UsrInp();
	unsigned int Count(unsigned int num);
	unsigned int Sum(unsigned int num);
	bool isPrime(unsigned int num);
	unsigned __int64 factorial(unsigned __int64 num);
private:
	bool isPrime2(unsigned int num, unsigned int numCheck, unsigned int numCurrent);
	bool isPrime4(unsigned int num, unsigned int numCheck, unsigned int numCurrent);
};