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
	//DrawableList‚ÌXV
	if (GlobalVariable::newDrawableFlag)
	{
		DrawableList.clear();
		for (std::list<DrawableBase*>::iterator itr = DrawableBase::DrawableList.begin(); itr != DrawableBase::DrawableList.end(); itr++)
		{
			if ((*itr)->scene == number)
			{
				DrawableList.push_back(*itr);
			}
		}
	}
	//DrawableList‚Ì•`‰æ
	int min = 0, count = 0;
	for (std::list<DrawableBase*>::iterator itr = DrawableList.begin(); itr != DrawableList.end(); itr++)
	{
		if ((*itr)->layer < min)
		{
			min = (*itr)->layer;
		}
		if (!(*itr)->isVisible)continue;
		(*itr)->upDate();
	}
	while (count < DrawableList.size())
	{
		for (std::list<DrawableBase*>::iterator itr = DrawableList.begin(); itr != DrawableList.end(); itr++)
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

