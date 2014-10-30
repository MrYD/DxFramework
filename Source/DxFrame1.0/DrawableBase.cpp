#include "DrawableBase.h"


DrawableBase::DrawableBase()
{
	isVisible = true;
	scene = GlobalVariable::sceneMode;
	layer = 0;
	DrawableBase::DrawableList.push_back(this);
	GlobalVariable::newDrawableFlag = true;
}


DrawableBase::~DrawableBase()
{
}

void DrawableBase::setLayer(int layer)
{
	this->layer = layer;
}

std::list<DrawableBase*> DrawableBase::DrawableList;