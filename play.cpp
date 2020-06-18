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
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false}
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
	{false,false,false,false,false,false,true,false,false,false,false,false,false}
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

Enemy enemys_stage1[9][21];

Enemy enemys_stage2[13][13];

Enemy enemys_stage3[7][23];

Tama Tamas[5];

int enemy_count_stage1 = 90;

int enemy_count_stage2 = 91;

int enemy_count_stage3 = 81;

bool enemy_move_flag = true;

int enemy_move_num = 0;

int enemy_move_tmp = 0;

double Timer = 0.0;

bool Time_Flag = false;

double Current_Timer_Sec = 0.0;

int Current_Timer_Min = 0;

double Timer_Tmp = 0.0;

//########## �v���C��ʂ̊֐� ##########
VOID MY_GAME_PLAY(VOID)
{
	PLAYER.width = 30;
	PLAYER.height = 40;

	//�w�i�\��
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);

	Timer = GetNowCount();

	if (Time_Flag == false)
	{
		Timer_Tmp = Timer;
		enemy_move_tmp = (int)Timer;
		Time_Flag = true;
	}

	Current_Timer_Sec = (Timer - Timer_Tmp) / 1000;
	if (Current_Timer_Sec >= 60.0)
	{
		Current_Timer_Min++;
		Timer_Tmp = Timer;
	}

	//�@�̈ړ�
	if (AllKeyState[KEY_INPUT_UP] != 0)
	{
		if (PLAYER.y > 0)
		{
			PLAYER.y -= 4;
		}
	}
	if (AllKeyState[KEY_INPUT_DOWN] != 0)
	{
		if (PLAYER.y < 560)
		{
			PLAYER.y += 4;
		}		
	}
	if (AllKeyState[KEY_INPUT_LEFT] != 0)
	{
		if (PLAYER.x > 0)
		{
			PLAYER.x -= 4;
		}
	}
	if (AllKeyState[KEY_INPUT_RIGHT] != 0)
	{
		if (PLAYER.x < 870)
		{
			PLAYER.x += 4;
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
		else if (Tamas[2].IsView == TRUE && Tamas[3].IsView == FALSE)
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

	if (AllKeyState[KEY_INPUT_A] != 0)	//A�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_END_OVER;	//�V�[�����G���h���(�Q�[���I�[�o�[)�ɂ���
	}

	if (AllKeyState[KEY_INPUT_S] != 0)	//S�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//�V�[�����G���h���(�Q�[���N���A)�ɂ���
	}

	if (s_position_stage == 0)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 1-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), play_FHandle, "ENEMY:%2d", enemy_count_stage1);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:10.00", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), play_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 10.0)
			{
				Tamas[0].y = -20;
				Tamas[1].y = -20;
				Tamas[2].y = -20;
				Tamas[3].y = -20;
				Tamas[4].y = -20;
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//�V�[�����G���h���(�Q�[���I�[�o�[)�ɂ���
			}
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 1-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), play_FHandle, "ENEMY:%2d", enemy_count_stage1);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:30.00", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), play_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 30.0)
			{
				Tamas[0].y = -20;
				Tamas[1].y = -20;
				Tamas[2].y = -20;
				Tamas[3].y = -20;
				Tamas[4].y = -20;
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//�V�[�����G���h���(�Q�[���I�[�o�[)�ɂ���
			}
		}

		for (int a = 0; a < 9; a++)
		{
			for (int b = 0; b < 21; b++)
			{
				if (enemy_flag_stage1[a][b] == true)
				{
					//�G�̂ǂꂩ����ʒ[�܂ňړ�������
					if (enemys_stage1[a][b].x_E > 870)
					{
						enemy_move_flag = false;
					}
					else if (enemys_stage1[a][b].x_E < 0)
					{
						enemy_move_flag = true;
					}
					
					//�e�ƓG�Ƃ̓����蔻��
					for (int i = 0; i < 5; i++)
					{
						if (Tamas[i].x < enemys_stage1[a][b].x_E + enemys_stage1[a][b].width_E &&		//�e�̍� < �G�̉E
							Tamas[i].y < enemys_stage1[a][b].y_E + enemys_stage1[a][b].height_E &&		//�e�̏� < �G�̉�
							Tamas[i].x + Tamas[i].width > enemys_stage1[a][b].x_E &&	//�e�̉E > �G�̍�
							Tamas[i].y + Tamas[i].height > enemys_stage1[a][b].y_E)	//�e�̉� > �G�̏�
						{
							for (int j = -1; j < 2; j++)
							{
								for (int k = -1; k < 2; k++)
								{
									//�G������A���z������Q�Ƃ��Ă����
									if (a + j < 9 && a + j > -1 && b + k < 21 && b + k > -1 && enemy_flag_stage1[a + j][b + k] == true)
									{
										enemy_flag_stage1[a + j][b + k] = false;
										enemys_stage1[a + j][b + k].IsView_E = FALSE;
										enemy_count_stage1--;
									}
								}
							}
							Tamas[i].IsView = FALSE;
							Tamas[i].y = -20;
						}
						else
						{
							if (enemy_move_flag == true)
							{
								//1/100�b���ƂɓG���ړ�
								if ((int)Timer - enemy_move_tmp > 10)
								{
									enemy_move_num++;
									enemy_move_tmp = (int)Timer;
								}
							}
							else if (enemy_move_flag == false)
							{
								//1/100�b���ƂɓG���ړ�
								if ((int)Timer - enemy_move_tmp > 10)
								{
									enemy_move_num--;
									enemy_move_tmp = (int)Timer;
								}
							}
							enemys_stage1[a][b].position_E(a, b, 135 + enemy_move_num, 100);
							enemys_stage1[a][b].view_E();
						}
					}

					//�@�̂ƓG�Ƃ̓����蔻��
					if (enemys_stage1[a][b].x_E < PLAYER.x + PLAYER.width &&
						PLAYER.x < enemys_stage1[a][b].x_E + enemys_stage1[a][b].width_E &&
						PLAYER.y < enemys_stage1[a][b].y_E + enemys_stage1[a][b].height_E &&
						enemys_stage1[a][b].y_E < PLAYER.y + PLAYER.height)
					{
						enemy_flag_stage1[a][b] = false;
						enemys_stage1[a][b].IsView_E = FALSE;
						enemy_count_stage1--;
					}
				}
			}
		}
	}
	else if (s_position_stage == 100)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 2-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), play_FHandle, "ENEMY:%2d", enemy_count_stage2);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:10.00", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), play_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 10.0)
			{
				Tamas[0].y = -20;
				Tamas[1].y = -20;
				Tamas[2].y = -20;
				Tamas[3].y = -20;
				Tamas[4].y = -20;
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//�V�[�����G���h���(�Q�[���I�[�o�[)�ɂ���
			}
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 2-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), play_FHandle, "ENEMY:%2d", enemy_count_stage2);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:30.00", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), play_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 30.0)
			{
				Tamas[0].y = -20;
				Tamas[1].y = -20;
				Tamas[2].y = -20;
				Tamas[3].y = -20;
				Tamas[4].y = -20;
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//�V�[�����G���h���(�Q�[���I�[�o�[)�ɂ���
			}
		}

		for (int a = 0; a < 13; a++)
		{
			for (int b = 0; b < 13; b++)
			{
				if (enemy_flag_stage2[a][b] == true)
				{
					//�G�̂ǂꂩ����ʒ[�܂ňړ�������
					if (enemys_stage2[a][b].x_E > 870)
					{
						enemy_move_flag = false;
					}
					else if (enemys_stage2[a][b].x_E < 0)
					{
						enemy_move_flag = true;
					}

					for (int i = 0; i < 5; i++)
					{
						if (Tamas[i].x < enemys_stage2[a][b].x_E + enemys_stage2[a][b].width_E &&		//�e�̍� < �G�̉E
							Tamas[i].y < enemys_stage2[a][b].y_E + enemys_stage2[a][b].height_E &&		//�e�̏� < �G�̉�
							Tamas[i].x + Tamas[i].width > enemys_stage2[a][b].x_E &&	//�e�̉E > �G�̍�
							Tamas[i].y + Tamas[i].height > enemys_stage2[a][b].y_E)	//�e�̉� > �G�̏�
						{
							for (int j = -1; j < 2; j++)
							{
								for (int k = -1; k < 2; k++)
								{
									//�G������A���z������Q�Ƃ��Ă����
									if (a + j < 13 && a + j > -1 && b + k < 13 && b + k > -1 && enemy_flag_stage2[a + j][b + k] == true)
									{
										enemy_flag_stage2[a + j][b + k] = false;
										enemys_stage2[a + j][b + k].IsView_E = FALSE;
										enemy_count_stage2--;
									}
								}
							}
							Tamas[i].IsView = FALSE;
							Tamas[i].y = -20;
						}
						else
						{						
							if (enemy_move_flag == true)
							{
								//1/100�b���ƂɓG���ړ�
								if ((int)Timer - enemy_move_tmp > 10)
								{
									enemy_move_num++;
									enemy_move_tmp = (int)Timer;
								}
							}
							else if (enemy_move_flag == false)
							{
								//1/100�b���ƂɓG���ړ�
								if ((int)Timer - enemy_move_tmp > 10)
								{
									enemy_move_num--;
									enemy_move_tmp = (int)Timer;
								}
							}
							enemys_stage2[a][b].position_E(a, b, 255 + enemy_move_num, 50);
							enemys_stage2[a][b].view_E();
						}
					}

					//�@�̂ƓG�Ƃ̓����蔻��
					if (enemys_stage2[a][b].x_E < PLAYER.x + PLAYER.width &&
						PLAYER.x < enemys_stage2[a][b].x_E + enemys_stage2[a][b].width_E &&
						PLAYER.y < enemys_stage2[a][b].y_E + enemys_stage2[a][b].height_E &&
						enemys_stage2[a][b].y_E < PLAYER.y + PLAYER.height)
					{
						enemy_flag_stage2[a][b] = false;
						enemys_stage2[a][b].IsView_E = FALSE;
						enemy_count_stage2--;
					}
				}
			}
		}
	}
	else if (s_position_stage == 200)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 3-NORMAL", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), play_FHandle, "ENEMY:%2d", enemy_count_stage3);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:10.00", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), play_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 10.0)
			{
				Tamas[0].y = -20;
				Tamas[1].y = -20;
				Tamas[2].y = -20;
				Tamas[3].y = -20;
				Tamas[4].y = -20;
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//�V�[�����G���h���(�Q�[���I�[�o�[)�ɂ���
			}
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 3-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), play_FHandle, "ENEMY:%2d", enemy_count_stage3);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:30.00", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), play_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 30.0)
			{
				Tamas[0].y = -20;
				Tamas[1].y = -20;
				Tamas[2].y = -20;
				Tamas[3].y = -20;
				Tamas[4].y = -20;
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//�V�[�����G���h���(�Q�[���I�[�o�[)�ɂ���
			}
		}

		for (int a = 0; a < 7; a++)
		{
			for (int b = 0; b < 23; b++)
			{
				if (enemy_flag_stage3[a][b] == true)
				{
					//�G�̂ǂꂩ����ʒ[�܂ňړ�������
					if (enemys_stage3[a][b].x_E > 870)
					{
						enemy_move_flag = false;
					}
					else if (enemys_stage3[a][b].x_E < 0)
					{
						enemy_move_flag = true;
					}

					for (int i = 0; i < 5; i++)
					{
						if (Tamas[i].x < enemys_stage3[a][b].x_E + enemys_stage3[a][b].width_E &&		//�e�̍� < �G�̉E
							Tamas[i].y < enemys_stage3[a][b].y_E + enemys_stage3[a][b].height_E &&		//�e�̏� < �G�̉�
							Tamas[i].x + Tamas[i].width > enemys_stage3[a][b].x_E &&	//�e�̉E > �G�̍�
							Tamas[i].y + Tamas[i].height > enemys_stage3[a][b].y_E)	//�e�̉� > �G�̏�
						{
							for (int j = -1; j < 2; j++)
							{
								for (int k = -1; k < 2; k++)
								{
									//�G������A���z������Q�Ƃ��Ă����
									if (a + j < 7 && a + j > -1 && b + k < 23 && b + k > -1 && enemy_flag_stage3[a + j][b + k] == true)
									{
										enemy_flag_stage3[a + j][b + k] = false;
										enemys_stage3[a + j][b + k].IsView_E = FALSE;
										enemy_count_stage3--;
									}
								}
							}
							Tamas[i].IsView = FALSE;
							Tamas[i].y = -20;
						}
						else
						{
							if (enemy_move_flag == true)
							{
								//1/100�b���ƂɓG���ړ�
								if ((int)Timer - enemy_move_tmp > 10)
								{
									enemy_move_num++;
									enemy_move_tmp = (int)Timer;
								}
							}
							else if (enemy_move_flag == false)
							{
								//1/100�b���ƂɓG���ړ�
								if ((int)Timer - enemy_move_tmp > 10)
								{
									enemy_move_num--;
									enemy_move_tmp = (int)Timer;
								}
							}
							enemys_stage3[a][b].position_E(a, b, 105 + enemy_move_num, 100);
							enemys_stage3[a][b].view_E();
						}
					}

					//�@�̂ƓG�Ƃ̓����蔻��
					if (enemys_stage3[a][b].x_E < PLAYER.x + PLAYER.width &&
						PLAYER.x < enemys_stage3[a][b].x_E + enemys_stage3[a][b].width_E &&
						PLAYER.y < enemys_stage3[a][b].y_E + enemys_stage3[a][b].height_E &&
						enemys_stage3[a][b].y_E < PLAYER.y + PLAYER.height)
					{
						enemy_flag_stage3[a][b] = false;
						enemys_stage3[a][b].IsView_E = FALSE;
						enemy_count_stage3--;
					}
				}
			}
		}
	}

	if (s_position_stage == 0)
	{
		int count = 189;
		for (int a = 0; a < 9; a++)
		{
			for (int b = 0; b < 21; b++)
			{
				if (enemy_flag_stage1[a][b] == true)
				{
					continue;
				}
				else
				{
					count--;
					if (count <= 0)
					{
						Tamas[0].y = -20;
						Tamas[1].y = -20;
						Tamas[2].y = -20;
						Tamas[3].y = -20;
						Tamas[4].y = -20;
						GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//�V�[�����G���h���(�Q�[���N���A)�ɂ���
					}
				}
			}
		}
	}
	else if (s_position_stage == 100)
	{
		int count = 169;
		for (int a = 0; a < 13; a++)
		{
			for (int b = 0; b < 13; b++)
			{
				if (enemy_flag_stage2[a][b] == true)
				{
					continue;
				}
				else
				{
					count--;
					if (count <= 0)
					{
						Tamas[0].y = -20;
						Tamas[1].y = -20;
						Tamas[2].y = -20;
						Tamas[3].y = -20;
						Tamas[4].y = -20;
						GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//�V�[�����G���h���(�Q�[���N���A)�ɂ���
					}
				}
			}
		}
	}
	else if (s_position_stage == 200)
	{
		int count = 161;
		for (int a = 0; a < 7; a++)
		{
			for (int b = 0; b < 23; b++)
			{
				if (enemy_flag_stage3[a][b] == true)
				{
					continue;
				}
				else
				{
					count--;
					if (count <= 0)
					{
						Tamas[0].y = -20;
						Tamas[1].y = -20;
						Tamas[2].y = -20;
						Tamas[3].y = -20;
						Tamas[4].y = -20;
						GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//�V�[�����G���h���(�Q�[���N���A)�ɂ���
					}
				}
			}
		}
	}

	return;
}
