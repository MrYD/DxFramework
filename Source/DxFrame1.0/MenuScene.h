#pragma once
#include "Scene.h"
#include <string>

class MenuScene :
	public Scene
{
public:
	MenuScene();
	~MenuScene();
	void init();
	void upDate();
private:
	Graphic* Back;
	Button* Hana;
	Button* devil;
};

