// Basic printing tests

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::nothrow;
using std::vector;
using std::to_string;

HANDLE hConsole;
CONSOLE_SCREEN_BUFFER_INFO csbi;

struct color {
	int col;
	size_t start;
	size_t end;
};

DWORD size;                      //number of visible characters
COORD coord = { 0 };               //Top left screen position

char* writeScreen;

vector<color> colors;

void WriteBuffer(int x, int y, char* input, int col = -1) {
	size_t sizeInput = strlen(input);
	int currentX{ x }, currentY{ y };
	int colPos{ -1 };

	if (currentX >= csbi.dwSize.X || currentY >= csbi.dwSize.Y) {
		return;
	}

	for (size_t i = 0; i < sizeInput; i++) {
		if (col != -1 && colPos >= 0)
			colors[colors.size() - 1].end = static_cast<size_t>(currentX + (csbi.dwSize.X * currentY));

		if (input[i] == '\n') {
			currentX = x;
			currentY++;

			colPos = -1;
		} else {
			if (0 <= currentX && currentX < csbi.dwSize.X && 0 <= currentY && currentY < csbi.dwSize.Y) {
				writeScreen[currentX + (csbi.dwSize.X * currentY)] = input[i];

				if (col != -1 && colPos == -1) {
					colors.push_back(color{ col, static_cast<size_t>(currentX + (csbi.dwSize.X * currentY)), static_cast<size_t>(currentX + (csbi.dwSize.X * currentY)) });
					colPos = currentX;
				}
			} else
				colPos = -1;

			currentX++;
			}
	}

	if (col != -1 && colPos >= 0)
		colors[colors.size() - 1].end = static_cast<size_t>(currentX + (csbi.dwSize.X * currentY));
}

void initDisplay() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	//remove scrolling
	COORD new_size =
	{
		csbi.srWindow.Right - csbi.srWindow.Left + 1,
		csbi.srWindow.Bottom - csbi.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(hConsole, new_size);
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	//Find the number of characters to overwrite
	size = csbi.dwSize.X * csbi.dwSize.Y;

	writeScreen = new (nothrow) char[size] { ' ' };
}

void display() {
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

		if (lastCall < strlen(writeScreen)) {
			char* p_next_write3 = &writeScreen[lastCall];
			cout << p_next_write3;
		}

		colors = {};
	}

	for (size_t i = 0; i < size - 1; i++) {
		writeScreen[i] = ' ';
	}

	cout.flush();
	SetConsoleCursorPosition(hConsole, coord);
}

void writeString(string inStr, int x, int y, int col = -1) {
	char* outChar = &inStr[0];
	WriteBuffer(x, y, outChar, col);
}

int main()
{   
	/*initDisplay();
	display();

	writeString("BattleScene Update\nlop", 0, 0, 20);
	writeString("BattleScene Update\nlop", 5, 3, 10);

	display();

	string input;
	int sum{ 0 };

	cout.flush();
	SetConsoleCursorPosition(hConsole, COORD{ 0, 5 });*/

	int i = 23;
	cout << to_string(*i);

	/*cout << "This is a C++ Program\n\n";
	cout << "This is a C++\nProgram\n\n";
	cout << "This\nis\na\nC++\nProgram\n\n";
	cout << "This\tis\ta\tC++\tProgram\n\n\n";

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

	cout << "Final resultant = " << sum << endl;*/

	return 0;
}