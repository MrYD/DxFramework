#include "SceneFactory.h"


SceneFactory::SceneFactory()
{
}


SceneFactory::~SceneFactory()
{
}

Scene* SceneFactory::createScene(int num)
{
	Scene* scene;
	switch (num)
	{
	default:
		scene = new TitleScene();
		break;
	case 1:
		scene = new MenuScene();
		break;
	case 2:
		scene = new GameScene();
		break;
	}
	scene->setNumber(num);
	return scene;
}