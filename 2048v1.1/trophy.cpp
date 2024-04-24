#include "trophy.hpp"



bool Trophy::canPurchaseTrophy(Player* player)
{
	return canPurchase(player->getBrownies());
}

Trophy::Trophy()
{
	mPrice = 2;
}

Trophy* Trophy::getInstance()
{
	if (trophyPtr == nullptr)
	{
		trophyPtr = new Trophy();
	}
	return trophyPtr;
}


bool Trophy::purchase(Player* player)
{
	if (canPurchase(player->getBrownies()))
	{
		player->setBrownies(player->getBrownies() - mPrice);
		player->setTrophyBool(true);
		return true;
	}
	return false;
}


Trophy* Trophy::trophyPtr = nullptr;
