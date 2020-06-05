#include <DxLib.h>
#include "header.hpp"
#include "global.hpp"
#include "play.hpp"
#include "tama.hpp"
#include "enemy.hpp"

bool enemy_flag_stage1[9][21] = {
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
	{true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true},
	{true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true},
	{true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true},
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
};

bool enemy_flag_stage2[13][13] = {
	{false,false,false,false,false,false,true,false,false,false,false,false,false},
	{false,false,false,false,false,true,true,true,false,false,false,false,false},
	{false,false,false,false,true,true,true,true,true,false,false,false,false},
	{true,true,true,true,true,true,true,true,true,true,true,true,true},
	{false,true,true,true,true,true,true,true,true,true,true,true,false},
	{false,false,true,true,true,true,true,true,true,true,true,false,false},
	{false,false,false,true,true,true,true,true,true,true,false,false,false},
	{false,false,true,true,true,true,true,true,true,true,true,false,false},
	{false,true,true,true,true,true,true,true,true,true,true,true,false},
	{true,true,true,true,true,true,true,true,true,true,true,true,true},
	{false,false,false,false,true,true,true,true,true,false,false,false,false},
	{false,false,false,false,false,true,true,true,false,false,false,false,false},
	{false,false,false,false,false,false,true,false,false,false,false,false,false},
};

bool enemy_flag_stage3[7][23] = {
	{true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true},
	{false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false},
	{true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true},
	{false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false},
	{true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true},
	{false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false},
	{true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true}
};

Enemy enemys_stage1[10][9];

Enemy enemys_stage2[13][13];

Enemy enemys_stage3[7][23];

Tama Tamas[5];

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

	//�@�̈ړ�
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

	//�w�i�\��
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);

	//�G�\��(�X�e�[�W�P)
	/*for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 21; b++)
		{
			if (enemy_flag_stage1[a][b] == true)
			{
				enemys_stage1[a][b].position_E(a, b);
				enemys_stage1[a][b].view_E();
			}
		}
	}*/

	//�G�\��(�X�e�[�W�Q)
	/*for (int a = 0; a < 13; a++)
	{
		for (int b = 0; b < 13; b++)
		{
			if (enemy_flag_stage2[a][b] == true)
			{
				enemys_stage2[a][b].position_E(a, b);
				enemys_stage2[a][b].view_E();
			}
		}
	}*/

	//�G�\��(�X�e�[�W�R)
	for (int a = 0; a < 7; a++)
	{
		for (int b = 0; b < 23; b++)
		{
			if (enemy_flag_stage3[a][b] == true)
			{
				enemys_stage3[a][b].position_E(a, b);
				enemys_stage3[a][b].view_E();
			}
		}
	}
	
	//�@�̕\��
	DrawGraph(PLAYER.x, PLAYER.y, PLAYER.handle, TRUE);

	//�e�Z�b�g
	if (AllKeyState[KEY_INPUT_SPACE] == 1)
	{
		if (Tamas[0].IsView == FALSE)
		{
			Tamas[0].IsView = TRUE;
			Tamas[0].position();
		}
		else if (Tamas[0].IsView == TRUE && Tamas[1].IsView == FALSE)
		{
			Tamas[1].IsView = TRUE;
			Tamas[1].position();
		}
		else if (Tamas[1].IsView == TRUE && Tamas[2].IsView == FALSE)
		{
			Tamas[2].IsView = TRUE;
			Tamas[2].position();
		}
		else if (Tamas[2].IsView == TRUE && Tamas[3].IsView== FALSE)
		{
			Tamas[3].IsView = TRUE;
			Tamas[3].position();
		}
		else if (Tamas[3].IsView == TRUE && Tamas[4].IsView == FALSE)
		{
			Tamas[4].IsView = TRUE;
			Tamas[4].position();
		}
	}

	//�e�\��
	for (int i = 0; i < 5; i++)
	{
		Tamas[i].view();
		Tamas[i].flag_false();
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
