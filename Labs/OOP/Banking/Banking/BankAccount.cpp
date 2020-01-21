#include "BankAccount.h"

Account::Account(string _firstName, string _lastName, signed __int64 _idNum, double _balance) {
	SetFirstName(_firstName);
	SetLastName(_lastName);
	SetIDNum(_idNum);
	cout << SetBalance(_balance);
}

void Account::SetFirstName(string name) {
	firstName = name;
}

void Account::SetLastName(string name) {
	lastName = name;
}

string Account::SetIDNum(signed __int64 num) {
	if (idNum = num)
		return "success\n";

	return "failed to set ID\n";
}

string Account::SetBalance(double _balance) {
	if (_balance >= 0) {
		balance = _balance;
		return "success\n";
	}

	return "Balance must be over or equal to 0\n";
}

string Account::GetFirstName() {
	return firstName;
}

string Account::GetLastName() {
	return lastName;
}

signed __int64 Account::GetIDNum() {
	return idNum;
}

double Account::GetBalance() {
	return balance;
}

string Account::GetAccountInfo() {
	string cache{ "" };

	cache += "Name: " + firstName + " " + lastName + "\n";
	cache += "ID Number: " + to_string(idNum) + "\n";
	cache += "Balance: " + to_string(balance) + "\n";

	return cache;
}

string Account::Credit(double _input) {
	balance += _input;

	return "Added " + to_string(balance) + " to the account " + to_string(idNum) + "\n";
}

string Account::Debit(double _input) {
	if (_input <= balance) {
		balance -= _input;
		return "Paid " + to_string(_input) + " from the account " + to_string(idNum) + "\n";
	}

	return "Debit exeeded account balance from the account " + to_string(idNum) + "\n";
}
