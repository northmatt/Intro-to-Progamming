// Basic printing tests

#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{   
	cout << "This is a C++ Program\n\n";
	cout << "This is a C++\nProgram\n\n";
	cout << "This\nis\na\nC++\nProgram\n\n";
	cout << "This\tis\ta\tC++\tProgram\n\n\n";


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