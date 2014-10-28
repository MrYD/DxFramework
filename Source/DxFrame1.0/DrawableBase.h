#pragma once
#include<list>
#include"GameModes.h""
class DrawableBase
{
public:
	DrawableBase();
	void setLayer(int layer);            //デフォルトは0
	virtual ~DrawableBase() = 0;
	virtual void draw() = 0;
	virtual void upDate() = 0;
	int layer;
	int scene;
	bool isVisible = true;
	static std::list<DrawableBase*> DrawableList;
};

