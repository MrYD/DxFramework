#include "MenuScene.h"


MenuScene::MenuScene(int number) :Scene(number)
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
	Hana->setGraph(Vector2(300, 400), ".\\Resource\\Pix\\Hana.png")
		->setTopPosition(Vector2(200, 150));

	devil = new Button();
	devil->setGraph(Vector2(300, 400), ".\\Resource\\Pix\\devil.png")
		 ->setTopPosition(Vector2(800, 150));
	
	Back = new Graphic();
	Back->setGraph(Vector2(0, 0), ".\\Resource\\Pix\\“V‘‚Æ’n–1280_720.png")
		->layer = -1;
	
	button1 = new Button();
	button1->setDragFlag(true);
}
void MenuScene::upDate()
{
	if (Hana->getClickedTimes())
	{
		GameModes::sceneMode = 1;
	}
}