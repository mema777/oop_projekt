#include "Bridge.h"

bool Bridge::bridgeToken(Wallet* wallet, string tokenCA, string sourceChain, string destChain)
{
	wallet->addChain(destChain);
	Chain* dest =wallet->getChain(destChain);
	Chain* src = wallet->getChain(sourceChain);

	Token* token = src->findTokenByContractAddress(tokenCA);
	if (!token)
	{
		return 0;
	}
	src->removeToken(tokenCA);

	dest->addToken(token);
	return 1;
}


bool Bridge::bridgeNFT(Wallet* wallet, string tokenCA, string sourceChain, string destChain)
{
	wallet->addChain(destChain);
	Chain* dest = wallet->getChain(destChain);
	Chain* src = wallet->getChain(sourceChain);

	NFToken* token = src->findNFTByContractAddress(tokenCA);
	if (!token)
	{
		return 0;
	}
	src->removeToken(tokenCA);

	dest->addNFT(token);
	return 1;
}