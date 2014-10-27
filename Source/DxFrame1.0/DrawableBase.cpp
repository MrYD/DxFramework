#include "DrawableBase.h"


DrawableBase::DrawableBase()
{
	isVisible = true;
	layer = 0;
}


DrawableBase::~DrawableBase()
{
}

void DrawableBase::setLayer(int layer)
{
	this->layer += layer;
}