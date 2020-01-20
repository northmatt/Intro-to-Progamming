#include <iostream>
#include "banking.h"

using std::cout;
using std::endl;

int main() {
	bankAccount thing;

	cout << thing.AddAccount("savings", 60, 50) << endl;
	cout << thing.AddAccount("savings", 2000, 100) << endl;
	cout << thing.AddAccount("chequing", 0, 1000) << "\n" << endl;

	cout << thing.GetInfo("savings") << endl;
	cout << thing.GetInfo("chequing") << endl;

	cout << "\n" << thing.Transfer("savings", "chequing", 500) << endl;
	cout << thing.Transfer("savings", "chequing", 50) << endl;
	cout << thing.Transfer("savings", "chequing", 50) << "\n" << endl;

	cout << thing.GetInfo("savings") << endl;
	cout << thing.GetInfo("chequing") << endl;
}