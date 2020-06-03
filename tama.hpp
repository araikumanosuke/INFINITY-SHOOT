#pragma once

#include <DxLib.h>
#include "global.hpp"

class Tama {
public:
	int x;
	int y;
	bool IsView;

	Tama();
	void view();
	void position();
	~Tama() {}
};
