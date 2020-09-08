#include <DxLib.h>
#include "global.hpp"
#include "howto.hpp"

VOID MY_GAME_HOWTO(VOID)
{
	//背景表示
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);

	DrawStringToHandle(310, 40, "How To", GetColor(255, 255, 255), superBig_FHandle);
	DrawStringToHandle(210, 180, "・ゲーム中の操作", GetColor(255, 255, 255), small_YU_FHandle);
	DrawStringToHandle(270, 240, "プレイヤーの移動：十字キー", GetColor(255, 255, 255), small_YU_FHandle);
	DrawStringToHandle(270, 300, "弾の発射：Ａキー(長押し可)", GetColor(255, 255, 255), small_YU_FHandle);
	DrawStringToHandle(210, 380, "・その他の操作", GetColor(255, 255, 255), small_YU_FHandle);
	DrawStringToHandle(270, 440, "決定：エンターキー", GetColor(255, 255, 255), small_YU_FHandle);
	DrawStringToHandle(270, 500, "戻る：バックスペースキー", GetColor(255, 255, 255), small_YU_FHandle);

	if (AllKeyState[KEY_INPUT_BACK] == 1)
	{
		PlaySoundMem(SE_CANCEL.handle, DX_PLAYTYPE_BACK);
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
	}
}