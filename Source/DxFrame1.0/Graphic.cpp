#include "Graphic.h"

Graphic::Graphic(Vector2 position, Vector2 graphPx, TCHAR* graphName) :DrawableBase()
{
	this->top = position;
	this->bottom = position + graphPx;
	this->graphHandle = LoadGraph(graphName);
}
Graphic::Graphic() :DrawableBase()
{
	this->top = Vector2(0, 0);
	this->bottom = Vector2(150,50);
}

Graphic::~Graphic()
{
}
Graphic* Graphic::setGraphPx(Vector2 graphPx)
{
	bottom = top + graphPx;
	return this;
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
Graphic* Graphic::setGraph(TCHAR* graphName)
{
	this->graphHandle = LoadGraph(graphName);
	return this;
}
Graphic* Graphic::setGraph(Vector2 pix, TCHAR* graphName)
{
	this->graphHandle = LoadGraph(graphName);
	bottom = top + pix;
	return this;
}
Vector2 Graphic::getMidPosition()
{
	return (this->bottom + this->top)*0.5f;
}

Graphic* Graphic::setMidPosition(Vector2 pos)
{
	Vector2 substracted = getMidPosition() - pos;
	this->top -= substracted;
	this->bottom -= substracted;
	return this;
}
Graphic* Graphic::setTopPosition(Vector2 pos)
{
	Vector2 substracted = top - pos;
	this->top -= substracted;
	this->bottom -= substracted;
	return this;
}
bool Graphic::pointOnFlag(Vector2 point)
{
	if (point.x>top.x&&point.y>top.y&&point.x<bottom.x&&point.y<bottom.y)
	{
		return true;
	}
	return false;
}