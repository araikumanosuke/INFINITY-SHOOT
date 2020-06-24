#include <DxLib.h>
#include "global.hpp"
#include "effect.hpp"

Effect::Effect(int Enemy_x,int Enemy_y)
{
	x = Enemy_x;
	y = Enemy_y;
}

void Effect::effect_view()
{
	for (int ef = 0; ef < 28; ef++)
	{
		DrawGraph(x, y, EFFECT[ef].handle, TRUE);
	}
}