#pragma once
#include "Read.h"
class FinalRead :
	public Read
{
public:
	FinalRead();
	FinalRead(Board board);
	~FinalRead();
	int answer();
	int answerRev();
private:
	void read();
	void readRev();
	int alfaBeta(int alfa, int beta);
	int alfaBetaRev(int alfa, int beta);
	int startFinalRead;
};

