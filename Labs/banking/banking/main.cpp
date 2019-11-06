#include <iostream>
#include "banking.h"

using std::cout;

int main() {
	bankAccount thing;

	thing.AddAccount("savings", 200, 100);

	cout << thing.GetInfo("savings");
}