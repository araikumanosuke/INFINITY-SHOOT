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

extern int BGHandle;	//�w�i
extern int RHandle;		//�^�C�g�����S
extern int THandle;		//�O�p
extern int PHandle;		//�v���C���[(�@��)
//�G
extern int E_YHandle;
extern int E_YHardHandle;
extern int E_GHandle;
extern int E_GHardHandle;
extern int E_RHandle;
extern int E_RHardHandle;
extern int E_BHandle;
extern int E_BHardHandle;

extern int choice_FHandle;
extern int play_FHandle;

extern int t_position_title;
extern int t_position_stage;
extern int t_position_difficult;

extern bool t_flug;