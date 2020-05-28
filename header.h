#pragma once
#include <DxLib.h>

//########## マクロ定義 ##########
#define GAME_WIDTH	900		//画面の横の大きさ
#define GAME_HEIGHT	600		//画面の縦の大きさ
#define GAME_COLOR	32		//画面のカラービット

#define GAME_WINDOW_NAME	"GAME TITLE"		//ウィンドウのタイトル
#define GAME_WINDOW_MODECHANGE	TRUE			//TRUE：ウィンドウモード / FALSE：フルスクリーン

#define SET_WINDOW_ST_MODE_DEFAULT			0	//デフォルト
#define SET_WINDOW_ST_MODE_TITLE_NONE		1	//タイトルバーなし
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2	//タイトルバーとフレームなし
#define SET_WINDOW_ST_MODE_FLAME_NONE		3	//フレームなし

#define GAME_FPS_SPEED					   60

#define GAME_IMAGE_BACK				"IMAGE\\back\\back_3.png"
#define GAME_IMAGE_KITAI			"IMAGE\\kitai\\kitai_black.png"
#define GAME_IMAGE_ROGO				"IMAGE\\rogo\\rogo.png"
#define GAME_IMAGE_TRIANGLE			"IMAGE\\sankaku.png"
#define GAME_IMAGE_TEKI_YELLOW		"IMAGE\\enemy\\enemy_yellow.png"
#define GAME_IMAGE_TEKI_YELLOW_HARD	"IMAGE\\enemy\\enemy_yellow_hard.png"
#define GAME_IMAGE_TEKI_RED			"IMAGE\\enemy\\enemy_red.png"
#define GAME_IMAGE_TEKI_RED_HARD	"IMAGE\\enemy\\enemy_red_hard.png"
#define GAME_IMAGE_TEKI_GREEN		"IMAGE\\enemy\\enemy_green.png"
#define GAME_IMAGE_TEKI_GREEN_HARD	"IMAGE\\enemy\\enemy_green_hard.png"
#define GAME_IMAGE_TEKI_BLUE		"IMAGE\\enemy\\enemy_blue.png"
#define GAME_IMAGE_TEKI_BLUE_HARD	"IMAGE\\enemy\\enemy_blue_hard.png"
