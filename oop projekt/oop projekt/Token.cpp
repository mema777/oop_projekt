#include "Token.h"

string Token::generateContract() {
	string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string result;
	for (int i = 0; i < 20; i++) {
		result.push_back(charset[rand() % charset.length()]);
	}
	return result;
}


string Token::mintToken(string name, double supply)
{
	this->balance = supply;
	this->contract = this->generateContract();
	this->name = name;
	return this->contract;
}

string Token::mintToken(double supply)
{
	this->balance = supply;
	this->contract = this->generateContract();
	return this->contract;
}

string Token::getContract()
{
	return this->contract;
}

string Token::getName()
{
	return this->name;
}

double Token::getBalance()
{
	return this->balance;
}

bool Token::isNFT()
{
	return 0;
}
