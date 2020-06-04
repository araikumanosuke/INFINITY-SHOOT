#include <DxLib.h>
#include "header.hpp"
#include "global.hpp"
#include "play.hpp"
#include "tama.hpp"
#include "enemy.hpp"

Enemy enemys[10][5];

Tama Tamas[5];

//########## プレイ画面の関数 ##########
VOID MY_GAME_PLAY(VOID)
{
	if (AllKeyState[KEY_INPUT_A] != 0)	//Aキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_END_OVER;	//シーンをエンド画面(ゲームオーバー)にする
	}

	if (AllKeyState[KEY_INPUT_S] != 0)	//Sキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//シーンをエンド画面(ゲームクリア)にする
	}

	if (AllKeyState[KEY_INPUT_UP] != 0)
	{
		PLAYER.y -= 4;
	}
	if (AllKeyState[KEY_INPUT_DOWN] != 0)
	{
		PLAYER.y += 4;
	}
	if (AllKeyState[KEY_INPUT_LEFT] != 0)
	{
		PLAYER.x -= 4;
	}
	if (AllKeyState[KEY_INPUT_RIGHT] != 0)
	{
		PLAYER.x += 4;
	}

	DrawGraph(BG.x, BG.y, BG.handle, TRUE);

	for (int a = 0; a < 10; a++)
	{
		for (int b = 0; b < 5; b++)
		{
			enemys[a][b].position_E(a, b);
			enemys[a][b].view_E();
		}
	}
	
	DrawGraph(PLAYER.x, PLAYER.y, PLAYER.handle, TRUE);

	if (AllKeyState[KEY_INPUT_SPACE] == 1)
	{
		if (Tamas[0].IsView == FALSE)
		{
			Tamas[0].IsView = TRUE;
			Tamas[0].position();
		}
		else if (Tamas[0].IsView == TRUE && Tamas[1].IsView == FALSE)
		{
			Tamas[1].IsView = TRUE;
			Tamas[1].position();
		}
		else if (Tamas[1].IsView == TRUE && Tamas[2].IsView == FALSE)
		{
			Tamas[2].IsView = TRUE;
			Tamas[2].position();
		}
		else if (Tamas[2].IsView == TRUE && Tamas[3].IsView== FALSE)
		{
			Tamas[3].IsView = TRUE;
			Tamas[3].position();
		}
		else if (Tamas[3].IsView == TRUE && Tamas[4].IsView == FALSE)
		{
			Tamas[4].IsView = TRUE;
			Tamas[4].position();
		}
	}

	for (int i = 0; i < 5; i++)
	{
		Tamas[i].view();
		Tamas[i].flag_false();
	}

	/*Tamas[0].view();
	Tamas[1].view();
	Tamas[2].view();
	Tamas[3].view();
	Tamas[4].view();*/

	/*Tamas[0].flag_false();
	Tamas[1].flag_false();
	Tamas[2].flag_false();
	Tamas[3].flag_false();
	Tamas[4].flag_false();*/

	if (s_position_stage == 0)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 1-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 50", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:10.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 1-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 50", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:20.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
	}
	else if (s_position_stage == 100)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 2-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 80", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:30.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 2-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 80", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:40.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
	}
	else if (s_position_stage == 200)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 3-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 100", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:50.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 3-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 100", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 1:00.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
	}

	//DrawString(0, 0, "プレイ画面(下キー(ゲームオーバー)または上キー(ゲームクリア)を押してください)", GetColor(255, 255, 255));

	return;
}
