#include "banking.h"

#include <iostream>

bankAccount::bankAccount() {
	accountsToAllow.push_back("savings");
	accountsToAllow.push_back("chequing");
	accountsToAllow.push_back("credit card");
}

string bankAccount::AddAccount(string name, double amount, double limit) {
	for (unsigned int i = 0; i < accountsToAllow.size(); i++)
		if (name == accountsToAllow[i]) {
			accountType acc{ name, amount, limit };
			accounts.push_back(acc);
			accountsToAllow.erase(accountsToAllow.begin() + i);
			return "Made " + name + " account";
		}

	return name + " account already exists";
}

string bankAccount::Transfer(string fromAccount, string toAccount, double amount) {
	int accs[2];
	accs[0] = FindAccount(fromAccount);
	accs[1] = FindAccount(toAccount);

	if (accs[0] < 0 && accs[1] < 0)
		return "can't find accounts";

	if (amount > accounts[accs[0]].limit)
		return fromAccount + " has a limit of $" + to_string(accounts[accs[0]].limit) + " and you tried to transfer $" + to_string(amount);

	if (amount > accounts[accs[0]].amount)
		return fromAccount + " only has $" + to_string(accounts[accs[0]].amount) + " in its account and you tried to transfer $" + to_string(amount);

	accounts[accs[0]].amount -= amount;
	accounts[accs[1]].amount += amount;
	return "transfered $" + to_string(amount) + " from " + fromAccount + " to " + toAccount;
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
