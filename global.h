#pragma once
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
extern BOOL IsWM_CREATE = FALSE;				//WM_CREATE������ɓ��삵�������f����

//�V�[���֘A
int GameSceneNow = (int)GAME_SCENE_TITLE;	//�ŏ��̃Q�[����ʂ��^�C�g���ɐݒ�

