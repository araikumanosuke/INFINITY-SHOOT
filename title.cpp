#include <DxLib.h>
#include "title.h"
#include "global.h"

//########## タイトル画面の関数 ##########
VOID MY_GAME_TITLE(VOID)
{
	if (AllKeyState[KEY_INPUT_RETURN] != 0)	//エンターキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	}

	DrawString(0, 0, "タイトル画面(エンターキーを押してください)", GetColor(255, 255, 255));

	return;
}
