#pragma once
#include "upgradeSuper.hpp"

class Oven : Upgrade
{
public:
	static Oven* getInstance();
	int getPriceFromFormula(int count);

	bool purchase(Player* player);
	bool canPurchaseOven(Player* player);

private:
	Oven();
	static Oven* ovenPtr;
};

