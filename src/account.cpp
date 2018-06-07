#include "account.h"


//Initialize the 10 sub accounts in the array and sets the id and name
Account::Account(std::string name, int id)
{
	for (int i = 0; i < 10; i++) {
		subaccounts[i] = 0;
		subHistory[i] = "";
	}
	this->name = name;
	subNames[0] = "Money Market";
	subNames[1] = "Prime Money Market";
	subNames[2] = "Long-Term Bond";
	subNames[3] = "Short-Term Bond";
	subNames[4] = "500 Index Fund";
	subNames[5] = "Capital Value Fund";
	subNames[6] = "Growth Equity Fund";
	subNames[7] = "Growth Index Fund";
	subNames[8] = "Value Fund";
	subNames[9] = "Value Stock Index";
	ID = id;
	history += "Transaction History for " + name + " by fund."; 
}


//Does nothing since you don't initialize anything with new
Account::~Account() {
	
}
//deposits money to the subaccount 
bool Account::deposit(const int & money, const int & subAccount)
{
	subHistory[subAccount % 10] += "D " + to_string(subAccount) + ' ' + to_string(money) + '\n';
	return (subaccounts[subAccount%10]+=money);
}
//checks whether you can withdraw the money from the subaccount 
//given by the parameter and if so, does it. Else there are
//special scenarios, 0, 1 and 2,3 which look to see whether 
//you can transfer withdraw the rest of the money out from them
bool Account::withdraw(const int & money, const int & subAccount)
{
	subHistory[subAccount % 10] += "W "; 
	if (subaccounts[subAccount % 10] >= money) {
		(subaccounts[subAccount % 10] -= money);
		subHistory[subAccount %10] += to_string(subAccount) + ' ' + to_string(money);
		subHistory[subAccount % 10] += '\n';
		return true;
		                             
	}
	else if (subAccount % 10 == 0) {
		if (subaccounts[0] + subaccounts[1] >= money) {
			int transfered = money - subaccounts[0];
			subHistory[0] += to_string(subAccount) + " " + to_string(subaccounts[0]);
			subaccounts[0] = 0;
			subHistory[1] += "W " + to_string(subAccount + 1) + " " + to_string(transfered) + '\n';
			subaccounts[1] -= transfered;
			subHistory[subAccount % 10] += '\n';
			return true;
		}
		else {
			subHistory[subAccount % 10] += to_string(subAccount) + " " + to_string(money) + " ";
			subHistory[subAccount % 10].append(" (Failed)\n");
			return false;
		}
	}
	else if (subAccount % 10 == 1) {
		if (subaccounts[0] + subaccounts[1] >= money) {
			int transfered = money - subaccounts[1];
			subHistory[1] += to_string(subAccount) + " " + to_string(subaccounts[1]);
			subaccounts[1] = 0;
			subHistory[0] += "W " + to_string(subAccount - 1) + " " + to_string(transfered) + '\n';
			subaccounts[0] -= transfered;
			subHistory[subAccount % 10] += '\n';
			return true;;
		}
		else {
			subHistory[subAccount % 10] += to_string(subAccount) + " " + to_string(money) + " ";
			subHistory[subAccount % 10].append(" (Failed)\n");
			return false;
		}
	}
	else if (subAccount % 10 == 2) {
		
		if ((subaccounts[2] + subaccounts[3] >= money)) {
			int transfered = money - subaccounts[2];
			subHistory[2] += to_string(subAccount) + " " + to_string(subaccounts[2]);
			subaccounts[2] = 0;
			
			subHistory[3] += "W " + to_string(subAccount + 1) + " " + to_string(transfered) + '\n';
			subaccounts[3] -= transfered;
			subHistory[subAccount % 10] += '\n';
			return true;
		}
		else {
			subHistory[subAccount % 10] += to_string(subAccount) + " " + to_string(money) + " ";
			subHistory[subAccount % 10].append(" (Failed)\n");
			return false;
		}
	}
	else if (subAccount % 10 == 3) {
		if (subaccounts[2] + subaccounts[3] >= money) {
			int transfered = money - subaccounts[3];
			subHistory[3] += to_string(subAccount) +  " " + to_string(subaccounts[0]);
			subaccounts[3] = 0;
			subHistory[2] += "W " + to_string(subAccount - 1) + " " +to_string(transfered) + '\n';
			subaccounts[2] -= transfered;
			subHistory[subAccount % 10] += '\n';
			return true;
		}
		else {
			subHistory[subAccount % 10] += to_string(subAccount) + " " + to_string(money) + " ";
			subHistory[subAccount % 10].append(" (Failed)\n");
			return false;
		}
	}
	else {
		subHistory[subAccount % 10] += to_string(subAccount) + " " + to_string(money) + " ";
		subHistory[subAccount % 10].append(" (Failed)\n");
		return false;
	}
}


//prints the transcations of the subaccount given by the id
string Account::PrintHistoryOfID(int id)
{
	string print = "";
	print.append(history);
	print += ' ';
	print.append(subNames[id % 10]);
	print.append(": ");
	print.append(to_string(subaccounts[id % 10]));
	print += '\n';
	print.append(subHistory[id % 10]);
	print += '\n';
	return print;
}
//transfers money from a certain subacount to this account
bool Account::transferTo(int subID1, int money, int subID2)
{
	subHistory[subID2 % 10].append("T ");
	subHistory[subID2 % 10].append(to_string(subID1));
	subHistory[subID2 % 10] += ' '; 
	subHistory[subID2 % 10].append(to_string(money));
	subHistory[subID2 % 10] += ' ';
	subHistory[subID2 % 10].append(to_string(subID2));
	subHistory[subID2 % 10] += '\n';
	subaccounts[subID2 % 10] += money;
	return true;
}
//takes money from this subaccount and adds it to the other subaccount
bool Account::transferFrom(int subID1, int money, int subID2)
{
	subHistory[subID1 % 10].append("T ");
	subHistory[subID1 % 10].append(to_string(subID1));
	subHistory[subID1 % 10] += ' ';
	subHistory[subID1 % 10].append(to_string(money));
	subHistory[subID1 % 10] += ' ';
	subHistory[subID1 % 10].append(to_string(subID2));


	if (subaccounts[subID1 % 10] >= money) {
		subaccounts[subID1 % 10] -= money;
		subHistory[subID1%10] += '\n';
		return true;
	}
	else {
		
		subHistory[subID1 % 10].append(" (Failed)");
		subHistory[subID1 % 10] += '\n';

		return false;
	}
}
//returns that subaccount associated with the id 
string Account::getSubIDName(int id)
{
	return subNames[id % 10];
}
//prc
string Account::processFinal()
{
	string r = "";
	r += name + "Account ID: " + to_string(ID);
	r += '\n';

	for (int i = 0; i < 10; i++) {
		r += subNames[i] + ": $" + to_string(subaccounts[i]);
		r += '\n';
	}
	return r;
}

string Account::printHistoryOfAll()
{
	string s = "";
	s.append(history);
	s += '\n';
	for (int i = 0; i < 10; i++) {
		if (subHistory[i] != "") {
			s.append(subNames[i]);
			s.append(": ");
			s.append(to_string(subaccounts[i]));
			s += '\n';
			s.append(subHistory[i]);
			s += '\n';
		}
	}
	return s;
}