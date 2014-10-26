#include "MenuScene.h"


MenuScene::MenuScene()
{
	init();
}


MenuScene::~MenuScene()
{
	delete Back;
	delete Hana;
	delete devil;
	delete button1;
}
void MenuScene::init()
{
	Hana = new Button();
	DrawableList.push_back(Hana);
	Hana->setGraph(Vector2(300,400),".\\Resource\\Pix\\Hana.png");
	Hana->setTopPosition(Vector2(200,150));
	Hana->layer = 2;
	devil = new Button();
	DrawableList.push_back(devil);
	devil->setGraph(Vector2(300,400),".\\Resource\\Pix\\devil.png");
	devil->setTopPosition(Vector2(800, 150));
	devil->layer = 2;
	Back = new Graphic();
	DrawableList.push_back(Back);
	Back->setGraph(Vector2(0, 0), ".\\Resource\\Pix\\“V‘‚Æ’n–1280_720.png");
	Back->layer = 1;
	button1 = new Button();
	DrawableList.push_back(button1);
	button1->setDragFlag(true);
	button1->layer = 2;
}
void MenuScene::upDate()
{
	if (Hana->getClickedTimes())
	{
		GameModes::sceneMode = 1;
	}
}