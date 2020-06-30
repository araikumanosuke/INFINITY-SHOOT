#include <DxLib.h>
#include "end_clear.hpp"
#include "global.hpp"
#include "enemy_init.hpp"

double S1_KiteiTime = 15.0;
double S2_KiteiTime = 10.0;
double S3_KiteiTime = 15.0;

int s_position_end_clear = 0;

//########## エンド画面の関数 ##########
VOID MY_GAME_END_CLEAR(VOID)
{
	//背景表示
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);

	DrawStringToHandle(155, 120, "GAME CLEAR!!", GetColor(255, 255, 255), Big_FHandle);
	DrawFormatStringToHandle(230, 220, GetColor(255, 255, 255), bigMiddle_FHandle, "CLEAR TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

	if (s_position_stage == 0)
	{
		if (s_position_difficult == 0)
		{
			if (S1_Hard_PlayFlag == false)
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
			if (S2_Hard_PlayFlag == false)
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
			if (S3_Hard_PlayFlag == false)
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

	if (AllKeyState[KEY_INPUT_DOWN] == 1 || AllKeyState[KEY_INPUT_UP] == 1)
	{
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


	if (AllKeyState[KEY_INPUT_RETURN] == 1)	//エンターキーが押されていた時
	{
		ENEMY_INIT();
		s_position_title = 0;
		s_flag = TRUE;
		enemy_count_stage1 = 90;
		enemy_count_stage2 = 91;
		enemy_count_stage3 = 81;
		Syoki_Flag = true;
		enemy_move_flag = true;
		enemy_move_num = 0;
		enemy_move_tmp = 0;

		if (s_position_stage == 0)
		{
			if (s_position_difficult == 0)
			{
				if (S2_Normal_PlayFlag == false)
				{
					S2_Normal_PlayFlag = true;
				}
				if (Current_Timer_Sec < S1_KiteiTime)
				{
					if (S1_Hard_PlayFlag == false)
					{
						S1_Hard_PlayFlag = true;
					}
				}
			}
		}
		else if (s_position_stage == 100)
		{
			if (s_position_difficult == 0)
			{
				if (S3_Normal_PlayFlag == false)
				{
					S3_Normal_PlayFlag = true;
				}
				if (Current_Timer_Sec < S2_KiteiTime)
				{
					if (S2_Hard_PlayFlag == false)
					{
						S2_Hard_PlayFlag = true;
					}
				}
			}
		}
		else if (s_position_stage == 200)
		{
			if (Current_Timer_Sec < S3_KiteiTime)
			{
				if (S3_Hard_PlayFlag == false)
				{
					S3_Hard_PlayFlag = true;
				}
			}
		}

		if (s_position_end_clear == 0)
		{
			GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
		}
		else if (s_position_end_clear == 100)
		{
			GameSceneNow = (int)GAME_SCENE_RANKING;	//シーンをランキング画面にする
		}
	}

	/*DrawString(0, 0, "エンド画面(ゲームクリア)(バックスペースキーを押してください)", GetColor(255, 255, 255));*/

	return;
}