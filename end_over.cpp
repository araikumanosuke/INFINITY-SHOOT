#include <DxLib.h>
#include "end_over.hpp"
#include "global.hpp"
#include "enemy_init.hpp"

//########## エンド画面の関数 ##########
VOID MY_GAME_END_OVER(VOID)
{
	//背景表示
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);

	DrawStringToHandle(185, 120, "GAME OVER...", GetColor(255, 255, 255), superBig_FHandle);

	DrawGraph(300, 387, SANKAKU.handle, TRUE);

	DrawStringToHandle(330, 380, "BACK TO TITLE", GetColor(255, 255, 255), bigMiddle_FHandle);

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
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
	}

	DrawString(0, 0, "エンド画面(ゲームオーバー)(バックスペースキーを押してください)", GetColor(255, 255, 255));

	return;
}