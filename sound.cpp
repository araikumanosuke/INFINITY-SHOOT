#include <DxLib.h>
#include "global.hpp"
#include "sound.hpp"

VOID MY_SOUND_LOAD(SOUND* s, const char* path)
{
	s->handle = LoadSoundMem(path);
	return;
}