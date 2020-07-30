#include <DxLib.h>
#include "end_clear.hpp"
#include "global.hpp"
#include "enemy_init.hpp"

double S1_KiteiTime = 15.0;
double S2_KiteiTime = 10.0;
double S3_KiteiTime = 15.0;

int s_position_end_clear = 0;

//########## �G���h��ʂ̊֐� ##########
VOID MY_GAME_END_CLEAR(VOID)
{
	//�w�i�\��
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);

	DrawStringToHandle(155, 120, "GAME CLEAR!!", GetColor(255, 255, 255), superBig_FHandle);
	DrawFormatStringToHandle(230, 220, GetColor(255, 255, 255), bigMiddle_FHandle, "CLEAR TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

	//HARD���[�h���J���ł��邩
	if (s_position_stage == 0)
	{
		if (s_position_difficult == 0)
		{
			if (S1_Hard_PlayFlag == FALSE)
			{
				if (Current_Timer_Sec < S1_KiteiTime)
				{
					DrawStringToHandle(245, 280, "(Release the HARD mode!)", GetColor(255, 255, 255), smallMiddle_FHandle);
				}
				else
				{
					DrawStringToHandle(105, 280, "(If you clear it within 15 seconds...?)", GetColor(255, 255, 255), smallMiddle_FHandle);
				}
			}
		}
	}
	else if (s_position_stage == 100)
	{
		if (s_position_difficult == 0)
		{
			if (S2_Hard_PlayFlag == FALSE)
			{
				if (Current_Timer_Sec < S2_KiteiTime)
				{
					DrawStringToHandle(245, 280, "(Release the HARD mode!)", GetColor(255, 255, 255), smallMiddle_FHandle);
				}
				else
				{
					DrawStringToHandle(105, 280, "(If you clear it within 10 seconds...?)", GetColor(255, 255, 255), smallMiddle_FHandle);
				}
			}
		}
	}
	else if (s_position_stage == 200)
	{
		if (s_position_difficult == 0)
		{
			if (S3_Hard_PlayFlag == FALSE)
			{
				if (Current_Timer_Sec < S3_KiteiTime)
				{
					DrawStringToHandle(245, 280, "(Release the HARD mode!)", GetColor(255, 255, 255), smallMiddle_FHandle);
				}
				else
				{
					DrawStringToHandle(105, 280, "(If you clear it within 10 seconds...?)", GetColor(255, 255, 255), smallMiddle_FHandle);
				}
			}
		}
	}

	//�O�p�̈ړ�
	if (AllKeyState[KEY_INPUT_DOWN] == 1 || AllKeyState[KEY_INPUT_UP] == 1)
	{
		PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
		if (s_position_end_clear == 0)
		{
			s_position_end_clear += 100;
		}
		else if (s_position_end_clear == 100)
		{
			s_position_end_clear -= 100;
		}
	}

	DrawGraph(300, 387 + s_position_end_clear, SANKAKU.handle, TRUE);

	DrawStringToHandle(330, 380, "BACK TO TITLE", GetColor(255, 255, 255), bigMiddle_FHandle);
	DrawStringToHandle(330, 480, "RANKING", GetColor(255, 255, 255), bigMiddle_FHandle);


	if (AllKeyState[KEY_INPUT_RETURN] == 1)	//�G���^�[�L�[��������Ă�����
	{
		StopSoundMem(CLEAR.handle);
		PlaySoundMem(SE_ENTER.handle, DX_PLAYTYPE_BACK);
		ENEMY_INIT();
		s_position_title = 0;
		s_flag = TRUE;
		enemy_count_stage1 = 90;
		enemy_count_stage2 = 91;
		enemy_count_stage3 = 81;
		enemy_count_stage1_hard = 90;
		enemy_count_stage2_hard = 91;
		enemy_count_stage3_hard = 81;
		Syoki_Flag = TRUE;
		enemy_move_flag = TRUE;
		enemy_move_num = 0;
		enemy_move_tmp = 0;

		//�����L���O�X�V
		if (s_position_stage == 0)
		{
			if (s_position_difficult == 0)
			{
				if (Current_Timer_Sec < stage1_N.first_sec)
				{
					stage1_N.fifth_sec = stage1_N.forth_sec;
					stage1_N.forth_sec = stage1_N.third_sec;
					stage1_N.third_sec = stage1_N.second_sec;
					stage1_N.second_sec = stage1_N.first_sec;
					stage1_N.first_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage1_N.second_sec)
				{
					stage1_N.fifth_sec = stage1_N.forth_sec;
					stage1_N.forth_sec = stage1_N.third_sec;
					stage1_N.third_sec = stage1_N.second_sec;
					stage1_N.second_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage1_N.third_sec)
				{
					stage1_N.fifth_sec = stage1_N.forth_sec;
					stage1_N.forth_sec = stage1_N.third_sec;
					stage1_N.third_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage1_N.forth_sec)
				{
					stage1_N.fifth_sec = stage1_N.forth_sec;
					stage1_N.forth_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage1_N.fifth_sec)
				{
					stage1_N.fifth_sec = Current_Timer_Sec;
				}
			}
			else if (s_position_difficult == 100)
			{
				if (Current_Timer_Sec < stage1_H.first_sec)
				{
					stage1_H.fifth_sec = stage1_H.forth_sec;
					stage1_H.forth_sec = stage1_H.third_sec;
					stage1_H.third_sec = stage1_H.second_sec;
					stage1_H.second_sec = stage1_H.first_sec;
					stage1_H.first_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage1_H.second_sec)
				{
					stage1_H.fifth_sec = stage1_H.forth_sec;
					stage1_H.forth_sec = stage1_H.third_sec;
					stage1_H.third_sec = stage1_H.second_sec;
					stage1_H.second_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage1_H.third_sec)
				{
					stage1_H.fifth_sec = stage1_H.forth_sec;
					stage1_H.forth_sec = stage1_H.third_sec;
					stage1_H.third_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage1_H.forth_sec)
				{
					stage1_H.fifth_sec = stage1_H.forth_sec;
					stage1_H.forth_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage1_H.fifth_sec)
				{
					stage1_H.fifth_sec = Current_Timer_Sec;
				}
			}
		}
		else if (s_position_stage == 100)
		{
			if (s_position_difficult == 0)
			{
				if (Current_Timer_Sec < stage2_N.first_sec)
				{
					stage2_N.fifth_sec = stage2_N.forth_sec;
					stage2_N.forth_sec = stage2_N.third_sec;
					stage2_N.third_sec = stage2_N.second_sec;
					stage2_N.second_sec = stage2_N.first_sec;
					stage2_N.first_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage2_N.second_sec)
				{
					stage2_N.fifth_sec = stage2_N.forth_sec;
					stage2_N.forth_sec = stage2_N.third_sec;
					stage2_N.third_sec = stage2_N.second_sec;
					stage2_N.second_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage2_N.third_sec)
				{
					stage2_N.fifth_sec = stage2_N.forth_sec;
					stage2_N.forth_sec = stage2_N.third_sec;
					stage2_N.third_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage2_N.forth_sec)
				{
					stage2_N.fifth_sec = stage2_N.forth_sec;
					stage2_N.forth_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage2_N.fifth_sec)
				{
					stage2_N.fifth_sec = Current_Timer_Sec;
				}
			}
			else if (s_position_difficult == 100)
			{
				if (Current_Timer_Sec < stage2_H.first_sec)
				{
					stage2_H.fifth_sec = stage2_H.forth_sec;
					stage2_H.forth_sec = stage2_H.third_sec;
					stage2_H.third_sec = stage2_H.second_sec;
					stage2_H.second_sec = stage2_H.first_sec;
					stage2_H.first_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage2_H.second_sec)
				{
					stage2_H.fifth_sec = stage2_H.forth_sec;
					stage2_H.forth_sec = stage2_H.third_sec;
					stage2_H.third_sec = stage2_H.second_sec;
					stage2_H.second_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage2_H.third_sec)
				{
					stage2_H.fifth_sec = stage2_H.forth_sec;
					stage2_H.forth_sec = stage2_H.third_sec;
					stage2_H.third_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage2_H.forth_sec)
				{
					stage2_H.fifth_sec = stage2_H.forth_sec;
					stage2_H.forth_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage2_H.fifth_sec)
				{
					stage2_H.fifth_sec = Current_Timer_Sec;
				}
			}
		}
		else if (s_position_stage == 200)
		{
			if (s_position_difficult == 0)
			{
				if (Current_Timer_Sec < stage3_N.first_sec)
				{
					stage3_N.fifth_sec = stage3_N.forth_sec;
					stage3_N.forth_sec = stage3_N.third_sec;
					stage3_N.third_sec = stage3_N.second_sec;
					stage3_N.second_sec = stage3_N.first_sec;
					stage3_N.first_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage3_N.second_sec)
				{
					stage3_N.fifth_sec = stage3_N.forth_sec;
					stage3_N.forth_sec = stage3_N.third_sec;
					stage3_N.third_sec = stage3_N.second_sec;
					stage3_N.second_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage3_N.third_sec)
				{
					stage3_N.fifth_sec = stage3_N.forth_sec;
					stage3_N.forth_sec = stage3_N.third_sec;
					stage3_N.third_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage3_N.forth_sec)
				{
					stage3_N.fifth_sec = stage3_N.forth_sec;
					stage3_N.forth_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage3_N.fifth_sec)
				{
					stage3_N.fifth_sec = Current_Timer_Sec;
				}
			}
			else if (s_position_difficult == 100)
			{
				if (Current_Timer_Sec < stage3_H.first_sec)
				{
					stage3_H.fifth_sec = stage3_H.forth_sec;
					stage3_H.forth_sec = stage3_H.third_sec;
					stage3_H.third_sec = stage3_H.second_sec;
					stage3_H.second_sec = stage3_H.first_sec;
					stage3_H.first_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage3_H.second_sec)
				{
					stage3_H.fifth_sec = stage3_H.forth_sec;
					stage3_H.forth_sec = stage3_H.third_sec;
					stage3_H.third_sec = stage3_H.second_sec;
					stage3_H.second_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage3_H.third_sec)
				{
					stage3_H.fifth_sec = stage3_H.forth_sec;
					stage3_H.forth_sec = stage3_H.third_sec;
					stage3_H.third_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage3_H.forth_sec)
				{
					stage3_H.fifth_sec = stage3_H.forth_sec;
					stage3_H.forth_sec = Current_Timer_Sec;
				}
				else if (Current_Timer_Sec < stage3_H.fifth_sec)
				{
					stage3_H.fifth_sec = Current_Timer_Sec;
				}
			}
		}

		if (s_position_stage == 0)
		{
			if (s_position_difficult == 0)
			{
				if (S2_Normal_PlayFlag == FALSE)
				{
					S2_Normal_PlayFlag = TRUE;
				}
				if (Current_Timer_Sec < S1_KiteiTime)
				{
					if (S1_Hard_PlayFlag == FALSE)
					{
						S1_Hard_PlayFlag = TRUE;
					}
				}
			}
		}
		else if (s_position_stage == 100)
		{
			if (s_position_difficult == 0)
			{
				if (S3_Normal_PlayFlag == FALSE)
				{
					S3_Normal_PlayFlag = TRUE;
				}
				if (Current_Timer_Sec < S2_KiteiTime)
				{
					if (S2_Hard_PlayFlag == FALSE)
					{
						S2_Hard_PlayFlag = TRUE;
					}
				}
			}
		}
		else if (s_position_stage == 200)
		{
			if (Current_Timer_Sec < S3_KiteiTime)
			{
				if (S3_Hard_PlayFlag == FALSE)
				{
					S3_Hard_PlayFlag = TRUE;
				}
			}
		}

		if (s_position_end_clear == 0)
		{
			GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
		}
		else if (s_position_end_clear == 100)
		{
			GameSceneNow = (int)GAME_SCENE_RANKING;	//�V�[���������L���O��ʂɂ���
		}
	}

	/*DrawString(0, 0, "�G���h���(�Q�[���N���A)(�o�b�N�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));*/

	return;
}