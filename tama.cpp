#include <DxLib.h>
#include "global.hpp"
#include "tama.hpp"

Tama::Tama()
{
	x = 0;
	y = 0;
	width = 20;
	height = 20;
	IsView = FALSE;
}

void Tama::view(int move_num, int handle)
{
	if (IsView == TRUE)
	{
		DrawGraph(x, y, handle, TRUE);
		y -= move_num;
	}
}

void Tama::position(int h_x, int h_y)
{
	x = h_x + 5;
	y = h_y;
}

void Tama::flag_false()
{
	if (y < -20)
	{
		IsView = FALSE;
	}
}

void Tama::flag_false_E()
{
	if (y > 620)
	{
		IsView = FALSE;
	}
}