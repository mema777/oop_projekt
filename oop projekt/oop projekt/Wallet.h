#pragma once
#include "Chain.h"  //<<<-- giving circular dependency, needs to use forward declaration
class Wallet
{
private:
	string walletaddress;
	Chain** chains;
	int cahincount = 0;

public:
	Wallet();
	Wallet(int chainInit);
	~Wallet();
	void addChain(string name);
	string getWalletAddress();
	Chain* getChain(string name);
	void printAllChains();
};

