#include <DxLib.h>
#include "header.hpp"
#include "global.hpp"
#include "play.hpp"
#include "tama.hpp"
#include "enemy.hpp"

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

Tama Tamas[5];

int enemy_count_stage1 = 90;

int enemy_count_stage2 = 91;

int enemy_count_stage3 = 81;

int enemy_count_stage1_hard = 90;

int enemy_count_stage2_hard = 91;

int enemy_count_stage3_hard = 81;

bool enemy_move_flag = true;

int enemy_move_num = 0;

int enemy_move_tmp = 0;

double Timer = 0.0;

bool Syoki_Flag = true;

double Current_Timer_Sec = 0.0;

int Current_Timer_Min = 0;

double Timer_Tmp = 0.0;

//########## プレイ画面の関数 ##########
VOID MY_GAME_PLAY(VOID)
{
	PLAYER.width = 30;
	PLAYER.height = 40;

	//背景表示
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);

	Timer = GetNowCount();

	if (Syoki_Flag == true)
	{
		Timer_Tmp = Timer;
		enemy_move_tmp = (int)Timer;
		Syoki_Flag = false;
	}

	Current_Timer_Sec = (Timer - Timer_Tmp) / 1000;
	if (Current_Timer_Sec >= 60.0)
	{
		Current_Timer_Min++;
		Timer_Tmp = Timer;
	}

	//機体移動
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

	//機体表示
	DrawGraph(PLAYER.x, PLAYER.y, PLAYER.handle, TRUE);

	//弾セット
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

	//弾表示
	for (int i = 0; i < 5; i++)
	{
		Tamas[i].view();
		Tamas[i].flag_false();
	}

	if (AllKeyState[KEY_INPUT_A] != 0)	//Aキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_END_OVER;	//シーンをエンド画面(ゲームオーバー)にする
	}

	if (AllKeyState[KEY_INPUT_S] != 0)	//Sキーが押されていた時
	{
		GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//シーンをエンド画面(ゲームクリア)にする
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
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//シーンをエンド画面(ゲームオーバー)にする
			}

			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 21; b++)
				{
					if (enemy_kind_stage1[a][b] != -1)
					{
						//敵のどれかが画面端まで移動したら
						if (enemys_stage1[a][b].x_E > 870)
						{
							enemy_move_flag = false;
						}
						else if (enemys_stage1[a][b].x_E < 0)
						{
							enemy_move_flag = true;
						}

						//敵の色を設定
						switch (enemy_kind_stage1[a][b])
						{
						case Yellow:
							enemys_stage1[a][b].kind_E = Yellow;
							break;

						case Green:
							enemys_stage1[a][b].kind_E = Green;
							break;

						case Blue:
							enemys_stage1[a][b].kind_E = Blue;
							break;

						case Red:
							enemys_stage1[a][b].kind_E = Red;
							break;

						default:
							break;
						}

						//弾と敵との当たり判定
						for (int i = 0; i < 5; i++)
						{
							if (Tamas[i].x < enemys_stage1[a][b].x_E + enemys_stage1[a][b].width_E &&		//弾の左 < 敵の右
								Tamas[i].y < enemys_stage1[a][b].y_E + enemys_stage1[a][b].height_E &&		//弾の上 < 敵の下
								Tamas[i].x + Tamas[i].width > enemys_stage1[a][b].x_E &&	//弾の右 > 敵の左
								Tamas[i].y + Tamas[i].height > enemys_stage1[a][b].y_E)	//弾の下 > 敵の上
							{
								for (int j = -1; j < 2; j++)
								{
									for (int k = -1; k < 2; k++)
									{
										//敵がいる、かつ配列内を参照していれば
										if (a + j < 9 && a + j > -1 && b + k < 21 && b + k > -1 && enemy_kind_stage1[a + j][b + k] != -1)
										{
											enemy_kind_stage1[a + j][b + k] = -1;
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
									//1/100秒ごとに敵が移動
									if ((int)Timer - enemy_move_tmp > 10)
									{
										enemy_move_num++;
										enemy_move_tmp = (int)Timer;
									}
								}
								else if (enemy_move_flag == false)
								{
									//1/100秒ごとに敵が移動
									if ((int)Timer - enemy_move_tmp > 10)
									{
										enemy_move_num--;
										enemy_move_tmp = (int)Timer;
									}
								}
								enemys_stage1[a][b].position_E(a, b, 135 + enemy_move_num, 100);
								enemys_stage1[a][b].view_E(a, b);
							}
						}

						//機体と敵との当たり判定
						if (enemys_stage1[a][b].x_E < PLAYER.x + PLAYER.width &&
							PLAYER.x < enemys_stage1[a][b].x_E + enemys_stage1[a][b].width_E &&
							PLAYER.y < enemys_stage1[a][b].y_E + enemys_stage1[a][b].height_E &&
							enemys_stage1[a][b].y_E < PLAYER.y + PLAYER.height)
						{
							enemy_kind_stage1[a][b] = -1;
							enemys_stage1[a][b].IsView_E = FALSE;
							enemy_count_stage1--;
						}
					}
				}
			}
		}
		else if (s_position_difficult == 100)
		{
			DrawStringToHandle(10, 10, "STAGE 1-HARD", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(780, 10, GetColor(255, 255, 255), play_FHandle, "ENEMY:%2d", enemy_count_stage1_hard);
			DrawStringToHandle(10, 570, "TIME LIMIT 0:30.00", GetColor(255, 255, 255), play_FHandle);
			DrawFormatStringToHandle(720, 570, GetColor(255, 255, 255), play_FHandle, "TIME %02d:%05.2lf", Current_Timer_Min, Current_Timer_Sec);

			if (Current_Timer_Sec >= 30.0)
			{
				Tamas[0].y = -20;
				Tamas[1].y = -20;
				Tamas[2].y = -20;
				Tamas[3].y = -20;
				Tamas[4].y = -20;
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//シーンをエンド画面(ゲームオーバー)にする
			}

			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 21; b++)
				{
					if (enemy_kind_stage1_hard[a][b] != -1)
					{
						//敵のどれかが画面端まで移動したら
						if (enemys_stage1_hard[a][b].x_E > 870)
						{
							enemy_move_flag = false;
						}
						else if (enemys_stage1_hard[a][b].x_E < 0)
						{
							enemy_move_flag = true;
						}

						//敵の色を設定
						switch (enemy_kind_stage1_hard[a][b])
						{
						case Yellow_Hard:
							enemys_stage1_hard[a][b].kind_E = Yellow_Hard;
							break;

						case Green_Hard:
							enemys_stage1_hard[a][b].kind_E = Green_Hard;
							break;

						case Blue_Hard:
							enemys_stage1_hard[a][b].kind_E = Blue_Hard;
							break;

						case Red_Hard:
							enemys_stage1_hard[a][b].kind_E = Red_Hard;
							break;

						default:
							break;
						}

						//弾と敵との当たり判定
						for (int i = 0; i < 5; i++)
						{
							if (Tamas[i].x < enemys_stage1_hard[a][b].x_E + enemys_stage1_hard[a][b].width_E &&		//弾の左 < 敵の右
								Tamas[i].y < enemys_stage1_hard[a][b].y_E + enemys_stage1_hard[a][b].height_E &&		//弾の上 < 敵の下
								Tamas[i].x + Tamas[i].width > enemys_stage1_hard[a][b].x_E &&	//弾の右 > 敵の左
								Tamas[i].y + Tamas[i].height > enemys_stage1_hard[a][b].y_E)	//弾の下 > 敵の上
							{
								for (int j = -1; j < 2; j++)
								{
									for (int k = -1; k < 2; k++)
									{
										//敵がいる、かつ配列内を参照していれば
										if (a + j < 9 && a + j > -1 && b + k < 21 && b + k > -1 && enemy_kind_stage1_hard[a + j][b + k] != -1)
										{
											enemy_kind_stage1_hard[a + j][b + k] = -1;
											enemys_stage1_hard[a + j][b + k].IsView_E = FALSE;
											enemy_count_stage1_hard--;
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
									//1/100秒ごとに敵が移動
									if ((int)Timer - enemy_move_tmp > 10)
									{
										enemy_move_num++;
										enemy_move_tmp = (int)Timer;
									}
								}
								else if (enemy_move_flag == false)
								{
									//1/100秒ごとに敵が移動
									if ((int)Timer - enemy_move_tmp > 10)
									{
										enemy_move_num--;
										enemy_move_tmp = (int)Timer;
									}
								}
								enemys_stage1_hard[a][b].position_E(a, b, 135 + enemy_move_num, 100);
								enemys_stage1_hard[a][b].view_E(a, b);
							}
						}

						//機体と敵との当たり判定
						if (enemys_stage1_hard[a][b].x_E < PLAYER.x + PLAYER.width &&
							PLAYER.x < enemys_stage1_hard[a][b].x_E + enemys_stage1_hard[a][b].width_E &&
							PLAYER.y < enemys_stage1_hard[a][b].y_E + enemys_stage1_hard[a][b].height_E &&
							enemys_stage1_hard[a][b].y_E < PLAYER.y + PLAYER.height)
						{
							enemy_kind_stage1_hard[a][b] = -1;
							enemys_stage1_hard[a][b].IsView_E = FALSE;
							enemy_count_stage1_hard--;
						}
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
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//シーンをエンド画面(ゲームオーバー)にする
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
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//シーンをエンド画面(ゲームオーバー)にする
			}
		}

		for (int a = 0; a < 13; a++)
		{
			for (int b = 0; b < 13; b++)
			{
				if (enemy_kind_stage2[a][b] != -1)
				{
					//敵のどれかが画面端まで移動したら
					if (enemys_stage2[a][b].x_E > 870)
					{
						enemy_move_flag = false;
					}
					else if (enemys_stage2[a][b].x_E < 0)
					{
						enemy_move_flag = true;
					}

					//敵の色を設定
					switch (enemy_kind_stage2[a][b])
					{
					case Yellow:
						enemys_stage2[a][b].kind_E = Yellow;
						break;

					case Green:
						enemys_stage2[a][b].kind_E = Green;
						break;

					case Blue:
						enemys_stage2[a][b].kind_E = Blue;
						break;

					case Red:
						enemys_stage2[a][b].kind_E = Red;
						break;

					default:
						break;
					}

					for (int i = 0; i < 5; i++)
					{
						if (Tamas[i].x < enemys_stage2[a][b].x_E + enemys_stage2[a][b].width_E &&		//弾の左 < 敵の右
							Tamas[i].y < enemys_stage2[a][b].y_E + enemys_stage2[a][b].height_E &&		//弾の上 < 敵の下
							Tamas[i].x + Tamas[i].width > enemys_stage2[a][b].x_E &&	//弾の右 > 敵の左
							Tamas[i].y + Tamas[i].height > enemys_stage2[a][b].y_E)	//弾の下 > 敵の上
						{
							for (int j = -1; j < 2; j++)
							{
								for (int k = -1; k < 2; k++)
								{
									//敵がいる、かつ配列内を参照していれば
									if (a + j < 13 && a + j > -1 && b + k < 13 && b + k > -1 && enemy_kind_stage2[a + j][b + k] != -1)
									{
										enemy_kind_stage2[a + j][b + k] = -1;
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
								//1/100秒ごとに敵が移動
								if ((int)Timer - enemy_move_tmp > 10)
								{
									enemy_move_num++;
									enemy_move_tmp = (int)Timer;
								}
							}
							else if (enemy_move_flag == false)
							{
								//1/100秒ごとに敵が移動
								if ((int)Timer - enemy_move_tmp > 10)
								{
									enemy_move_num--;
									enemy_move_tmp = (int)Timer;
								}
							}
							enemys_stage2[a][b].position_E(a, b, 255 + enemy_move_num, 50);
							enemys_stage2[a][b].view_E(a, b);
						}
					}

					//機体と敵との当たり判定
					if (enemys_stage2[a][b].x_E < PLAYER.x + PLAYER.width &&
						PLAYER.x < enemys_stage2[a][b].x_E + enemys_stage2[a][b].width_E &&
						PLAYER.y < enemys_stage2[a][b].y_E + enemys_stage2[a][b].height_E &&
						enemys_stage2[a][b].y_E < PLAYER.y + PLAYER.height)
					{
						enemy_kind_stage2[a][b] = -1;
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
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//シーンをエンド画面(ゲームオーバー)にする
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
				GameSceneNow = (int)GAME_SCENE_END_OVER;	//シーンをエンド画面(ゲームオーバー)にする
			}
		}

		for (int a = 0; a < 7; a++)
		{
			for (int b = 0; b < 23; b++)
			{
				if (enemy_kind_stage3[a][b] != -1)
				{
					//敵のどれかが画面端まで移動したら
					if (enemys_stage3[a][b].x_E > 870)
					{
						enemy_move_flag = false;
					}
					else if (enemys_stage3[a][b].x_E < 0)
					{
						enemy_move_flag = true;
					}

					//敵の色を設定
					switch (enemy_kind_stage3[a][b])
					{
					case Yellow:
						enemys_stage3[a][b].kind_E = Yellow;
						break;

					case Green:
						enemys_stage3[a][b].kind_E = Green;
						break;

					case Blue:
						enemys_stage3[a][b].kind_E = Blue;
						break;

					case Red:
						enemys_stage3[a][b].kind_E = Red;
						break;

					default:
						break;
					}

					for (int i = 0; i < 5; i++)
					{
						if (Tamas[i].x < enemys_stage3[a][b].x_E + enemys_stage3[a][b].width_E &&		//弾の左 < 敵の右
							Tamas[i].y < enemys_stage3[a][b].y_E + enemys_stage3[a][b].height_E &&		//弾の上 < 敵の下
							Tamas[i].x + Tamas[i].width > enemys_stage3[a][b].x_E &&	//弾の右 > 敵の左
							Tamas[i].y + Tamas[i].height > enemys_stage3[a][b].y_E)	//弾の下 > 敵の上
						{
							for (int j = -1; j < 2; j++)
							{
								for (int k = -1; k < 2; k++)
								{
									//敵がいる、かつ配列内を参照していれば
									if (a + j < 7 && a + j > -1 && b + k < 23 && b + k > -1 && enemy_kind_stage3[a + j][b + k] != -1)
									{
										enemy_kind_stage3[a + j][b + k] = -1;
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
								//1/100秒ごとに敵が移動
								if ((int)Timer - enemy_move_tmp > 10)
								{
									enemy_move_num++;
									enemy_move_tmp = (int)Timer;
								}
							}
							else if (enemy_move_flag == false)
							{
								//1/100秒ごとに敵が移動
								if ((int)Timer - enemy_move_tmp > 10)
								{
									enemy_move_num--;
									enemy_move_tmp = (int)Timer;
								}
							}
							enemys_stage3[a][b].position_E(a, b, 105 + enemy_move_num, 100);
							enemys_stage3[a][b].view_E(a, b);
						}
					}

					//機体と敵との当たり判定
					if (enemys_stage3[a][b].x_E < PLAYER.x + PLAYER.width &&
						PLAYER.x < enemys_stage3[a][b].x_E + enemys_stage3[a][b].width_E &&
						PLAYER.y < enemys_stage3[a][b].y_E + enemys_stage3[a][b].height_E &&
						enemys_stage3[a][b].y_E < PLAYER.y + PLAYER.height)
					{
						enemy_kind_stage3[a][b] = -1;
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
				if (s_position_difficult == 0)
				{
					if (enemy_kind_stage1[a][b] != -1)
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
							GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//シーンをエンド画面(ゲームクリア)にする
						}
					}
				}
				else if (s_position_difficult == 100)
				{
					if (enemy_kind_stage1_hard[a][b] != -1)
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
							GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//シーンをエンド画面(ゲームクリア)にする
						}
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
				if (enemy_kind_stage2[a][b] != -1)
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
						GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//シーンをエンド画面(ゲームクリア)にする
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
				if (enemy_kind_stage3[a][b] != -1)
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
						GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//シーンをエンド画面(ゲームクリア)にする
					}
				}
			}
		}
	}

	return;
}
