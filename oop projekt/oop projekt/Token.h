#pragma once
#include "AbstractToken.h"
#include <string>
using namespace std;
class Token : public AbstractToken
{
protected:
	string name = "";
	double balance = 0;
	string contract;

public:
	virtual string mintToken(string name, double supply);
	virtual string mintToken(double supply);
	virtual double getBalance(); // pozdni vazba + rozsireni dat a metod v NFToken
	virtual bool isNFT();
	string generateContract();
	string getContract();
	string getName();
};
