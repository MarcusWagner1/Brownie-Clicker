#pragma once

#include "upgradeSuper.hpp"

class Chef : Upgrade
{
public:
	

	 int getPriceFromFormula(int count);
	 bool purchase(Player* player);
	 static Chef* getInstance();
	 bool canPurchaseChef(Player* player);
	 

private:
	Chef();
	static Chef* ChefSingleton;
	
};

