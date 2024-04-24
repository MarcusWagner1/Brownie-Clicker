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

	background = new Sprite;
	chef = new Sprite;
	brownie = new Sprite;
	goldenbrownie = new Sprite;
	oven = new Sprite;
	shopMenu = new Sprite;
	winDraw2 = new Sprite;

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
	//std::cout << chefPtr->getPriceFromFormula(1);
	
	//windowPtr->setSize(sf::Vector2u(1005 / 2, 1239 / 2));

	/*chefPtr = nullptr;
	ovenPtr = nullptr;
	factoryPtr = nullptr;
	secretFormulaPtr = nullptr;
	goldenBrowniePtr = nullptr;
	trophyPtr = nullptr;*/

	
	
	/*chefPtr = Chef::getInstance();
	ovenPtr = Oven::getInstance();
	factoryPtr = Factory::getInstance();
	secretFormulaPtr = SecretFormula::getInstance();
	goldenBrowniePtr = GoldenBrownie::getInstance();
	trophyPtr = Trophy::getInstance();*/

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
				windowPtr->draw(*winDraw2);



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
			//if (event.type == sf::Event::MouseButtonPressed)
			//{
			//	Vector2i position = sf::Mouse::getPosition(*windowPtr);
			//	//if (playButton->getGlobalBounds().contains(position.x, position.y))
			//	//{
			//	//	GameBoard gameBoard;
			//	//	gameBoard.displayGameBoard();
			//	//	//gameBoard.importPreset();
			//	//	play2048(gameBoard);
			//	//	
			//	//}
			//	if(exitButton->getGlobalBounds().contains(position.x, position.y))
			//	{
			//		return 1;
			//	}
			//	if (scoresButton->getGlobalBounds().contains(position.x, position.y))
			//	{
			//		
			//		displayScores();
			//		
			//	}
			//}
		}
	}
	return 1;
}



	/*int input = 0;
	int debounce = 0;
	displayMenu();
	cin >> input;
	serverConnect();
	while (debounce == 0)
	{
		while (input < 1 || input > 3)
		{
			system("cls");
			displayMenu();
			cin >> input;
		}
		switch (input)
		{
		case 1:
		{
			displayRules();
			input = 0;
			break;
		}
		case 2:
		{
			GameBoard gameBoard;
			gameBoard.displayGameBoard();
			play2048(gameBoard);
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Exiting the Application..." << endl;
			cout << "Thank you for Playing!" << endl;

			return 1;
			break;
		}
		}
	}*/


//int Wrapper::playBrownieClicker(Player& player)
//{
//	SpriteHandler spriteHandler;
//	
//	
//
//	//sf::Sprite boardSprite(*spriteHandler.drawGameBoard());
//	//sprite.scale(0.1, 0.1);
//	//boardSprite.scale(0.5, 0.5);
//	while (windowPtr->isOpen())
//	{
//		sf::Event event;
//		while (windowPtr->pollEvent(event))
//		{
//			windowPtr->display();
//			
//			spriteHandler.displayBoard(*windowPtr, gameBoard);
//			windowPtr->draw(*backButton);
//			//window.draw(boardSprite);
//			
//			if (event.type == sf::Event::Closed)
//			{
//				windowPtr->close();
//				cout << "Yo this thang just closed for real";
//			}
//			if (gameBoard.getState() == true)
//			{
//				windowPtr->draw(*gameOver);
//				windowPtr->draw(*backButton);
//				backButton->setPosition(225, 400);
//			}
//			if (event.type == sf::Event::KeyPressed)
//			{
//				if (event.key.scancode == sf::Keyboard::Scan::W && keyMap['W'] == false && gameBoard.getState() == false)
//				{
//					keyMap['W'] = true;
//					cout << "W was pressed" << endl;
//					gameBoard.traversal(1);
//				}
//				if (event.key.scancode == sf::Keyboard::Scan::A && keyMap['A'] == false && gameBoard.getState() == false)
//				{
//					keyMap['A'] = true;
//					//cout << "A was pressed" << endl;
//					gameBoard.traversal(4);
//				}
//				if (event.key.scancode == sf::Keyboard::Scan::S && keyMap['S'] == false && gameBoard.getState() == false)
//				{
//					keyMap['S'] = true;
//					//cout << "S was pressed" << endl;
//					gameBoard.traversal(3);
//				}
//				if (event.key.scancode == sf::Keyboard::Scan::D && keyMap['D'] == false && gameBoard.getState() == false)
//				{
//					keyMap['D'] = true;
//					//cout << "D was pressed" << endl;
//					gameBoard.traversal(2);
//				}
//			}
//			if (event.type == sf::Event::KeyReleased)
//			{
//				if (event.key.scancode == sf::Keyboard::Scan::W)
//				{
//					keyMap['W'] = false;
//					cout << "W was released" << endl;
//				}
//				if (event.key.scancode == sf::Keyboard::Scan::A)
//				{
//					keyMap['A'] = false;
//					cout << "A was released" << endl;
//				}
//				if (event.key.scancode == sf::Keyboard::Scan::S)
//				{
//					keyMap['S'] = false;
//					cout << "S was released" << endl;
//				}
//				if (event.key.scancode == sf::Keyboard::Scan::D)
//				{
//					keyMap['D'] = false;
//					cout << "D was released" << endl;
//				}
//			}
//			if (event.type == sf::Event::MouseButtonPressed)
//			{
//				Vector2i position = sf::Mouse::getPosition(*windowPtr);
//				if (backButton->getGlobalBounds().contains(position.x, position.y))
//				{
//					return 1;
//				}
//			}
//		}
//	}
//}




//void Wrapper::displayMenu()
//{
//	system("cls");
//	cout << "Welcome to 2048" << endl;
//	cout << endl;
//	cout << "Select an option:" << endl;
//	cout << "1.) Rules and Introduction" << endl;
//	cout << "2.) Play game" << endl;
//	cout << "3.) Exit Game" << endl;
//
//}

//void Wrapper::displayRules()
//{
//	system("cls");
//	cout << "2048 Is a very simple game where you can move the blocks in the direction of your arrow keys or wasd keys" << endl;
//	cout << "The goal is to merge like blocks together and eventually have a block with the value 2048" << endl;
//	cout << "Be careful though because you can only merge blocks that are the same value otherwise the blocks will retain their values" << endl;
//	cout << "Press any button to return back to the menu...";
//	system("pause");
//}