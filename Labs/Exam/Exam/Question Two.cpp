#include "Question Two.h"

void StartQ2() {
	ifstream theFile;
	theFile.open("words.txt");

	if (!theFile.is_open())
		return;

	theFile.eof();

	char vowels[]{ 'a', 'e', 'i', 'o', 'u'};
	string currentWord{ "" };
	int numOfVowels{ 0 };
	string longestWord{ "" };
	int lenOfWord{ 0 };

	while (getline(theFile, currentWord)) {
		numOfVowels = 0;
		for (char curChar : currentWord) {
			for (char curVow : vowels)
				if (tolower(curChar) == curVow) {
					numOfVowels++;
					
					break;
				}

			if (numOfVowels > 1)
				break;
		}

		if (numOfVowels != 1)
			continue;

		if (currentWord.length() <= lenOfWord)
			continue;

		longestWord = currentWord;
		lenOfWord = currentWord.length();
	}

	cout << "longest word with one vowel: ";
	cout << longestWord << "\n";

	theFile.close();
}
