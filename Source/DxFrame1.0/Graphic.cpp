#include "Graphic.h"

Graphic::Graphic(Vector2 position, Vector2 graphPx, TCHAR* graphName)
{
	this->top = position;
	this->bottom = position + graphPx;
	this->graphHandle = LoadGraph(graphName);
}
Graphic::Graphic()
{
	this->top = Vector2(0, 0);
	this->bottom = Vector2(150,50);
}

Graphic::~Graphic()
{
}
void Graphic::setGraphPx(Vector2 graphPx)
{
	bottom = top + graphPx;
}
void Graphic::upDate()
{}
void Graphic::afterDraw()
{}

void Graphic::draw()
{
	DrawGraph(top.x, top.y, graphHandle, TRUE);
	afterDraw();
}
void Graphic::setGraph(TCHAR* graphName)
{
	this->graphHandle = LoadGraph(graphName);
}
void Graphic::setGraph(Vector2 pix,TCHAR* graphName)
{
	this->graphHandle = LoadGraph(graphName);
	bottom = top + pix;
}
Vector2 Graphic::getMidPosition()
{
	return (this->bottom + this->top)*0.5f;
}

void Graphic::setMidPosition(Vector2 pos)
{
	Vector2 substracted = getMidPosition() - pos;
	this->top -= substracted;
	this->bottom -= substracted;
}
void Graphic::setTopPosition(Vector2 pos)
{
	Vector2 substracted = top - pos;
	this->top -= substracted;
	this->bottom -= substracted;
}
bool Graphic::pointOnFlag(Vector2 point)
{
	if (point.x>top.x&&point.y>top.y&&point.x<bottom.x&&point.y<bottom.y)
	{
		return true;
	}
	return false;
}