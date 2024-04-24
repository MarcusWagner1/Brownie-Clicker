#include "header.hpp"

typedef struct position
{
	int row;
	int col;
}Position;

class NullBlock
{
public:
	NullBlock();
	~NullBlock();
private:

protected:
	int val;
	Position position;


};


NullBlock::NullBlock()
{
	val = 0;
}
NullBlock::~NullBlock()
{

}