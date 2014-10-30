#include "Scene.h"


Scene::Scene()
{
}

Scene::~Scene()
{
}
void Scene::setNumber(int num)
{
	this->number = num;
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
		if (!(*itr)->isVisible || (*itr)->scene != number)continue;
		(*itr)->upDate();
	}
	while (count < DrawableBase::DrawableList.size())
	{
		for (std::list<DrawableBase*>::iterator itr = DrawableBase::DrawableList.begin(); itr != DrawableBase::DrawableList.end(); itr++)
		{
			if ((*itr)->layer == min)
			{
				count++;
				if (!(*itr)->isVisible || (*itr)->scene != number)continue;
				(*itr)->draw();
			}
		}
		min++;
	}
}

