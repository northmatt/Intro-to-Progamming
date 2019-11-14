// Basic printing tests

#include <iostream>
#include <Windows.h>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main()
{   
	cout << "This is a C++ Program\n\n";
	cout << "This is a C++\nProgram\n\n";
	cout << "This\nis\na\nC++\nProgram\n\n";
	cout << "This\tis\ta\tC++\tProgram\n\n\n";

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	string writeString = "This is a test";
	char* writeScreen = &writeString[0];

	struct color {
		int col;
		size_t start;
		size_t end;
	};
	vector<color> colors;
	colors.push_back(color{20, 0, 4});
	colors.push_back(color{20, 10, 14});

	if (colors.size() == 0)
		cout << writeScreen;
	else {
		size_t lastCall{ 0 };
		for (color currentCol : colors) {
			char* p_next_write1 = &writeScreen[lastCall];
			cout.write(p_next_write1, currentCol.start - lastCall);

			SetConsoleTextAttribute(hConsole, currentCol.col);

			char* p_next_write2 = &writeScreen[currentCol.start];
			cout.write(p_next_write2, currentCol.end - currentCol.start);

			SetConsoleTextAttribute(hConsole, 7);

			lastCall = currentCol.end;
		}

		char* p_next_write3 = &writeScreen[lastCall];
		cout << p_next_write3;
	}
	cout << "\n" << endl;

	string input;
	int sum{0};

	cout << "Give numbers and have them added. Enter e to exit\n";
	while (true)
	{
		cout << "\nNumber: ";
		cin >> input;

		if (input == "e")
			break;

		sum += atoi(input.c_str());
		cout << "resultant: " << sum << "\n";
	}

	cout << "Final resultant = " << sum << endl;

	return 0;
}