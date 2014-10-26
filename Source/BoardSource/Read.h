#pragma once
#include"Board.h"
#include"PointSheet.h"
class Read
{
public:
	Read();
	Read(Board board);
	~Read();
	int answer();
protected:
	Board board;
	PointSheet *pointSheet;
	void read();
	int count;
};

