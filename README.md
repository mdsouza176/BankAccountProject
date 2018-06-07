# BankAccountProject
Takes in a text file with a certain format of transaction statements, processes them and outputs the results onto the command line



Transaction statement options:

O Cash Johnny 1001 //This opens an account with the following two word name and id number (if the id is not already taken by another account).

D 10010 542 //deposits the 542 into the subaccount 0 of the id 1001 if that id exists.

W 10011 500 //withdraws 500 from subaccount 1 of id 1001 if there is at least 500 in the account or if subaccount 0 has enough in it to make the difference.
//this works between 0 and 1 subaccounts and 2 and 3 subaccounts. Works one way or the other when withrawing money.
//fails if neither account has enough money (altogether) to pay it off.

H 1001 // prints each subaccounts transcations (if 1001 exists).

H 10010 //prints the 0 subaccounts transactions from the 1001 id number (if 1001 exists).

T 10017 54 10015 //transfers 54 funds between subaccount 7 and 5 of id 1001 (if the funds exist). 

T 10024 600 10012 //transfers 600 funds between subaccount 4 of id 1002 to subaccount 2 of id 1001.

