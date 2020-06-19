#include <DxLib.h>
#include "enemy.hpp"
#include "global.hpp"

Enemy::Enemy()
{
	x_E = 570;
	y_E = 570;
	width_E = 30;
	height_E = 30;
	kind_E = -1;
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
		else if (s_position_stage == 100)
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
		else if (s_position_stage == 200)
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
	}
}