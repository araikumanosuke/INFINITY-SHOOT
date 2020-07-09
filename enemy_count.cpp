#include <DxLib.h>
#include "global.hpp"
#include "enemy_count.hpp"

int ENEMY_COUNT()
{
	int count = 0;
	if (s_position_stage == 0)
	{
		if (s_position_difficult == 0)
		{
			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 21; b++)
				{
					if (enemy_kind_stage1[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
		else if (s_position_difficult == 100)
		{
			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 21; b++)
				{
					if (enemy_kind_stage1_hard[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
	}
	else if (s_position_stage == 100)
	{
		if (s_position_difficult == 0)
		{
			for (int a = 0; a < 13; a++)
			{
				for (int b = 0; b < 13; b++)
				{
					if (enemy_kind_stage2[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
		else if (s_position_difficult == 100)
		{
			for (int a = 0; a < 13; a++)
			{
				for (int b = 0; b < 13; b++)
				{
					if (enemy_kind_stage2_hard[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
	}
	else if (s_position_stage == 200)
	{
		if (s_position_difficult == 0)
		{
			for (int a = 0; a < 7; a++)
			{
				for (int b = 0; b < 23; b++)
				{
					if (enemy_kind_stage3[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
		else if (s_position_difficult == 100)
		{
			for (int a = 0; a < 7; a++)
			{
				for (int b = 0; b < 23; b++)
				{
					if (enemy_kind_stage3_hard[a][b] != -1)
					{
						count++;
					}
				}
			}
		}
	}

	return count;
}