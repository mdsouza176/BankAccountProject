#include "BSTree.h"
#include <iostream>

using namespace std;
//Contructor, just sets root to nullptr
BSTree::BSTree()
{
	root = nullptr;
	
}

//Destroys all nodes in the binary search tree
BSTree::~BSTree()
{
	deleteInOrder(root);
	root = nullptr;
}




//Works with the private search method that finds the right 
//account and then sets that account to the parameter and returns
//whether if found it or not in the tree.
bool BSTree::Retrieve(const int & id, Account *& pointer)
{

	Node * cur = root;
	pointer = search(cur, id);
	if (pointer == nullptr) {
		return false;
	}
	else {
		return true;
	}
}
//method that returns the processes the balances by calling the private
//printInOrder method.
string BSTree::display()
{
	Node * cur = root;
	string st = "";
	 printInOrder(cur, st);
	 return st;
}
//Does the same thing as the destructor, meaning deletes the nodes
//in the tree.
void BSTree::empty()
{
	deleteInOrder(root);
}

//Just checks if the tree is empty meaning root is nullptr or not
bool BSTree::isEmpty() const
{
	if (root !=nullptr) {
		return false;
	}
	else {
		return true;
	}
}
//Private method that looks through tree and finds the right account
Account* BSTree::search(Node * cur, const int & id)
{
	if (cur == nullptr) {
		return nullptr;
	}
	if (cur->pAcct->ID < id) {
		return search(cur->right, id);
	}
	else if (cur->pAcct->ID > id) {
		return search(cur->left, id);
	}
	else {
		return cur->pAcct;
	}
}
//method that uses a private method to add account to the binary tree,
bool BSTree::insert(Account * account)
{
	if (root == nullptr) {
		root = new Node();
	
		root->pAcct = account;
		return true;
	}
	else {
		Node *cur = root;
		return add(cur, account);
	}
}
//private recursive method that adds the node to the tree by checking where it is nullptr
//If account already exists, returns failed.
bool BSTree::add(Node * cur, Account * ac)
{
	if (cur->pAcct->ID == ac->ID) {
		
		return false;
	}
	else if (cur->pAcct->ID < ac->ID) {
		if (cur->right != nullptr) {
			return add(cur->right, ac);
		}
		else {
			cur->right = new Node();
		
			cur->right->pAcct = ac;
			return true;
		}
	} 
	else {
		if (cur->left != nullptr) {
			return add(cur->left, ac);
		}
		else {
			cur->left = new Node();
		
			cur->left->pAcct = ac;
			return true;
		}
	}

}
//Prints the processing final section of the bank account by going through each account and
//calling the process final method which returns a string of that accounts balances
//returns cumulative string.
void BSTree::printInOrder(Node * node, string &r)
{
	if (node == nullptr) {
		return;
	}
	printInOrder(node->left, r);
	r += node->pAcct->processFinal();
	r += '\n'; 
	printInOrder(node->right, r);
}


//private helper method that deletes all the nodes in the tree.
void BSTree::deleteInOrder(Node * node)
{
	if (node == nullptr) {
		return;
	}
	deleteInOrder(node->left);
	deleteInOrder(node->right);
	delete node->pAcct;
	
	delete node;
}




