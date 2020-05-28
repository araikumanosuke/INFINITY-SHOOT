#include <DxLib.h>
#include "header.h"
#include "global.h"
#include "play.h"

//########## プレイ画面の関数 ##########
VOID MY_GAME_PLAY(VOID)
{
	if (AllKeyState[KEY_INPUT_DOWN] != 0)	//下キーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_END_OVER;	//シーンをエンド画面(ゲームオーバー)にする
	}

	if (AllKeyState[KEY_INPUT_UP] != 0)	//上キーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//シーンをエンド画面(ゲームクリア)にする
	}

	DrawString(0, 0, "プレイ画面(下キー(ゲームオーバー)または上キー(ゲームクリア)を押してください)", GetColor(255, 255, 255));

	return;
}
