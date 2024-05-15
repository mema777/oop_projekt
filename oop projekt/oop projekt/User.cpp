#include "User.h"



User::User(string username, string pass):Wallet()
{
	this->name = username;
	this->password = pass;
}
User::User(string username, string pass, int chainInit) : Wallet(chainInit)
{
	this->name = username;
	this->password = pass;
}

string User::getName() 
{
return this->name;
}

string User::getPass()
{
	return this->password;
}

bool User::changePass(string currentPass, string newPass)
{
	if (currentPass != this->password)
		return 0;

	this->password = newPass;
	return 1;
}

