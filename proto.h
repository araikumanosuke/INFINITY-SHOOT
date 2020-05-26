#pragma once
#include "header.h"

//########## プロトタイプ宣言 ##########
LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM);	//自作ウィンドウプロシージャ

extern VOID MY_FPS_UPDATE(VOID);			//FPS値を計測、更新する関数
extern VOID MY_FPS_DRAW(VOID);				//FPS値を描画する関数
extern VOID MY_FPS_WAIT(VOID);				//FPS値を計測し、待つ関数

extern VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する関数

extern VOID MY_GAME_TITLE(VOID);			//タイトル画面の関数
extern VOID MY_GAME_PLAY(VOID);			//プレイ画面の関数
extern VOID MY_GAME_END(VOID);				//エンド画面の関数

