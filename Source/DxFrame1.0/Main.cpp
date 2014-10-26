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
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	//�^�C�g���`��
	int Handle = LoadGraph(".\\Resource\\Pix\\�^�C�g��1280_720.png", TRUE);
	//�t�F�[�h�C��
	for (int i = 0; i <= 260; i += 20) {
		SetDrawBright(i, i, i);
		DrawGraph(0, 0, Handle, TRUE);
		ScreenFlip();
	}
	//�V�[��������
	Scene *scene[2];
	scene[0] = new MenuScene();
	scene[1] = new GameScene();
	WaitTimer(1000);
	//�t�F�[�h�A�E�g
	for (int i = 255; i >= 0; i-=20) {
		SetDrawBright(i, i, i);
		DrawGraph(0, 0, Handle, TRUE);
		ScreenFlip();
	}
	//�t�F�[�h�C��
	for (int i = 0; i <= 260; i += 20) {
		SetDrawBright(i, i, i);
		scene[GameModes::sceneMode]->draw();
		ScreenFlip();
	}
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		// ��ʂ�������
		ClearDrawScreen();
		// �`����ʂ𗠂ɂ���
		SetDrawScreen(DX_SCREEN_BACK);
		BasicInput::update();
		int sceneMode = GameModes::sceneMode;
		//�V�[���X�V
		scene[GameModes::sceneMode]->upDate();
		if (!(sceneMode == GameModes::sceneMode))
		//�V�[���̐؂�ւ��
		{
			//�t�F�[�h�A�E�g
			for (int i = 255; i >= 0; i -= 20) {
				SetDrawBright(i, i, i);
				scene[sceneMode]->draw();
				ScreenFlip();
			}
			//�t�F�[�h�C��
			for (int i = 0; i <= 260; i += 20) {
				SetDrawBright(i, i, i);
				scene[GameModes::sceneMode]->draw();
				ScreenFlip();
			}
		}
		//�V�[���`��
		scene[GameModes::sceneMode]->draw();
		// ����ʂ̓��e��\��ʂɔ��f���܂�
		ScreenFlip();
	}
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}