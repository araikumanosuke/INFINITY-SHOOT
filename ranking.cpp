#include <DxLib.h>
#include "ranking.hpp"
#include "global.hpp"

VOID MY_GAME_RANKING(VOID)
{
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);
	DrawStringToHandle(290, 20, "RANKING", GetColor(255, 255, 255), Big_FHandle);

	DrawStringToHandle(100, 200, "1-NORMAL", GetColor(255, 255, 255), Middle_FHandle);
	if (AllKeyState[KEY_INPUT_BACK] == 1)	//バックスペースキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
		s_position_title = 0;
	}

	DrawString(0, 0, "ランキング画面(バックスペースキーを押してください)", GetColor(255, 255, 255));
}