#include "Scene.h"


Scene::Scene(int number)
{
	this->number = number;
	BeforeInit();
}

Scene::~Scene()
{
}
void Scene::BeforeInit()
{
	GameModes::sceneMode = number;
}

void Scene::draw()
{
	//DrawableList‚Ì•`‰æ
	int min = 0, count = 0;
	for (std::list<DrawableBase*>::iterator itr = DrawableBase::DrawableList.begin(); itr != DrawableBase::DrawableList.end(); itr++)
	{
		if ((*itr)->layer < min)
		{
			min = (*itr)->layer;
		}
		if (!(*itr)->isVisible || (*itr)->scene != GameModes::sceneMode)continue;
		(*itr)->upDate();
	}
	while (count < DrawableBase::DrawableList.size())
	{
		for (std::list<DrawableBase*>::iterator itr = DrawableBase::DrawableList.begin(); itr != DrawableBase::DrawableList.end(); itr++)
		{
			if ((*itr)->layer == min)
			{
				count++;
				if (!(*itr)->isVisible || (*itr)->scene != GameModes::sceneMode)continue;
				(*itr)->draw();
			}
		}
		min++;
	}
}

