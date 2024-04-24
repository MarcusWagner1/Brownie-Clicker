#include "Player.hpp"


Player::Player()
{
	mBrownies = 0;
	mChefs = 0;
	mFactories = 0;
	mOvens = 0;
	mSecretformulas = 0;
	mGoldenbrownies = 0;
	mHasTrophy = false;
}

void Player::incrementers()
{
	mBrownies += (1 * mChefs) + (3 * mOvens) + (17 * mFactories) + (39 * mSecretformulas) + (129 * mGoldenbrownies);
	std::cout << "Number of brownies = " << mBrownies << std::endl;
}





Player::~Player()
{
	//delete this;
}

void Player::setBrownies(int brownies)
{
	mBrownies = brownies;
}
int Player::getBrownies()
{
	return mBrownies;
}

void Player::setChefs(int chefs)
{
	mChefs = chefs;
}
int Player::getChefs()
{
	return mChefs;
}


void Player::setFactories(int factories)
{
	mFactories = factories;
}
int Player::getFactories()
{
	return mFactories;
}

void Player::setOvens(int ovens)
{
	mOvens = ovens;
}
int Player::getOvens()
{
	return mOvens;
}

void Player::setSecretFormulas(int secretFormulas)
{
	mSecretformulas = secretFormulas;
}
int Player::getSecretFormulas()
{
	return mSecretformulas;
}

void Player::setGoldenBrownies(int goldenBrownies)
{
	mGoldenbrownies = goldenBrownies;
}
int Player::getGoldenBrownies()
{
	return mGoldenbrownies;
}

bool Player::getTrophyBool()
{
	return mHasTrophy;
}
void Player::setTrophyBool(bool condition)
{
	mHasTrophy = condition;
}



