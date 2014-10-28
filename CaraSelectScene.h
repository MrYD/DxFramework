#pragma once
#include "Scene.h"
class CaraSelectScene :
	public Scene
{
public:
	CaraSelectScene(int number);
	~CaraSelectScene();
	void init();
	void upDate();
};

