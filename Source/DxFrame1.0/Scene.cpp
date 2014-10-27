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
	int min = 0, count = 0;
	for (std::list<DrawableBase*>::iterator itr = DrawableList.begin(); itr != DrawableList.end(); itr++)
	{
		if (!(*itr)->isVisible)continue;
		(*itr)->upDate();
		if ((*itr)->layer < min)
		{
			min = (*itr)->layer;
		}
	}
	while (count<DrawableList.size())
	{
		for (std::list<DrawableBase*>::iterator itr =DrawableList.begin(); itr != DrawableList.end(); itr++)
		{
			if ((*itr)->layer == min)
			{
				count++;
				if (!(*itr)->isVisible)continue;
				(*itr)->draw();
			}
		}
		min++;
	}
}

Button* Scene::createButton()
{
	Button* button = new Button();
	DrawableList.push_back(button);
	return button;
}