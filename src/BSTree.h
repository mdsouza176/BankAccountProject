#pragma once
#include "account.h"
class BSTree
{
public:
	BSTree();
	~BSTree();
	//Insets node into tree
	bool insert(Account *account);
	//checks whether tree has node, if does, returns true, plus makes
	//pointer equal to that nodes account
	bool Retrieve(const int& id, Account *& pointer);
	//displays the final balances of the tree
	string display();
	//Destrosy all nodes in the tree
	void empty(); 
	//checks if the tree is empty
	bool isEmpty() const;
private:

	struct Node
	{
		Account *pAcct;
		Node *right;
		Node *left;

	};
	//helper method which is used by the retrieve class to check
	//for a specific id
	Account* search(Node *cur, const int &id);
	//helper method which helps add the node to the tree
	bool add(Node *cur, Account* ac);
	Node *root;
	//helper method that helps with printing u
	void printInOrder(Node *node, string &r);

	void deleteInOrder(Node * node);
};

