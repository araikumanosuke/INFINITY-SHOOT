#pragma once
#include <DxLib.h>
#include "header.h"

//FPS関連
static int StartTimeFps;						//測定開始時刻
static int CountFps;							//カウンタ
static float CalcFps;							//計算結果
static int SampleNumFps = GAME_FPS_SPEED;		//平均を取るサンプル数

extern VOID MY_FPS_UPDATE(VOID);			//FPS値を計測、更新する関数
extern VOID MY_FPS_DRAW(VOID);				//FPS値を描画する関数
extern VOID MY_FPS_WAIT(VOID);				//FPS値を計測し、待つ関数

