#pragma once
#include "header.h"

//########## 列挙型 ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,	//タイトル画面
	GAME_SCENE_PLAY,	//プレイ画面
	GAME_SCENE_END		//エンド画面
};

//########## グローバル変数 ##########

//ウィンドウ関係
extern WNDPROC WndProc;						//ウィンドウプロシージャのアドレス
extern BOOL IsWM_CREATE = FALSE;				//WM_CREATEが正常に動作したか判断する

//シーン関連
int GameSceneNow = (int)GAME_SCENE_TITLE;	//最初のゲーム画面をタイトルに設定

