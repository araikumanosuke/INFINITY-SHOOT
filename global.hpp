#pragma once
#include <DxLib.h>
#include <stdio.h>
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

struct SOUND {
	int handle;
	char filepath[128];
	int playtype;
};

class TIME_RANK {
public:
	double first_sec = 0.0;
	double second_sec = 0.0;
	double third_sec = 0.0;
	double forth_sec = 0.0;
	double fifth_sec = 0.0;

	void time_read(char t[]) {
		FILE *file;
		fopen_s(&file, t, "r");
		fscanf_s(file, "%lf,%lf,%lf,%lf,%lf", &first_sec, &second_sec, &third_sec, &forth_sec, &fifth_sec);
		fclose(file);
	}

	void time_write(char t[]) {
		FILE* file;
		fopen_s(&file, t, "w");
		fprintf_s(file, "%.2lf,%.2lf,%.2lf,%.2lf,%.2lf", first_sec, second_sec, third_sec, forth_sec, fifth_sec);
		fclose(file);
	}
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
extern IMAGE TAMA_ENEMY;	//弾
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

//音
extern SOUND SE_BAKUHATSU;
extern SOUND SE_SHOT;
extern SOUND SE_REFLECT;
extern SOUND SE_CANCEL;
extern SOUND SE_SELECT;
extern SOUND SE_ENTER;
extern SOUND BGM_TITLE;
extern SOUND BGM_RANK;
extern SOUND BGM_PLAY;
extern SOUND GAMEOVER;
extern SOUND CLEAR;

extern int Small_FHandle;
extern int small_YU_FHandle;
extern int Middle_FHandle;
extern int bigMiddle_FHandle;
extern int Big_FHandle;
extern int superBig_FHandle;

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
extern int enemy_count_stage1_hard;
extern int enemy_count_stage2_hard;
extern int enemy_count_stage3_hard;

extern bool Syoki_Flag;
extern double Current_Timer_Sec;
extern int Current_Timer_Min;

extern bool enemy_move_flag;
extern int enemy_move_num;
extern int enemy_move_tmp;

extern int S1_Hard_PlayFlag;
extern int S2_Normal_PlayFlag;
extern int S2_Hard_PlayFlag;
extern int S3_Normal_PlayFlag;
extern int S3_Hard_PlayFlag;

extern bool ranking_flag_update;
extern bool S1_Hard_release_once;
extern bool S2_Hard_release_once;
extern bool S3_Hard_release_once;

extern TIME_RANK stage1_N;
extern TIME_RANK stage1_H;
extern TIME_RANK stage2_N;
extern TIME_RANK stage2_H;
extern TIME_RANK stage3_N;
extern TIME_RANK stage3_H;