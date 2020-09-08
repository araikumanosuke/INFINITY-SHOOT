#include <DxLib.h>
#include "title.hpp"
#include "global.hpp"

int s_position_title = 0;

//########## タイトル画面の関数 ##########
VOID MY_GAME_TITLE(VOID)
{
	//エンド画面で初期化するとまずい変数
	s_position_ranking = 0;
	s_position_stage = 0;
	s_position_difficult = 0;
	s_position_end_clear = 0;
	Current_Timer_Sec = 0.0;
	Current_Timer_Min = 0;
	ranking_flag_update = FALSE;
	enemy_move_flag = TRUE;

	if (S1_Hard_PlayFlag == TRUE)
	{
		S1_Hard_release_once = TRUE;
	}
	if (S2_Hard_PlayFlag == TRUE)
	{
		S2_Hard_release_once = TRUE;
	}
	if (S3_Hard_PlayFlag == TRUE)
	{
		S3_Hard_release_once = TRUE;
	}

	if (CheckSoundMem(BGM_TITLE.handle) == 0)
	{
		PlaySoundMem(BGM_TITLE.handle, DX_PLAYTYPE_LOOP);
	}

	if (AllKeyState[KEY_INPUT_RETURN] == 1)	//エンターキーが押されていた時
	{
		PlaySoundMem(SE_ENTER.handle, DX_PLAYTYPE_BACK);
		if (s_position_title == 0)
		{
			GameSceneNow = (int)GAME_SCENE_STAGECHOICE;	//シーンをステージ選択画面にする
		}
		else if (s_position_title == 80)
		{
			GameSceneNow = (int)GAME_SCENE_RANKING;	//シーンをランキング画面にする
			StopSoundMem(BGM_TITLE.handle);
		}
		else if (s_position_title == 160)
		{
			GameSceneNow = (int)GAME_SCENE_HOWTO;	//シーンを操作説明画面にする
			/*StopSoundMem(BGM_TITLE.handle);*/
		}
	}

	if (AllKeyState[KEY_INPUT_DOWN] == 1)
	{
		PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
		if (s_position_title == 160)
		{
			s_position_title -= 160;
		}
		else
		{
			s_position_title += 80;
		}
	}
	else if (AllKeyState[KEY_INPUT_UP] == 1)
	{
		PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
		if (s_position_title == 0)
		{
			s_position_title += 160;
		}
		else
		{
			s_position_title -= 80;
		}
	}

	DrawGraph(BG.x, BG.y, BG.handle, TRUE);
	DrawGraph(ROGO.x, ROGO.y, ROGO.handle, TRUE);

	DrawGraph(370, 327 + s_position_title, SANKAKU.handle, TRUE);

	DrawStringToHandle(400, 320, "START", GetColor(255, 255, 255), bigMiddle_FHandle);
	DrawStringToHandle(400, 400, "RANKING", GetColor(255, 255, 255), bigMiddle_FHandle);
	DrawStringToHandle(400, 480, "HOW TO", GetColor(255, 255, 255), bigMiddle_FHandle);

	//DrawString(0, 0, "タイトル画面(エンターキーを押してください)", GetColor(255, 255, 255));

	return;
}
