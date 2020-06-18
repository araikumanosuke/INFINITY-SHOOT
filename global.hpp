#pragma once
#include <DxLib.h>
#include "header.hpp"
#include "enemy.hpp"

//########## �񋓌^ ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,		//�^�C�g�����
	GAME_SCENE_RANKING,		//�����L���O���
	GAME_SCENE_STAGECHOICE,	//�X�e�[�W�I�����
	GAME_SCENE_PLAY,		//�v���C���
	GAME_SCENE_END_CLEAR,	//�G���h���(�N���A)
	GAME_SCENE_END_OVER		//�G���h���(�Q�[���I�[�o�[)
};

enum ENEMY_KIND {
	Yellow,
	Green,
	Blue,
	Red,
	Yellow_Hard,
	Green_Hard,
	Blue_Hard,
	Red_Hard
};

struct IMAGE {
	int handle;
	char filepath[128];
	int x;
	int y;
	int width;
	int height;
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

extern int enemy_kind_stage1[9][21];
extern int enemy_kind_stage2[13][13];
extern bool enemy_flag_stage3[7][23];

extern Enemy enemys_stage1[9][21];
extern Enemy enemys_stage2[13][13];
extern Enemy enemys_stage3[7][23];

extern int enemy_count_stage1;
extern int enemy_count_stage2;
extern int enemy_count_stage3;

extern bool Time_Flag;
extern double Current_Timer_Sec;
extern int Current_Timer_Min;

extern bool enemy_move_flag;
extern int enemy_move_num;
extern int enemy_move_tmp;