#include <DxLib.h>
#include "ranking.h"
#include "global.h"

VOID MY_GAME_RANKING(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)	//バックスペースキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
		t_position = 0;
	}

	DrawString(0, 0, "ランキング画面(バックスペースキーを押してください)", GetColor(255, 255, 255));
}