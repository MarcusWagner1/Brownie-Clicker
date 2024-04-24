#pragma once
#include "upgradeSuper.hpp"

class SecretFormula : Upgrade
{
public:
	static SecretFormula* getInstance();
	int getPriceFromFormula(int count);

	bool purchase(Player* player);

	bool canPurchaseSF(Player* player);
private:
	SecretFormula();
	static SecretFormula* secretFormulaPtr;
};

