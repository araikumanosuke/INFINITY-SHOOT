#include <DxLib.h>
#include "global.hpp"
#include "tama.hpp"

Tama::Tama()
{
	x = 0;
	y = 0;
	IsView = FALSE;
}

void Tama::view()
{
	if (IsView == TRUE)
	{
		DrawGraph(x, y, TAMA.handle, TRUE);
		y -= 4;
	}
}

void Tama::position()
{
	x = PLAYER.x + 5;
	y = PLAYER.y;
}

void Tama::flag_false()
{
	if (y < -20)
	{
		IsView = FALSE;
	}
}