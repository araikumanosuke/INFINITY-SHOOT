#include <DxLib.h>
#include "enemy.hpp"
#include "global.hpp"

Enemy::Enemy()
{
	x_E = 570;
	y_E = 570;
	width_E = 30;
	height_E = 30;
	IsView_E = TRUE;
}

void Enemy::position_E(int tate, int yoko, int kijun_x, int kijun_y)
{
	y_E = kijun_y + tate * 30;
	x_E = kijun_x + yoko * 30;
}

void Enemy::view_E()
{
	if (IsView_E == TRUE)
	{
		DrawGraph(x_E, y_E, E_YELLOW.handle, TRUE);
	}
}