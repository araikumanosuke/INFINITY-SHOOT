#include <DxLib.h>
#include "stagechoice.h"
#include "global.h"

int s_position_stage = 0;
int s_position_difficult = 0;

bool s_flug = TRUE;	//ステージ選択か難易度選択か

VOID MY_GAME_STAGECHOICE(VOID)
{
	if (AllKeyState[KEY_INPUT_RETURN] == 1)	//エンターキーが押されていた時
	{
		if (s_flug == TRUE)
		{
			s_flug = FALSE;
		}
		else if (s_flug == FALSE)
		{
			if (s_position_stage == 0)	//STAGE 1
			{
				if (s_position_difficult == 0)	//NORMAL
				{
					GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
				}
				else if (s_position_difficult == 100)	//HARD
				{
					GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
				}
			}
			else if (s_position_stage == 100)	//STAGE 2
			{
				if (s_position_difficult == 0)	//NORMAL
				{
					GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
				}
				else if (s_position_difficult == 100)	//HARD
				{
					GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
				}
			}
			else if (s_position_stage == 200)	//STAGE 3
			{
				if (s_position_difficult == 0)	//NORMAL
				{
					GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
				}
				else if (s_position_difficult == 100)	//HARD
				{
					GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
				}
			}
		}
	}

	if (AllKeyState[KEY_INPUT_BACK] == 1)
	{
		if (s_flug == TRUE)
		{
			GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
			s_position_title = 0;
			s_position_stage = 0;
			s_position_difficult = 0;
		}
		else if (s_flug == FALSE)
		{
			s_flug = TRUE;
			s_position_difficult = 0;
		}
	}

	if (AllKeyState[KEY_INPUT_UP] == 1)
	{
		if (s_flug == TRUE)	//ステージ選択
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
		else if (s_flug == FALSE)	//難易度選択
		{
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
	else if (AllKeyState[KEY_INPUT_DOWN] == 1)
	{
		if (s_flug == TRUE)	//ステージ選択
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
		else if (s_flug == FALSE)	//難易度選択
		{
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
	
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);
	DrawGraph(ROGO.x, ROGO.y, ROGO.handle, TRUE);

	DrawGraph(170, 307 + s_position_stage, SANKAKU.handle, TRUE);
	
	if (s_flug == FALSE)
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

	DrawStringToHandle(200, 300, "STAGE 1", GetColor(255, 255, 255), choice_FHandle);
	DrawStringToHandle(200, 400, "STAGE 2", GetColor(255, 255, 255), choice_FHandle);
	DrawStringToHandle(200, 500, "STAGE 3", GetColor(255, 255, 255), choice_FHandle);

	DrawStringToHandle(600, 350, "NORMAL", GetColor(255, 255, 255), choice_FHandle);
	DrawStringToHandle(600, 450, "HARD", GetColor(255, 255, 255), choice_FHandle);
}