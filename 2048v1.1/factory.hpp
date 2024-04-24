#pragma once
#include "upgradeSuper.hpp"


class Factory : Upgrade
{
public:
	static Factory* getInstance();
	int getPriceFromFormula(int count);

	bool purchase(Player* player);
	bool canPurchaseFactory(Player* player);


private:
	Factory();
	static Factory* factoryPtr;
};

