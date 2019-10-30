// Calc BMI.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
	unsigned int mass{ 0 };
	float height{ 0 };
	float BMI{ 0 };

	cout << "Input your mass (kg) and height (cm) to find your BMI\n";

	cout << "Mass: ";
	cin >> mass;

	cout << "Height: ";
	cin >> height;
	//convert cm to m
	height /= 100;
	//calc BMI
	BMI = mass / (height * height);

	cout << "Your BMI is " << BMI << " and you are ";
	if (BMI < 18.5)
		cout << "under weight";
	else if (BMI < 25)
		cout << "normal weight";
	else if (BMI < 30)
		cout << "over weight";
	else
		cout << "obese";

	cout << "\n" << endl;

	return 0;
}