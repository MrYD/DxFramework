#include "DxLib.h"
#include "BasicInput.h"
#include "GameModes.h"
#include "Scene.h"
#include "SceneFactory.h"
#include <map>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウィンドウの初期化
	SetGraphMode(1280, 720, 32);
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	// シーンの準備
	std::map<int,Scene*> SceneMap;
	GameModes::sceneMode = 0;
	SceneMap[0] = SceneFactory::createScene(0);
	SceneMap[0]->init();
	int scene = 0;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		// 画面を初期化
		ClearDrawScreen();
		// 描画先画面を裏にする
		SetDrawScreen(DX_SCREEN_BACK);
		// 入力の更新
		BasicInput::update();
		if (scene != GameModes::sceneMode)
		//シーンの切り替わり
		{
			// シーンの初期化
			if (SceneMap.find(GameModes::sceneMode) == SceneMap.end()) {
				SceneMap[GameModes::sceneMode] = SceneFactory::createScene(GameModes::sceneMode);
				SceneMap[GameModes::sceneMode]->init();
			}
			// フェードアウト
			for (int i = 255; i >= 0; i -= 20) {
				SetDrawBright(i, i, i);
				SceneMap[scene]->draw();
				ScreenFlip();
			}
			// フェードイン
			for (int i = 0; i <= 260; i += 20) {
				SetDrawBright(i, i, i);
				SceneMap[GameModes::sceneMode]->draw();
				ScreenFlip();
			}
		}
		scene = GameModes::sceneMode;
		// シーン描画
		SceneMap[GameModes::sceneMode]->draw();
		// シーン更新
		SceneMap[GameModes::sceneMode]->upDate();
		// 裏画面の内容を表画面に反映します
		ScreenFlip();
	}

	// 描画メモリの解放
	for (std::list<DrawableBase*>::iterator itr = DrawableBase::DrawableList.begin(); itr != DrawableBase::DrawableList.end(); itr++)
	{
		delete (*itr);
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}