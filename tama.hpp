#pragma once
#include <DxLib.h>

class Tama {
public:
	int x;
	int y;
	int width;
	int height;
	bool IsView;

	Tama();
	void view();
	void position();
	void flag_false();
	~Tama() {}
};
