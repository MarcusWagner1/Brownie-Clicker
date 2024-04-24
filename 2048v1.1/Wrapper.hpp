#pragma once

#include <unordered_map>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spriteHandler.hpp"
//#include "Player.hpp"
#include "chef.hpp"
#include "oven.hpp"
#include "factory.hpp"
#include "secretformula.hpp"
#include "goldenbrownies.hpp"
#include "trophy.hpp"
#include "template.hpp"

using namespace std;
using namespace sf;

typedef struct canbuy
{
	Sprite* chef;
	Sprite* oven;
	Sprite* factory;
	Sprite* secretFormula;
	Sprite* goldenBrownie;
	Sprite* trophy;
}CanbuySprites;

typedef struct cantbuy
{
	Sprite* chef;
	Sprite* oven;
	Sprite* factory;
	Sprite* secretFormula;
	Sprite* goldenBrownie;
	Sprite* trophy;
}CantbuySprites;



class Wrapper
{
public:
	Wrapper();
	int serverConnect();
	int runApp();
	//void displayMenu();
	//void displayRules();
	//int displayScores();
	//int play2048(GameBoard& gameBoard);
	int playBrownieClicker(Player& player);
	
private:
	Player* player;
	RenderWindow* windowPtr;
	Sprite* background;
	Sprite* chef;
	Sprite* brownie;
	Sprite* goldenbrownie;
	Sprite* oven;
	Sprite* factory;
	Sprite* shopMenu;
	Sprite* canBuy;
	Sprite* noBuy;
	CanbuySprites canbuySprites;
	CantbuySprites cantbuySprites;
	Sprite* trophy;
	Sprite* secretFormula;
	Sprite* closeButton;
	Sprite* shopButton;
	Sprite* moneyCount;
	Sprite* winDraw2;
	Sprite* winDraw1;
	sf::Text* moneyText;
	sf::Font* moneyFont;
	int lastTimeSlot;
	Chef* chefPtr;
	Oven* ovenPtr;
	Factory* factoryPtr;
	SecretFormula* secretFormulaPtr;
	GoldenBrownie* goldenBrowniePtr;
	Trophy* trophyPtr;


	//Chef gives 1 brownie per second, you can buy up to 50 chefs, 
	// Money += 1 * chefcount
	//price for chef = 50 + (chefcount * 1.2^1.2)

	// Ovens increment function
	// Money += 2 * ovenscount


};


Wrapper::Wrapper()
{
	player = new Player;
	moneyText = new sf::Text;
	moneyFont = new sf::Font;
	if(!moneyFont->loadFromFile("LDFComicSans.ttf"))
	{
		cout << " Cant load font" << endl;
	}
	moneyText->setFont(*moneyFont);
	moneyText->setString(to_string(player->getBrownies()));
	moneyText->setPosition(50, 50);


	Texture* backgroundT = new Texture;
	Texture* chefT = new Texture;
	Texture* brownieT = new Texture;
	Texture* goldenbrownieT = new Texture;
	Texture* ovenT = new Texture;
	Texture* factoryT = new Texture;
	Texture* shopMenuT = new Texture;
	Texture* canBuyT = new Texture;
	Texture* noBuyT = new Texture;
	Texture* trophyT = new Texture;
	Texture* secretFormulaT = new Texture;
	Texture* closeButtonT = new Texture;
	Texture* shopButtonT = new Texture;
	Texture* moneyCountT = new Texture;
	Texture* winDraw2T = new Texture;
	Texture* winDraw1T = new Texture;
	backgroundT->loadFromFile("Gamebackground.png");
	chefT->loadFromFile("chef.png");
	brownieT->loadFromFile("brownieSmall.png");
	goldenbrownieT->loadFromFile("goldenbrownie.png");
	ovenT->loadFromFile("Oven.png");
	factoryT->loadFromFile("Factory.png");
	shopMenuT->loadFromFile("Shop Menu.png");
	canBuyT->loadFromFile("canBuy.png");
	noBuyT->loadFromFile("cantBuy.png");
	trophyT->loadFromFile("Trophy.png");
	secretFormulaT->loadFromFile("secretformula.png");
	closeButtonT->loadFromFile("CloseButton.png");
	shopButtonT->loadFromFile("ShopButton.png");
	moneyCountT->loadFromFile("moneyCount.png");
	winDraw2T->loadFromFile("win2.jpeg");
	winDraw1T->loadFromFile("YOUWIN.png");


	background = new Sprite;
	chef = new Sprite;
	brownie = new Sprite;
	goldenbrownie = new Sprite;
	oven = new Sprite;
	shopMenu = new Sprite;
	winDraw2 = new Sprite;
	winDraw1 = new Sprite;

	canbuySprites.chef = new Sprite;
	canbuySprites.oven = new Sprite;
	canbuySprites.factory = new Sprite;
	canbuySprites.secretFormula = new Sprite;
	canbuySprites.goldenBrownie = new Sprite;
	canbuySprites.trophy = new Sprite;
	cantbuySprites.chef = new Sprite;
	cantbuySprites.oven = new Sprite;
	cantbuySprites.factory = new Sprite;
	cantbuySprites.secretFormula = new Sprite;
	cantbuySprites.goldenBrownie = new Sprite;
	cantbuySprites.trophy = new Sprite;

	
	canbuySprites.chef->setTexture(*canBuyT);
	canbuySprites.oven->setTexture(*canBuyT);
	canbuySprites.factory->setTexture(*canBuyT);
	canbuySprites.secretFormula->setTexture(*canBuyT);
	canbuySprites.goldenBrownie->setTexture(*canBuyT);
	canbuySprites.trophy->setTexture(*canBuyT);
	canbuySprites.chef->setScale(0.5,0.5);
	canbuySprites.oven->setScale(0.5, 0.5);
	canbuySprites.factory->setScale(0.5, 0.5);
	canbuySprites.secretFormula->setScale(0.5, 0.5);
	canbuySprites.goldenBrownie->setScale(0.5, 0.5);
	canbuySprites.trophy->setScale(0.5, 0.5);



	cantbuySprites.chef->setTexture(*noBuyT);
	cantbuySprites.oven->setTexture(*noBuyT);
	cantbuySprites.factory->setTexture(*noBuyT);
	cantbuySprites.secretFormula->setTexture(*noBuyT);
	cantbuySprites.goldenBrownie->setTexture(*noBuyT);
	cantbuySprites.trophy->setTexture(*noBuyT);
	cantbuySprites.chef->setScale(0.5, 0.5);
	cantbuySprites.oven->setScale(0.5, 0.5);
	cantbuySprites.factory->setScale(0.5, 0.5);
	cantbuySprites.secretFormula->setScale(0.5, 0.5);
	cantbuySprites.goldenBrownie->setScale(0.5, 0.5);
	cantbuySprites.trophy->setScale(0.5, 0.5);


	winDraw2->setTexture(*winDraw2T);
	winDraw2->setScale(0.5, 0.5);
	winDraw1->setTexture(*winDraw1T);

	canBuy = new Sprite;
	noBuy = new Sprite;
	trophy = new Sprite;
	secretFormula = new Sprite;
	closeButton = new Sprite;
	shopButton = new Sprite;
	moneyCount = new Sprite;

	background->setTexture(*backgroundT);
	background->scale(0.5, 0.5);
	background->setPosition(1, 1);
	chef->setTexture(*chefT);
	chef->scale(1, 1);
	chef->setPosition(1, 1);
	brownie->setTexture(*brownieT);
	brownie->scale(0.5, 0.5);
	//brownie->setOrigin(0.5, 0.5);
	brownie->setPosition(750/2, 500/2);

	goldenbrownie->setTexture(*goldenbrownieT);
	goldenbrownie->scale(1, 1);
	goldenbrownie->setPosition(1, 1);
	oven->setTexture(*ovenT);
	oven->scale(1, 1);
	oven->setPosition(1, 1);
	shopMenu->setTexture(*shopMenuT);
	shopMenu->scale(0.5, 0.5);
	shopMenu->setPosition(250, 50);
	canBuy->setTexture(*canBuyT);
	canBuy->scale(1, 1);
	canBuy->setPosition(1, 1);
	noBuy->setTexture(*noBuyT);
	noBuy->scale(1, 1);
	noBuy->setPosition(1, 1);
	trophy->setTexture(*trophyT);
	trophy->scale(1, 1);
	trophy->setPosition(1, 1);
	secretFormula->setTexture(*secretFormulaT);
	secretFormula->scale(1, 1);
	secretFormula->setPosition(1, 1);
	closeButton->setTexture(*closeButtonT);
	closeButton->scale(0.5, 0.5);
	closeButton->setPosition(200, 100);
	shopButton->setTexture(*shopButtonT);
	shopButton->scale(0.25, 0.25);
	shopButton->setPosition(0, 100);
	moneyCount->setTexture(*moneyCountT);
	moneyCount->scale(0.6,0.6);
	moneyCount->setPosition(250, 500);





	lastTimeSlot = time(NULL);
	


	windowPtr = new RenderWindow(sf::VideoMode(2000 / 2, 1239 / 2), "SFML SCREEN");

	chefPtr = Chef::getInstance();
	ovenPtr = Oven::getInstance();
	factoryPtr = Factory::getInstance();
	secretFormulaPtr = SecretFormula::getInstance();
	goldenBrowniePtr = GoldenBrownie::getInstance();
	trophyPtr = Trophy::getInstance();

	

	
	


}





int Wrapper::serverConnect()
{
	// send the score to the server

   // Get the server's IP address and port
	sf::IpAddress serverIP = "40.78.64.118"; // Replace with your server's IP address
	unsigned short serverPort = 8080;    // Replace with your server's port number

	// Create a TCP socket
	sf::TcpSocket socket;

	// Connect to the server
	if (socket.connect(serverIP, serverPort) != sf::Socket::Done)
	{
		std::cerr << "Failed to connect to the server" << std::endl;
		return 1;
	}

	std::cout << "Connected to the server" << std::endl;

	sf::Uint16 score = 500;
	Uint16 sendScore = 0;

	Packet packet1, packet2;

	packet1 << sendScore;
	packet2 << score;

	if (socket.send(packet1) != sf::Socket::Done)
	{
		std::cerr << "Failed to send score to the server" << std::endl;
		return 2;
	}

	std::cout << "Data sent to the server: Score = " << score << std::endl;

	// Close the connection
	socket.disconnect();
	std::cout << "Connection closed" << std::endl;

	return 0;
}

#define GAME 0
#define SHOP 1
#define WIN 2
int counttothree = 0;
int Wrapper::runApp()
{
	int Mode = GAME;
	//chefPtr = Chef::getInstance();
	while (windowPtr->isOpen())
	{
		
		sf::Event event;
		//cout << "hello";
		//cout << lastTimeSlot << "vs" << time(NULL) << endl;
		if (lastTimeSlot != time(NULL))
		{
			if (Mode == WIN)
			{
				if (counttothree < 2)
				{
					counttothree++;
				}
				else
				{
					counttothree = 0;
					player->setTrophyBool(false);
					Mode = GAME;
				}
			}
			lastTimeSlot = time(NULL);
			player->incrementers();
		}
		
		while (windowPtr->pollEvent(event))
		{
			if (player->getTrophyBool())
			{
				Mode = WIN;
			}

			if (Mode == GAME)
			{
				windowPtr->draw(*background);
				windowPtr->draw(*brownie);
				windowPtr->draw(*shopButton);
				windowPtr->draw(*moneyCount);
				moneyText->setString(to_string(player->getBrownies()));
				moneyText->setScale(1, 1);
				moneyText->setPosition(650, 525);
				windowPtr->draw(*moneyText);
			}
			if (Mode == SHOP)
			{
				typedef struct position
				{
					int x;
					int y;
				}Position;
				Position map[6] = { {263,280}, {263 + 175,280}, {263 + 175 * 2,280}, {263, 280 + 200}, {263 + 175,280 + 200}, {263 + 175 * 2,280 + 200} };
				windowPtr->draw(*background);
				windowPtr->draw(*shopMenu);
				windowPtr->draw(*closeButton);

				if (!chefPtr->canPurchaseChef((player))) { cantbuySprites.chef->setPosition(map[0].x, map[0].y); windowPtr->draw(*(cantbuySprites.chef)); }
				else { canbuySprites.chef->setPosition(map[0].x, map[0].y); windowPtr->draw(*(canbuySprites.chef)); }
				if (!ovenPtr->canPurchaseOven((player))) { cantbuySprites.oven->setPosition(map[1].x, map[1].y); windowPtr->draw(*(cantbuySprites.oven)); }
				else { canbuySprites.oven->setPosition(map[1].x, map[1].y); windowPtr->draw(*(canbuySprites.oven)); }
				if (!factoryPtr->canPurchaseFactory((player))) { cantbuySprites.factory->setPosition(map[2].x, map[2].y); windowPtr->draw(*(cantbuySprites.factory)); }
				else { canbuySprites.factory->setPosition(map[2].x, map[2].y); windowPtr->draw(*(canbuySprites.factory)); }
				if (!secretFormulaPtr->canPurchaseSF((player))) { cantbuySprites.secretFormula->setPosition(map[3].x, map[3].y); windowPtr->draw(*(cantbuySprites.secretFormula)); }
				else { canbuySprites.secretFormula->setPosition(map[3].x, map[3].y); windowPtr->draw(*(canbuySprites.secretFormula)); }
				if (!goldenBrowniePtr->canPurchaseGB((player))) { cantbuySprites.goldenBrownie->setPosition(map[4].x, map[4].y); windowPtr->draw(*(cantbuySprites.goldenBrownie)); }
				else { canbuySprites.goldenBrownie->setPosition(map[4].x, map[4].y); windowPtr->draw(*(canbuySprites.goldenBrownie)); }
				if (!trophyPtr->canPurchaseTrophy((player))) { cantbuySprites.trophy->setPosition(map[5].x, map[5].y); windowPtr->draw(*(cantbuySprites.trophy)); }
				else { canbuySprites.trophy->setPosition(map[5].x, map[5].y); windowPtr->draw(*(canbuySprites.trophy)); }


				if (event.type == sf::Event::MouseButtonPressed)
				{
					Vector2i mPos = sf::Mouse::getPosition(*windowPtr);
					if (canbuySprites.chef->getGlobalBounds().contains(mPos.x, mPos.y))
					{
						chefPtr->purchase(player);
					}
					if (canbuySprites.oven->getGlobalBounds().contains(mPos.x, mPos.y))
					{
						ovenPtr->purchase(player);
					}
					if (canbuySprites.factory->getGlobalBounds().contains(mPos.x, mPos.y))
					{
						factoryPtr->purchase(player);
					}
					if (canbuySprites.secretFormula->getGlobalBounds().contains(mPos.x, mPos.y))
					{
						secretFormulaPtr->purchase(player);
					}
					if (canbuySprites.goldenBrownie->getGlobalBounds().contains(mPos.x, mPos.y))
					{
						goldenBrowniePtr->purchase(player);
					}
					if (canbuySprites.trophy->getGlobalBounds().contains(mPos.x, mPos.y))
					{
						trophyPtr->purchase(player);
					}
					/*if (closeButton->getGlobalBounds().contains(mPos.x, mPos.y))
					{
						Mode = GAME;
					}*/



				}
			}
			if (Mode == WIN)
			{
				windowPtr->draw(*winDraw1);
				//windowPtr->draw(*winDraw2);



			}
			windowPtr->display();
			if (event.type == sf::Event::Closed)
			{
				windowPtr->close();
			}
			if (event.type == sf::Event::MouseEntered)
			{
				
			}
			if (event.type == sf::Event::MouseLeft)
			{

			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				Vector2i position = sf::Mouse::getPosition(*windowPtr);
				if (brownie->getGlobalBounds().contains(position.x, position.y))
				{
					player->setBrownies(player->getBrownies() + 1);
					//cout << player->getBrownies();
				}
				if (shopButton->getGlobalBounds().contains(position.x, position.y))
				{
					Mode = SHOP;
				}
				if (closeButton->getGlobalBounds().contains(position.x, position.y))
				{
					Mode = GAME;
				}
				
			}
			
		}
	}
	return 1;
}



	

