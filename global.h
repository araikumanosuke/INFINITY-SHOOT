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

struct IMAGE {
	int handle;
	char filepath[128];
	int x;
	int y;
};

//########## �O���[�o���ϐ� ##########

//�L�[�{�[�h�֘A
extern char AllKeyState[256];			//���ׂẴL�[�̏�Ԃ�����

//�V�[���֘A
extern int GameSceneNow;	//�ŏ��̃Q�[����ʂ��^�C�g���ɐݒ�

extern IMAGE BG;	//�w�i
extern IMAGE ROGO;		//�^�C�g�����S
extern IMAGE SANKAKU;		//�O�p
extern IMAGE TAMA;		//�e
extern IMAGE PLAYER;		//�v���C���[(�@��)
//�G
extern IMAGE E_YELLOW;
extern IMAGE E_YELLOW_HARD;
extern IMAGE E_GREEN;
extern IMAGE E_GREEN_HARD;
extern IMAGE E_RED;
extern IMAGE E_RED_HARD;
extern IMAGE E_BLUE;
extern IMAGE E_BLUE_HARD;

extern int choice_FHandle;
extern int play_FHandle;

extern int s_position_title;
extern int s_position_stage;
extern int s_position_difficult;

extern bool s_flug;