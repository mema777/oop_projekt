#include "Wallet.h"
#include <iostream>
using namespace std;
Wallet::Wallet()
{
	////////////////////////////////	GENERATE WALL ADDR	
	string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string result;
	for (int i = 0; i < 40; i++) {
		result.push_back(charset[rand() % charset.length()]);
	}

	this->walletaddress = result;
	this->chains = new Chain * [10];
}

Wallet::Wallet(int chainInit)
{
	////////////////////////////////	GENERATE WALL ADDR	
	string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string result;
	for (int i = 0; i < 40; i++) {
		result.push_back(charset[rand() % charset.length()]);
	}

	this->walletaddress = result;
	this->chains = new Chain * [chainInit];
}

Wallet::~Wallet()
{
	for (int i = 0; i < this->cahincount; i++)
	{
		delete this->chains[i];
	}
	delete this->chains;
}

void Wallet::addChain(string name)
{
	for (int i = 0; i < this->cahincount; i++)
	{
		if (this->chains[i]->getChainName() == name) { return; }
	}
	Chain* newchain = new Chain(name, this->getWalletAddress());
	chains[cahincount] = newchain;
	cahincount++;
}

string Wallet::getWalletAddress()
{
	return this->walletaddress;
}

Chain* Wallet::getChain(string name)
{
	for (int i = 0; i < this->cahincount; i++)
	{
		if (this->chains[i]->getChainName() == name) { return chains[i]; }
	}

	return nullptr;
}

void Wallet::printAllChains()
{
	cout << this->walletaddress << " chains are:" << endl;
	for (int i = 0; i < this->cahincount; i++)
	{
		Chain* actualchain = this->chains[i];
		cout << "Chain name: " << actualchain->getChainName() << endl;
	}
	cout << endl;
}