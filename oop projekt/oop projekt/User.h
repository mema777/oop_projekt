#pragma once
#include "Wallet.h"
#include <string>
using namespace std;

class User : public Wallet
{
private:
	string name;
	string password;

public:
	User(string n, string p);
	User(string n, string p, int chainInit);
	string getName();
	string getPass();
	bool changePass(string currentPass, string newPass);

};

