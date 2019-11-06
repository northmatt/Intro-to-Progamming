#include "banking.h"

#include <iostream>

bankAccount::bankAccount() {
	accountsToAllow.push_back("savings");
	accountsToAllow.push_back("chequing");
	accountsToAllow.push_back("credit card");
}

void bankAccount::AddAccount(string name, double amount, double limit) {
	for (unsigned int i = 0; i < accountsToAllow.size(); i++)
		if (name == accountsToAllow[i]) {
			accountType acc{ name, amount, limit };
			accounts.push_back(acc);
			accountsToAllow.erase(accountsToAllow.begin() + i);
			break;
		}
}

void bankAccount::Transfer(string fromAccount, string toAccount, double amount) {

}

string bankAccount::GetInfo(string name) {
	int accIndex = FindAccount(name);
	if (accIndex >= 0)
		return "Name: " + accounts[accIndex].name + ", Amount: " + to_string(accounts[accIndex].amount) + ", Max Transfer: " + to_string(accounts[accIndex].limit);

	return "No account found";
}

int bankAccount::FindAccount(string name) {
	for (unsigned int i = 0; i < accounts.size(); i++) {
		if (accounts[i].name == name)
			return i;
	}

	return -1;
}
