#pragma once

#include "valBlock.hpp"

class GameBoard
{
public:
	GameBoard();
	~GameBoard();
	ValBlock* getGameBoardCell(int row, int col);
	vector<ValBlock*>* getEmptyCells();
	vector<ValBlock*>* getValueCells();
	void displayGameBoard();
	void traversal(int dir);
	void checkPathing(ValBlock* blockIQ, int dir);
	void importPreset();
	bool checkState();
	int getScore();
	bool getState();
	
private:
	bool checkAdjacentCombos(ValBlock* blockIQ);
	
	bool isBorderPiece(Position pos);
	void addNewBlock();
	void leftTraversal();
	void rightTraversal();
	void upTraversal();
	void downTraversal();
	void checkLeft(ValBlock* blockIQ);
	void checkUp(ValBlock* blockIQ);
	void checkRight(ValBlock* blockIQ);
	void checkDown(ValBlock* blockIQ);
	ValBlock* gameBoard[4][4];
	int score;
	bool hasLost;
};

bool GameBoard::getState()
{
	return hasLost;
}

int GameBoard::getScore()
{
	return score;
}
void GameBoard::importPreset()
{
	vector<int> vStack;
	int i = 0;
	int r = 0;
	int c = 0;
	ifstream infile("gameBoardPreset.txt");
	while (i < 16)
	{
		int val;
		infile >> val;
		gameBoard[r][c]->setValue(val);
		if (c == 3)
		{
			c = 0;
			r++;
		}
		else
		{
			c++;
		}
		
		i++;
	}
}


void GameBoard::traversal(int dir)
{
	
	switch (dir)
	{
	case 1:
	{
		upTraversal();
		break;
	}
	case 2:
	{
		rightTraversal();
		break;
	}
	case 3:
	{
		downTraversal();
		break;
	}
	case 4:
	{
		leftTraversal();
		break;
	}
	}
	// Need to check if chosen direction has any moving blocks, if no blocks can move in that direction, then require user to give a different direction. NEW BLOCK NOT PLACED IN THSI CASE
	//Can check if previous game board is the same as the new game board?
	addNewBlock();
	displayGameBoard();
	if (!checkState())
	{
		hasLost = true;
	}
}

bool GameBoard::checkState()
{
	vector<ValBlock*>* vStack;
	vStack = getValueCells();
	if (vStack->size() == 16);
	{
		while (!vStack->empty())
		{
			if(checkAdjacentCombos(vStack->back()))
			{
				return true;
			}
			vStack->pop_back();
		}
	}
	return false;
}

bool GameBoard::checkAdjacentCombos(ValBlock* blockIQ)
{
	int rowIQ = blockIQ->getPosition().row;
	int colIQ = blockIQ->getPosition().col;
	if (colIQ > 0 && colIQ < 3)
	{
		if (gameBoard[rowIQ][colIQ + 1]->getValue() == 0 || gameBoard[rowIQ][colIQ + 1]->getValue() == blockIQ->getValue())
		{
			return true;
		}
		if (gameBoard[rowIQ][colIQ - 1]->getValue() == 0 || gameBoard[rowIQ][colIQ - 1]->getValue() == blockIQ->getValue())
		{
			return true;
		}
	}
	if (rowIQ > 0 && rowIQ < 3)
	{
		if (gameBoard[rowIQ + 1][colIQ]->getValue() == 0 || gameBoard[rowIQ + 1][colIQ]->getValue() == blockIQ->getValue())
		{
			return true;
		}
		if (gameBoard[rowIQ - 1][colIQ]->getValue() == 0 || gameBoard[rowIQ - 1][colIQ]->getValue() == blockIQ->getValue())
		{
			return true;
		}
	}
	return false;
}

void GameBoard::addNewBlock()
{
	vector<Position> pStack;
	vector<ValBlock*>* vStack;
	int bVal = 2;
	int ran = rand() % 10 + 1;
	if (ran == 10)
	{
		bVal = 4;
	}
	vStack = getEmptyCells();
	if (vStack->size() != 0)
	{
		int ran2 = (rand() % vStack->size());
		/*while (!isBorderPiece(vStack->at(ran2)->getPosition()))
		{
			ran2 = rand() % vStack->size();
		}*/
		int row = vStack->at(ran2)->getPosition().row;
		int col = vStack->at(ran2)->getPosition().col;
		gameBoard[row][col]->setValue(bVal);
	}
	
}

bool GameBoard::isBorderPiece(Position pos)
{
	if ((pos.row == 1 || pos.row == 2) && (pos.col == 1 || pos.col == 2))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void GameBoard::upTraversal()
{
	for (int row = 1; row < 4; row++) // can ignore the top row since its given they cant move hence starting at index 1
	{
		for (int col = 0; col < 4; col++)
		{
			if (gameBoard[row][col]->getValue() != 0)
			{
				checkUp(gameBoard[row][col]);
			}
		}
	}
}

void GameBoard::rightTraversal()
{
	for (int col = 2; col >= 0; col--)
	{
		for (int row = 0; row < 4; row++)
		{
			if (gameBoard[row][col]->getValue() != 0)
			{
				checkRight(gameBoard[row][col]);
			}
		}
	}
}

void GameBoard::downTraversal()
{
	for (int row = 2; row >= 0; row--)
	{
		for (int col = 0; col < 4; col++)
		{
			if (gameBoard[row][col]->getValue() != 0)
			{
				checkDown(gameBoard[row][col]);
			}
		}
	}
}

void GameBoard::leftTraversal()
{
	for (int col = 1; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			if (gameBoard[row][col]->getValue() != 0)
			{
				checkLeft(gameBoard[row][col]);
			}
		}
	}
}


void GameBoard::checkUp(ValBlock* blockIQ)
{
	Position LSP;
	LSP.row = blockIQ->getPosition().row;
	LSP.col = blockIQ->getPosition().col;

	bool canJump = false;
	int debounce = 1;
	int blockRow = blockIQ->getPosition().row;
	int blockCol = blockIQ->getPosition().col;
	int index = blockRow - 1; // cooperative programming since we know that for an up check the row index will NEVER! be 0 so a negative value will not be posible here
	while (debounce == 1 && index >= 0)
	{ // Have to check for two cases, arrival cell is either a zero or a value
		if (gameBoard[index][blockCol]->getValue() == 0)
		{
			//Next cell in path is collidable thru NULLobJECT
			LSP.row = index;
			LSP.col = blockCol;
			canJump = true;
		}
		if (gameBoard[index][blockCol]->getValue() == blockIQ->getValue())
		{
			//Next cell in path is collidable thru merging
			if (blockRow > 1)
			{
				if (blockRow - index >= 2)
				{
					if (gameBoard[index + 1][blockCol]->getValue() != blockIQ->getValue() && gameBoard[index + 1][blockCol]->getValue() != 0)
					{
						cout << "attempted to skip over object" << endl;
					}
					else
					{
						LSP.row = index;
						LSP.col = blockCol;
						gameBoard[index][blockCol]->setValue(blockIQ->getValue() * 2);
						score += blockIQ->getValue() * 2;
						debounce = 0;
					}
				}
			}
			
			
		}
		
		index--;
	}
	if (LSP.row != blockIQ->getPosition().row)
	{
		if (debounce == 1)
		{
			gameBoard[LSP.row][LSP.col]->setValue(blockIQ->getValue());
			blockIQ->setValue(0);
		}
		if (debounce == 0)
		{
			blockIQ->setValue(0);
		}
	}
}

void GameBoard::checkRight(ValBlock* blockIQ)
{
	Position LSP;
	LSP.row = blockIQ->getPosition().row;
	LSP.col = blockIQ->getPosition().col;
	int debounce = 1;
	int blockRow = blockIQ->getPosition().row;
	int blockCol = blockIQ->getPosition().col;
	int index = blockCol + 1; // cooperative programming since we know that for an up check the row index will NEVER! be 0 so a negative value will not be posible here
	while (debounce == 1 && index <= 3)
	{ // Have to check for two cases, arrival cell is either a zero or a value
		if (gameBoard[blockRow][index]->getValue() == 0)
		{
			//Next cell in path is collidable thru NULLobJECT
			LSP.row = blockRow;
			LSP.col = index;

		}
		if (gameBoard[blockRow][index]->getValue() == blockIQ->getValue())
		{
			if (blockCol < 2)
			{
				if (index - blockCol >= 2)
				{
					if (gameBoard[blockRow][index - 1]->getValue() != blockIQ->getValue() && gameBoard[blockRow][index-1]->getValue() != 0)
					{
						cout << "attempted to skip over object" << endl;
					}
					else
					{
						LSP.row = blockRow;
						LSP.col = index;
						gameBoard[blockRow][index]->setValue(blockIQ->getValue() * 2);
						score += blockIQ->getValue() * 2;
						debounce = 0;
					}
				}
				else
				{

				}
			}
		}

		index++;
	}
	if (LSP.col != blockIQ->getPosition().col)
	{
		if (debounce == 1)
		{
			gameBoard[LSP.row][LSP.col]->setValue(blockIQ->getValue());
			blockIQ->setValue(0);
		}
		if (debounce == 0)
		{
			blockIQ->setValue(0);
		}
	}
}

void GameBoard::checkDown(ValBlock* blockIQ)
{
	Position LSP;
	LSP.row = blockIQ->getPosition().row;
	LSP.col = blockIQ->getPosition().col;
	int debounce = 1;
	int blockRow = blockIQ->getPosition().row;
	int blockCol = blockIQ->getPosition().col;
	int index = blockRow + 1; // cooperative programming since we know that for an up check the row index will NEVER! be 0 so a negative value will not be posible here
	while (debounce == 1 && index <= 3)
	{ // Have to check for two cases, arrival cell is either a zero or a value
		if (gameBoard[index][blockCol]->getValue() == 0)
		{
			//Next cell in path is collidable thru NULLobJECT
			LSP.row = index;
			LSP.col = blockCol;

		}
		if (gameBoard[index][blockCol]->getValue() == blockIQ->getValue())
		{
			//Next cell in path is collidable thru merging
			LSP.row = index;
			LSP.col = blockCol;
			gameBoard[index][blockCol]->setValue(blockIQ->getValue() * 2);
			score += blockIQ->getValue() * 2;
			debounce = 0;
		}

		index++;
	}
	if (LSP.row != blockIQ->getPosition().row)
	{
		if (debounce == 1)
		{
			gameBoard[LSP.row][LSP.col]->setValue(blockIQ->getValue());
			blockIQ->setValue(0);
		}
		if (debounce == 0)
		{
			blockIQ->setValue(0);
		}
	}
}

void GameBoard::checkLeft(ValBlock* blockIQ)
{
	Position LSP;
	LSP.row = blockIQ->getPosition().row;
	LSP.col = blockIQ->getPosition().col;
	int debounce = 1;
	int blockRow = blockIQ->getPosition().row;
	int blockCol = blockIQ->getPosition().col;
	int index = blockCol - 1; // cooperative programming since we know that for an up check the row index will NEVER! be 0 so a negative value will not be posible here
	while (debounce == 1 && index >= 0)
	{ // Have to check for two cases, arrival cell is either a zero or a value
		if (gameBoard[blockRow][index]->getValue() == 0)
		{
			//Next cell in path is collidable thru NULLobJECT
			LSP.row = blockRow;
			LSP.col = index;

		}
		if (gameBoard[blockRow][index]->getValue() == blockIQ->getValue())
		{
			//Next cell in path is collidable thru merging
			LSP.row = blockRow;
			LSP.col = index;
			gameBoard[blockRow][index]->setValue(blockIQ->getValue() * 2);
			score += blockIQ->getValue() * 2;
			debounce = 0;
		}

		index--;
	}
	if (LSP.col != blockIQ->getPosition().col)
	{
		if (debounce == 1)
		{
			gameBoard[LSP.row][LSP.col]->setValue(blockIQ->getValue());
			blockIQ->setValue(0);
		}
		if (debounce == 0)
		{
			blockIQ->setValue(0);
		}
	}
}



ValBlock* GameBoard::getGameBoardCell(int row, int col)
{
	return gameBoard[row][col];
}

GameBoard::GameBoard()
{
	
	srand(time(NULL));
	int row1 = rand() % 4;
	int row2 = rand() % 4;
	int col1 = rand() % 4;
	int col2 = rand() % 4;
	while (row1 == row2 && col1 == col2)
	{
		col2 = rand() % 4 + 1; // Generates two unique cells for starter 2's
	}
	
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			gameBoard[row][col] = new ValBlock(0, row, col);
		}
	}
	gameBoard[row1][col1]->setValue(2);
	gameBoard[row2][col2]->setValue(2);
	score = 0;
	hasLost = false;
}

GameBoard::~GameBoard()
{
	
}

vector<ValBlock*>* GameBoard::getEmptyCells()
{
	// store memory address for the initialized gameboardobject
	vector<ValBlock*>* emptyCells = new vector<ValBlock*>;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (getGameBoardCell(row, col)->getValue() == 0)
			{
				emptyCells->push_back(getGameBoardCell(row, col));
			}
		}
	}
	return emptyCells;
}

vector<ValBlock*>* GameBoard::getValueCells()
{
	vector<ValBlock*>* valueCells = new vector<ValBlock*>;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (getGameBoardCell(row, col)->getValue() != 0)
			{
				valueCells->push_back(getGameBoardCell(row, col));
			}
		}
	}
	return valueCells;
}


void GameBoard::displayGameBoard()
{
	system("cls");
	cout << "[" << gameBoard[0][0]->getValue() << "] [" << gameBoard[0][1]->getValue() << "] [" << gameBoard[0][2]->getValue() << "] [" << gameBoard[0][3]->getValue() << "]" << endl;
	cout << "[" << gameBoard[1][0]->getValue() << "] [" << gameBoard[1][1]->getValue() << "] [" << gameBoard[1][2]->getValue() << "] [" << gameBoard[1][3]->getValue() << "]" << endl;
	cout << "[" << gameBoard[2][0]->getValue() << "] [" << gameBoard[2][1]->getValue() << "] [" << gameBoard[2][2]->getValue() << "] [" << gameBoard[2][3]->getValue() << "]" << endl;
	cout << "[" << gameBoard[3][0]->getValue() << "] [" << gameBoard[3][1]->getValue() << "] [" << gameBoard[3][2]->getValue() << "] [" << gameBoard[3][3]->getValue() << "]" << endl;
}



