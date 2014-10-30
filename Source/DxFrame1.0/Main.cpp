#include "DxLib.h"
#include "BasicInput.h"
#include "GlobalVariable.h"
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
	GlobalVariable::sceneMode = 0;
	int scene = 0;
	// タイトルシーンの初期化
	SceneMap[GlobalVariable::sceneMode] = SceneFactory::createScene(GlobalVariable::sceneMode);
	SceneMap[GlobalVariable::sceneMode]->init();
	// フェードイン
	for (double i = 0; i <= 255; i += 25.5) {
		SetDrawBright(i, i, i);
		SceneMap[GlobalVariable::sceneMode]->draw();
		ScreenFlip();
	}
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0){
		// 画面を初期化
		ClearDrawScreen();
		// 描画先画面を裏にする
		SetDrawScreen(DX_SCREEN_BACK);
		// 入力の更新
		BasicInput::update();
		GlobalVariable::newDrawableFlag = false;
		if (scene != GlobalVariable::sceneMode)
		// シーンの切り替わり
		{
			// シーンの生成
			if (SceneMap.find(GlobalVariable::sceneMode) == SceneMap.end()) {
				SceneMap[GlobalVariable::sceneMode] = SceneFactory::createScene(GlobalVariable::sceneMode);
				SceneMap[GlobalVariable::sceneMode]->init();
			}
			// フェードアウト
			for (double i = 255; i >= 0; i -= 25.5) {
				SetDrawBright(i, i, i);
				SceneMap[scene]->draw();
				ScreenFlip();
			}
			// フェードイン
			for (double i = 0; i <= 255; i += 25.5) {
				SetDrawBright(i, i, i);
				SceneMap[GlobalVariable::sceneMode]->draw();
				ScreenFlip();
			}
		}
		scene = GlobalVariable::sceneMode;
		// シーン描画
		SceneMap[GlobalVariable::sceneMode]->draw();
		// シーン更新
		SceneMap[GlobalVariable::sceneMode]->upDate();
		// 裏画面の内容を表画面に反映します
		ScreenFlip();
	}

	// 描画メモリの解放
	for (std::list<DrawableBase*>::iterator itr = DrawableBase::DrawableList.begin(); itr != DrawableBase::DrawableList.end(); itr++){
		delete (*itr);
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}