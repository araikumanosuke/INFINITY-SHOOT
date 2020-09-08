#include <DxLib.h>
#include "ranking.hpp"
#include "global.hpp"

TIME_RANK stage1_N;
TIME_RANK stage1_H;
TIME_RANK stage2_N;
TIME_RANK stage2_H;
TIME_RANK stage3_N;
TIME_RANK stage3_H;

int s_position_ranking = 0;

VOID MY_GAME_RANKING(VOID)
{
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);
	DrawStringToHandle(290, 20, "RANKING", GetColor(255, 255, 255), superBig_FHandle);
	/*DrawBox(695, 32, 885, 107, GetColor(255, 255, 255), FALSE);
	DrawStringToHandle(700, 37, "BACK TO TITLE:", GetColor(255, 255, 255), Small_FHandle);
	DrawStringToHandle(700, 77, "BACK SPACE Key", GetColor(255, 255, 255), Small_FHandle);*/

	if (CheckSoundMem(BGM_RANK.handle) == 0)
	{
		PlaySoundMem(BGM_RANK.handle, DX_PLAYTYPE_LOOP);
	}

	switch (s_position_ranking)
	{
	case 0:
		DrawStringToHandle(550, 150, "1-NORMAL", GetColor(255, 255, 255), Big_FHandle);
		DrawFormatStringToHandle(510, 250, GetColor(255, 255, 255), bigMiddle_FHandle, "1st.  0:%05.2lf", stage1_N.first_sec);
		DrawFormatStringToHandle(510, 315, GetColor(255, 255, 255), bigMiddle_FHandle, "2nd.  0:%05.2lf", stage1_N.second_sec);
		DrawFormatStringToHandle(510, 380, GetColor(255, 255, 255), bigMiddle_FHandle, "3rd.  0:%05.2lf", stage1_N.third_sec);
		DrawFormatStringToHandle(510, 445, GetColor(255, 255, 255), bigMiddle_FHandle, "4th.  0:%05.2lf", stage1_N.forth_sec);
		DrawFormatStringToHandle(510, 510, GetColor(255, 255, 255), bigMiddle_FHandle, "5th.  0:%05.2lf", stage1_N.fifth_sec);

		DrawLineAA(280.0f, 180.0f, 390.0f, 180.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 180.0f, 390.0f, 360.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 360.0f, 500.0f, 360.0f, GetColor(255, 255, 255));
		break;

	case 70:
		DrawStringToHandle(580, 150, "1-HARD", GetColor(255, 255, 255), Big_FHandle);
		DrawFormatStringToHandle(510, 250, GetColor(255, 255, 255), bigMiddle_FHandle, "1st.  0:%05.2lf", stage1_H.first_sec);
		DrawFormatStringToHandle(510, 315, GetColor(255, 255, 255), bigMiddle_FHandle, "2nd.  0:%05.2lf", stage1_H.second_sec);
		DrawFormatStringToHandle(510, 380, GetColor(255, 255, 255), bigMiddle_FHandle, "3rd.  0:%05.2lf", stage1_H.third_sec);
		DrawFormatStringToHandle(510, 445, GetColor(255, 255, 255), bigMiddle_FHandle, "4th.  0:%05.2lf", stage1_H.forth_sec);
		DrawFormatStringToHandle(510, 510, GetColor(255, 255, 255), bigMiddle_FHandle, "5th.  0:%05.2lf", stage1_H.fifth_sec);

		DrawLineAA(280.0f, 250.0f, 390.0f, 250.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 250.0f, 390.0f, 360.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 360.0f, 500.0f, 360.0f, GetColor(255, 255, 255));
		break;

	case 140:
		DrawStringToHandle(550, 150, "2-NORMAL", GetColor(255, 255, 255), Big_FHandle);
		DrawFormatStringToHandle(510, 250, GetColor(255, 255, 255), bigMiddle_FHandle, "1st.  0:%05.2lf", stage2_N.first_sec);
		DrawFormatStringToHandle(510, 315, GetColor(255, 255, 255), bigMiddle_FHandle, "2nd.  0:%05.2lf", stage2_N.second_sec);
		DrawFormatStringToHandle(510, 380, GetColor(255, 255, 255), bigMiddle_FHandle, "3rd.  0:%05.2lf", stage2_N.third_sec);
		DrawFormatStringToHandle(510, 445, GetColor(255, 255, 255), bigMiddle_FHandle, "4th.  0:%05.2lf", stage2_N.forth_sec);
		DrawFormatStringToHandle(510, 510, GetColor(255, 255, 255), bigMiddle_FHandle, "5th.  0:%05.2lf", stage2_N.fifth_sec);

		DrawLineAA(280.0f, 320.0f, 390.0f, 320.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 320.0f, 390.0f, 360.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 360.0f, 500.0f, 360.0f, GetColor(255, 255, 255));
		break;

	case 210:
		DrawStringToHandle(580, 150, "2-HARD", GetColor(255, 255, 255), Big_FHandle);
		DrawFormatStringToHandle(510, 250, GetColor(255, 255, 255), bigMiddle_FHandle, "1st.  0:%05.2lf", stage2_H.first_sec);
		DrawFormatStringToHandle(510, 315, GetColor(255, 255, 255), bigMiddle_FHandle, "2nd.  0:%05.2lf", stage2_H.second_sec);
		DrawFormatStringToHandle(510, 380, GetColor(255, 255, 255), bigMiddle_FHandle, "3rd.  0:%05.2lf", stage2_H.third_sec);
		DrawFormatStringToHandle(510, 445, GetColor(255, 255, 255), bigMiddle_FHandle, "4th.  0:%05.2lf", stage2_H.forth_sec);
		DrawFormatStringToHandle(510, 510, GetColor(255, 255, 255), bigMiddle_FHandle, "5th.  0:%05.2lf", stage2_H.fifth_sec);

		DrawLineAA(280.0f, 390.0f, 390.0f, 390.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 390.0f, 390.0f, 360.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 360.0f, 500.0f, 360.0f, GetColor(255, 255, 255));
		break;

	case 280:
		DrawStringToHandle(550, 150, "3-NORMAL", GetColor(255, 255, 255), Big_FHandle);
		DrawFormatStringToHandle(510, 250, GetColor(255, 255, 255), bigMiddle_FHandle, "1st.  0:%05.2lf", stage3_N.first_sec);
		DrawFormatStringToHandle(510, 315, GetColor(255, 255, 255), bigMiddle_FHandle, "2nd.  0:%05.2lf", stage3_N.second_sec);
		DrawFormatStringToHandle(510, 380, GetColor(255, 255, 255), bigMiddle_FHandle, "3rd.  0:%05.2lf", stage3_N.third_sec);
		DrawFormatStringToHandle(510, 445, GetColor(255, 255, 255), bigMiddle_FHandle, "4th.  0:%05.2lf", stage3_N.forth_sec);
		DrawFormatStringToHandle(510, 510, GetColor(255, 255, 255), bigMiddle_FHandle, "5th.  0:%05.2lf", stage3_N.fifth_sec);

		DrawLineAA(280.0f, 460.0f, 390.0f, 460.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 460.0f, 390.0f, 360.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 360.0f, 500.0f, 360.0f, GetColor(255, 255, 255));
		break;

	case 350:
		DrawStringToHandle(580, 150, "3-HARD", GetColor(255, 255, 255), Big_FHandle);
		DrawFormatStringToHandle(510, 250, GetColor(255, 255, 255), bigMiddle_FHandle, "1st.  0:%05.2lf", stage3_H.first_sec);
		DrawFormatStringToHandle(510, 315, GetColor(255, 255, 255), bigMiddle_FHandle, "2nd.  0:%05.2lf", stage3_H.second_sec);
		DrawFormatStringToHandle(510, 380, GetColor(255, 255, 255), bigMiddle_FHandle, "3rd.  0:%05.2lf", stage3_H.third_sec);
		DrawFormatStringToHandle(510, 445, GetColor(255, 255, 255), bigMiddle_FHandle, "4th.  0:%05.2lf", stage3_H.forth_sec);
		DrawFormatStringToHandle(510, 510, GetColor(255, 255, 255), bigMiddle_FHandle, "5th.  0:%05.2lf", stage3_H.fifth_sec);

		DrawLineAA(280.0f, 530.0f, 390.0f, 530.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 530.0f, 390.0f, 360.0f, GetColor(255, 255, 255));
		DrawLineAA(390.0f, 360.0f, 500.0f, 360.0f, GetColor(255, 255, 255));
		break;

	default:
		break;
	}
	
	//三角の操作
	if (AllKeyState[KEY_INPUT_UP] == 1)
	{
		if (S2_Normal_PlayFlag == TRUE)
		{
			PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
		}

		switch (s_position_ranking)
		{
		case 0:	//1-NORMALの位置のとき
			if (S3_Hard_PlayFlag == TRUE)
			{
				s_position_ranking += 350;
			}
			else if (S3_Normal_PlayFlag == TRUE)
			{
				s_position_ranking += 280;
			}
			else if (S2_Normal_PlayFlag == TRUE)
			{
				s_position_ranking += 140;
			}
			break;

		case 70:	//1-HARDの位置のときは座標を一番上に戻す
			s_position_ranking -= 70;
			break;

		case 140:	//2-NORMALの位置のとき
			if (S1_Hard_PlayFlag == TRUE)
			{
				s_position_ranking -= 70;
			}
			else if (S1_Hard_PlayFlag == FALSE)
			{
				s_position_ranking -= 140;
			}
			break;

		case 210:	//2-HARDの位置のときは座標を１段階上にずらす
			s_position_ranking -= 70;
			break;

		case 280:	//3-NORMALの位置のとき
			if (S2_Hard_PlayFlag == TRUE)
			{
				s_position_ranking -= 70;
			}
			else if (S2_Hard_PlayFlag == FALSE)
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
		if (S2_Normal_PlayFlag == TRUE)
		{
			PlaySoundMem(SE_SELECT.handle, DX_PLAYTYPE_BACK);
		}

		switch (s_position_ranking)
		{
		case 0:	//1-NORMALの位置のとき
			if (S2_Normal_PlayFlag == TRUE)	//2-NORMALが解放されているとき
			{
				if (S1_Hard_PlayFlag == TRUE)	//1-HARDが解放されていれば座標を１段階下にずらす
				{
					s_position_ranking += 70;
				}
				else if (S1_Hard_PlayFlag == FALSE)	//1-HARDが解放されていなければ座標を２段階下にずらす
				{
					s_position_ranking += 140;
				}
			}
			break;

		case 70:	//1-HARDの位置のときは座標を１段階下にずらす
			s_position_ranking += 70;
			break;

		case 140:	//2-NORMALの位置のとき
			if (S3_Normal_PlayFlag == TRUE)	//3-NORMALが解放されているとき
			{
				if (S2_Hard_PlayFlag == TRUE)	//2-HARDが解放されていれば座標を１段階下にずらす
				{
					s_position_ranking += 70;
				}
				else if (S2_Hard_PlayFlag == FALSE)	//2-HARDが解放されていなければ座標を２段階下にずらす
				{
					s_position_ranking += 140;
				}
			}
			else if (S3_Normal_PlayFlag == FALSE)	//3-NORMALが解放されていなければ座標を一番上に戻す
			{
				s_position_ranking -= 140;
			}
			break;

		case 210:	//2-HARDの位置のときは座標を１段階下にずらす
			s_position_ranking += 70;
			break;

		case 280:	//3-NORMALの位置のとき
			if (S3_Hard_PlayFlag == TRUE)	//3-HARDが解放されていれば座標を１段階下にずらす
			{
				s_position_ranking += 70;
			}
			else if (S3_Hard_PlayFlag == FALSE)	//3-HARDが解放されていなければ座標を一番上に戻す
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
	if (S1_Hard_PlayFlag == TRUE)
	{
		DrawStringToHandle(100, 230, "1-HARD", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S2_Normal_PlayFlag == TRUE)
	{
		DrawStringToHandle(100, 300, "2-NORMAL", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S2_Hard_PlayFlag == TRUE)
	{
		DrawStringToHandle(100, 370, "2-HARD", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S3_Normal_PlayFlag == TRUE)
	{
		DrawStringToHandle(100, 440, "3-NORMAL", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S3_Hard_PlayFlag == TRUE)
	{
		DrawStringToHandle(100, 510, "3-HARD", GetColor(255, 255, 255), Middle_FHandle);
	}
	
	if (AllKeyState[KEY_INPUT_BACK] == 1)	//バックスペースキーが押されていた時
	{
		PlaySoundMem(SE_CANCEL.handle, DX_PLAYTYPE_BACK);
		GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
		s_position_title = 0;
		StopSoundMem(BGM_RANK.handle);
	}

	//DrawString(0, 0, "ランキング画面(バックスペースキーを押してください)", GetColor(255, 255, 255));
}