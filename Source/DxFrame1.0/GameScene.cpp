#include "GameScene.h"


GameScene::GameScene() : Scene()
{
	init();
}


GameScene::~GameScene()
{
	delete Back;
}
void GameScene::init()
{
	Back = new Graphic();
	DrawableList.push_back(Back);
	Back->setGraph(Vector2(0, 0), ".\\Resource\\Pix\\�V���ƒn��1280_720.png");
	Back->layer = 1;
}
void GameScene::upDate()
{


}
