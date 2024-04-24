//#include "upgradeSuper.hpp"
//
//template <typename T> class upgrades : Upgrade
//{
//public:
//	static T* getInstance();
//	int getPriceFromFormula(int count);
//
//	bool purchase(Player* player);
//
//
//private:
//	SecretFormula();
//	static SecretFormula* singleton;
//};
//
//
//template <typename T> T* upgrades<T>::getInstance()
//{
//
//	if (secretFormulaPtr == nullptr)
//	{
//		secretFormulaPtr = new SecretFormula();
//	}
//	return secretFormulaPtr;
//}
//
//template <typename T> bool upgrades<T>::purchase(Player* player)
//{
//	if (canPurchase(player))
//	{
//		player->setBrownies(player->getBrownies() - mPrice);
//		player->setSecretFormulas(player->getSecretFormulas() + 1);
//		mPrice = getPriceFromFormula(player->getSecretFormulas());
//		return true;
//	}
//	return false;
//}
//
//SecretFormula::SecretFormula()
//{
//	mPrice = 200;
//}
//
//int SecretFormula::getPriceFromFormula(int count)
//{
//	int newPrice = 0;
//	newPrice = 200 + (count * (1.8 * 1.8));
//	setPrice(newPrice);
//	return mPrice;
//}