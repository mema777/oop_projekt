#pragma once
#include "Token.h"
using namespace std;
class NFToken : public Token
{
private:
	string collectionName;

public:
	virtual bool isNFT();
	virtual double getBalance();
	virtual string mintToken(string name, string collectionName);
	virtual string mintToken(string name);
	string getCollecton();
};

