#include <DxLib.h>
#include "header.h"
#include "global.h"
#include "play.h"

int T_flag;

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
		PLAYER.y -= 4;
	}
	if (AllKeyState[KEY_INPUT_DOWN] != 0)
	{
		PLAYER.y += 4;
	}
	if (AllKeyState[KEY_INPUT_LEFT] != 0)
	{
		PLAYER.x -= 4;
	}
	if (AllKeyState[KEY_INPUT_RIGHT] != 0)
	{
		PLAYER.x += 4;
	}

	DrawGraph(BG.x, BG.y, BG.handle, TRUE);
	DrawGraph(E_YELLOW.x, E_YELLOW.y, E_YELLOW.handle, TRUE);
	DrawGraph(PLAYER.x, PLAYER.y, PLAYER.handle, TRUE);

	if (AllKeyState[KEY_INPUT_SPACE] != 0)
	{
		T_flag = TRUE;
		TAMA.x = PLAYER.x + 5;
		TAMA.y = PLAYER.y;
	}

	if (T_flag == TRUE)
	{
		DrawGraph(TAMA.x, TAMA.y, TAMA.handle, TRUE);
		TAMA.y--;
	}

	if (s_position_stage == 0)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 1-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 50", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:10.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 1-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 50", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:20.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
	}
	else if (s_position_stage == 100)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 2-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 80", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:30.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 2-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 80", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:40.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
	}
	else if (s_position_stage == 200)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 3-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(780, 10, "ENEMY: 100", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:50.00", GetColor(255, 255, 255), play_FHandle);
			DrawStringToHandle(740, 570, "TIME 0:00.00", GetColor(255, 255, 255), play_FHandle);
		}
		else if (s_position_difficult == 100)
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
