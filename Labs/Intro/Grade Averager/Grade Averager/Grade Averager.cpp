// Grade Averager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::fixed;
using std::setprecision;
using std::endl;

int main()
{
	int input{ 0 };
	int total{ -1 };
	double average{ 0 };

    cout << "Enter a grade or -1 to exit\n";

	while (input != -1) {
		average += input;
		total++;

		cout << "Grade: ";
		cin >> input;
	}

	average /= total;
	cout << fixed << setprecision(2);
	cout << "\nThe grade average is " << average << endl;

	return 0;
}