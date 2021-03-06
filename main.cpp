//########## ヘッダーファイル読み込み ##########
#include <DxLib.h>
#include <stdio.h>
#include "header.hpp"
#include "global.hpp"
#include "main.hpp"
#include "fps.hpp"
#include "title.hpp"
#include "key.hpp"
#include "play.hpp"
#include "end_over.hpp"
#include "ranking.hpp"
#include "howto.hpp"
#include "stagechoice.hpp"
#include "end_clear.hpp"
#include "image.hpp"
#include "sound.hpp"

//グローバル変数の実体たち
int GameSceneNow = (int)GAME_SCENE_TITLE;

char AllKeyState[256];	//すべてのキーの状態が入る

IMAGE BG;			//背景
IMAGE ROGO;			//ロゴ
IMAGE SANKAKU;		//三角形
IMAGE TAMA;			//弾
IMAGE TAMA_ENEMY;	//弾
IMAGE PLAYER;		//プレイヤー(機体)
IMAGE EFFECT[28];	//爆発エフェクト

//敵
IMAGE E_YELLOW;
IMAGE E_YELLOW_HARD;
IMAGE E_GREEN;
IMAGE E_GREEN_HARD;
IMAGE E_RED;
IMAGE E_RED_HARD;
IMAGE E_BLUE;
IMAGE E_BLUE_HARD;

//音
SOUND SE_BAKUHATSU;
SOUND SE_SHOT;
SOUND SE_REFLECT;
SOUND SE_CANCEL;
SOUND SE_SELECT;
SOUND SE_ENTER;

SOUND BGM_TITLE;
SOUND BGM_RANK;
SOUND BGM_PLAY;
SOUND GAMEOVER;
SOUND CLEAR;

char txt[6][100] = {
	{GAME_RANK_TXT1_N},
	{GAME_RANK_TXT1_H},
	{GAME_RANK_TXT2_N},
	{GAME_RANK_TXT2_H},
	{GAME_RANK_TXT3_N},
	{GAME_RANK_TXT3_H},
};

int Small_FHandle;
int small_YU_FHandle;
int Middle_FHandle;
int bigMiddle_FHandle;
int Big_FHandle;
int superBig_FHandle;

int S1_Hard_PlayFlag;
int S2_Normal_PlayFlag;
int S2_Hard_PlayFlag;
int S3_Normal_PlayFlag;
int S3_Hard_PlayFlag;

//ウィンドウ関係
static WNDPROC WndProc;						//ウィンドウプロシージャのアドレス

static BOOL IsWM_CREATE = FALSE;				//WM_CREATEが正常に動作したか判断する

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);			//タイトルバー

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//タイトルの文字

	SetAlwaysRunFlag(TRUE);                                //非アクティブでも実行する

	if (DxLib_Init() == -1) { return -1; }						//ＤＸライブラリ初期化処理

	SetDrawScreen(DX_SCREEN_BACK);								//Draw系関数は裏画面に描画

	image_load(&BG, 0, 0, GAME_IMAGE_BACK);
	image_load(&PLAYER, 425, 500, GAME_IMAGE_PLAYER);
	image_load(&ROGO, 80, 40, GAME_IMAGE_ROGO);
	image_load(&SANKAKU, 0, 0, GAME_IMAGE_SANKAKU);
	image_load(&TAMA, 0, 0, GAME_IMAGE_TAMA);
	image_load(&TAMA_ENEMY, 0, 0, GAME_IMAGE_TAMA_ENEMY);
	image_load(&E_YELLOW, 425, 300, GAME_IMAGE_ENEMY_YELLOW);
	image_load(&E_YELLOW_HARD, 0, 0, GAME_IMAGE_ENEMY_YELLOW_HARD);
	image_load(&E_GREEN, 0, 0, GAME_IMAGE_ENEMY_GREEN);
	image_load(&E_GREEN_HARD, 0, 0,  GAME_IMAGE_ENEMY_GREEN_HARD);
	image_load(&E_RED, 0, 0, GAME_IMAGE_ENEMY_RED);
	image_load(&E_RED_HARD, 0, 0, GAME_IMAGE_ENEMY_RED_HARD);
	image_load(&E_BLUE, 0, 0, GAME_IMAGE_ENEMY_BLUE);
	image_load(&E_BLUE_HARD, 0, 0, GAME_IMAGE_ENEMY_BLUE_HARD);
	
	image_load(&EFFECT[0], 0, 0, GAME_IMAGE_EFFECT1);
	image_load(&EFFECT[1], 0, 0, GAME_IMAGE_EFFECT2);
	image_load(&EFFECT[2], 0, 0, GAME_IMAGE_EFFECT3);
	image_load(&EFFECT[3], 0, 0, GAME_IMAGE_EFFECT4);
	image_load(&EFFECT[4], 0, 0, GAME_IMAGE_EFFECT5);
	image_load(&EFFECT[5], 0, 0, GAME_IMAGE_EFFECT6);
	image_load(&EFFECT[6], 0, 0, GAME_IMAGE_EFFECT7);
	image_load(&EFFECT[7], 0, 0, GAME_IMAGE_EFFECT8);
	image_load(&EFFECT[8], 0, 0, GAME_IMAGE_EFFECT9);
	image_load(&EFFECT[9], 0, 0, GAME_IMAGE_EFFECT10);
	image_load(&EFFECT[10], 0, 0, GAME_IMAGE_EFFECT11);
	image_load(&EFFECT[11], 0, 0, GAME_IMAGE_EFFECT12);
	image_load(&EFFECT[12], 0, 0, GAME_IMAGE_EFFECT13);
	image_load(&EFFECT[13], 0, 0, GAME_IMAGE_EFFECT14);
	image_load(&EFFECT[14], 0, 0, GAME_IMAGE_EFFECT14);
	image_load(&EFFECT[15], 0, 0, GAME_IMAGE_EFFECT13);
	image_load(&EFFECT[16], 0, 0, GAME_IMAGE_EFFECT12);
	image_load(&EFFECT[17], 0, 0, GAME_IMAGE_EFFECT11);
	image_load(&EFFECT[18], 0, 0, GAME_IMAGE_EFFECT10);
	image_load(&EFFECT[19], 0, 0, GAME_IMAGE_EFFECT9);
	image_load(&EFFECT[20], 0, 0, GAME_IMAGE_EFFECT8);
	image_load(&EFFECT[21], 0, 0, GAME_IMAGE_EFFECT7);
	image_load(&EFFECT[22], 0, 0, GAME_IMAGE_EFFECT6);
	image_load(&EFFECT[23], 0, 0, GAME_IMAGE_EFFECT5);
	image_load(&EFFECT[24], 0, 0, GAME_IMAGE_EFFECT4);
	image_load(&EFFECT[25], 0, 0, GAME_IMAGE_EFFECT3);
	image_load(&EFFECT[26], 0, 0, GAME_IMAGE_EFFECT2);
	image_load(&EFFECT[27], 0, 0, GAME_IMAGE_EFFECT1);

	MY_SOUND_LOAD(&SE_BAKUHATSU, GAME_SOUND_BAKUHATSU);
	MY_SOUND_LOAD(&SE_SHOT, GAME_SOUND_SHOT);
	MY_SOUND_LOAD(&SE_REFLECT, GAME_SOUND_REFLECT);
	MY_SOUND_LOAD(&SE_CANCEL, GAME_SOUND_CANCEL);
	MY_SOUND_LOAD(&SE_SELECT, GAME_SOUND_SELECT);
	MY_SOUND_LOAD(&SE_ENTER, GAME_SOUND_ENTER);
	MY_SOUND_LOAD(&BGM_TITLE, GAME_SOUND_BGM_TITLE);
	MY_SOUND_LOAD(&BGM_RANK, GAME_SOUND_BGM_RANK);
	MY_SOUND_LOAD(&BGM_PLAY, GAME_SOUND_BGM_PLAY);
	MY_SOUND_LOAD(&GAMEOVER, GAME_SOUND_GAMEOVER);
	MY_SOUND_LOAD(&CLEAR, GAME_SOUND_CLEAR);

	ChangeVolumeSoundMem(255 * 70 / 100, SE_BAKUHATSU.handle);
	ChangeVolumeSoundMem(255 * 70 / 100, SE_SHOT.handle);
	ChangeVolumeSoundMem(255 * 70 / 100, SE_REFLECT.handle);

	ChangeVolumeSoundMem(255 * 50 / 100, BGM_TITLE.handle);
	ChangeVolumeSoundMem(255 * 50 / 100, BGM_RANK.handle);
	ChangeVolumeSoundMem(255 * 50 / 100, BGM_PLAY.handle);

	Small_FHandle = CreateFontToHandle("HG教科書体", 24, 9, DX_FONTTYPE_ANTIALIASING);
	small_YU_FHandle = CreateFontToHandle("游ゴシック", 24, 5, DX_FONTTYPE_ANTIALIASING);
	Middle_FHandle = CreateFontToHandle("HG教科書体", 42, 5, DX_FONTTYPE_ANTIALIASING);
	bigMiddle_FHandle = CreateFontToHandle("HG教科書体", 48, 5, DX_FONTTYPE_ANTIALIASING);
	Big_FHandle = CreateFontToHandle("HG教科書体", 60, 5, DX_FONTTYPE_ANTIALIASING);
	superBig_FHandle = CreateFontToHandle("HG教科書体", 100, 5, DX_FONTTYPE_ANTIALIASING);

	stage1_N.time_read(txt[0]);
	stage1_H.time_read(txt[1]);
	stage2_N.time_read(txt[2]);
	stage2_H.time_read(txt[3]);
	stage3_N.time_read(txt[4]);
	stage3_H.time_read(txt[5]);

	FILE* f;
	fopen_s(&f, "PlayFlag.txt", "r");
	fscanf_s(f, "%d,%d,%d,%d,%d", &S1_Hard_PlayFlag, &S2_Normal_PlayFlag, &S2_Hard_PlayFlag, &S3_Normal_PlayFlag, &S3_Hard_PlayFlag);
	fclose(f);

	//無限ループ
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了

		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		MY_ALL_KEYDOWN_UPDATE();				//キーの状態を取得

		//シーン選択
		switch (GameSceneNow)
		{
		case (int)GAME_SCENE_TITLE:	//タイトル画面の処理ここから

			MY_GAME_TITLE();	//タイトル画面の処理

			break;	//タイトル画面の処理ここまで

		case (int)GAME_SCENE_RANKING:	//ランキング画面の処理ここから

			MY_GAME_RANKING();	//ランキング画面の処理

			break;	//ランキング画面の処理ここまで

		case (int)GAME_SCENE_HOWTO:	//操作説明画面の処理ここから

			MY_GAME_HOWTO();	//操作説明画面の処理

			break;	//操作説明画面の処理ここまで

		case (int)GAME_SCENE_STAGECHOICE:	//ステージ選択画面の処理ここから

			MY_GAME_STAGECHOICE();	//ステージ選択画面の処理

			break;	//ステージ選択画面の処理ここまで

		case (int)GAME_SCENE_PLAY:	//プレイ画面の処理ここから

			MY_GAME_PLAY();		//プレイ画面の処理

			break;	//プレイ画面の処理ここまで

		case (int)GAME_SCENE_END_CLEAR:	//エンド画面(ゲームクリア)の処理ここから

			MY_GAME_END_CLEAR();	//エンド画面(ゲームクリア)の処理

			break;	//エンド画面(ゲームクリア)の処理ここまで

		case (int)GAME_SCENE_END_OVER:	//エンド画面(ゲームオーバー)の処理ここから

			MY_GAME_END_OVER();		//エンド画面(ゲームオーバー)の処理

			break;	//エンド画面(ゲームオーバー)の処理ここまで

		default:

			break;

		}

		MY_FPS_UPDATE();						//FPSの処理[更新]

		//MY_FPS_DRAW();		//FPSの処理[描画]

		ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画

		MY_FPS_WAIT();		//FPSの処理[待つ]
	}

	stage1_N.time_write(txt[0]);
	stage1_H.time_write(txt[1]);
	stage2_N.time_write(txt[2]);
	stage2_H.time_write(txt[3]);
	stage3_N.time_write(txt[4]);
	stage3_H.time_write(txt[5]);

	fopen_s(&f, "PlayFlag.txt", "w");
	fprintf_s(f, "%d,%d,%d,%d,%d", S1_Hard_PlayFlag, S2_Normal_PlayFlag, S2_Hard_PlayFlag, S3_Normal_PlayFlag, S3_Hard_PlayFlag);
	fclose(f);

	DeleteGraph(BG.handle);
	DeleteGraph(ROGO.handle);
	DeleteGraph(SANKAKU.handle);
	DeleteGraph(TAMA.handle);
	DeleteGraph(PLAYER.handle);
	DeleteGraph(E_YELLOW.handle);
	DeleteGraph(E_YELLOW_HARD.handle);
	DeleteGraph(E_GREEN.handle);
	DeleteGraph(E_GREEN_HARD.handle);
	DeleteGraph(E_RED.handle);
	DeleteGraph(E_RED_HARD.handle);
	DeleteGraph(E_BLUE.handle);
	DeleteGraph(E_BLUE_HARD.handle);
	DeleteGraph(EFFECT[0].handle);
	DeleteGraph(EFFECT[1].handle);
	DeleteGraph(EFFECT[2].handle);
	DeleteGraph(EFFECT[3].handle);
	DeleteGraph(EFFECT[4].handle);
	DeleteGraph(EFFECT[5].handle);
	DeleteGraph(EFFECT[6].handle);
	DeleteGraph(EFFECT[7].handle);
	DeleteGraph(EFFECT[8].handle);
	DeleteGraph(EFFECT[9].handle);
	DeleteGraph(EFFECT[10].handle);
	DeleteGraph(EFFECT[11].handle);
	DeleteGraph(EFFECT[12].handle);
	DeleteGraph(EFFECT[13].handle);
	DeleteGraph(EFFECT[14].handle);
	DeleteGraph(EFFECT[15].handle);
	DeleteGraph(EFFECT[16].handle);
	DeleteGraph(EFFECT[17].handle);
	DeleteGraph(EFFECT[18].handle);
	DeleteGraph(EFFECT[19].handle);
	DeleteGraph(EFFECT[20].handle);
	DeleteGraph(EFFECT[21].handle);
	DeleteGraph(EFFECT[22].handle);
	DeleteGraph(EFFECT[23].handle);
	DeleteGraph(EFFECT[24].handle);
	DeleteGraph(EFFECT[25].handle);
	DeleteGraph(EFFECT[26].handle);
	DeleteGraph(EFFECT[27].handle);

	DeleteSoundMem(SE_BAKUHATSU.handle);
	DeleteSoundMem(SE_SHOT.handle);
	DeleteSoundMem(SE_REFLECT.handle);
	DeleteSoundMem(SE_CANCEL.handle);
	DeleteSoundMem(SE_SELECT.handle);
	DeleteSoundMem(SE_ENTER.handle);
	DeleteSoundMem(BGM_TITLE.handle);
	DeleteSoundMem(BGM_RANK.handle);
	DeleteSoundMem(BGM_PLAY.handle);
	DeleteSoundMem(GAMEOVER.handle);
	DeleteSoundMem(CLEAR.handle);

	DeleteFontToHandle(Small_FHandle);
	DeleteFontToHandle(small_YU_FHandle);
	DeleteFontToHandle(Middle_FHandle);
	DeleteFontToHandle(bigMiddle_FHandle);
	DeleteFontToHandle(Big_FHandle);
	DeleteFontToHandle(superBig_FHandle);	

	DxLib_End();		//ＤＸライブラリ使用の終了処理

	return 0;
}

//########## ウィンドウプロシージャ関数 ##########
LRESULT CALLBACK MY_WNDPROC(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{

	case WM_CREATE:	//ウィンドウの生成＆初期化


		IsWM_CREATE = TRUE;	//WM_CREATE正常終了
		return 0;

	case WM_CLOSE:		//閉じるボタンを押したとき

		MessageBox(hwnd, TEXT("ゲームを終了します"), TEXT("終了メッセージ"), MB_OK);
		break;

	case WM_RBUTTONDOWN:	//マウスの右ボタンを押したとき

		SendMessage(hwnd, WM_CLOSE, 0, 0);		//WM_CLOSEメッセージをキューに追加
		break;

	case WM_LBUTTONDOWN:	//マウスの左ボタンを押したとき

		//WM_NCLBUTTONDOWN(タイトルバーでマウスの左ボタンを押した)メッセージをすぐに発行
		PostMessage(hwnd, WM_NCLBUTTONDOWN, (WPARAM)HTCAPTION, lp);
		break;

	case WM_DESTROY:	//ウィンドウが破棄された(なくなった)とき

		PostQuitMessage(0);		//メッセージキューに WM_QUIT を送る
		return 0;
	}

	//デフォルトのウィンドウプロシージャ関数を呼び出す
	return DefWindowProc(hwnd, msg, wp, lp);
}