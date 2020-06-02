#include <DxLib.h>
#include "global.h"

void image_load(IMAGE *i,int x,int y,const char *path)
{
	wsprintf(i->filepath, path);
	i->handle = LoadGraph(i->filepath);

	i->x = x;
	i->y = y;
}