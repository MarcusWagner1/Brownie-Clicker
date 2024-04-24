#pragma once
#include "upgradeSuper.hpp"

class Trophy : Upgrade
{
public:
	static Trophy* getInstance();
	bool purchase(Player* player);
	bool canPurchaseTrophy(Player* player);
private:
	Trophy();
	static Trophy* trophyPtr;
};



