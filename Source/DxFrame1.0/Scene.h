#pragma once
#include "BasicInput.h"
#include "GameModes.h"
#include "Button.h"
#include "DrawableBase.h"
#include <list>

class Scene
{
public:
	Scene();
	virtual ~Scene();
	virtual void init() = 0;
	virtual void upDate() = 0;
	void draw();
	std::list<DrawableBase*> DrawableList;
	Button* createButton();
};

