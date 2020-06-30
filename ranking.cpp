#include <DxLib.h>
#include "ranking.hpp"
#include "global.hpp"

int s_position_ranking = 0;

VOID MY_GAME_RANKING(VOID)
{
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);
	DrawStringToHandle(290, 20, "RANKING", GetColor(255, 255, 255), Big_FHandle);
	DrawBox(695, 32, 885, 107, GetColor(255, 255, 255), false);
	DrawStringToHandle(700, 37, "BACK TO TITLE:", GetColor(255, 255, 255), Small_FHandle);
	DrawStringToHandle(700, 77, "BACK SPACE Key", GetColor(255, 255, 255), Small_FHandle);

	if (AllKeyState[KEY_INPUT_UP] == 1)
	{
		switch (s_position_ranking)
		{
		case 0:	//1-NORMALの位置のとき
			if (S3_Hard_PlayFlag == true)
			{
				s_position_ranking += 350;
			}
			else if (S3_Normal_PlayFlag == true)
			{
				s_position_ranking += 280;
			}
			else if (S2_Normal_PlayFlag == true)
			{
				s_position_ranking += 140;
			}
			break;

		case 70:	//1-HARDの位置のときは座標を一番上に戻す
			s_position_ranking -= 70;
			break;

		case 140:	//2-NORMALの位置のとき
			if (S1_Hard_PlayFlag == true)
			{
				s_position_ranking -= 70;
			}
			else if (S1_Hard_PlayFlag == false)
			{
				s_position_ranking -= 140;
			}
			break;

		case 210:	//2-HARDの位置のときは座標を１段階上にずらす
			s_position_ranking -= 70;
			break;

		case 280:	//3-NORMALの位置のとき
			if (S2_Hard_PlayFlag == true)
			{
				s_position_ranking -= 70;
			}
			else if (S2_Hard_PlayFlag == false)
			{
				s_position_ranking -= 140;
			}
			break;

		case 350:	//3-HARDの位置のときは座標を一段階上に戻す
			s_position_ranking -= 70;
			break;

		default:
			break;
		}
	}
	else if (AllKeyState[KEY_INPUT_DOWN] == 1)
	{
		switch (s_position_ranking)
		{
		case 0:	//1-NORMALの位置のとき
			if (S2_Normal_PlayFlag == true)	//2-NORMALが解放されているとき
			{
				if (S1_Hard_PlayFlag == true)	//1-HARDが解放されていれば座標を１段階下にずらす
				{
					s_position_ranking += 70;
				}
				else if (S1_Hard_PlayFlag == false)	//1-HARDが解放されていなければ座標を２段階下にずらす
				{
					s_position_ranking += 140;
				}
			}
			break;

		case 70:	//1-HARDの位置のときは座標を１段階下にずらす
			s_position_ranking += 70;
			break;

		case 140:	//2-NORMALの位置のとき
			if (S3_Normal_PlayFlag == true)	//3-NORMALが解放されているとき
			{
				if (S2_Hard_PlayFlag == true)	//2-HARDが解放されていれば座標を１段階下にずらす
				{
					s_position_ranking += 70;
				}
				else if (S2_Hard_PlayFlag == false)	//2-HARDが解放されていなければ座標を２段階下にずらす
				{
					s_position_ranking += 140;
				}
			}
			else if (S3_Normal_PlayFlag == false)	//3-NORMALが解放されていなければ座標を一番上に戻す
			{
				s_position_ranking -= 140;
			}
			break;

		case 210:	//2-HARDの位置のときは座標を１段階下にずらす
			s_position_ranking += 70;
			break;

		case 280:	//3-NORMALの位置のとき
			if (S3_Hard_PlayFlag == true)	//3-HARDが解放されていれば座標を１段階下にずらす
			{
				s_position_ranking += 70;
			}
			else if (S3_Hard_PlayFlag == false)	//3-HARDが解放されていなければ座標を一番上に戻す
			{
				s_position_ranking -= 280;
			}
			break;

		case 350:	//3-HARDの位置のときは座標を一番上に戻す
			s_position_ranking -= 350;
			break;

		default:
			break;
		}
	}

	DrawGraph(70, 166 + s_position_ranking, SANKAKU.handle, TRUE);

	DrawStringToHandle(100, 160, "1-NORMAL", GetColor(255, 255, 255), Middle_FHandle);
	if (S1_Hard_PlayFlag == true)
	{
		DrawStringToHandle(100, 230, "1-HARD", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S2_Normal_PlayFlag == true)
	{
		DrawStringToHandle(100, 300, "2-NORMAL", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S2_Hard_PlayFlag == true)
	{
		DrawStringToHandle(100, 370, "2-HARD", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S3_Normal_PlayFlag == true)
	{
		DrawStringToHandle(100, 440, "3-NORMAL", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S3_Hard_PlayFlag == true)
	{
		DrawStringToHandle(100, 510, "3-HARD", GetColor(255, 255, 255), Middle_FHandle);
	}
	
	if (AllKeyState[KEY_INPUT_BACK] == 1)	//バックスペースキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
		s_position_title = 0;
	}

	DrawString(0, 0, "ランキング画面(バックスペースキーを押してください)", GetColor(255, 255, 255));
}