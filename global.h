#pragma once
#include <DxLib.h>
#include "header.h"

//########## 列挙型 ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,		//タイトル画面
	GAME_SCENE_RANKING,		//ランキング画面
	GAME_SCENE_STAGECHOICE,	//ステージ選択画面
	GAME_SCENE_PLAY,		//プレイ画面
	GAME_SCENE_END_CLEAR,	//エンド画面(クリア)
	GAME_SCENE_END_OVER		//エンド画面(ゲームオーバー)
};

//########## グローバル変数 ##########

//キーボード関連
extern char AllKeyState[256];			//すべてのキーの状態が入る

//シーン関連
extern int GameSceneNow;	//最初のゲーム画面をタイトルに設定

extern int BGHandle;
extern int RHandle;
extern int THandle;

extern int choice_FHandle;
extern int t_position;