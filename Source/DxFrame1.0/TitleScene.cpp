#include"TitleScene.h"

TitleScene::TitleScene()
{}
TitleScene::~TitleScene()
{}
void TitleScene::init()
{
	(new Graphic())->setGraph(".\\Resource\\Pix\\�^�C�g��1280_720.png");
	time = 0;
}
void TitleScene::upDate()
{
	time++;
	if(time==50){
		GlobalVariable::sceneMode = 1;
	}
}