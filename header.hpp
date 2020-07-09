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

#define GAME_IMAGE_BACK					"IMAGE\\back\\back_3.png"
#define GAME_IMAGE_PLAYER				"IMAGE\\player\\kitai_black2.png"
#define GAME_IMAGE_ROGO					"IMAGE\\rogo\\rogo.png"
#define GAME_IMAGE_SANKAKU				"IMAGE\\sankaku.png"
#define GAME_IMAGE_TAMA					"IMAGE\\tama.png"
#define GAME_IMAGE_ENEMY_YELLOW			"IMAGE\\enemy\\enemy_yellow.png"
#define GAME_IMAGE_ENEMY_YELLOW_HARD	"IMAGE\\enemy\\enemy_yellow_hard.png"
#define GAME_IMAGE_ENEMY_RED			"IMAGE\\enemy\\enemy_red.png"
#define GAME_IMAGE_ENEMY_RED_HARD		"IMAGE\\enemy\\enemy_red_hard.png"
#define GAME_IMAGE_ENEMY_GREEN			"IMAGE\\enemy\\enemy_green.png"
#define GAME_IMAGE_ENEMY_GREEN_HARD		"IMAGE\\enemy\\enemy_green_hard.png"
#define GAME_IMAGE_ENEMY_BLUE			"IMAGE\\enemy\\enemy_blue.png"
#define GAME_IMAGE_ENEMY_BLUE_HARD		"IMAGE\\enemy\\enemy_blue_hard.png"

#define GAME_IMAGE_EFFECT1				"IMAGE\\effect\\effect1.png"
#define GAME_IMAGE_EFFECT2				"IMAGE\\effect\\effect2.png"
#define GAME_IMAGE_EFFECT3				"IMAGE\\effect\\effect3.png"
#define GAME_IMAGE_EFFECT4				"IMAGE\\effect\\effect4.png"
#define GAME_IMAGE_EFFECT5				"IMAGE\\effect\\effect5.png"
#define GAME_IMAGE_EFFECT6				"IMAGE\\effect\\effect6.png"
#define GAME_IMAGE_EFFECT7				"IMAGE\\effect\\effect7.png"
#define GAME_IMAGE_EFFECT8				"IMAGE\\effect\\effect8.png"
#define GAME_IMAGE_EFFECT9				"IMAGE\\effect\\effect9.png"
#define GAME_IMAGE_EFFECT10				"IMAGE\\effect\\effect10.png"
#define GAME_IMAGE_EFFECT11				"IMAGE\\effect\\effect11.png"
#define GAME_IMAGE_EFFECT12				"IMAGE\\effect\\effect12.png"
#define GAME_IMAGE_EFFECT13				"IMAGE\\effect\\effect13.png"
#define GAME_IMAGE_EFFECT14				"IMAGE\\effect\\effect14.png"

#define GAME_SOUND_BAKUHATSU			"SOUND\\bakuhatsu.mp3"
#define GAME_SOUND_SHOT					"SOUND\\shot1.mp3"

#define GAME_RANK_TXT1_N				"rank_1_N.txt"
#define GAME_RANK_TXT1_H				"rank_1_H.txt"
#define GAME_RANK_TXT2_N				"rank_2_N.txt"
#define GAME_RANK_TXT2_H				"rank_2_H.txt"
#define GAME_RANK_TXT3_N				"rank_3_N.txt"
#define GAME_RANK_TXT3_H				"rank_3_H.txt"