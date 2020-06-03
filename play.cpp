#include <DxLib.h>
#include "header.hpp"
#include "global.hpp"
#include "play.hpp"
#include "tama.hpp"

int T_flag;

Tama a;
 
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

	for (int e = 0; e < 300; e += 30)
	{
		DrawGraph(E_YELLOW.x + e, E_YELLOW.y, E_YELLOW.handle, TRUE);
	}
	
	DrawGraph(PLAYER.x, PLAYER.y, PLAYER.handle, TRUE);

	if (AllKeyState[KEY_INPUT_SPACE] == 1)
	{
		a.IsView = TRUE;
		a.position();
	}

	a.view();

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
