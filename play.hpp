#pragma once
#include <DxLib.h>

extern VOID MY_GAME_PLAY(VOID);			//ÉvÉåÉCâÊñ ÇÃä÷êî
extern int ENEMY_COUNT();
extern void ENEMY_MOVE();
extern void ENEMY_TURN(Enemy*);
extern void ENEMY_COLOR(int, Enemy*);
extern void COLLISION_ENEMY_PLAYER_N(int*, int*, Enemy*);
extern void COLLISION_ENEMY_PLAYER_H(int*, int*, Enemy*);
extern void COLLISION_ENEMY_TAMA_METHOD(int*, int*, Enemy*);
extern void GAMEOVER_METHOD();
extern void WAIT();