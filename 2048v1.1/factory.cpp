#include "factory.hpp"

bool Factory::canPurchaseFactory(Player* player)
{
	return canPurchase(player->getBrownies());
}

Factory* Factory::getInstance()
{

	if (factoryPtr == nullptr)
	{
		factoryPtr = new Factory();
	}
	return factoryPtr;
}

bool Factory::purchase(Player* player)
{
	if (canPurchase(player->getBrownies()))
	{
		player->setBrownies(player->getBrownies() - mPrice);
		player->setFactories(player->getFactories() + 1);
		mPrice = getPriceFromFormula(player->getFactories());
		return true;
	}
	return false;
}

Factory::Factory()
{
	mPrice = 150;
}

int Factory::getPriceFromFormula(int count)
{
	int newPrice = 0;
	newPrice = 150 + (count * (1.6 * 1.6));
	setPrice(newPrice);
	return mPrice;
}

Factory* Factory::factoryPtr = nullptr;