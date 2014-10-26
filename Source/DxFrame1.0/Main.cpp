#include "DxLib.h"
#include "BasicInput.h"
#include "GameModes.h"
#include "MenuScene.h"
#include "GameScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(1280, 720, 32);
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	//タイトル描画
	int Handle = LoadGraph(".\\Resource\\Pix\\タイトル1280_720.png", TRUE);
	//フェードイン
	for (int i = 0; i <= 260; i += 20) {
		SetDrawBright(i, i, i);
		DrawGraph(0, 0, Handle, TRUE);
		ScreenFlip();
	}
	//シーン初期化
	Scene *scene[2];
	scene[0] = new MenuScene();
	scene[1] = new GameScene();
	WaitTimer(1000);
	//フェードアウト
	for (int i = 255; i >= 0; i-=20) {
		SetDrawBright(i, i, i);
		DrawGraph(0, 0, Handle, TRUE);
		ScreenFlip();
	}
	//フェードイン
	for (int i = 0; i <= 260; i += 20) {
		SetDrawBright(i, i, i);
		scene[GameModes::sceneMode]->draw();
		ScreenFlip();
	}
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		// 画面を初期化
		ClearDrawScreen();
		// 描画先画面を裏にする
		SetDrawScreen(DX_SCREEN_BACK);
		BasicInput::update();
		int sceneMode = GameModes::sceneMode;
		//シーン更新
		scene[GameModes::sceneMode]->upDate();
		if (!(sceneMode == GameModes::sceneMode))
		//シーンの切り替わり
		{
			//フェードアウト
			for (int i = 255; i >= 0; i -= 20) {
				SetDrawBright(i, i, i);
				scene[sceneMode]->draw();
				ScreenFlip();
			}
			//フェードイン
			for (int i = 0; i <= 260; i += 20) {
				SetDrawBright(i, i, i);
				scene[GameModes::sceneMode]->draw();
				ScreenFlip();
			}
		}
		//シーン描画
		scene[GameModes::sceneMode]->draw();
		// 裏画面の内容を表画面に反映します
		ScreenFlip();
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}