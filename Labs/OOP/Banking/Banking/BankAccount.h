#pragma once
#include <string>

using std::string;

class Account {
	Account(string firstName = "", string lastName = "", signed __int64 idNum = 0, __int64 balance = 0);

public:
	void SetFirstName(string name);
	void SetLastName(string name);
	string SetIDNum(signed __int64 idNum);
	string SetBalance(__int64 balance);

	string GetFirstName();
	string GetLastName();
	signed __int64 GetIDNum();
	__int64 GetBalance();
private:
	string firstName{ "" };
	string lastName{ "" };
	signed __int64 idNum{ 0 };
	__int64 balance{ 0 };
};