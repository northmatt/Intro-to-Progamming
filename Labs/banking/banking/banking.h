#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;
using std::to_string;

class bankAccount {
public:
	bankAccount();

	struct accountType {
		string name;
		double amount;
		double limit;
	};

	void AddAccount(string name, double amount, double limit);
	void Transfer(string fromAccount, string toAccount, double amount);
	string GetInfo(string name);
	int FindAccount(string name);
private:
	vector<string> accountsToAllow;
	vector<accountType> accounts;
};