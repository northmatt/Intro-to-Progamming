#pragma once
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::to_string;

class Account {
public:
	Account(string firstName = "", string lastName = "", signed __int64 idNum = 0, double balance = 0);

	void SetFirstName(string name);
	void SetLastName(string name);
	string SetIDNum(signed __int64 idNum);
	string SetBalance(double balance);

	string GetFirstName();
	string GetLastName();
	signed __int64 GetIDNum();
	double GetBalance();
	string GetAccountInfo();

	string Credit(double _input);
	string Debit(double _input);
private:
	string firstName{ "" };
	string lastName{ "" };
	signed __int64 idNum{ 0 };
	double balance{ 0 };
};