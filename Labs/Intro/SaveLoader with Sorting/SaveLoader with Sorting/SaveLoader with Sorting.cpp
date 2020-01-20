// SaveLoader with Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::nothrow;
using std::ofstream;
using std::ifstream;

int* globalArray;

string save(string fileName, int toSave[], size_t size) {
	ofstream theFile;

	theFile.open(fileName);

	if (!theFile.is_open())
		return "Can't create file";

	theFile << size << "\n";

	for (size_t i = 0; i < size; i++)
		theFile << toSave[i] << "\n";

	theFile.close();
	return "Saved File";
}

string load(string fileName, size_t &size) {
	ifstream theFile;
	string cache;
	string currentLine;

	theFile.open(fileName);

	if (!theFile.is_open())
		return "Failed to load";

	getline(theFile, currentLine);
	size = atoi(currentLine.c_str());

	globalArray = new (nothrow) int[size];

	for (size_t i = 0; i < size; i++) {
		getline(theFile, currentLine);
		globalArray[i] = atoi(currentLine.c_str());
	}

	theFile.close();
	return "Loaded File";
}

void SortI(int inArray[], size_t size) {
	int* outArray;

	outArray = new (nothrow) int[size];

	int least{ 0 }, largest{ 0 };
	size_t pos{ 0 };

	for (size_t i = 0; i < size; i++) {
		outArray[i] = i;
		if (inArray[i] < least)
			least = inArray[i];
	}

	for (size_t y = 0; y < size; y++) {
		largest = least;

		for (size_t x = y; x < size; x++)
			if (inArray[x] > largest) {
				largest = inArray[x];
				pos = x;
			}

		outArray[y] = largest;
		inArray[pos] = inArray[y];
	}

	for (size_t i = 0; i < size; i++)
		inArray[i] = outArray[i];

	delete[] outArray;
}

void UsrInp() {
	string fileName;
	string input;

	cout << "Which file would like to load/save from: ";
	getline(cin, fileName);
	fileName += ".txt";

	cout << "Save or Load file: ";
	cin >> input;

	if (input == "load") {
		size_t size;
		cout << load(fileName, size) << "\n";

		SortI(globalArray, size);

		for (size_t i = 0; i < size; i++)
			cout << globalArray[i] << "\n";
	} else if (input == "save") {
		size_t size{ 0 };

		while (size == 0) {
			cout << "How many numbers do you want to save: ";
			cin >> input;

			if (atoi(input.c_str()) > 0)
				size = atoi(input.c_str());
		}

		globalArray = new (nothrow) int[size];
		
		for (size_t i = 0; i < size; i++) {
			cin >> input;
			globalArray[i] = atoi(input.c_str());
		}

		cout << save(fileName, globalArray, size);
	}

	cout << endl;

	delete[] globalArray;
}

int main()
{
	UsrInp();

	return 0;
}