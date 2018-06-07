#include "JollyBanker.h"
#include <iostream>

#include <fstream>
#include <queue>

#include "account.h"
using namespace std;
//DOes nothing
JollyBanker::JollyBanker()
{

}

//Does nothing
JollyBanker::~JollyBanker()
{
}
//Processes file and checks all transcations and creates accounts
// and then processes and prints out the historys o
//called upon by a transcation and afterwards, prints out the 
//final balances in each account initialized by the list of transcations.
void JollyBanker::processTranscations(std::string textFile)
{
	ifstream file(textFile);
	if (file.is_open()) {
	

		BSTree tree;
		queue<std::string> transcations;
		std::string single = "";
		while (getline(file, single)) {
			transcations.push(single);
		}
		while (transcations.empty() == false) {
			stringstream ss(transcations.front());
			transcations.pop();
			string action = "";
			getline(ss, action, ' ');
			if (action[0] == 'O') {
				string transcation = "";
				string fname = "";
				string lname = "";
				string id = "";
				int ID = 0;
				getline(ss, fname, ' ');
				fname.append(" ");
				getline(ss, lname, ' ');
				fname.append(lname);
				getline(ss, id, ' ');
				ID = stoi(id);
				Account *name = new Account(fname, ID);
				bool inserted = tree.insert(name);

				if (inserted == false) {
					cout << "ERROR: Account " << id << " is already open. Transcation refused." << endl;
					delete name;
				}
			}
			else if (action[0] == 'D') {
				Account * point;
				string id = "";
				getline(ss, id, ' ');
				string  fund = "";
				getline(ss, fund, ' ');
				int money = stoi(fund);
				int ID = stoi(id);
				
				tree.Retrieve((int) (ID*.1), point);
				if (point == nullptr) {
					cout << "No such Account Exists" << endl;
				}
				else {
					point->deposit(money, ID);
				}

			}
			else if (action[0] == 'W') {
				Account * point;
				string id = "";
				getline(ss, id, ' ');
				string  fund = "";
				getline(ss, fund, ' ');
				int money = stoi(fund);
				int ID = stoi(id);
				tree.Retrieve((int)(ID*.1), point);
				if (point == nullptr) {
					cout << "No such Account Exists" << endl;
				}
				else {
					bool withdrawn = point->withdraw(money, ID);
					if (withdrawn == false) {
						cout << "ERROR: Not enough funds to withdraw " << money << " from " << point->name << " "<< point->getSubIDName(ID) << endl;
					}
				}
			}
			else if (action[0] == 'H') {
				Account * point;
				string id = "";
				getline(ss, id, ' ');
				
				int ID = stoi(id);
				if (ID > 9999) {
					tree.Retrieve((int)( ID*.1), point);
					cout << point->PrintHistoryOfID(ID);
				}
				else {
					tree.Retrieve(ID, point);
					cout <<point->printHistoryOfAll();
				}
			}
			else if (action[0] == 'T') {

				string id = "";
				string mone = "";
				string idx = "";
				
				getline(ss, id, ' ');
				getline(ss, mone, ' ');
				getline(ss, idx, ' ');
				int id1 = stoi(id);
				int id2 = stoi(idx);
				int money = stoi(mone);
				Account * transferFrom;
				Account * transferTo;
				tree.Retrieve((int)(id1*.1), transferFrom);
				tree.Retrieve((int)(id2*.1), transferTo);
				if (transferFrom == nullptr) {
					cout << "Error: Account " << id1 << " not found. Transcation refused." << endl;
				}
				else if (transferTo == nullptr) {
					cout << "Error: Account " << id2 << " not found. Transcation refused." << endl;
				}
				else if (transferFrom->transferFrom(id1, money, id2) == true) {
					transferTo->transferTo(id1, money, id2);
				}
				
				
			}
			else {
			}
 			
		}
		cout << "Processing Done. Final Balances" << endl;
		cout << tree.display() << endl;


	}
	file.close();
}

bool JollyBanker::transfer(int id1, int money, int id2, BSTree tree)
{
	Account * transferFrom;
	Account * transferTo;
	tree.Retrieve((int) (id1*.1), transferFrom);
	tree.Retrieve((int) (id2*.1), transferTo);
	if (transferFrom == nullptr || transferTo == nullptr) {
		return false;
	}
	else if (transferFrom->transferFrom(id1, money, id2) == true) {
		return transferTo->transferTo(id1, money, id2);
	}
	else {
		return false;
	}
}

