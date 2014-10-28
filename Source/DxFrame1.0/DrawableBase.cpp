#include "DrawableBase.h"


DrawableBase::DrawableBase()
{
	isVisible = true;
	scene = GameModes::sceneMode;
	layer = 0;
	DrawableBase::DrawableList.push_back(this);
}


DrawableBase::~DrawableBase()
{
}

void DrawableBase::setLayer(int layer)
{
	this->layer = layer;
}

std::list<DrawableBase*> DrawableBase::DrawableList;