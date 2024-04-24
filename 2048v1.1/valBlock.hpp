#include "nullBlock.hpp"




class ValBlock : NullBlock
{
public:
	ValBlock(int newVal, int row, int col);
	~ValBlock();
	int getValue();
	void setValue(int newValue);
	Position getPosition();
	void setPosition(int row, int col);

	
private:
	int hasMerged;
	string color;
protected:

};

ValBlock::ValBlock(int newVal, int row, int col)
{
	this->val = newVal;
	this->position.col = col;
	this->position.row = row;
}

ValBlock::~ValBlock()
{

}





int ValBlock::getValue()
{
	return val;
}

void ValBlock::setValue(int newVal)
{
	val = newVal;
}

Position ValBlock::getPosition()
{
	return this->position;
}

void ValBlock::setPosition(int row, int col)
{
	position.row = row;
	position.col = col;
}