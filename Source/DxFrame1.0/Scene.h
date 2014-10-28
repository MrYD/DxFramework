#pragma once
#include "BasicInput.h"
#include "GameModes.h"
#include "Button.h"
#include "DrawableBase.h"
#include <list>

class Scene
{
public:
	Scene(int number);
	virtual ~Scene();
	void BeforeInit();
	virtual void init()=0;
	virtual void upDate() = 0;
	void draw();
	int number;
};

