#pragma once
#include <DxLib.h>
#include "header.h"

//########## �񋓌^ ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,		//�^�C�g�����
	GAME_SCENE_RANKING,		//�����L���O���
	GAME_SCENE_STAGECHOICE,	//�X�e�[�W�I�����
	GAME_SCENE_PLAY,		//�v���C���
	GAME_SCENE_END_CLEAR,	//�G���h���(�N���A)
	GAME_SCENE_END_OVER		//�G���h���(�Q�[���I�[�o�[)
};

//########## �O���[�o���ϐ� ##########

//�L�[�{�[�h�֘A
extern char AllKeyState[256];			//���ׂẴL�[�̏�Ԃ�����

//�V�[���֘A
extern int GameSceneNow;	//�ŏ��̃Q�[����ʂ��^�C�g���ɐݒ�

extern int BGHandle;
extern int RHandle;
extern int THandle;

extern int choice_FHandle;
extern int t_position;