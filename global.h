#pragma once
#include <DxLib.h>
#include "header.h"

//########## �񋓌^ ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,	//�^�C�g�����
	GAME_SCENE_PLAY,	//�v���C���
	GAME_SCENE_END		//�G���h���
};

//########## �O���[�o���ϐ� ##########

//�E�B���h�E�֌W
extern WNDPROC WndProc;						//�E�B���h�E�v���V�[�W���̃A�h���X

//�L�[�{�[�h�֘A
extern char AllKeyState[256];			//���ׂẴL�[�̏�Ԃ�����

//�V�[���֘A
extern int GameSceneNow;	//�ŏ��̃Q�[����ʂ��^�C�g���ɐݒ�

