#include <DxLib.h>
#include "header.hpp"
#include "global.hpp"
#include "play.hpp"
#include "tama.hpp"
#include "enemy.hpp"
#include "effect.hpp"

int enemy_kind_stage1[9][21] = {
	{-1,-1,-1,Red,Red,Red,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Green,Green,Green,-1,-1,-1},
	{-1,-1,-1,Red,Red,Red,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Green,Green,Green,-1,-1,-1},
	{-1,-1,-1,Red,Red,Red,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Green,Green,Green,-1,-1,-1},
	{Red,Red,Red,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Green,Green,Green},
	{Red,Red,Red,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Green,Green,Green},
	{Red,Red,Red,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Green,Green,Green},
	{-1,-1,-1,Red,Red,Red,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Green,Green,Green,-1,-1,-1},
	{-1,-1,-1,Red,Red,Red,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Green,Green,Green,-1,-1,-1},
	{-1,-1,-1,Red,Red,Red,-1,-1,-1,Yellow,Yellow,Yellow,-1,-1,-1,Green,Green,Green,-1,-1,-1}
};

int enemy_kind_stage1_hard[9][21] = {
	{-1,-1,-1,Red_Hard,Red_Hard,Red_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Green_Hard,Green_Hard,Green_Hard,-1,-1,-1},
	{-1,-1,-1,Red_Hard,Red_Hard,Red_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Green_Hard,Green_Hard,Green_Hard,-1,-1,-1},
	{-1,-1,-1,Red_Hard,Red_Hard,Red_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Green_Hard,Green_Hard,Green_Hard,-1,-1,-1},
	{Red_Hard,Red_Hard,Red_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Green_Hard,Green_Hard,Green_Hard},
	{Red_Hard,Red_Hard,Red_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Green_Hard,Green_Hard,Green_Hard},
	{Red_Hard,Red_Hard,Red_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Green_Hard,Green_Hard,Green_Hard},
	{-1,-1,-1,Red_Hard,Red_Hard,Red_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Green_Hard,Green_Hard,Green_Hard,-1,-1,-1},
	{-1,-1,-1,Red_Hard,Red_Hard,Red_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Green_Hard,Green_Hard,Green_Hard,-1,-1,-1},
	{-1,-1,-1,Red_Hard,Red_Hard,Red_Hard,-1,-1,-1,Yellow_Hard,Yellow_Hard,Yellow_Hard,-1,-1,-1,Green_Hard,Green_Hard,Green_Hard,-1,-1,-1}
};

int enemy_kind_stage2[13][13] = {
	{-1,-1,-1,-1,-1,-1,Blue,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,Blue,Green,Blue,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,Blue,Green,Yellow,Green,Blue,-1,-1,-1,-1},
	{Blue,Blue,Blue,Blue,Green,Yellow,Red,Yellow,Green,Blue,Blue,Blue,Blue},
	{-1,Blue,Green,Green,Yellow,Red,Red,Red,Yellow,Green,Green,Blue,-1},
	{-1,-1,Blue,Green,Yellow,Red,Red,Red,Yellow,Green,Blue,-1,-1},
	{-1,-1,-1,Blue,Green,Yellow,Red,Yellow,Green,Blue,-1,-1,-1},
	{-1,-1,Blue,Green,Yellow,Red,Red,Red,Yellow,Green,Blue,-1,-1},
	{-1,Blue,Green,Green,Yellow,Red,Red,Red,Yellow,Green,Green,Blue,-1},
	{Blue,Blue,Blue,Blue,Green,Yellow,Red,Yellow,Green,Blue,Blue,Blue,Blue},
	{-1,-1,-1,-1,Blue,Green,Yellow,Green,Blue,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,Blue,Green,Blue,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,Blue,-1,-1,-1,-1,-1,-1}
};

int enemy_kind_stage2_hard[13][13] = {
	{-1,-1,-1,-1,-1,-1,Blue_Hard,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,Blue_Hard,Green_Hard,Blue_Hard,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,Blue_Hard,Green_Hard,Yellow_Hard,Green_Hard,Blue_Hard,-1,-1,-1,-1},
	{Blue_Hard,Blue_Hard,Blue_Hard,Blue_Hard,Green_Hard,Yellow_Hard,Red_Hard,Yellow_Hard,Green_Hard,Blue_Hard,Blue_Hard,Blue_Hard,Blue_Hard},
	{-1,Blue_Hard,Green_Hard,Green_Hard,Yellow_Hard,Red_Hard,Red_Hard,Red_Hard,Yellow_Hard,Green_Hard,Green_Hard,Blue_Hard,-1},
	{-1,-1,Blue_Hard,Green_Hard,Yellow_Hard,Red_Hard,Red_Hard,Red_Hard,Yellow_Hard,Green_Hard,Blue_Hard,-1,-1},
	{-1,-1,-1,Blue_Hard,Green_Hard,Yellow_Hard,Red_Hard,Yellow_Hard,Green_Hard,Blue_Hard,-1,-1,-1},
	{-1,-1,Blue_Hard,Green_Hard,Yellow_Hard,Red_Hard,Red_Hard,Red_Hard,Yellow_Hard,Green_Hard,Blue_Hard,-1,-1},
	{-1,Blue_Hard,Green_Hard,Green_Hard,Yellow_Hard,Red_Hard,Red_Hard,Red_Hard,Yellow_Hard,Green_Hard,Green_Hard,Blue_Hard,-1},
	{Blue_Hard,Blue_Hard,Blue_Hard,Blue_Hard,Green_Hard,Yellow_Hard,Red_Hard,Yellow_Hard,Green_Hard,Blue_Hard,Blue_Hard,Blue_Hard,Blue_Hard},
	{-1,-1,-1,-1,Blue_Hard,Green_Hard,Yellow_Hard,Green_Hard,Blue_Hard,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,Blue_Hard,Green_Hard,Blue_Hard,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,Blue_Hard,-1,-1,-1,-1,-1,-1}
};

int enemy_kind_stage3[7][23] = {
	{Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green},
	{-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1},
	{Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow},
	{-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1},
	{Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red},
	{-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1},
	{Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow}
};

int enemy_kind_stage3_hard[7][23] = {
	{Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard},
	{-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1},
	{Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard},
	{-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1},
	{Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard},
	{-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1},
	{Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard}
};

Enemy enemys_stage1[9][21];

Enemy enemys_stage1_hard[9][21];

Enemy enemys_stage2[13][13];

Enemy enemys_stage2_hard[13][13];

Enemy enemys_stage3[7][23];

Enemy enemys_stage3_hard[7][23];

Tama Tamas[20];

int enemy_count_stage1 = 90;

int enemy_count_stage2 = 91;

int enemy_count_stage3 = 81;

int enemy_count_stage1_hard = 90;

int enemy_count_stage2_hard = 91;

int enemy_count_stage3_hard = 81;

bool enemy_move_flag = TRUE;

int enemy_move_num = 0;

int enemy_move_tmp = 0;

int ready_tmp = 0;

double Timer = 0.0;

bool Syoki_Flag = TRUE;

double Current_Timer_Sec = 0.0;

int Current_Timer_Min = 0;

double Timer_Tmp = 0.0;

int judge = 0;	//í∑âüÇµÇ≈íeÇî≠éÀÇ≈Ç´ÇÈÇ©ÇÃîªíËÇ…égÇ§

//########## ÉvÉåÉCâÊñ ÇÃä÷êî ##########
VOID MY_GAME_PLAY(VOID)
{
	PLAYER.width = 30;
	PLAYER.height = 40;

	//îwåiï\é¶
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);

	Timer = GetNowCount();

	if (Syoki_Flag == TRUE)
	{
		Timer_Tmp = Timer;
		enemy_move_tmp = (int)Timer;
		Syoki_Flag = FALSE;
	}

	Current_Timer_Sec = (Timer - Timer_Tmp) / 1000;
	if (Current_Timer_Sec >= 60.0)
	{
		Current_Timer_Min++;
		Timer_Tmp = Timer;
	}

	if (CheckSoundMem(BGM_PLAY.handle) == 0)
	{
		PlaySoundMem(BGM_PLAY.handle, DX_PLAYTYPE_LOOP);
	}

	//ã@ëÃà⁄ìÆ
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

	//íeÉZÉbÉg
	if (AllKeyState[KEY_INPUT_A] != 0)
	{
		if (judge % 10 == 0)
		{
			if (Tamas[0].IsView == FALSE)
			{
				Tamas[0].IsView = TRUE;
				Tamas[0].position();
				PlaySoundMem(SE_SHOT.handle, DX_PLAYTYPE_BACK);
			}
			else
			{
				for (int i = 1; i <= 19; i++)
				{
					if (Tamas[i - 1].IsView == TRUE && Tamas[i].IsView == FALSE)
					{
						Tamas[i].IsView = TRUE;
						Tamas[i].position();
						PlaySoundMem(SE_SHOT.handle, DX_PLAYTYPE_BACK);
						break;
					}
				}
			}
		}
		++judge;
	}
	if (AllKeyState[KEY_INPUT_A] == 0)
	{
		judge = 0;
	}
	
	//íeï\é¶
	for (int i = 0; i < 20; i++)
	{
		Tamas[i].view();
		Tamas[i].flag_false();
	}

	//ÉeÉLÉXÉgï\é¶ÅAìGï\é¶ÅïìñÇΩÇËîªíËÇ»Ç«ÉXÉeÅ[ÉWÇ≤Ç∆Ç…à·Ç§èàóùèîÅX
	if (s_position_stage == 0)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 1-NORMAL", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), Small_FHandle, "ENEMY:%2d", enemy_count_stage1);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:30.00", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), Small_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 30.0)
			{
				GAMEOVER_METHOD();
			}

			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 21; b++)
				{
					if (enemy_kind_stage1[a][b] != -1)
					{
						//ìGÇÃÇ«ÇÍÇ©Ç™âÊñ í[Ç‹Ç≈à⁄ìÆÇµÇΩÇ©îªíË
						ENEMY_TURN(&enemys_stage1[a][b]);

						//ìGÇÃêFÇê›íË
						ENEMY_COLOR(enemy_kind_stage1[a][b], &enemys_stage1[a][b]);
						
						//íeÇ∆ìGÇ∆ÇÃìñÇΩÇËîªíË
						for (int i = 0; i < 20; i++)
						{
							if (Tamas[i].x < enemys_stage1[a][b].x_E + enemys_stage1[a][b].width_E &&		//íeÇÃç∂ < ìGÇÃâE
								Tamas[i].y < enemys_stage1[a][b].y_E + enemys_stage1[a][b].height_E &&		//íeÇÃè„ < ìGÇÃâ∫
								Tamas[i].x + Tamas[i].width > enemys_stage1[a][b].x_E &&	//íeÇÃâE > ìGÇÃç∂
								Tamas[i].y + Tamas[i].height > enemys_stage1[a][b].y_E)	//íeÇÃâ∫ > ìGÇÃè„
							{
								for (int j = -1; j < 2; j++)
								{
									for (int k = -1; k < 2; k++)
									{
										//ìGÇ™Ç¢ÇÈÅAÇ©Ç¬îzóÒì‡ÇéQè∆ÇµÇƒÇ¢ÇÍÇŒ
										if (a + j < 9 && a + j > -1 && b + k < 21 && b + k > -1 && enemy_kind_stage1[a + j][b + k] != -1)
										{
											COLLISION_ENEMY_TAMA_METHOD(&enemy_count_stage1, &enemy_kind_stage1[a + j][b + k], &enemys_stage1[a + j][b + k]);
										}
									}
								}
								Tamas[i].IsView = FALSE;
								Tamas[i].y = -20;
							}
							else
							{
								ENEMY_MOVE();
								enemys_stage1[a][b].position_E(a, b, 135 + enemy_move_num, 100);
								enemys_stage1[a][b].view_E(a, b);
							}
						}

						//ã@ëÃÇ∆ìGÇ∆ÇÃìñÇΩÇËîªíË
						COLLISION_ENEMY_PLAYER_N(&enemy_count_stage1, &enemy_kind_stage1[a][b], &enemys_stage1[a][b]);
					}
				}
			}
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 1-HARD", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), Small_FHandle, "ENEMY:%2d", enemy_count_stage1_hard);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:30.00", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), Small_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 30.0)
			{
				GAMEOVER_METHOD();
			}

			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 21; b++)
				{
					if (enemy_kind_stage1_hard[a][b] != -1)
					{
						//ìGÇÃÇ«ÇÍÇ©Ç™âÊñ í[Ç‹Ç≈à⁄ìÆÇµÇΩÇ©îªíË
						ENEMY_TURN(&enemys_stage1_hard[a][b]);

						//ìGÇÃêFÇê›íË
						ENEMY_COLOR(enemy_kind_stage1_hard[a][b], &enemys_stage1_hard[a][b]);
						
						//íeÇ∆ìGÇ∆ÇÃìñÇΩÇËîªíË
						for (int i = 0; i < 20; i++)
						{
							if (Tamas[i].x < enemys_stage1_hard[a][b].x_E + enemys_stage1_hard[a][b].width_E &&		//íeÇÃç∂ < ìGÇÃâE
								Tamas[i].y < enemys_stage1_hard[a][b].y_E + enemys_stage1_hard[a][b].height_E &&		//íeÇÃè„ < ìGÇÃâ∫
								Tamas[i].x + Tamas[i].width > enemys_stage1_hard[a][b].x_E &&	//íeÇÃâE > ìGÇÃç∂
								Tamas[i].y + Tamas[i].height > enemys_stage1_hard[a][b].y_E)	//íeÇÃâ∫ > ìGÇÃè„
							{
								for (int j = -1; j < 2; j++)
								{
									for (int k = -1; k < 2; k++)
									{
										//ìGÇ™Ç¢ÇÈÅAÇ©Ç¬îzóÒì‡ÇéQè∆ÇµÇƒÇ¢ÇÍÇŒ
										if (a + j < 9 && a + j > -1 && b + k < 21 && b + k > -1 && enemy_kind_stage1_hard[a + j][b + k] != -1)
										{
											//HPÇ™êsÇ´ÇÍÇŒè¡ñ≈ÅAécÇ¡ÇƒÇ¢ÇÍÇŒ1å∏ÇÁÇ∑
											if (enemys_stage1_hard[a + j][b + k].hp_E <= 1)
											{
												COLLISION_ENEMY_TAMA_METHOD(&enemy_count_stage1_hard, &enemy_kind_stage1_hard[a + j][b + k], &enemys_stage1_hard[a + j][b + k]);
											}
											else
											{
												enemys_stage1_hard[a + j][b + k].hp_E--;
												PlaySoundMem(SE_REFLECT.handle, DX_PLAYTYPE_BACK);
											}
										}
									}
								}
								Tamas[i].IsView = FALSE;
								Tamas[i].y = -20;
							}
							else
							{
								ENEMY_MOVE();
								enemys_stage1_hard[a][b].position_E(a, b, 135 + enemy_move_num, 100);
								enemys_stage1_hard[a][b].view_E(a, b);
							}
						}

						//ã@ëÃÇ∆ìGÇ∆ÇÃìñÇΩÇËîªíË
						COLLISION_ENEMY_PLAYER_H(&enemy_count_stage1_hard, &enemy_kind_stage1_hard[a][b], &enemys_stage1_hard[a][b]);
					}
				}
			}
		}
	}
	else if (s_position_stage == 100)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 2-NORMAL", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), Small_FHandle, "ENEMY:%2d", enemy_count_stage2);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:20.00", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), Small_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 20.0)
			{
				GAMEOVER_METHOD();
			}

			for (int a = 0; a < 13; a++)
			{
				for (int b = 0; b < 13; b++)
				{
					if (enemy_kind_stage2[a][b] != -1)
					{
						//ìGÇÃÇ«ÇÍÇ©Ç™âÊñ í[Ç‹Ç≈à⁄ìÆÇµÇΩÇ©îªíË
						ENEMY_TURN(&enemys_stage2[a][b]);

						//ìGÇÃêFÇê›íË
						ENEMY_COLOR(enemy_kind_stage2[a][b], &enemys_stage2[a][b]);
						
						for (int i = 0; i < 20; i++)
						{
							if (Tamas[i].x < enemys_stage2[a][b].x_E + enemys_stage2[a][b].width_E &&		//íeÇÃç∂ < ìGÇÃâE
								Tamas[i].y < enemys_stage2[a][b].y_E + enemys_stage2[a][b].height_E &&		//íeÇÃè„ < ìGÇÃâ∫
								Tamas[i].x + Tamas[i].width > enemys_stage2[a][b].x_E &&	//íeÇÃâE > ìGÇÃç∂
								Tamas[i].y + Tamas[i].height > enemys_stage2[a][b].y_E)	//íeÇÃâ∫ > ìGÇÃè„
							{
								for (int j = -1; j < 2; j++)
								{
									for (int k = -1; k < 2; k++)
									{
										//ìGÇ™Ç¢ÇÈÅAÇ©Ç¬îzóÒì‡ÇéQè∆ÇµÇƒÇ¢ÇÍÇŒ
										if (a + j < 13 && a + j > -1 && b + k < 13 && b + k > -1 && enemy_kind_stage2[a + j][b + k] != -1)
										{
											COLLISION_ENEMY_TAMA_METHOD(&enemy_count_stage2, &enemy_kind_stage2[a + j][b + k], &enemys_stage2[a + j][b + k]);
										}
									}
								}
								Tamas[i].IsView = FALSE;
								Tamas[i].y = -20;
							}
							else
							{
								ENEMY_MOVE();
								enemys_stage2[a][b].position_E(a, b, 255 + enemy_move_num, 50);
								enemys_stage2[a][b].view_E(a, b);
							}
						}

						//ã@ëÃÇ∆ìGÇ∆ÇÃìñÇΩÇËîªíË
						COLLISION_ENEMY_PLAYER_N(&enemy_count_stage2, &enemy_kind_stage2[a][b], &enemys_stage2[a][b]);
					}
				}
			}
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 2-HARD", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), Small_FHandle, "ENEMY:%2d", enemy_count_stage2_hard);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:20.00", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), Small_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 20.0)
			{
				GAMEOVER_METHOD();
			}

			for (int a = 0; a < 13; a++)
			{
				for (int b = 0; b < 13; b++)
				{
					if (enemy_kind_stage2_hard[a][b] != -1)
					{
						//ìGÇÃÇ«ÇÍÇ©Ç™âÊñ í[Ç‹Ç≈à⁄ìÆÇµÇΩÇ©îªíË
						ENEMY_TURN(&enemys_stage2_hard[a][b]);

						//ìGÇÃêFÇê›íË
						ENEMY_COLOR(enemy_kind_stage2_hard[a][b], &enemys_stage2_hard[a][b]);
						
						for (int i = 0; i < 20; i++)
						{
							if (Tamas[i].x < enemys_stage2_hard[a][b].x_E + enemys_stage2_hard[a][b].width_E &&		//íeÇÃç∂ < ìGÇÃâE
								Tamas[i].y < enemys_stage2_hard[a][b].y_E + enemys_stage2_hard[a][b].height_E &&		//íeÇÃè„ < ìGÇÃâ∫
								Tamas[i].x + Tamas[i].width > enemys_stage2_hard[a][b].x_E &&	//íeÇÃâE > ìGÇÃç∂
								Tamas[i].y + Tamas[i].height > enemys_stage2_hard[a][b].y_E)	//íeÇÃâ∫ > ìGÇÃè„
							{
								for (int j = -1; j < 2; j++)
								{
									for (int k = -1; k < 2; k++)
									{
										//ìGÇ™Ç¢ÇÈÅAÇ©Ç¬îzóÒì‡ÇéQè∆ÇµÇƒÇ¢ÇÍÇŒ
										if (a + j < 13 && a + j > -1 && b + k < 13 && b + k > -1 && enemy_kind_stage2_hard[a + j][b + k] != -1)
										{
											//HPÇ™êsÇ´ÇÍÇŒè¡ñ≈ÅAécÇ¡ÇƒÇ¢ÇÍÇŒ1å∏ÇÁÇ∑
											if (enemys_stage2_hard[a + j][b + k].hp_E <= 1)
											{
												COLLISION_ENEMY_TAMA_METHOD(&enemy_count_stage2_hard, &enemy_kind_stage2_hard[a + j][b + k], &enemys_stage2_hard[a + j][b + k]);
											}
											else
											{
												enemys_stage2_hard[a + j][b + k].hp_E--;
												PlaySoundMem(SE_REFLECT.handle, DX_PLAYTYPE_BACK);
											}
										}
									}
								}
								Tamas[i].IsView = FALSE;
								Tamas[i].y = -20;
							}
							else
							{
								ENEMY_MOVE();
								enemys_stage2_hard[a][b].position_E(a, b, 255 + enemy_move_num, 50);
								enemys_stage2_hard[a][b].view_E(a, b);
							}
						}

						//ã@ëÃÇ∆ìGÇ∆ÇÃìñÇΩÇËîªíË
						COLLISION_ENEMY_PLAYER_H(&enemy_count_stage2_hard, &enemy_kind_stage2_hard[a][b], &enemys_stage2_hard[a][b]);
					}
				}
			}
		}
	}
	else if (s_position_stage == 200)
	{
		if (s_position_difficult == 0)
		{
			DrawStringToHandle(10, 10, "STAGE 3-NORMAL", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), Small_FHandle, "ENEMY:%2d", enemy_count_stage3);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:30.00", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), Small_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 30.0)
			{
				GAMEOVER_METHOD();
			}

			for (int a = 0; a < 7; a++)
			{
				for (int b = 0; b < 23; b++)
				{
					if (enemy_kind_stage3[a][b] != -1)
					{
						//ìGÇÃÇ«ÇÍÇ©Ç™âÊñ í[Ç‹Ç≈à⁄ìÆÇµÇΩÇ©îªíË
						ENEMY_TURN(&enemys_stage3[a][b]);

						//ìGÇÃêFÇê›íË
						ENEMY_COLOR(enemy_kind_stage3[a][b], &enemys_stage3[a][b]);
						
						for (int i = 0; i < 20; i++)
						{
							if (Tamas[i].x < enemys_stage3[a][b].x_E + enemys_stage3[a][b].width_E &&		//íeÇÃç∂ < ìGÇÃâE
								Tamas[i].y < enemys_stage3[a][b].y_E + enemys_stage3[a][b].height_E &&		//íeÇÃè„ < ìGÇÃâ∫
								Tamas[i].x + Tamas[i].width > enemys_stage3[a][b].x_E &&	//íeÇÃâE > ìGÇÃç∂
								Tamas[i].y + Tamas[i].height > enemys_stage3[a][b].y_E)	//íeÇÃâ∫ > ìGÇÃè„
							{
								for (int j = -1; j < 2; j++)
								{
									for (int k = -1; k < 2; k++)
									{
										//ìGÇ™Ç¢ÇÈÅAÇ©Ç¬îzóÒì‡ÇéQè∆ÇµÇƒÇ¢ÇÍÇŒ
										if (a + j < 7 && a + j > -1 && b + k < 23 && b + k > -1 && enemy_kind_stage3[a + j][b + k] != -1)
										{
											COLLISION_ENEMY_TAMA_METHOD(&enemy_count_stage3, &enemy_kind_stage3[a + j][b + k], &enemys_stage3[a + j][b + k]);
										}
									}
								}
								Tamas[i].IsView = FALSE;
								Tamas[i].y = -20;
							}
							else
							{
								ENEMY_MOVE();
								enemys_stage3[a][b].position_E(a, b, 105 + enemy_move_num, 100);
								enemys_stage3[a][b].view_E(a, b);
							}
						}

						//ã@ëÃÇ∆ìGÇ∆ÇÃìñÇΩÇËîªíË
						COLLISION_ENEMY_PLAYER_N(&enemy_count_stage3, &enemy_kind_stage3[a][b], &enemys_stage3[a][b]);
					}
				}
			}
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 3-HARD", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), Small_FHandle, "ENEMY:%2d", enemy_count_stage3_hard);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:30.00", GetColor(255, 255, 255), Small_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), Small_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 30.0)
			{
				GAMEOVER_METHOD();
			}

			for (int a = 0; a < 7; a++)
			{
				for (int b = 0; b < 23; b++)
				{
					if (enemy_kind_stage3_hard[a][b] != -1)
					{
						//ìGÇÃÇ«ÇÍÇ©Ç™âÊñ í[Ç‹Ç≈à⁄ìÆÇµÇΩÇ©îªíË
						ENEMY_TURN(&enemys_stage3_hard[a][b]);

						//ìGÇÃêFÇê›íË
						ENEMY_COLOR(enemy_kind_stage3_hard[a][b], &enemys_stage3_hard[a][b]);
						
						for (int i = 0; i < 20; i++)
						{
							if (Tamas[i].x < enemys_stage3_hard[a][b].x_E + enemys_stage3_hard[a][b].width_E &&		//íeÇÃç∂ < ìGÇÃâE
								Tamas[i].y < enemys_stage3_hard[a][b].y_E + enemys_stage3_hard[a][b].height_E &&		//íeÇÃè„ < ìGÇÃâ∫
								Tamas[i].x + Tamas[i].width > enemys_stage3_hard[a][b].x_E &&	//íeÇÃâE > ìGÇÃç∂
								Tamas[i].y + Tamas[i].height > enemys_stage3_hard[a][b].y_E)	//íeÇÃâ∫ > ìGÇÃè„
							{
								for (int j = -1; j < 2; j++)
								{
									for (int k = -1; k < 2; k++)
									{
										//ìGÇ™Ç¢ÇÈÅAÇ©Ç¬îzóÒì‡ÇéQè∆ÇµÇƒÇ¢ÇÍÇŒ
										if (a + j < 7 && a + j > -1 && b + k < 23 && b + k > -1 && enemy_kind_stage3_hard[a + j][b + k] != -1)
										{
											//HPÇ™êsÇ´ÇÍÇŒè¡ñ≈ÅAécÇ¡ÇƒÇ¢ÇÍÇŒ1å∏ÇÁÇ∑
											if (enemys_stage3_hard[a + j][b + k].hp_E <= 1)
											{
												COLLISION_ENEMY_TAMA_METHOD(&enemy_count_stage3_hard, &enemy_kind_stage3_hard[a + j][b + k], &enemys_stage3_hard[a + j][b + k]);
											}
											else
											{
												enemys_stage3_hard[a + j][b + k].hp_E--;
												PlaySoundMem(SE_REFLECT.handle, DX_PLAYTYPE_BACK);
											}
										}
									}
								}
								Tamas[i].IsView = FALSE;
								Tamas[i].y = -20;
							}
							else
							{
								ENEMY_MOVE();
								enemys_stage3_hard[a][b].position_E(a, b, 105 + enemy_move_num, 100);
								enemys_stage3_hard[a][b].view_E(a, b);
							}
						}

						//ã@ëÃÇ∆ìGÇ∆ÇÃìñÇΩÇËîªíË
						COLLISION_ENEMY_PLAYER_H(&enemy_count_stage3_hard, &enemy_kind_stage3_hard[a][b], &enemys_stage3_hard[a][b]);
					}
				}
			}
		}
	}

	//ã@ëÃï\é¶
	DrawGraph(PLAYER.x, PLAYER.y, PLAYER.handle, TRUE);

	return;
}

int ENEMY_COUNT()
{
	int count = 0;
	if (s_position_stage == 0)
	{
		if (s_position_difficult == 0)
		{
			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 21; b++)
				{
					if (enemy_kind_stage1[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
		else if (s_position_difficult == 100)
		{
			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 21; b++)
				{
					if (enemy_kind_stage1_hard[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
	}
	else if (s_position_stage == 100)
	{
		if (s_position_difficult == 0)
		{
			for (int a = 0; a < 13; a++)
			{
				for (int b = 0; b < 13; b++)
				{
					if (enemy_kind_stage2[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
		else if (s_position_difficult == 100)
		{
			for (int a = 0; a < 13; a++)
			{
				for (int b = 0; b < 13; b++)
				{
					if (enemy_kind_stage2_hard[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
	}
	else if (s_position_stage == 200)
	{
		if (s_position_difficult == 0)
		{
			for (int a = 0; a < 7; a++)
			{
				for (int b = 0; b < 23; b++)
				{
					if (enemy_kind_stage3[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
		else if (s_position_difficult == 100)
		{
			for (int a = 0; a < 7; a++)
			{
				for (int b = 0; b < 23; b++)
				{
					if (enemy_kind_stage3_hard[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
	}

	return count;
}

void ENEMY_MOVE() 
{
	if (enemy_move_flag == TRUE)
	{
		//1/100ïbÇ≤Ç∆Ç…ìGÇ™à⁄ìÆ
		if ((int)Timer - enemy_move_tmp > 10)
		{
			enemy_move_num++;
			enemy_move_tmp = (int)Timer;
		}
	}
	else if (enemy_move_flag == FALSE)
	{
		//1/100ïbÇ≤Ç∆Ç…ìGÇ™à⁄ìÆ
		if ((int)Timer - enemy_move_tmp > 10)
		{
			enemy_move_num--;
			enemy_move_tmp = (int)Timer;
		}
	}
}

void ENEMY_TURN(Enemy* e)
{
	if (e->x_E > 870)
	{
		enemy_move_flag = FALSE;
	}
	else if (e->x_E < 0)
	{
		enemy_move_flag = TRUE;
	}
}

void ENEMY_COLOR(int color, Enemy* e)
{
	switch (color)
	{
	case Yellow:
		e->kind_E = Yellow;
		break;

	case Green:
		e->kind_E = Green;
		break;

	case Blue:
		e->kind_E = Blue;
		break;

	case Red:
		e->kind_E = Red;
		break;

	case Yellow_Hard:
		e->kind_E = Yellow_Hard;
		break;

	case Green_Hard:
		e->kind_E = Green_Hard;
		break;

	case Blue_Hard:
		e->kind_E = Blue_Hard;
		break;

	case Red_Hard:
		e->kind_E = Red_Hard;
		break;

	default:
		break;
	}
}

void COLLISION_ENEMY_PLAYER_N(int* count, int* kind, Enemy* e)
{
	if (e->x_E < PLAYER.x + PLAYER.width &&
		PLAYER.x < e->x_E + e->width_E &&
		PLAYER.y < e->y_E + e->height_E &&
		e->y_E < PLAYER.y + PLAYER.height)
	{
		*kind = -1;
		e->IsView_E = FALSE;
		*count = ENEMY_COUNT();
		if (ENEMY_COUNT() == 0)
		{
			for (int i = 0; i < 20; i++)
			{
				Tamas[i].y = -20;
			}
			GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//ÉVÅ[ÉìÇÉGÉìÉhâÊñ (ÉQÅ[ÉÄÉNÉäÉA)Ç…Ç∑ÇÈ
			StopSoundMem(BGM_PLAY.handle);
			PlaySoundMem(CLEAR.handle, DX_PLAYTYPE_BACK);
		}
		PlaySoundMem(SE_BAKUHATSU.handle, DX_PLAYTYPE_BACK);
		Effect effect(e->x_E, e->y_E);
		effect.effect_view();
	}
}

void COLLISION_ENEMY_PLAYER_H(int* count, int* kind, Enemy* e)
{
	if (e->x_E < PLAYER.x + PLAYER.width &&
		PLAYER.x < e->x_E + e->width_E &&
		PLAYER.y < e->y_E + e->height_E &&
		e->y_E < PLAYER.y + PLAYER.height)
	{
		if (e->collision_flag == FALSE)
		{
			if (e->hp_E <= 1)
			{
				*kind = -1;
				e->IsView_E = FALSE;
				*count = ENEMY_COUNT();
				if (ENEMY_COUNT() == 0)
				{
					for (int i = 0; i < 20; i++)
					{
						Tamas[i].y = -20;
					}
					GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//ÉVÅ[ÉìÇÉGÉìÉhâÊñ (ÉQÅ[ÉÄÉNÉäÉA)Ç…Ç∑ÇÈ
					StopSoundMem(BGM_PLAY.handle);
					PlaySoundMem(CLEAR.handle, DX_PLAYTYPE_BACK);
				}
				PlaySoundMem(SE_BAKUHATSU.handle, DX_PLAYTYPE_BACK);
				Effect effect(e->x_E, e->y_E);
				effect.effect_view();
			}
			else
			{
				e->hp_E--;
				e->collision_flag = TRUE;
				PlaySoundMem(SE_REFLECT.handle, DX_PLAYTYPE_BACK);
			}
		}
	}
	else
	{
		e->collision_flag = FALSE;
	}
}

void COLLISION_ENEMY_TAMA_METHOD(int* count, int* kind, Enemy* e)
{
	*kind = -1;
	e->IsView_E = FALSE;
	*count = ENEMY_COUNT();
	if (ENEMY_COUNT() == 0)
	{
		for (int i = 0; i < 20; i++)
		{
			Tamas[i].y = -20;
		}
		GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//ÉVÅ[ÉìÇÉGÉìÉhâÊñ (ÉQÅ[ÉÄÉNÉäÉA)Ç…Ç∑ÇÈ
		StopSoundMem(BGM_PLAY.handle);
		PlaySoundMem(CLEAR.handle, DX_PLAYTYPE_BACK);
	}
	PlaySoundMem(SE_BAKUHATSU.handle, DX_PLAYTYPE_BACK);
	Effect effect(e->x_E, e->y_E);
	effect.effect_view();
}

void GAMEOVER_METHOD()
{
	for (int i = 0; i < 20; i++)
	{
		Tamas[i].y = -20;
	}
	GameSceneNow = (int)GAME_SCENE_END_OVER;	//ÉVÅ[ÉìÇÉGÉìÉhâÊñ (ÉQÅ[ÉÄÉIÅ[ÉoÅ[)Ç…Ç∑ÇÈ
	StopSoundMem(BGM_PLAY.handle);
	PlaySoundMem(GAMEOVER.handle, DX_PLAYTYPE_BACK);
}