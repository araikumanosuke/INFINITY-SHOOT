#include <DxLib.h>
#include "end_over.hpp"
#include "global.hpp"

//########## エンド画面の関数 ##########
VOID MY_GAME_END_OVER(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)	//バックスペースーキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
		s_position_title = 0;
		s_position_stage = 0;
		s_position_difficult = 0;
		s_flug = TRUE;
	}

	DrawString(0, 0, "エンド画面(ゲームオーバー)(バックスペースキーを押してください)", GetColor(255, 255, 255));

	return;
}