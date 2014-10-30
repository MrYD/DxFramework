#pragma once
#include"Scene.h"
#include"MenuScene.h"
#include"GameScene.h"
#include"TitleScene.h"
class SceneFactory
{
public:
	SceneFactory();
	~SceneFactory();
	static Scene* createScene(int num);
};

