#include <DxLib.h>
#include "enemy.hpp"
#include "global.hpp"
#include "tama.hpp"

Enemy::Enemy()
{
	x_E = 0;
	y_E = 700;
	width_E = 30;
	height_E = 30;
	kind_E = -1;
	hp_E = 3;	//Hardモードのみ使用する体力
	collision_flag = FALSE;	//Hardモードのみ使用する、機体と敵が当たっているかの判定
	IsView_E = TRUE;
}

void Enemy::position_E(int tate, int yoko, int kijun_x, int kijun_y)
{
	y_E = kijun_y + tate * 30;
	x_E = kijun_x + yoko * 30;
}

void Enemy::view_E(int a, int b)
{
	if (IsView_E == TRUE)
	{
		if (s_position_stage == 0)
		{
			if (s_position_difficult == 0)
			{
				switch (enemys_stage1[a][b].kind_E)
				{
				case Yellow:
					DrawGraph(x_E, y_E, E_YELLOW.handle, TRUE);
					break;

				case Green:
					DrawGraph(x_E, y_E, E_GREEN.handle, TRUE);
					break;

				case Blue:
					DrawGraph(x_E, y_E, E_BLUE.handle, TRUE);
					break;

				case Red:
					DrawGraph(x_E, y_E, E_RED.handle, TRUE);
					break;

				default:
					break;
				}
			}
			else if (s_position_difficult == 100)
			{
				switch (enemys_stage1_hard[a][b].kind_E)
				{
				case Yellow_Hard:
					DrawGraph(x_E, y_E, E_YELLOW_HARD.handle, TRUE);
					break;

				case Green_Hard:
					DrawGraph(x_E, y_E, E_GREEN_HARD.handle, TRUE);
					break;

				case Blue_Hard:
					DrawGraph(x_E, y_E, E_BLUE_HARD.handle, TRUE);
					break;

				case Red_Hard:
					DrawGraph(x_E, y_E, E_RED_HARD.handle, TRUE);
					break;

				default:
					break;
				}
			}
		}
		else if (s_position_stage == 100)
		{
			if (s_position_difficult == 0)
			{
				switch (enemys_stage2[a][b].kind_E)
				{
				case Yellow:
					DrawGraph(x_E, y_E, E_YELLOW.handle, TRUE);
					break;

				case Green:
					DrawGraph(x_E, y_E, E_GREEN.handle, TRUE);
					break;

				case Blue:
					DrawGraph(x_E, y_E, E_BLUE.handle, TRUE);
					break;

				case Red:
					DrawGraph(x_E, y_E, E_RED.handle, TRUE);
					break;

				default:
					break;
				}
			}
			else if (s_position_difficult == 100)
			{
				switch (enemys_stage2_hard[a][b].kind_E)
				{
				case Yellow_Hard:
					DrawGraph(x_E, y_E, E_YELLOW_HARD.handle, TRUE);
					break;

				case Green_Hard:
					DrawGraph(x_E, y_E, E_GREEN_HARD.handle, TRUE);
					break;

				case Blue_Hard:
					DrawGraph(x_E, y_E, E_BLUE_HARD.handle, TRUE);
					break;

				case Red_Hard:
					DrawGraph(x_E, y_E, E_RED_HARD.handle, TRUE);
					break;

				default:
					break;
				}
			}
		}
		else if (s_position_stage == 200)
		{
			if (s_position_difficult == 0)
			{
				switch (enemys_stage3[a][b].kind_E)
				{
				case Yellow:
					DrawGraph(x_E, y_E, E_YELLOW.handle, TRUE);
					break;

				case Green:
					DrawGraph(x_E, y_E, E_GREEN.handle, TRUE);
					break;

				case Blue:
					DrawGraph(x_E, y_E, E_BLUE.handle, TRUE);
					break;

				case Red:
					DrawGraph(x_E, y_E, E_RED.handle, TRUE);
					break;

				default:
					break;
				}
			}
			else if (s_position_difficult == 100)
			{
				switch (enemys_stage3_hard[a][b].kind_E)
				{
				case Yellow_Hard:
					DrawGraph(x_E, y_E, E_YELLOW_HARD.handle, TRUE);
					break;

				case Green_Hard:
					DrawGraph(x_E, y_E, E_GREEN_HARD.handle, TRUE);
					break;

				case Blue_Hard:
					DrawGraph(x_E, y_E, E_BLUE_HARD.handle, TRUE);
					break;

				case Red_Hard:
					DrawGraph(x_E, y_E, E_RED_HARD.handle, TRUE);
					break;

				default:
					break;
				}
			}
		}
	}
}

void Enemy::tama_random() 
{
	//1/1000の確率で敵から弾を出す
	int judge = GetRand(1000);
	if (judge == 0)
	{
		if (tama_enemy.IsView == FALSE)
		{
			tama_enemy.IsView = TRUE;
			tama_enemy.position(x_E + width_E, y_E + height_E);
		}
	}
}

void Enemy::enemy_tama_false()
{
	//敵の弾とプレイヤーが当たったら敵の弾を消す
	if (tama_enemy.x < PLAYER.x + PLAYER.width &&		//弾の左 < プレイヤーの右
		PLAYER.x < tama_enemy.x + tama_enemy.width &&	//プレイヤーの左 < 弾の右
		PLAYER.y < tama_enemy.y + tama_enemy.height &&	//プレイヤーの上 < 弾の下
		tama_enemy.y < PLAYER.y + PLAYER.height)		//弾の上 < プレイヤーの下
	{
		if (tama_enemy.IsView == TRUE)
		{
			PlaySoundMem(SE_REFLECT.handle, DX_PLAYTYPE_BACK);
			tama_enemy.IsView = FALSE;
		}
	}

	//敵の弾とプレイヤーの弾が当たったら両方消す
	for (int i = 0; i < 20; i++)
	{
		if (tama_enemy.x < Tamas[i].x + Tamas[i].width &&		//敵の弾の左 < プレイヤーの弾の右
			Tamas[i].x < tama_enemy.x + tama_enemy.width &&	//プレイヤーの弾の左 < 敵の弾の右
			Tamas[i].y < tama_enemy.y + tama_enemy.height &&	//プレイヤーの弾の上 < 敵の弾の下
			tama_enemy.y < Tamas[i].y + Tamas[i].height)		//敵の弾の上 < プレイヤーの弾の下
		{
			if (tama_enemy.IsView == TRUE && Tamas[i].IsView == TRUE)
			{
				PlaySoundMem(SE_BAKUHATSU.handle, DX_PLAYTYPE_BACK);
				Tamas[i].IsView = FALSE;
				tama_enemy.IsView = FALSE;
			}
		}
	}
}