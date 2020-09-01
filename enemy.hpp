#pragma once
#include <DxLib.h>
#include "tama.hpp"

class Enemy {
public:
	int x_E;
	int y_E;
	int width_E;
	int height_E;
	int kind_E;
	int hp_E;	//Hard���[�h�̂ݎg�p����̗�
	bool collision_flag;	//Hard���[�h�̂ݎg�p����A�@�̂ƓG���������Ă��邩�̔���
	bool IsView_E;
	Tama tama_enemy;

	Enemy();
	void position_E(int, int, int, int);
	void view_E(int, int);
	void tama_random(int, int);
	void enemy_tama_false();
	~Enemy() {}
};
