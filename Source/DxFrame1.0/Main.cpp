#include "DxLib.h"
#include "BasicInput.h"
#include "GameModes.h"
#include "Scene.h"
#include "SceneFactory.h"
#include <map>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�B���h�E�̏�����
	SetGraphMode(1280, 720, 32);
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	// �V�[���̏���
	std::map<int,Scene*> SceneMap;
	GameModes::sceneMode = 0;
	SceneMap[0] = SceneFactory::createScene(0);
	SceneMap[0]->init();
	int scene = 0;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		// ��ʂ�������
		ClearDrawScreen();
		// �`����ʂ𗠂ɂ���
		SetDrawScreen(DX_SCREEN_BACK);
		// ���͂̍X�V
		BasicInput::update();
		if (scene != GameModes::sceneMode)
		//�V�[���̐؂�ւ��
		{
			// �V�[���̏�����
			if (SceneMap.find(GameModes::sceneMode) == SceneMap.end()) {
				SceneMap[GameModes::sceneMode] = SceneFactory::createScene(GameModes::sceneMode);
				SceneMap[GameModes::sceneMode]->init();
			}
			// �t�F�[�h�A�E�g
			for (int i = 255; i >= 0; i -= 20) {
				SetDrawBright(i, i, i);
				SceneMap[scene]->draw();
				ScreenFlip();
			}
			// �t�F�[�h�C��
			for (int i = 0; i <= 260; i += 20) {
				SetDrawBright(i, i, i);
				SceneMap[GameModes::sceneMode]->draw();
				ScreenFlip();
			}
		}
		scene = GameModes::sceneMode;
		// �V�[���`��
		SceneMap[GameModes::sceneMode]->draw();
		// �V�[���X�V
		SceneMap[GameModes::sceneMode]->upDate();
		// ����ʂ̓��e��\��ʂɔ��f���܂�
		ScreenFlip();
	}

	// �`�惁�����̉��
	for (std::list<DrawableBase*>::iterator itr = DrawableBase::DrawableList.begin(); itr != DrawableBase::DrawableList.end(); itr++)
	{
		delete (*itr);
	}
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}