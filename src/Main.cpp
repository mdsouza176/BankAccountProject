#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>
#include "account.h"
#include "BSTree.h"
#include "JollyBanker.h"
using namespace std;
//Takes commandline input from user and they calls jollyBanker
int main(int argc, char **argv) {
	if (argc > 1) {
		JollyBanker jolly;
		jolly.processTranscations(argv[1]);
	} 
	
	
	

	cin.get();
	return 0;
}