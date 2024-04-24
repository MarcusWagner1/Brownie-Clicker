#include "goldenbrownies.hpp"

bool GoldenBrownie::canPurchaseGB(Player* player)
{
	return canPurchase(player->getBrownies());
}


GoldenBrownie* GoldenBrownie::getInstance()
{

	if (goldenBrowniePtr == nullptr)
	{
		goldenBrowniePtr = new GoldenBrownie();
	}
	return goldenBrowniePtr;
}

bool GoldenBrownie::purchase(Player* player)
{
	if (canPurchase(player->getBrownies()))
	{
		player->setBrownies(player->getBrownies() - mPrice);
		player->setGoldenBrownies(player->getGoldenBrownies() + 1);
		mPrice = getPriceFromFormula(player->getGoldenBrownies());
		return true;
	}
	return false;
}

GoldenBrownie::GoldenBrownie()
{
	mPrice = 300;
}

int GoldenBrownie::getPriceFromFormula(int count)
{
	int newPrice = 0;
	newPrice = 300 + (count * (2.0 * 2.0));
	setPrice(newPrice);
	return mPrice;
}

GoldenBrownie* GoldenBrownie::goldenBrowniePtr = nullptr;