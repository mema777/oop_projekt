#pragma once
#include "Token.h"
#include "NFToken.h"
#include "AbstractToken.h"
class Wallet; //forward declaration
#include <string>

using namespace std;
class Chain
{
private:
	string chainname;
	Token** tokens;
	NFToken** nfts;
	AbstractToken** alltokens; // polymorf. struct. - ( nfts + normal tokens )
	int tokencount = 0;
	int NFTcount = 0;
	string ownerWallet = "";

public:
	Chain(string name, string asocWallet);
	Chain(string name, string asocWallet, int i);
	~Chain();
	void generateAlltokens();
	string generateToken(string name, double supply);
	string generateToken(double supply);
	string generateNFToken(string name, string collection);
	string generateNFToken(string name);
	string getChainName();
	void addToken(Token* token);
	void addNFT(NFToken* token);
	int findTokenIndexByContractAddress(string CA); //CA = contractaddress
	Token* findTokenByContractAddress(string CA);
	NFToken* findNFTByContractAddress(string CA);
	int findNFTIndexByContractAddress(string CA);
	void removeToken(string CA);
	string Transfer(Wallet* destWall, int index);
	string Transfer(Wallet* destWall,string CA);
	string TransferNFT(Wallet* destWall, int index);
	string TransferNFT(Wallet* destWall, string CA);
	void printAllTokens();
	void printAllNFTs();

};

