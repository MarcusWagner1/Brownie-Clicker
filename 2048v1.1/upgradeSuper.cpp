#include "upgradeSuper.hpp"

bool Upgrade::canPurchase(int amount)
{
	if (amount >= mPrice)
	{
		return true;
	}
	return false;
}



void Upgrade::setPrice(int price)
{
	mPrice = price;
}

int Upgrade::getPrice()
{
	return mPrice;
}