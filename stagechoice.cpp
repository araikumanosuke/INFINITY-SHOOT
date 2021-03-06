#include <DxLib.h>
#include "stagechoice.hpp"
#include "global.hpp"

int s_position_stage = 0;
int s_position_difficult = 0;

bool s_flag = TRUE;	//TRUE:ステージ選択 FALSE:難易度選択

VOID MY_GAME_STAGECHOICE(VOID)
{
	if (CheckSoundMem(BGM_TITLE.handle) == 0)
	{
		PlaySoundMem(BGM_TITLE.handle, DX_PLAYTYPE_LOOP);
	}

	if (AllKeyState[KEY_INPUT_RETURN] == 1)	//エンターキーが押されていた時
	{
		PlaySoundMem(SE_ENTER.handle, DX_PLAYTYPE_BACK);
		if (s_flag == TRUE)
		{
			s_flag = FALSE;
		}
		else if (s_flag == FALSE)
		{
			StopSoundMem(BGM_TITLE.handle);
			GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		}
	}

	if (AllKeyState[KEY_INPUT_BACK] == 1)
	{
		PlaySoundMem(SE_CANCEL.handle, DX_PLAYTYPE_BACK);
		if (s_flag == TRUE)
		{
			GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
			s_position_title = 0;
			s_position_stage = 0;
			s_position_difficult = 0;
		}
		else if (s_flag == FALSE)
		{
			s_flag = TRUE;
			s_position_difficult = 0;
		}
	}

	//三角形操作
	if (AllKeyState[KEY_INPUT_UP] == 1)
	{
		if (s_flag == TRUE)	//ステージ選択
		{
			if (S2_Normal_PlayFlag == TRUE)	//ステージ２がプレイできるか
			{
				PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
				if (S3_Normal_PlayFlag == TRUE)	//ステージ３がプレイできるか
				{
					if (s_position_stage == 0)
					{
						s_position_stage += 200;
					}
					else
					{
						s_position_stage -= 100;
					}
				}
				else if (S3_Normal_PlayFlag == FALSE)
				{
					if (s_position_stage == 0)
					{
						s_position_stage += 100;
					}
					else if (s_position_stage == 100)
					{
						s_position_stage -= 100;
					}
				}
			}
		}
		else if (s_flag == FALSE)	//難易度選択
		{
			if (s_position_stage == 0)
			{
				if (S1_Hard_PlayFlag == TRUE)	//ステージ１HARDモードがプレイできるか
				{
					PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
					if (s_position_difficult == 0)
					{
						s_position_difficult += 100;
					}
					else if (s_position_difficult == 100)
					{
						s_position_difficult -= 100;
					}
				}
			}
			if (s_position_stage == 100)
			{
				if (S2_Hard_PlayFlag == TRUE)	//ステージ２HARDモードがプレイできるか
				{
					PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
					if (s_position_difficult == 0)
					{
						s_position_difficult += 100;
					}
					else if (s_position_difficult == 100)
					{
						s_position_difficult -= 100;
					}
				}
			}
			if (s_position_stage == 200)
			{
				if (S3_Hard_PlayFlag == TRUE)	//ステージ３HARDモードがプレイできるか
				{
					PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
					if (s_position_difficult == 0)
					{
						s_position_difficult += 100;
					}
					else if (s_position_difficult == 100)
					{
						s_position_difficult -= 100;
					}
				}
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_DOWN] == 1)
	{
		if (s_flag == TRUE)	//ステージ選択
		{
			if (S2_Normal_PlayFlag == TRUE)	//ステージ２がプレイできるか
			{
				PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
				if (S3_Normal_PlayFlag == TRUE)	//ステージ３がプレイできるか
				{
					if (s_position_stage == 200)
					{
						s_position_stage -= 200;
					}
					else
					{
						s_position_stage += 100;
					}
				}
				else if (S3_Normal_PlayFlag == FALSE)
				{
					if (s_position_stage == 0)
					{
						s_position_stage += 100;
					}
					else if (s_position_stage == 100)
					{
						s_position_stage -= 100;
					}
				}
			}
			
		}
		else if (s_flag == FALSE)	//難易度選択
		{
			if (s_position_stage == 0)
			{
				if (S1_Hard_PlayFlag == TRUE)	//ステージ１HARDモードがプレイできるか
				{
					PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
					if (s_position_difficult == 0)
					{
						s_position_difficult += 100;
					}
					else if (s_position_difficult == 100)
					{
						s_position_difficult -= 100;
					}
				}
			}
			if (s_position_stage == 100)
			{
				if (S2_Hard_PlayFlag == TRUE)	//ステージ２HARDモードがプレイできるか
				{
					PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
					if (s_position_difficult == 0)
					{
						s_position_difficult += 100;
					}
					else if (s_position_difficult == 100)
					{
						s_position_difficult -= 100;
					}
				}
			}
			if (s_position_stage == 200)
			{
				if (S3_Hard_PlayFlag == TRUE)	//ステージ３HARDモードがプレイできるか
				{
					PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
					if (s_position_difficult == 0)
					{
						s_position_difficult += 100;
					}
					else if (s_position_difficult == 100)
					{
						s_position_difficult -= 100;
					}
				}
			}
		}
	}
	
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);
	DrawGraph(ROGO.x, ROGO.y, ROGO.handle, TRUE);

	DrawGraph(170, 307 + s_position_stage, SANKAKU.handle, TRUE);
	
	if (s_flag == FALSE)
	{
		DrawGraph(570, 357 + s_position_difficult, SANKAKU.handle, TRUE);

		if (s_position_stage == 0)
		{
			DrawLineAA(390.0f, 322.0f, 475.0f, 322.0f, GetColor(255, 255, 255));
			DrawLineAA(475.0f, 322.0f, 475.0f, 422.0f, GetColor(255, 255, 255));
			DrawLineAA(475.0f, 422.0f, 560.0f, 422.0f, GetColor(255, 255, 255));
		}
		else if (s_position_stage == 100)
		{
			DrawLineAA(390.0f, 422.0f, 560.0f, 422.0f, GetColor(255, 255, 255));
		}
		else if (s_position_stage == 200)
		{
			DrawLineAA(390.0f, 522.0f, 475.0f, 522.0f, GetColor(255, 255, 255));
			DrawLineAA(475.0f, 522.0f, 475.0f, 422.0f, GetColor(255, 255, 255));
			DrawLineAA(475.0f, 422.0f, 560.0f, 422.0f, GetColor(255, 255, 255));
		}
	}

	DrawStringToHandle(200, 300, "STAGE 1", GetColor(255, 255, 255), bigMiddle_FHandle);
	if (S2_Normal_PlayFlag == TRUE)
	{
		DrawStringToHandle(200, 400, "STAGE 2", GetColor(255, 255, 255), bigMiddle_FHandle);
	}
	if (S3_Normal_PlayFlag == TRUE)
	{
		DrawStringToHandle(200, 500, "STAGE 3", GetColor(255, 255, 255), bigMiddle_FHandle);
	}
	
	DrawStringToHandle(600, 350, "NORMAL", GetColor(255, 255, 255), bigMiddle_FHandle);
	if (s_position_stage == 0)
	{
		if (S1_Hard_PlayFlag == TRUE)
		{
			DrawStringToHandle(600, 450, "HARD", GetColor(255, 255, 255), bigMiddle_FHandle);
		}
	}
	else if (s_position_stage == 100)
	{
		if (S2_Hard_PlayFlag == TRUE)
		{
			DrawStringToHandle(600, 450, "HARD", GetColor(255, 255, 255), bigMiddle_FHandle);
		}
	}
	else if (s_position_stage == 200)
	{
		if (S3_Hard_PlayFlag == TRUE)
		{
			DrawStringToHandle(600, 450, "HARD", GetColor(255, 255, 255), bigMiddle_FHandle);
		}
	}
}