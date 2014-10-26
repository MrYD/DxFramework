#pragma once
#include "Scene.h"
#include "Button.h"
#include <list>
class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();
	void init();
	void upDate();
private:
	Graphic* Back;
};
