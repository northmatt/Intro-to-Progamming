// Prime Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int> primeNums;

int checkNum(unsigned int num) {
	for (int currentPrimeNum : primeNums) {

	}

}

int main()
{
	unsigned int maxNum{ 0 };

	primeNums.push_back(2);
	primeNums.push_back(3);

    cout << "Number to check to: ";
	cin >> maxNum;

	int newNum[] = { -1, 1 };
	for (int currentNum = 6; currentNum <= maxNum; currentNum += 6)
		for (int offset : newNum)
			cout << checkNum(currentNum + offset) << "\n";


	return 0;
}
