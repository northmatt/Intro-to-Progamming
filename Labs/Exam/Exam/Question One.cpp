#include "Question One.h"

void StartQ1() {
	ifstream theFile;
	theFile.open("words.txt");

	if (!theFile.is_open())
		return;

	string mainWord;
	string tempWord;
	int mainArray[26]{ 0 };
	int tempArray[26]{ 0 };

	cout << "Enter a word to find the words that can be made with the letters in the word:\n";
	cin >> mainWord;
	cout << "\n";

	SetupArray(mainWord, mainArray);

	while (getline(theFile, tempWord)) {
		SetupArray(tempWord, tempArray);
		if (TestArray(mainArray, tempArray))
			cout << tempWord << "\n";
	}

	theFile.close();
}

void SetupArray(string inpWord, int inpArray[]) {
	for (size_t i = 0; i < 26; i++)
		inpArray[i] = 0;

	for (char curChar : inpWord)
		inpArray[tolower(curChar) - 'a']++;
}

bool TestArray(int mainArray[], int testArray[]) {
	for (size_t i = 0; i < 26; i++)
		if (mainArray[i] < testArray[i])
			return false;

	return true;
}
