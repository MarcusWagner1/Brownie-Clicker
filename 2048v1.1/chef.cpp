#include "chef.hpp"
//#include "Player.hpp"

//#include "factory.hpp"
//#include "oven.hpp"
//#include "secretformula.hpp"
//#include "goldenbrownies.hpp"
//#include "trophy.hpp"

Chef::Chef()
{
	mPrice = 50;
}

Chef* Chef::getInstance()
{
	if (ChefSingleton == nullptr)
	{
		ChefSingleton = new Chef();
		return ChefSingleton;
	}
	return ChefSingleton;
}

bool Chef::canPurchaseChef(Player* player)
{
	return canPurchase(player->getBrownies());
}





bool Chef::purchase(Player* player)
{
	if (canPurchase(player->getBrownies()))
	{
		player->setBrownies(player->getBrownies() - mPrice);
		player->setChefs(player->getChefs() + 1);
		mPrice = getPriceFromFormula(player->getChefs());
		return true;
	}
	return false;
}

//Chef::Chef()
//{
//	ChefSingleton = nullptr;
//	//mPrice = 50;
//}

int Chef::getPriceFromFormula(int count)
{
	int newPrice = 0;
	newPrice = 50 + (count * (1.2 * 1.2));
	setPrice(newPrice);
	return mPrice;
}

Chef* Chef::ChefSingleton = nullptr;
