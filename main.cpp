//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
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

//�O���[�o���ϐ��̎��̂���
int GameSceneNow = (int)GAME_SCENE_TITLE;

char AllKeyState[256];	//���ׂẴL�[�̏�Ԃ�����

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

//�E�B���h�E�֌W
static WNDPROC WndProc;						//�E�B���h�E�v���V�[�W���̃A�h���X

static BOOL IsWM_CREATE = FALSE;				//WM_CREATE������ɓ��삵�������f����

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������

	SetWindowStyleMode(SET_WINDOW_ST_MODE_TITLE_NONE);			//�^�C�g���o�[�Ȃ�

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	//�t�b�N��WM_CLOSE�Ȃǂ̃��b�Z�[�W�������|���Ď擾����
	SetHookWinProc(MY_WNDPROC);	//�E�B���h�E�v���V�[�W���̐ݒ�

	if (DxLib_Init() == -1) { return -1; }						//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);								//Draw�n�֐��͗���ʂɕ`��

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

	choice_FHandle = CreateFontToHandle("HGS ���ȏ���", 48, 0, DX_FONTTYPE_ANTIALIASING);
	play_FHandle = CreateFontToHandle("HGS ���ȏ���", 24, 0, DX_FONTTYPE_ANTIALIASING);

	//�������[�v
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		MY_ALL_KEYDOWN_UPDATE();				//�L�[�̏�Ԃ��擾

		//�V�[���I��
		switch (GameSceneNow)
		{
		case (int)GAME_SCENE_TITLE:	//�^�C�g����ʂ̏�����������

			MY_GAME_TITLE();	//�^�C�g����ʂ̏���

			break;	//�^�C�g����ʂ̏��������܂�

		case (int)GAME_SCENE_RANKING:	//�����L���O��ʂ̏�����������

			MY_GAME_RANKING();	//�����L���O��ʂ̏���

			break;	//�����L���O��ʂ̏��������܂�

		case (int)GAME_SCENE_STAGECHOICE:	//�X�e�[�W�I����ʂ̏�����������

			MY_GAME_STAGECHOICE();	//�X�e�[�W�I����ʂ̏���

			break;	//�X�e�[�W�I����ʂ̏��������܂�

		case (int)GAME_SCENE_PLAY:	//�v���C��ʂ̏�����������

			MY_GAME_PLAY();		//�v���C��ʂ̏���

			break;	//�v���C��ʂ̏��������܂�

		case (int)GAME_SCENE_END_CLEAR:	//�G���h���(�Q�[���N���A)�̏�����������

			MY_GAME_END_CLEAR();	//�G���h���(�Q�[���N���A)�̏���

			break;	//�G���h���(�Q�[���N���A)�̏��������܂�

		case (int)GAME_SCENE_END_OVER:	//�G���h���(�Q�[���I�[�o�[)�̏�����������

			MY_GAME_END_OVER();		//�G���h���(�Q�[���I�[�o�[)�̏���

			break;	//�G���h���(�Q�[���I�[�o�[)�̏��������܂�

		default:

			break;

		}

		MY_FPS_UPDATE();						//FPS�̏���[�X�V]

		MY_FPS_DRAW();		//FPS�̏���[�`��]

		ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		MY_FPS_WAIT();		//FPS�̏���[�҂�]
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

	DxLib_End();		//�c�w���C�u�����g�p�̏I������

	return 0;
}

//########## �E�B���h�E�v���V�[�W���֐� ##########
LRESULT CALLBACK MY_WNDPROC(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{

	case WM_CREATE:	//�E�B���h�E�̐�����������


		IsWM_CREATE = TRUE;	//WM_CREATE����I��
		return 0;

	case WM_CLOSE:		//����{�^�����������Ƃ�

		MessageBox(hwnd, TEXT("�Q�[�����I�����܂�"), TEXT("�I�����b�Z�[�W"), MB_OK);
		break;

	case WM_RBUTTONDOWN:	//�}�E�X�̉E�{�^�����������Ƃ�

		SendMessage(hwnd, WM_CLOSE, 0, 0);		//WM_CLOSE���b�Z�[�W���L���[�ɒǉ�
		break;

	case WM_LBUTTONDOWN:	//�}�E�X�̍��{�^�����������Ƃ�

		//WM_NCLBUTTONDOWN(�^�C�g���o�[�Ń}�E�X�̍��{�^����������)���b�Z�[�W�������ɔ��s
		PostMessage(hwnd, WM_NCLBUTTONDOWN, (WPARAM)HTCAPTION, lp);
		break;

	case WM_DESTROY:	//�E�B���h�E���j�����ꂽ(�Ȃ��Ȃ���)�Ƃ�

		PostQuitMessage(0);		//���b�Z�[�W�L���[�� WM_QUIT �𑗂�
		return 0;
	}

	//�f�t�H���g�̃E�B���h�E�v���V�[�W���֐����Ăяo��
	return DefWindowProc(hwnd, msg, wp, lp);
}