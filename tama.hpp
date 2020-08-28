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
	void view(int, int);
	void position(int, int);
	void flag_false();
	void flag_false_E();
	~Tama() {}
};
