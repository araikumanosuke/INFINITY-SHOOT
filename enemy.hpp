#pragma once
#include <DxLib.h>

class Enemy {
public:
	int x_E;
	int y_E;
	int width_E;
	int height_E;
	int kind_E;
	int hp_E;	//Hardモードのみ使用する体力
	bool collision_flag;	//Hardモードのみ使用する、機体と敵が当たっているかの判定
	bool IsView_E;

	Enemy();
	void position_E(int, int, int, int);
	void view_E(int, int);
	~Enemy() {}
};
