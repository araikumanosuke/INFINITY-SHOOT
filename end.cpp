#include <DxLib.h>
#include "end.h"
#include "global.h"

//########## エンド画面の関数 ##########
VOID MY_GAME_END(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)	//バックスペースーキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
	}

	DrawString(0, 0, "エンド画面(バックスペースキーを押してください)", GetColor(255, 255, 255));

	return;
}