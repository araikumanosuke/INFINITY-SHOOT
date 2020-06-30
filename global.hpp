#pragma once
#include <DxLib.h>
#include "header.hpp"
#include "enemy.hpp"

//########## 列挙型 ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,		//タイトル画面
	GAME_SCENE_RANKING,		//ランキング画面
	GAME_SCENE_STAGECHOICE,	//ステージ選択画面
	GAME_SCENE_PLAY,		//プレイ画面
	GAME_SCENE_END_CLEAR,	//エンド画面(クリア)
	GAME_SCENE_END_OVER		//エンド画面(ゲームオーバー)
};

enum ENEMY_KIND {
	Yellow,
	Green,
	Blue,
	Red,
	Yellow_Hard,
	Green_Hard,
	Blue_Hard,
	Red_Hard
};

struct IMAGE {
	int handle;
	char filepath[128];
	int x;
	int y;
	int width;
	int height;
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
extern IMAGE EFFECT[28];	//爆発エフェクト
//敵
extern IMAGE E_YELLOW;
extern IMAGE E_YELLOW_HARD;
extern IMAGE E_GREEN;
extern IMAGE E_GREEN_HARD;
extern IMAGE E_RED;
extern IMAGE E_RED_HARD;
extern IMAGE E_BLUE;
extern IMAGE E_BLUE_HARD;

extern int Small_FHandle;
extern int smallMiddle_FHandle;
extern int Middle_FHandle;
extern int bigMiddle_FHandle;
extern int Big_FHandle;

extern int s_position_title;
extern int s_position_ranking;
extern int s_position_stage;
extern int s_position_difficult;
extern int s_position_end_clear;

extern bool s_flag;

extern int enemy_kind_stage1[9][21];
extern int enemy_kind_stage2[13][13];
extern int enemy_kind_stage3[7][23];

extern int enemy_kind_stage1_hard[9][21];
extern int enemy_kind_stage2_hard[13][13];
extern int enemy_kind_stage3_hard[7][23];

extern Enemy enemys_stage1[9][21];
extern Enemy enemys_stage2[13][13];
extern Enemy enemys_stage3[7][23];

extern Enemy enemys_stage1_hard[9][21];
extern Enemy enemys_stage2_hard[13][13];
extern Enemy enemys_stage3_hard[7][23];

extern int enemy_count_stage1;
extern int enemy_count_stage2;
extern int enemy_count_stage3;

extern bool Syoki_Flag;
extern double Current_Timer_Sec;
extern int Current_Timer_Min;

extern bool enemy_move_flag;
extern int enemy_move_num;
extern int enemy_move_tmp;

extern bool S1_Hard_PlayFlag;
extern bool S2_Normal_PlayFlag;
extern bool S2_Hard_PlayFlag;
extern bool S3_Normal_PlayFlag;
extern bool S3_Hard_PlayFlag;