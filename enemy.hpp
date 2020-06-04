#pragma once
#include <DxLib.h>

class Enemy {
public:
	int x_E;
	int y_E;
	bool IsView_E;

	Enemy();
	void position_E(int, int);
	void view_E();
	~Enemy() {}
};
