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

struct IMAGE {
	int handle;
	char filepath[128];
	int x;
	int y;
};

//########## グローバル変数 ##########

//キーボード関連
extern char AllKeyState[256];			//すべてのキーの状態が入る

//シーン関連
extern int GameSceneNow;	//最初のゲーム画面をタイトルに設定

extern IMAGE BG;	//背景
extern IMAGE ROGO;		//タイトルロゴ
extern IMAGE SANKAKU;		//三角
extern IMAGE TAMA;		//弾
extern IMAGE PLAYER;		//プレイヤー(機体)
//敵
extern IMAGE E_YELLOW;
extern IMAGE E_YELLOW_HARD;
extern IMAGE E_GREEN;
extern IMAGE E_GREEN_HARD;
extern IMAGE E_RED;
extern IMAGE E_RED_HARD;
extern IMAGE E_BLUE;
extern IMAGE E_BLUE_HARD;

extern int choice_FHandle;
extern int play_FHandle;

extern int s_position_title;
extern int s_position_stage;
extern int s_position_difficult;

extern bool s_flug;