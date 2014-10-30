#include "DxLib.h"
#include "BasicInput.h"
#include "GlobalVariable.h"
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
	GlobalVariable::sceneMode = 0;
	int scene = 0;
	// �^�C�g���V�[���̏�����
	SceneMap[GlobalVariable::sceneMode] = SceneFactory::createScene(GlobalVariable::sceneMode);
	SceneMap[GlobalVariable::sceneMode]->init();
	// �t�F�[�h�C��
	for (double i = 0; i <= 255; i += 25.5) {
		SetDrawBright(i, i, i);
		SceneMap[GlobalVariable::sceneMode]->draw();
		ScreenFlip();
	}
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0){
		// ��ʂ�������
		ClearDrawScreen();
		// �`����ʂ𗠂ɂ���
		SetDrawScreen(DX_SCREEN_BACK);
		// ���͂̍X�V
		BasicInput::update();
		GlobalVariable::newDrawableFlag = false;
		if (scene != GlobalVariable::sceneMode)
		// �V�[���̐؂�ւ��
		{
			// �V�[���̐���
			if (SceneMap.find(GlobalVariable::sceneMode) == SceneMap.end()) {
				SceneMap[GlobalVariable::sceneMode] = SceneFactory::createScene(GlobalVariable::sceneMode);
				SceneMap[GlobalVariable::sceneMode]->init();
			}
			// �t�F�[�h�A�E�g
			for (double i = 255; i >= 0; i -= 25.5) {
				SetDrawBright(i, i, i);
				SceneMap[scene]->draw();
				ScreenFlip();
			}
			// �t�F�[�h�C��
			for (double i = 0; i <= 255; i += 25.5) {
				SetDrawBright(i, i, i);
				SceneMap[GlobalVariable::sceneMode]->draw();
				ScreenFlip();
			}
		}
		scene = GlobalVariable::sceneMode;
		// �V�[���`��
		SceneMap[GlobalVariable::sceneMode]->draw();
		// �V�[���X�V
		SceneMap[GlobalVariable::sceneMode]->upDate();
		// ����ʂ̓��e��\��ʂɔ��f���܂�
		ScreenFlip();
	}

	// �`�惁�����̉��
	for (std::list<DrawableBase*>::iterator itr = DrawableBase::DrawableList.begin(); itr != DrawableBase::DrawableList.end(); itr++){
		delete (*itr);
	}
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}