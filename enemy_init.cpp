#include <DxLib.h>
#include "global.hpp"
#include "enemy_init.hpp"

int enemy_kind_stage1_syoki[9][21] = {
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

int enemy_kind_stage1_hard_syoki[9][21] = {
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

int enemy_kind_stage2_syoki[13][13] = {
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

int enemy_kind_stage2_hard_syoki[13][13] = {
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

int enemy_kind_stage3_syoki[7][23] = {
	{Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green},
	{-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1},
	{Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow},
	{-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1},
	{Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red},
	{-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1},
	{Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow,-1,Red,-1,Yellow,-1,Green,-1,Blue,-1,Green,-1,Yellow}
};

int enemy_kind_stage3_hard_syoki[7][23] = {
	{Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard},
	{-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1},
	{Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard},
	{-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1},
	{Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard},
	{-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1},
	{Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard,-1,Red_Hard,-1,Yellow_Hard,-1,Green_Hard,-1,Blue_Hard,-1,Green_Hard,-1,Yellow_Hard}
};

void ENEMY_INIT()
{
	if (s_position_stage == 0)
	{
		for (int a = 0; a < 9; a++)
		{
			for (int b = 0; b < 21; b++)
			{
				if (s_position_difficult == 0)
				{
					enemys_stage1[a][b].IsView_E = TRUE;
					PLAYER.x = 425;
					PLAYER.y = 500;
					switch (enemy_kind_stage1_syoki[a][b])
					{
					case Yellow:
						enemy_kind_stage1[a][b] = Yellow;
						break;

					case Green:
						enemy_kind_stage1[a][b] = Green;
						break;

					case Blue:
						enemy_kind_stage1[a][b] = Blue;
						break;

					case Red:
						enemy_kind_stage1[a][b] = Red;
						break;

					default:
						break;
					}
				}
				else if (s_position_difficult == 100)
				{
					enemys_stage1_hard[a][b].IsView_E = TRUE;
					enemys_stage1_hard[a][b].hp_E = 3;
					PLAYER.x = 425;
					PLAYER.y = 500;
					switch (enemy_kind_stage1_hard_syoki[a][b])
					{
					case Yellow_Hard:
						enemy_kind_stage1_hard[a][b] = Yellow_Hard;
						break;

					case Green_Hard:
						enemy_kind_stage1_hard[a][b] = Green_Hard;
						break;

					case Blue_Hard:
						enemy_kind_stage1_hard[a][b] = Blue_Hard;
						break;

					case Red_Hard:
						enemy_kind_stage1_hard[a][b] = Red_Hard;
						break;

					default:
						break;
					}
				}
			}
		}
	}
	else if (s_position_stage == 100)
	{
		for (int a = 0; a < 13; a++)
		{
			for (int b = 0; b < 13; b++)
			{
				if (s_position_difficult == 0)
				{
					enemys_stage2[a][b].IsView_E = TRUE;
					PLAYER.x = 425;
					PLAYER.y = 500;
					switch (enemy_kind_stage2_syoki[a][b])
					{
					case Yellow:
						enemy_kind_stage2[a][b] = Yellow;
						break;

					case Green:
						enemy_kind_stage2[a][b] = Green;
						break;

					case Blue:
						enemy_kind_stage2[a][b] = Blue;
						break;

					case Red:
						enemy_kind_stage2[a][b] = Red;
						break;

					default:
						break;
					}
				}
				else if (s_position_difficult == 100)
				{
					enemys_stage2_hard[a][b].IsView_E = TRUE;
					enemys_stage2_hard[a][b].hp_E = 3;
					PLAYER.x = 425;
					PLAYER.y = 500;
					switch (enemy_kind_stage2_hard_syoki[a][b])
					{
					case Yellow_Hard:
						enemy_kind_stage2_hard[a][b] = Yellow_Hard;
						break;

					case Green_Hard:
						enemy_kind_stage2_hard[a][b] = Green_Hard;
						break;

					case Blue_Hard:
						enemy_kind_stage2_hard[a][b] = Blue_Hard;
						break;

					case Red_Hard:
						enemy_kind_stage2_hard[a][b] = Red_Hard;
						break;

					default:
						break;
					}
				}
			}
		}
	}
	else if (s_position_stage == 200)
	{
		for (int a = 0; a < 7; a++)
		{
			for (int b = 0; b < 23; b++)
			{
				if (s_position_difficult == 0)
				{
					enemys_stage3[a][b].IsView_E = TRUE;
					PLAYER.x = 425;
					PLAYER.y = 500;
					switch (enemy_kind_stage3_syoki[a][b])
					{
					case Yellow:
						enemy_kind_stage3[a][b] = Yellow;
						break;

					case Green:
						enemy_kind_stage3[a][b] = Green;
						break;

					case Blue:
						enemy_kind_stage3[a][b] = Blue;
						break;

					case Red:
						enemy_kind_stage3[a][b] = Red;
						break;

					default:
						break;
					}
				}
				else if (s_position_difficult == 100)
				{
					enemys_stage3_hard[a][b].IsView_E = TRUE;
					enemys_stage3_hard[a][b].hp_E = 3;
					PLAYER.x = 425;
					PLAYER.y = 500;
					switch (enemy_kind_stage3_hard_syoki[a][b])
					{
					case Yellow_Hard:
						enemy_kind_stage3_hard[a][b] = Yellow_Hard;
						break;

					case Green_Hard:
						enemy_kind_stage3_hard[a][b] = Green_Hard;
						break;

					case Blue_Hard:
						enemy_kind_stage3_hard[a][b] = Blue_Hard;
						break;

					case Red_Hard:
						enemy_kind_stage3_hard[a][b] = Red_Hard;
						break;

					default:
						break;
					}
				}
			}
		}
	}
}