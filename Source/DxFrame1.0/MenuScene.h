#pragma once
#include "Scene.h"
#include <string>

class MenuScene :
	public Scene
{
public:
	MenuScene(int number);
	~MenuScene();
	void init();
	void upDate();
private:
	Graphic* Back;
	Button* Hana;
	Button* devil;
	Button* button1;
};

