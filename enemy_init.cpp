#include <DxLib.h>
#include "global.hpp"
#include "enemy_init.hpp"

bool enemy_flag_stage1_syoki[9][21] = {
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
	{true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true},
	{true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true},
	{true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true},
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false},
	{false,false,false,true,true,true,false,false,false,true,true,true,false,false,false,true,true,true,false,false,false}
};

bool enemy_flag_stage2_syoki[13][13] = {
	{false,false,false,false,false,false,true,false,false,false,false,false,false},
	{false,false,false,false,false,true,true,true,false,false,false,false,false},
	{false,false,false,false,true,true,true,true,true,false,false,false,false},
	{true,true,true,true,true,true,true,true,true,true,true,true,true},
	{false,true,true,true,true,true,true,true,true,true,true,true,false},
	{false,false,true,true,true,true,true,true,true,true,true,false,false},
	{false,false,false,true,true,true,true,true,true,true,false,false,false},
	{false,false,true,true,true,true,true,true,true,true,true,false,false},
	{false,true,true,true,true,true,true,true,true,true,true,true,false},
	{true,true,true,true,true,true,true,true,true,true,true,true,true},
	{false,false,false,false,true,true,true,true,true,false,false,false,false},
	{false,false,false,false,false,true,true,true,false,false,false,false,false},
	{false,false,false,false,false,false,true,false,false,false,false,false,false}
};

bool enemy_flag_stage3_syoki[7][23] = {
	{true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true},
	{false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false},
	{true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true},
	{false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false},
	{true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true},
	{false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false},
	{true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true}
};

void ENEMY_INIT()
{
	if (s_position_stage == 0)
	{
		for (int a = 0; a < 9; a++)
		{
			for (int b = 0; b < 21; b++)
			{
				enemys_stage1[a][b].IsView_E = TRUE;
				PLAYER.x = 425;
				PLAYER.y = 500;
				if (enemy_flag_stage1_syoki[a][b] == true)
				{
					enemy_flag_stage1[a][b] = true;
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
				enemys_stage2[a][b].IsView_E = TRUE;
				PLAYER.x = 425;
				PLAYER.y = 500;
				if (enemy_flag_stage2_syoki[a][b] == true)
				{
					enemy_flag_stage2[a][b] = true;
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
				enemys_stage3[a][b].IsView_E = TRUE;
				PLAYER.x = 425;
				PLAYER.y = 500;
				if (enemy_flag_stage3_syoki[a][b] == true)
				{
					enemy_flag_stage3[a][b] = true;
				}
			}
		}
	}
}