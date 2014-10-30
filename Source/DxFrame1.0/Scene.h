#pragma once
#include "BasicInput.h"
#include "GlobalVariable.h"
#include "Button.h"
#include "DrawableBase.h"
#include <list>
#include <map>

class Scene
{
public:
	Scene();
	void setNumber(int num);
	virtual ~Scene();
	virtual void init() = 0;
	virtual void upDate() = 0;
	void draw();
	int number;
	std::map<int, std::list<DrawableBase*>> DrawableLayers;
};

