#include <iostream>
#include "AbstractToken.h"
#include "User.h"
#include "Chain.h"
#include "Wallet.h"
#include "Token.h"
#include "NFToken.h"
#include "Bridge.h"

using namespace std;


int main() {
	string ethAliceTokens[20];
	string ethBobTokens[30];


	cout << "generating users alice and bob" << endl << endl;

	User* Alice = new User("ALICE", "testovaciheslo");
	cout << "wallet alice is: " << Alice->getWalletAddress() << endl;
	cout << "testing os change alices pass. (first shoud fail, second no): " << Alice->changePass("fes", "?")
		<< "\t" << Alice->changePass("testovaciheslo", "?") << endl;

	User* Bob = new User("BOB", "gfgghvno");
	cout << endl << "wallet bob is: " << Bob->getWalletAddress() << endl;



	cout <<endl<<endl<< "generating eth and metis chain under alice account..." << endl;
	Alice->addChain("eth");
	Alice->addChain("metis");
	cout << "printing all alices chains:" << endl;
	Alice->printAllChains();

	cout <<endl<<" ----------------------------------------- " << endl << "generating 20 tokens on alices eth chain: " << endl;
	Chain* AliceEthChain = Alice->getChain("eth");
	Chain* AliceMetisChain = Alice->getChain("metis");

	for (int i = 0; i < 20; i++)
	{
		ethAliceTokens[i] = AliceEthChain->generateToken( to_string(i), rand() % 10000);

	}
	cout<< endl << "printing alices coins on eth chain:" << endl;
	AliceEthChain->printAllTokens();



	cout << endl << "transfering last 10 coins t bob wallet: " << endl;
	for (int i = 10; i < 20; i++)
	{
		ethBobTokens[i-10] = AliceEthChain->Transfer(Bob, ethAliceTokens[i]);
	}

	cout << endl << "showing new balances of alices and bobs wallets :" <<endl;
	cout << "Alice: ";
	AliceEthChain->printAllTokens();
	cout <<endl<< "Bob: ";
	Bob->getChain("eth")->printAllTokens();

//////////////////////////////////  Example of doing it with nfts: ////////////////////
	cout << endl << " ------------------------------------------ " << endl << "minting two nfts in alice wallet" <<endl<< "NFT list:" << endl;
	string firstnft  = AliceEthChain->generateNFToken("jmeno", "kolekce");
	string secondnft = AliceEthChain->generateNFToken("jmeno2");
	AliceEthChain->printAllNFTs();
	cout <<endl<< "transfering first nft to Bob wallet"<<endl;

	AliceEthChain->TransferNFT(Bob, firstnft);
	cout << "Alices NFTs:" << endl;
	AliceEthChain->printAllNFTs();
	cout << "Bobs NFTs:" << endl;
	Bob->getChain("eth")->printAllNFTs();




///////////////////////////////// Example of bridging  //////////////////////
	cout <<endl<<endl<< " --------------------------------------- " <<endl<< "bridging alices first token and NFT from eth to metis chain" << endl;
	Bridge* mybridge = new Bridge();

	mybridge->bridgeToken(Alice, ethAliceTokens[0], "eth", "metis");
	mybridge->bridgeNFT(Alice, secondnft, "eth", "metis");

	AliceMetisChain->printAllNFTs();
	AliceEthChain->printAllNFTs();
	AliceMetisChain->printAllTokens();
	AliceEthChain->printAllTokens();
/////////////////////////// generating polymorf. struct. of all alice metis coins + nft //////////////////////////////////
	AliceMetisChain->generateAlltokens();

	delete mybridge;
	delete Alice;
	delete Bob;

}