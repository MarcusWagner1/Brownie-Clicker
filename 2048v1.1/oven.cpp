#include "oven.hpp"

bool Oven::canPurchaseOven(Player* player)
{
	return canPurchase(player->getBrownies());
}

Oven* Oven::getInstance()
{

	if (ovenPtr == nullptr)
	{
		ovenPtr = new Oven();
	}
	return ovenPtr;
}

bool Oven::purchase(Player* player)
{
	if (canPurchase(player->getBrownies()))
	{
		player->setBrownies(player->getBrownies() - mPrice);
		player->setOvens(player->getOvens() + 1);
		mPrice = getPriceFromFormula(player->getOvens());
		return true;
	}
	return false;
}

Oven::Oven()
{
	mPrice = 100;
}

int Oven::getPriceFromFormula(int count)
{
	int newPrice = 0;
	newPrice = 100 + (count * (1.4 * 1.4));
	setPrice(newPrice);
	return mPrice;
}

Oven* Oven::ovenPtr = nullptr;