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
	// DrawableLayers‚ÌXV
	if (GlobalVariable::newDrawableFlag)
	{
		for (std::map<int, std::list<DrawableBase*>>::iterator Listitr = DrawableLayers.begin(); Listitr != DrawableLayers.end(); Listitr++)
		{
			Listitr->second.clear();
		}
		for (std::list<DrawableBase*>::iterator itr = DrawableBase::DrawableList.begin(); itr != DrawableBase::DrawableList.end(); itr++)
		{
			if ((*itr)->scene == number)
			{
				DrawableLayers[(*itr)->layer].push_back(*itr);
			}
		}
	}
	// DrawableLayers‚Ì•`‰æ
	for (std::map<int, std::list<DrawableBase*>>::iterator Listitr = DrawableLayers.begin(); Listitr != DrawableLayers.end(); Listitr++)
	{
		for (std::list<DrawableBase*>::iterator itr = Listitr->second.begin(); itr != Listitr->second.end(); itr++)
		{
			if (!(*itr)->isVisible)continue;
			(*itr)->upDate();
		}
	}
	for (std::map<int, std::list<DrawableBase*>>::iterator Listitr = DrawableLayers.begin(); Listitr != DrawableLayers.end(); Listitr++)
	{
		for (std::list<DrawableBase*>::iterator itr = Listitr->second.begin(); itr != Listitr->second.end(); itr++)
		{
			if (!(*itr)->isVisible)continue;
			(*itr)->draw();
		}
	}
	
}

