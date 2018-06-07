#include <string>
#include <queue>
#include <sstream>
#include "BSTree.h"
#pragma once

class JollyBanker
{
public:
	JollyBanker();
	~JollyBanker();
	//Processes the file given and prints transcations
	void processTranscations(std::string textFile);
	//Helper method which helps with transfering funds from
	bool transfer(int id1, int money, int id2, BSTree tree);

private:
	
};


