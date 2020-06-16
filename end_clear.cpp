#include <DxLib.h>
#include "end_clear.hpp"
#include "global.hpp"
#include "enemy_init.hpp"

//########## エンド画面の関数 ##########
VOID MY_GAME_END_CLEAR(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] == 1)	//バックスペースーキーが押されていた時
	{
		ENEMY_INIT();
		s_position_title = 0;
		s_position_stage = 0;
		s_position_difficult = 0;
		s_flug = TRUE;
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
	}

	DrawString(0, 0, "エンド画面(ゲームクリア)(バックスペースキーを押してください)", GetColor(255, 255, 255));

	return;
}