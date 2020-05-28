#include <DxLib.h>
#include "stagechoice.h"
#include "global.h"

VOID MY_GAME_STAGECHOICE(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//スペースキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
	}

	DrawString(0, 0, "ステージ選択画面(スペースキーを押してください)", GetColor(255, 255, 255));
}