// SaveLoader.cpp : This file saves ad loads TXT files
//

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

string save(string fileName, string toSave) {
	ofstream theFile;

	theFile.open(fileName);
	
	if (!theFile.is_open())
		return "Can't create file";

	theFile << toSave.c_str();

	theFile.close();
	return "Saved File";
}

string load(string fileName) {
	ifstream theFile;
	string cache;
	string currentLine;

	theFile.open(fileName);

	if (!theFile.is_open())
		return "Can't open file";

	while (getline(theFile, currentLine)) {
		cache += currentLine + "\n";
	}

	theFile.close();
	return cache;
}

int main()
{
	string fileName;
	string input;

	cout << "Which file would like to load/save from: ";
	getline(cin, fileName);
	fileName += ".txt";

	cout << "Save or Load file: ";
	getline(cin, input);

	if (input == "load") {
		cout << load(fileName);
	} else if (input == "save") {
		cout << "What to save: ";
		getline(cin, input);
		cout << save(fileName, input);
	}

    cout << endl;

	return 0;
}