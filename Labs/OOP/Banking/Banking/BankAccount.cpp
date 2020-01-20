#include "BankAccount.h"

Account::Account(string _firstName, string _lastName, signed __int64 _idNum, __int64 _balance) {
	SetFirstName(_firstName);
	SetLastName(_lastName);
	SetIDNum(_idNum);
	SetBalance(_balance);
}

void Account::SetFirstName(string name) {
	firstName = name;
}

void Account::SetLastName(string name) {
	lastName = name;
}

string Account::SetIDNum(signed __int64 num) {
	if (idNum = num)
		return "success";

	return "failed to set ID";
}

string Account::SetBalance(__int64 _balance) {
	if (_balance > 0) {
		balance = _balance;
		return "success";
	}

	return "Balance must be over 0";
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

__int64 Account::GetBalance() {
	return balance;
}
