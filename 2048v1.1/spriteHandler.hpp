#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "header.hpp"
#include "GameBoard.hpp"


using sf::Sprite;
using sf::Texture;
using sf::RenderWindow;






class SpriteHandler
{
public:
	//Sprite* drawValBlock(int val);
	Sprite* drawSprite();
	
	int displayBoard(RenderWindow& window, GameBoard& gameBoard);
	SpriteHandler();

	

	



private:
	static Texture* loadTexture(const string& textureName);
	static Sprite* drawGameBoard();
	bool boardDrawn;
	//unordered_map<sf::Vector2i, sf::Vector2f> posMap;
	unordered_map<int, float> posMapX;
	unordered_map<int, float> posMapY;
	sf::Text* scoreDisplay;
	sf::Font font;
};

SpriteHandler::SpriteHandler()
{
	if(!font.loadFromFile("LDFComicSans.ttf"))
	{
		cout << "could not load font" << endl;
	}
	boardDrawn = false;
	posMapX[0] = 12;
	posMapX[1] = 12+125;
	posMapX[2] = 12+125*2;
	posMapX[3] = 12+125*3;
	posMapY[0] = 102;
	posMapY[1] = 102+121;
	posMapY[2] = 102+121*2;
	posMapY[3] = 102+121*3;
	scoreDisplay = new sf::Text;
	scoreDisplay->setFont(font);
	scoreDisplay->setString("0");
}

//inline int SpriteHandler::displayBoard(RenderWindow& window, GameBoard& gameBoard)
//{
//	scoreDisplay->setString(to_string(gameBoard.getScore()));
//	if (boardDrawn == false)
//	{
//		sf::Color color;
//		
//		scoreDisplay->setPosition(325, 28);
//		scoreDisplay->setCharacterSize(24);
//		scoreDisplay->setFillColor(color.Black);
//		Sprite gameBoardSprite = *drawGameBoard();
//		gameBoardSprite.scale(0.5, 0.5);
//
//		window.draw(gameBoardSprite);
//		window.draw(*scoreDisplay);
//		
//	}
//	for(int r = 0; r < 4; r++)
//	{
//		for(int c = 0; c < 4; c++)
//		{
//			ValBlock* valBlock = gameBoard.getGameBoardCell(r, c);
//			if (valBlock->getValue() != 0)
//			{
//				Sprite vSprite = *drawValBlock(valBlock->getValue());
//				vSprite.scale(0.4, 0.4);
//				vSprite.setPosition(posMapX[c], posMapY[r]);
//				window.draw(vSprite);
//			}
//		}
//	}
//	
//	//window.draw(*scoreDisplay);
//	return 1;
//}

 inline Texture* SpriteHandler::loadTexture(const string& textureName)
{
	auto* texture = new Texture;
	texture->loadFromFile(textureName + ".png");
	return texture;
}


//inline Sprite* SpriteHandler::drawValBlock(int val)
//{
//	auto* sprite = new Sprite;
//	sprite->setTexture(*loadTexture(to_string(val)));
//	return sprite;
//}

//inline Sprite* SpriteHandler::drawGameBoard()
// {
//	auto sprite = new Sprite;
//	sprite->setTexture(*loadTexture("Board"));
//	return sprite;
// }
