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

extern int BGHandle;	//背景
extern int RHandle;		//タイトルロゴ
extern int THandle;		//三角
extern int PHandle;		//プレイヤー(機体)
//敵
extern int E_YHandle;
extern int E_YHardHandle;
extern int E_GHandle;
extern int E_GHardHandle;
extern int E_RHandle;
extern int E_RHardHandle;
extern int E_BHandle;
extern int E_BHardHandle;

extern int choice_FHandle;
extern int play_FHandle;

extern int t_position_title;
extern int t_position_stage;
extern int t_position_difficult;

extern bool t_flug;