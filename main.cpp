//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "header.h"
#include "global.h"
#include "proto.h"

//�L�[�{�[�h�֘A
char AllKeyState[256];			//���ׂẴL�[�̏�Ԃ�����

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

		case (int)GAME_SCENE_PLAY:	//�v���C��ʂ̏�����������

			MY_GAME_PLAY();		//�v���C��ʂ̏���

			break;	//�v���C��ʂ̏��������܂�

		case (int)GAME_SCENE_END:	//�G���h��ʂ̏�����������

			MY_GAME_END();		//�G���h��ʂ̏���

			break;	//�G���h��ʂ̏��������܂�

		default:

			break;

		}

		MY_FPS_UPDATE();						//FPS�̏���[�X�V]

		MY_FPS_DRAW();		//FPS�̏���[�`��]

		ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		MY_FPS_WAIT();		//FPS�̏���[�҂�]
	}

	DxLib_End();		//�c�w���C�u�����g�p�̏I������

	return 0;
}

//########## �L�[�̓��͏�Ԃ��X�V����֐� ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];			//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//########## �^�C�g����ʂ̊֐� ##########
VOID MY_GAME_TITLE(VOID)
{
	if (AllKeyState[KEY_INPUT_RETURN] != 0)	//�G���^�[�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
	}

	DrawString(0, 0, "�^�C�g�����(�G���^�[�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
}

//########## �v���C��ʂ̊֐� ##########
VOID MY_GAME_PLAY(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�X�y�[�X�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_END;	//�V�[�����G���h��ʂɂ���
	}

	DrawString(0, 0, "�v���C���(�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
}

//########## �G���h��ʂ̊֐� ##########
VOID MY_GAME_END(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)	//�o�b�N�X�y�[�X�[�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
	}

	DrawString(0, 0, "�G���h���(�o�b�N�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
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