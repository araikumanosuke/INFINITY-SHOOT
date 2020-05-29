#include <DxLib.h>
#include "end_clear.h"
#include "global.h"

//########## エンド画面の関数 ##########
VOID MY_GAME_END_CLEAR(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)	//バックスペースーキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
		t_position_title = 0;
		t_position_stage = 0;
		t_position_difficult = 0;
		t_flug = TRUE;
	}

	DrawString(0, 0, "エンド画面(ゲームクリア)(バックスペースキーを押してください)", GetColor(255, 255, 255));

	return;
}