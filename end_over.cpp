#include <DxLib.h>
#include "end_over.hpp"
#include "global.hpp"
#include "enemy_init.hpp"

//########## �G���h��ʂ̊֐� ##########
VOID MY_GAME_END_OVER(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] == 1)	//�o�b�N�X�y�[�X�[�L�[��������Ă�����
	{
		ENEMY_INIT();
		s_position_title = 0;
		s_position_stage = 0;
		s_position_difficult = 0;
		s_flug = TRUE;
		enemy_count_stage1 = 90;
		enemy_count_stage2 = 91;
		enemy_count_stage3 = 81;
		Time_Flag = false;
		Current_Timer_Sec = 0.0;
		Current_Timer_Min = 0;
		enemy_move_flag = true;
		enemy_move_num = 0;
		enemy_move_tmp = 0;
		GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
	}

	DrawString(0, 0, "�G���h���(�Q�[���I�[�o�[)(�o�b�N�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
}