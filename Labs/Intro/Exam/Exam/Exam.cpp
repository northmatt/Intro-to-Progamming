#include <iostream>
#include "Question One.h"
#include "Question Two.h"
#include "Question Three.h"

using std::cin;
using std::cout;
using std::string;

int main() {
	int inp{ 0 };
	string inpStr;

	cout << "Which question to run: ";
	cin >> inpStr;

	inp = atoi(inpStr.c_str());

	cout << "\n\n";

	switch (inp) {
	case 1:
		StartQ1();
		break;
	case 2:
		StartQ2();
		break;
	case 3:
		StartQ3();
		break;
	default:
		break;
	}
}