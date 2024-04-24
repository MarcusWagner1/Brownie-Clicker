#pragma once
#include "upgradeSuper.hpp"

class GoldenBrownie : Upgrade
{
public:
	static GoldenBrownie* getInstance();
	int getPriceFromFormula(int count);

	bool purchase(Player* player);
	bool canPurchaseGB(Player* player);

private:
	GoldenBrownie();
	static GoldenBrownie* goldenBrowniePtr;
};

