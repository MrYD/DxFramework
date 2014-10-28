#include "GameScene.h"


GameScene::GameScene(int number) : Scene(number)
{
}


GameScene::~GameScene()
{
	delete Back;
}
void GameScene::init()
{
	Back = new Graphic();
	Back->setGraph(Vector2(0, 0), ".\\Resource\\Pix\\“V‘‚Æ’n–1280_720.png");
	Back->layer = 1;
}
void GameScene::upDate()
{


}
