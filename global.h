#pragma once
#include <DxLib.h>
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

//キーボード関連
extern char AllKeyState[256];			//すべてのキーの状態が入る

//シーン関連
extern int GameSceneNow;	//最初のゲーム画面をタイトルに設定

