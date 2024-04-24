#include "secretformula.hpp"

bool SecretFormula::canPurchaseSF(Player* player)
{
	return canPurchase(player->getBrownies());
}

SecretFormula* SecretFormula::getInstance()
{

	if (secretFormulaPtr == nullptr)
	{
		secretFormulaPtr = new SecretFormula();
	}
	return secretFormulaPtr;
}

bool SecretFormula::purchase(Player* player)
{
	if (canPurchase(player->getBrownies()))
	{
		player->setBrownies(player->getBrownies() - mPrice);
		player->setSecretFormulas(player->getSecretFormulas() + 1);
		mPrice = getPriceFromFormula(player->getSecretFormulas());
		return true;
	}
	return false;
}

SecretFormula::SecretFormula()
{
	mPrice = 200;
}

int SecretFormula::getPriceFromFormula(int count)
{
	int newPrice = 0;
	newPrice = 200 + (count * (1.8 * 1.8));
	setPrice(newPrice);
	return mPrice;
}

SecretFormula* SecretFormula::secretFormulaPtr = nullptr;
