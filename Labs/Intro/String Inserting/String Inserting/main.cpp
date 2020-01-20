#include <iostream>
#include "String Inserting.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	string thatStr1{ "" };
	string thatStr2{ "" };
	size_t pos{ 0 };

	cout << "String 1: ";
	cin >> thatStr1;
	cout << "String 2: ";
	cin >> thatStr2;
	cout << "Pos to Insert: ";
	cin >> pos;
	cout << InsStr(thatStr1, thatStr2, pos) << endl;
}