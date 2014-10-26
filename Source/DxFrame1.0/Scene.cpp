#include "Scene.h"


Scene::Scene()
{
}

Scene::~Scene()
{
}


void Scene::draw()
{
	//DrawableList‚Ì•`‰æ
	for (std::list<DrawableBase*>::iterator itr = DrawableList.begin(); itr != DrawableList.end(); itr++)
	{
		if (!(*itr)->isVisible)continue;
		(*itr)->upDate();
	}
	int i = 0, count = 0;
	while (count<DrawableList.size())
	{
		i++;
		for (std::list<DrawableBase*>::iterator itr =DrawableList.begin(); itr != DrawableList.end(); itr++)
		{
			if ((*itr)->layer == i)
			{
				count++;
				if (!(*itr)->isVisible)continue;
				(*itr)->draw();
			}
		}
	}
}

Button* Scene::createButton()
{
	Button* button = new Button();
	DrawableList.push_back(button);
	return button;
}