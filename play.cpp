#include <DxLib.h>
#include "header.h"
#include "global.h"
#include "play.h"

int P_x = 425;
int P_y = 500;

//########## �v���C��ʂ̊֐� ##########
VOID MY_GAME_PLAY(VOID)
{
	if (AllKeyState[KEY_INPUT_A] != 0)	//A�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_END_OVER;	//�V�[�����G���h���(�Q�[���I�[�o�[)�ɂ���
	}

	if (AllKeyState[KEY_INPUT_S] != 0)	//S�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//�V�[�����G���h���(�Q�[���N���A)�ɂ���
	}

	if (AllKeyState[KEY_INPUT_UP] != 0)
	{
		P_y -= 4;
	}
	if (AllKeyState[KEY_INPUT_DOWN] != 0)
	{
		P_y += 4;
	}
	if (AllKeyState[KEY_INPUT_LEFT] != 0)
	{
		P_x -= 4;
	}
	if (AllKeyState[KEY_INPUT_RIGHT] != 0)
	{
		P_x += 4;
	}

	DrawGraph(0, 0, BGHandle, TRUE);
	DrawGraph(425, 300, E_YHandle, TRUE);
	DrawGraph(P_x, P_y, PHandle, TRUE);

	if (t_position_stage == 0)
	{
		if (t_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 1-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 50", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:10.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
		else if (t_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 1-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 50", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:20.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
	}
	else if (t_position_stage == 100)
	{
		if (t_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 2-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 80", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:30.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
		else if (t_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 2-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 80", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:40.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
	}
	else if (t_position_stage == 200)
	{
		if (t_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 3-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 100", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:50.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
		else if (t_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 3-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 100", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 1:00.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
	}

	//DrawString(0, 0, "�v���C���(���L�[(�Q�[���I�[�o�[)�܂��͏�L�[(�Q�[���N���A)�������Ă�������)", GetColor(255, 255, 255));

	return;
}
