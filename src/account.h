#pragma once
#include <iostream>
#include <string>
using namespace std;
class Account
{
public:
	Account(std::string name, int id);
	~Account();
	//stores the id of the account
	int ID; 
	//Holds all transactions for the account
	std::string history;
	//This the clients name
	std::string name;
	// takes certain amount of money and adds it to a subaccount of the Account
	bool deposit(const int& money, const int &subAccount); 
	//withdraws money from the account fund, returns -1 if failed.
	bool withdraw(const int & money, const int& subAccount); 
	//Takes money from one subAccount and moves it to another, can be different accounts
	//Prints all transactions done in the account
	string printHistoryOfAll();
	
	//Prints specific subaccounts transactions
	string PrintHistoryOfID(int id);
	//these methods are for transferring money
	bool transferTo(int subID1, int money, int subID2);
	bool transferFrom(int subID1, int money, int subID2);
	//returns string with the subID's name 
	string getSubIDName(int id);
	//This method returns the final funds in each account
	string processFinal();
private:
	//holds the money for each subaccount
	int subaccounts[10];
	//holds all transcations done on the subaccount
	std::string subHistory[10];
	//this holds all the names of the subaccounts
	std::string subNames[10];
};

