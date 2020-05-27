#include <DxLib.h>
#include "header.h"
#include "global.h"
#include "play.h"

//########## プレイ画面の関数 ##########
VOID MY_GAME_PLAY(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//スペースキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_END;	//シーンをエンド画面にする
	}

	DrawString(0, 0, "プレイ画面(スペースキーを押してください)", GetColor(255, 255, 255));

	return;
}
