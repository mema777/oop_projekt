#pragma once
#include "Wallet.h"
#include "Chain.h"
class Bridge
{
public:
	bool bridgeToken(Wallet* wallet, string tokenCA, string sourceChain, string destChain);
	bool bridgeNFT(Wallet* wallet, string tokenCA, string sourceChain, string destChain);
};

