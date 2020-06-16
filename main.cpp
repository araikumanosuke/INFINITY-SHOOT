//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include <DxLib.h>
#include "header.hpp"
#include "global.hpp"
#include "main.hpp"
#include "fps.hpp"
#include "title.hpp"
#include "key.hpp"
#include "play.hpp"
#include "end_over.hpp"
#include "ranking.hpp"
#include "stagechoice.hpp"
#include "end_clear.hpp"
#include "image.hpp"

//�O���[�o���ϐ��̎��̂���
int GameSceneNow = (int)GAME_SCENE_TITLE;

char AllKeyState[256];	//���ׂẴL�[�̏�Ԃ�����

IMAGE BG;		//�w�i
IMAGE ROGO;		//���S
IMAGE SANKAKU;		//�O�p�`
IMAGE TAMA;		//�e
IMAGE PLAYER;		//�v���C���[(�@��)

//�G
IMAGE E_YELLOW;
IMAGE E_YELLOW_HARD;
IMAGE E_GREEN;
IMAGE E_GREEN_HARD;
IMAGE E_RED;
IMAGE E_RED_HARD;
IMAGE E_BLUE;
IMAGE E_BLUE_HARD;

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

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);			//�^�C�g���o�[

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	SetAlwaysRunFlag(TRUE);                                //��A�N�e�B�u�ł����s����

	if (DxLib_Init() == -1) { return -1; }						//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);								//Draw�n�֐��͗���ʂɕ`��

	image_load(&BG, 0, 0, GAME_IMAGE_BACK);
	image_load(&PLAYER, 425, 500, GAME_IMAGE_PLAYER);
	image_load(&ROGO, 80, 40, GAME_IMAGE_ROGO);
	image_load(&SANKAKU, 0, 0, GAME_IMAGE_SANKAKU);
	image_load(&TAMA, 0, 0, GAME_IMAGE_TAMA);
	image_load(&E_YELLOW, 425, 300, GAME_IMAGE_ENEMY_YELLOW);
	image_load(&E_YELLOW_HARD, 0, 0, GAME_IMAGE_ENEMY_YELLOW_HARD);
	image_load(&E_GREEN, 0, 0, GAME_IMAGE_ENEMY_GREEN);
	image_load(&E_GREEN_HARD, 0, 0,  GAME_IMAGE_ENEMY_GREEN_HARD);
	image_load(&E_RED, 0, 0, GAME_IMAGE_ENEMY_RED);
	image_load(&E_RED_HARD, 0, 0, GAME_IMAGE_ENEMY_RED);
	image_load(&E_BLUE, 0, 0, GAME_IMAGE_ENEMY_BLUE);
	image_load(&E_BLUE_HARD, 0, 0, GAME_IMAGE_ENEMY_BLUE_HARD);

	choice_FHandle = CreateFontToHandle("HG���ȏ���", 48, 5, DX_FONTTYPE_ANTIALIASING);
	play_FHandle = CreateFontToHandle("HG���ȏ���", 24, 9, DX_FONTTYPE_ANTIALIASING);

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