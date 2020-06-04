#include <DxLib.h>
#include "enemy.hpp"
#include "global.hpp"

Enemy::Enemy()
{
	x_E = 0;
	y_E = 0;
	IsView_E = TRUE;
}

void Enemy::position_E(int a, int b)
{
	x_E = 300 + a * 30;
	y_E = 200 + b * 30;
}

void Enemy::view_E()
{
	if (IsView_E == TRUE)
	{
		DrawGraph(x_E, y_E, E_YELLOW.handle, TRUE);
	}
}