#include "Chain.h"
#include "Wallet.h"
#include <iostream>
using namespace std;
Chain::~Chain()
{
	for (int i = 0; i < this->tokencount; i++)
	{
		delete this->tokens[i];
	}

	for (int i = 0; i < this->NFTcount; i++)
	{
		delete this->nfts[i];
	}


	delete tokens;
	delete nfts;

}

Chain::Chain(string name, string asocWallet)
{
	this->ownerWallet = asocWallet;
	this -> chainname = name;
	this->tokens = new Token * [50];
	this->nfts = new NFToken * [50];

}

Chain::Chain(string name, string asocWallet, int count)
{
	this->ownerWallet = asocWallet;
	this->chainname = name;
	this->tokens = new Token * [count];
	this->nfts = new NFToken * [count];

}

string Chain::generateToken(string name, double supply)
{
	Token* newtoken = new Token;
	newtoken->mintToken(name, supply);
	this->tokens[this->tokencount] = newtoken;
	this->tokencount++;
	return newtoken->getContract();
}

string Chain::generateToken(double supply)
{
	Token* newtoken = new Token;
	newtoken->mintToken(supply);
	this->tokens[this->tokencount] = newtoken;
	this->tokencount++;
	return newtoken->getContract();
}


string Chain::generateNFToken(string name, string collection)
{
	NFToken* newtoken = new NFToken;
	newtoken->mintToken(name, collection);
	this->nfts[this->NFTcount] = newtoken;
	this->NFTcount++;
	return newtoken->getContract();
}

string Chain::generateNFToken(string name)
{
	NFToken* newtoken = new NFToken;
	newtoken->mintToken(name);
	this->nfts[this->NFTcount] = newtoken;
	this->NFTcount++;
	return newtoken->getContract();
}


string Chain::getChainName()
{
	return this->chainname;
}


void Chain::addToken(Token* token)
{
	this->tokens[tokencount] = token;
	this->tokencount++;
}

void Chain::addNFT(NFToken* token)
{
	this->nfts[NFTcount] = token;
	this->NFTcount++;
}

string Chain::Transfer(Wallet* destWall, string CA)
{
	int tokenindex = this->findTokenIndexByContractAddress(CA);
	if (tokenindex == -1) 
	{ 
		cout << "You dont have this token, so you cant transfer it!" << endl;
		return "";
	}
	this->Transfer(destWall, tokenindex);
	return CA;
}

string Chain::Transfer(Wallet* destWall, int index)
{
	Token* transferedToken = tokens[index];
	for (int i = index; i < this->tokencount; i++)
	{
		this->tokens[i] = this->tokens[i + 1];
	}
	this->tokencount--;
	destWall->addChain(this->chainname);
	Chain* destChain = destWall->getChain(this->chainname);
	destChain->addToken(transferedToken);
	return transferedToken->getContract();
	
}

string Chain::TransferNFT(Wallet* destWall, string CA)
{
	int nftindex = this->findNFTIndexByContractAddress(CA);
	if (nftindex == -1)
	{
		cout << "You dont have this token, so you cant transfer it!" << endl;
		return "";
	}
	this->TransferNFT(destWall, nftindex);
	return CA;
}

string Chain::TransferNFT(Wallet* destWall, int index)
{
	NFToken* transferedToken = nfts[index];
	for (int i = index; i < this->NFTcount; i++)
	{
		this->nfts[i] = this->nfts[i + 1];
	}
	this->NFTcount--;
	destWall->addChain(this->chainname);
	Chain* destChain = destWall->getChain(this->chainname);
	destChain->addNFT(transferedToken);
	return transferedToken->getContract();

}

int Chain::findTokenIndexByContractAddress(string CA)
{
	
	for (int i = 0; i < this->tokencount; i++)
	{
		if (this->tokens[i]->getContract() == CA) { return i; }
	}

	return -1;
	
}

Token* Chain::findTokenByContractAddress(string CA)
{

	for (int i = 0; i < this->tokencount; i++)
	{
		if (this->tokens[i]->getContract() == CA) { return tokens[i]; }
	}

	return nullptr;

}

int Chain::findNFTIndexByContractAddress(string CA)
{

	for (int i = 0; i < this->NFTcount; i++)
	{
		if (this->nfts[i]->getContract() == CA) { return i; }
	}

	return -1;

}

NFToken* Chain::findNFTByContractAddress(string CA)
{

	for (int i = 0; i < this->NFTcount; i++)
	{
		if (this->nfts[i]->getContract() == CA) { return nfts[i]; }
	}

	return nullptr;

}


void Chain::printAllTokens()
{
	if (!this->tokencount)
	{
		cout << this->ownerWallet << " HAVE NO TOKENS on  chain " << this->chainname << " !!!" << endl;
		return;
	}
	cout << this->ownerWallet << " tokens on chain " << this->chainname << " are:" << endl;
	for (int i = 0; i < this->tokencount; i++)
	{
		Token* actualToken = this->tokens[i];
		cout << "Token contract: " << actualToken->getContract() << ", name: " <<
			actualToken->getName() << ", balance: " << actualToken->getBalance() << endl;
	}
	cout << endl;
}

void Chain::printAllNFTs()
{
	if (!this->NFTcount)
	{
		cout << this->ownerWallet << " HAVE NO NFTs on  chain " << this->chainname << " !!!" << endl;
		return;
	}
	cout << this->ownerWallet << " NFTs on chain " << this->chainname << " are:" << endl;
	for (int i = 0; i < this->NFTcount; i++)
	{
		NFToken* actualToken = this->nfts[i];
		cout << "Token contract: " << actualToken->getContract() << ", name: " <<
			actualToken->getName() << ", collection: " << actualToken->getCollecton() << ", balance: ";
		cout << actualToken->getBalance() << endl; // <-- different output of getbalance because od late binding
	}
	cout << endl;
}

void Chain::removeToken(string CA)
{
	int tokenindex = this->findTokenIndexByContractAddress(CA);
	if (tokenindex != -1)
	{
		for (int i = tokenindex; i < this->tokencount; i++)
		{
			this->tokens[i] = this->tokens[i + 1];
		}
		this->tokencount--;
		return;
	}

	tokenindex = this->findNFTIndexByContractAddress(CA);
	if (tokenindex != -1)
	{
		for (int i = tokenindex; i < this->tokencount; i++)
		{
			this->nfts[i] = this->nfts[i + 1];
		}
		this->NFTcount--;
		return;
	}



}

void Chain::generateAlltokens() {
	if (alltokens != nullptr) {
		delete[] alltokens;
	}

	int totalTokens = tokencount + NFTcount;

	alltokens = new AbstractToken * [totalTokens];

	for (int i = 0; i < tokencount; ++i) {
		alltokens[i] = tokens[i];
	}

	for (int i = 0; i < NFTcount; ++i) {
		alltokens[tokencount + i] = nfts[i];
	}
}