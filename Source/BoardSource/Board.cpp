#include "Board.h"
#include<iostream>
#include<memory>
#include<time.h>
using namespace std;


Board::Board(int firstPlayer)
{
	init(firstPlayer);
}
Board::Board()
{
}
Board::~Board()
{
}
void Board::init(int firstPlayer)
{
	thisTurn = 0;
	this->turnPlayer = firstPlayer;
	clear(log[thisTurn]);
	log[thisTurn][3][3] = 1;
	log[thisTurn][3][4] = 2;
	log[thisTurn][4][3] = 2;
	log[thisTurn][4][4] = 1;
	setAbleSpace();
}

void Board::clear(int arr[8][8])
{
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
		arr[i][j] = 0;
}
int Board::oponent(int player)
{
	if (player == 1) return 2;
	else if (player == 2) return 1;
	else return 0;
}
bool Board::isAble(int fu[8][8], Point point, int t)
{
	int i = point.get_x();
	int j = point.get_y();
	int a = oponent(t);
	int count;
	int check;
	if (fu[i][j] == 0)
	{
		count = 0;    //右チェック
		check = a;
		while (check == a && (i + count)< 7)
		{
			count++;
			check = fu[i + count][j];
		}
		if (check == t && count > 1)
		{
			return true;
		}

		count = 0; // 左チェック
		check = a;
		while (check == a && 0 < (i - count))
		{
			count++;
			check = fu[i - count][j];
		}
		if (check == t && count > 1)
		{
			return true;
		}

		count = 0; //上チェック
		check = a;
		while (check == a && 0 < (j - count))
		{
			count++;
			check = fu[i][j - count];
		}
		if (check == t && count > 1)
		{
			return true;
		}

		count = 0;  //下チェック
		check = a;
		while (check == a && (j + count) <7)
		{
			count++;
			check = fu[i][j + count];
		}
		if (check == t && count > 1)
		{
			return true;
		}

		count = 0; //右下チェック
		check = a;
		while (check == a && (i + count) < 7 && (j + count) <7)
		{
			count++;
			check = fu[i + count][j + count];
		}
		if (check == t && count > 1)
		{
			return true;
		}
		count = 0; //左下チェック
		check = a;
		while (check == a && 0 < (i - count) && (j + count)<7)
		{
			count++;
			check = fu[i - count][j + count];
		}
		if (check == t && count > 1)
		{
			return true;
		}
		count = 0;  //右上チェック
		check = a;
		while (check == a && (i + count) < 7 && 0 < (j - count))
		{
			count++;
			check = fu[i + count][j - count];
		}
		if (check == t && count > 1)
		{
			return true;
		}

		count = 0; //右上チェック
		check = a;
		while (check == a && 0 < (i - count) && 0 <(j - count))
		{
			count++;
			check = fu[i - count][j - count];

		}
		if (check == t && count > 1)
		{
			return true;
		}
	}
	return false;
}

int Board::put(Point point)
{
	if (ableSpace[point.get_x()][point.get_y()] == 0)
	{
		return false;
	}
	int count, check, num = 0;
	int i = point.get_x();
	int j = point.get_y();
	int t = turnPlayer;
	int a = oponent(turnPlayer);
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
		log[thisTurn + 1][i][j] = log[thisTurn][i][j];

	log[thisTurn + 1][i][j] = t;
	this->point[thisTurn + 1] = point;

	count = 0;		//右チェック
	check = a;
	while ((check == a) && (i + count< 7))
	{
		count++;
		check = log[thisTurn + 1][i + count][j];
	}
	if (check == t && count > 1)
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i + k][j] = t;
		num++;
	}
	count = 0;		// 左チェック
	check = a;
	while ((check == a) && (0 < i - count))
	{
		count++;
		check = log[thisTurn + 1][i - count][j];
	}
	if (check == t && count > 1)
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i - k][j] = t;
		num++;
	}
	count = 0;		//上チェック
	check = a;
	while ((check == a) && (0 < j - count))
	{
		count++;
		check = log[thisTurn + 1][i][j - count];
	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i][j - k] = t;
		num++;
	}
	count = 0;		//下チェック
	check = a;
	while ((check == a) && (j + count <7))
	{
		count++;
		check = log[thisTurn + 1][i][j + count];
	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i][j + k] = t;
		num++;
	}
	count = 0; //右下チェック
	check = a;
	while ((check == a) && (i + count < 7) && (j + count <7))
	{
		count++;
		check = log[thisTurn + 1][i + count][j + count];
	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i + k][j + k] = t;
		num++;
	}
	count = 0; //左下チェック
	check = a;
	while ((check == a) && (0 < i - count) && (j + count <7))
	{
		count++;
		check = log[thisTurn + 1][i - count][j + count];
	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i - k][j + k] = t;
		num++;
	}

	count = 0;  //右上チェック
	check = a;
	while ((check == a) && (i + count < 7) && (0 < j - count))
	{
		count++;
		check = log[thisTurn + 1][i + count][j - count];
	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i + k][j - k] = t;
		num++;
	}
	count = 0; //右上チェック
	check = a;
	while ((check == a) && (0 < i - count) && (0 < j - count))
	{
		count++;
		check = log[thisTurn + 1][i - count][j - count];

	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i - k][j - k] = t;
		num++;
	}
	if (num != 0)
	{
		nextTurn();
		return num;
	}
	else
		return false;
}
int Board::put(int number)
{
	return put(Point(number, ableSpace));
}
void Board::pass()
{
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
		log[thisTurn + 1][i][j] = log[thisTurn][i][j];
	nextTurn();
}
void Board::undo()
{
	if (thisTurn > 0)
	{
		thisTurn--;
		turnPlayer = oponent(turnPlayer);
	}
	setAbleSpace();
}
void Board::nextTurn()
{
	thisTurn++;
	turnPlayer = oponent(turnPlayer);
	setAbleSpace();
}
int Board::getNumber(int player)
{
	int count = 0;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (log[thisTurn][i][j] == player)
				count++;
		}
	}
	return count;
}
int Board::getAbleNumber(int player)
{
	if (player == getTurnPlayer()) return ableNumber;
	else
	{
		int t = player, a = turnPlayer, count = 0, check = 0, num = 0;
		for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (log[thisTurn][i][j] == 0)
			{
				count = 0;//右チェック
				check = a;
				while (check == a && (i + count)< 7)
				{
					count++;
					check = log[thisTurn][i + count][j];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0;// 左チェック
				check = a;
				while (check == a && 0 < (i - count))
				{
					count++;
					check = log[thisTurn][i - count][j];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0; //上チェック
				check = a;
				while (check == a && 0 < (j - count))
				{
					count++;
					check = log[thisTurn][i][j - count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0; //下チェック
				check = a;
				while (check == a && (j + count) <7)
				{
					count++;
					check = log[thisTurn][i][j + count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0; //右下チェック
				check = a;
				while (check == a && (i + count) < 7 && (j + count) <7)
				{
					count++;
					check = log[thisTurn][i + count][j + count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0;//左下チェック
				check = a;
				while (check == a && 0 < (i - count) && (j + count)<7)
				{
					count++;
					check = log[thisTurn][i - count][j + count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0; //右上チェック
				check = a;
				while (check == a && (i + count) < 7 && 0 < (j - count))
				{
					count++;
					check = log[thisTurn][i + count][j - count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0;//右上チェック
				check = a;
				while (check == a && 0 < (i - count) && 0 <(j - count))
				{
					count++;
					check = log[thisTurn][i - count][j - count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
			}
		}
		return num;
	}
}
int Board::getAbleNumber()
{
	return ableNumber;
}
int Board::getThisTurn()
{
	return thisTurn;
}
int Board::getCondition()
{
	return	getCondition(1);
}
int Board::getCondition(int player)
{
	int condition = 0;
	if (getAbleNumber(turnPlayer) == 0)
	{
		condition = 4;
		if (getAbleNumber(oponent(turnPlayer)) == 0)
		{
			int x = getNumber(player);
			int y = getNumber(oponent(player));
			if (x > y) condition = 1;
			if (x < y) condition = 2;
			if (x == y)condition = 3;
		}
	}
	return condition;
}
int Board::getSCondition()
{
	int condition = 0;
	if (getAbleNumber(turnPlayer) == 0)
	{
		if (getAbleNumber(oponent(turnPlayer)) == 0) condition = 5;
		else condition = 4;
	}
	return condition;
}

int Board::getTurnPlayer()
{
	return turnPlayer;
}

void Board::setAbleSpace()
{
	clear(ableSpace);
	int count, check, num = 0;
	int t = turnPlayer;
	int a = oponent(turnPlayer);
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	{

		if (log[thisTurn][i][j] == 0) {
			count = 0;    //右チェック
			check = a;
			while (check == a && (i + count)< 7)
			{
				count++;
				check = log[thisTurn][i + count][j];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}

			count = 0; // 左チェック
			check = a;
			while (check == a && 0 < (i - count))
			{
				count++;
				check = log[thisTurn][i - count][j];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}

			count = 0; //上チェック
			check = a;
			while (check == a && 0 < (j - count))
			{
				count++;
				check = log[thisTurn][i][j - count];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}

			count = 0;  //下チェック
			check = a;
			while (check == a && (j + count) <7)
			{
				count++;
				check = log[thisTurn][i][j + count];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}

			count = 0; //右下チェック
			check = a;
			while (check == a && (i + count) < 7 && (j + count) <7)
			{
				count++;
				check = log[thisTurn][i + count][j + count];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}
			count = 0; //左下チェック
			check = a;
			while (check == a && 0 < (i - count) && (j + count)<7)
			{
				count++;
				check = log[thisTurn][i - count][j + count];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}
			count = 0;  //右上チェック
			check = a;
			while (check == a && (i + count) < 7 && 0 < (j - count))
			{
				count++;
				check = log[thisTurn][i + count][j - count];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}

			count = 0; //右上チェック
			check = a;
			while (check == a && 0 < (i - count) && 0 <(j - count))
			{
				count++;
				check = log[thisTurn][i - count][j - count];

			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}
		}
	}

	this->ableNumber = num;
}

