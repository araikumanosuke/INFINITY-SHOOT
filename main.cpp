//########## ヘッダーファイル読み込み ##########
#include <DxLib.h>
#include "header.h"
#include "global.h"
#include "main.h"
#include "fps.h"
#include "title.h"
#include "key.h"
#include "play.h"
#include "end_over.h"
#include "ranking.h"
#include "stagechoice.h"
#include "end_clear.h"

//グローバル変数の実体たち
int GameSceneNow = (int)GAME_SCENE_TITLE;

char AllKeyState[256];	//すべてのキーの状態が入る

int BGHandle;
int RHandle;
int THandle;
int PHandle;
int E_YHandle;
int E_YHardHandle;
int E_GHandle;
int E_GHardHandle;
int E_RHandle;
int E_RHardHandle;
int E_BHandle;
int E_BHardHandle;

int choice_FHandle;
int play_FHandle;

//ウィンドウ関係
static WNDPROC WndProc;						//ウィンドウプロシージャのアドレス

static BOOL IsWM_CREATE = FALSE;				//WM_CREATEが正常に動作したか判断する

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する

	SetWindowStyleMode(SET_WINDOW_ST_MODE_TITLE_NONE);			//タイトルバーなし

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//タイトルの文字

	//フック→WM_CLOSEなどのメッセージを引っ掛けて取得する
	SetHookWinProc(MY_WNDPROC);	//ウィンドウプロシージャの設定

	if (DxLib_Init() == -1) { return -1; }						//ＤＸライブラリ初期化処理

	SetDrawScreen(DX_SCREEN_BACK);								//Draw系関数は裏画面に描画

	BGHandle = LoadGraph(GAME_IMAGE_BACK);
	RHandle = LoadGraph(GAME_IMAGE_ROGO);
	THandle = LoadGraph(GAME_IMAGE_TRIANGLE);
	PHandle = LoadGraph(GAME_IMAGE_PLAYER);
	E_YHandle = LoadGraph(GAME_IMAGE_ENEMY_YELLOW);
	E_YHardHandle = LoadGraph(GAME_IMAGE_ENEMY_YELLOW_HARD);
	E_GHandle = LoadGraph(GAME_IMAGE_ENEMY_GREEN);
	E_GHardHandle = LoadGraph(GAME_IMAGE_ENEMY_GREEN_HARD);
	E_RHandle = LoadGraph(GAME_IMAGE_ENEMY_RED);
	E_RHardHandle = LoadGraph(GAME_IMAGE_ENEMY_RED_HARD);
	E_BHandle = LoadGraph(GAME_IMAGE_ENEMY_BLUE);
	E_BHardHandle = LoadGraph(GAME_IMAGE_ENEMY_BLUE_HARD);

	choice_FHandle = CreateFontToHandle("HGS 教科書体", 48, 0, DX_FONTTYPE_ANTIALIASING);
	play_FHandle = CreateFontToHandle("HGS 教科書体", 24, 0, DX_FONTTYPE_ANTIALIASING);

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

		MY_FPS_DRAW();		//FPSの処理[描画]

		ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画

		MY_FPS_WAIT();		//FPSの処理[待つ]
	}

	DeleteGraph(BGHandle);
	DeleteGraph(RHandle);
	DeleteGraph(THandle);
	DeleteGraph(PHandle);
	DeleteGraph(E_YHandle);
	DeleteGraph(E_YHardHandle);
	DeleteGraph(E_GHandle);
	DeleteGraph(E_GHardHandle);
	DeleteGraph(E_RHandle);
	DeleteGraph(E_RHardHandle);
	DeleteGraph(E_BHandle);
	DeleteGraph(E_BHardHandle);

	DeleteFontToHandle(choice_FHandle);
	DeleteFontToHandle(play_FHandle);

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