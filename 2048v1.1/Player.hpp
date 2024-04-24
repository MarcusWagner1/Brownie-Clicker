#pragma once
#include <iostream>

class Player
{
public:
	Player();
	~Player();

	void setBrownies(int brownies);
	int getBrownies();
	
	void setChefs(int chefs);
	int getChefs();
	
	void setFactories(int factories);
	int getFactories();

	void setOvens(int ovens);
	int getOvens();

	void setSecretFormulas(int secretFormulas);
	int getSecretFormulas();

	void setGoldenBrownies(int goldenBrownies);
	int getGoldenBrownies();

	bool getTrophyBool();
	void setTrophyBool(bool condition);

	void incrementers();

private:
	int mBrownies;
	int mChefs;
	int mFactories;
	int mOvens;
	int mSecretformulas;
	int mGoldenbrownies;
	bool mHasTrophy;

};

