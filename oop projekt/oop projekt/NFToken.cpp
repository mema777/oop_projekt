#include "NFToken.h"
#include "iostream"
using namespace std;



bool NFToken::isNFT()
{
	return 1;
}

double NFToken::getBalance()
{
	cout << "this is NFT! Token is unique! Balance is 1 everytime! ";
	return 1;
}

string NFToken::mintToken(string name, string collection)
{
	this->balance = 1;
	this->contract = this->generateContract();
	this->name = name;
	this->collectionName = collection;
	return this->contract;
}

string NFToken::mintToken(string name)
{
	this->balance = 1;
	this->contract = this->generateContract();
	this->name = name;
	this->collectionName = "collectionNameNotSet";
	return this->contract;

}

string NFToken::getCollecton()
{
	return this->collectionName;
}