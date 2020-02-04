// Banking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "BankAccount.h"

int main() {
	Account acc1{ "Jim", "Nu", 001, 0 };
	Account acc2("Jin", "Nu", 002, -5);
	Account acc3("Jiw", "Nu", 003, 10);

	cout << "\n" << acc1.GetAccountInfo() << "\n";
	cout << acc2.GetAccountInfo() << "\n";
	cout << acc3.GetAccountInfo() << "\n";

	cout << acc1.Credit(10);
	cout << acc2.Credit(100) << "\n";

	cout << "Account " << acc1.GetIDNum() << " balance: " << acc1.GetBalance() << "\n";
	cout << "Account " << acc2.GetIDNum() << " balance: " << acc2.GetBalance() << "\n\n";

	cout << acc1.Debit(20);
	cout << acc2.Debit(20) << "\n";

	cout << acc1.GetAccountInfo() << "\n";
	cout << acc2.GetAccountInfo() << "\n";
	cout << acc3.GetAccountInfo() << "\n";
}