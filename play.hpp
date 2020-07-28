#pragma once
#include <DxLib.h>

extern VOID MY_GAME_PLAY(VOID);			//ÉvÉåÉCâÊñ ÇÃä÷êî
extern void ENEMY_MOVE(void);
extern void ENEMY_COLOR(int, Enemy*);
extern void COLLISION_ENEMY_PLAYER_N(int*, int*, Enemy*);
extern void COLLISION_ENEMY_PLAYER_H(int*, int*, Enemy*);
extern void COLLISION_ENEMY_TAMA(int*, int*, Enemy*);