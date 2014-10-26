#include "Read.h"

Read::Read()
{
}
Read::Read(Board board)
{
	this->board = board;
}

Read::~Read()
{
	delete pointSheet;
}
void Read::read()
{}
int Read::answer()
{
	if (board.getTurnPlayer() == 1)
	{
		return pointSheet->getMaxPoint().get_num(board.ableSpace);
	}
	if (board.getTurnPlayer() == 2)
	{
		return pointSheet->getMinPoint().get_num(board.ableSpace);
	}
}