#pragma once
#include "header.h"

//########## �v���g�^�C�v�錾 ##########
LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM);	//����E�B���h�E�v���V�[�W��

extern VOID MY_FPS_UPDATE(VOID);			//FPS�l���v���A�X�V����֐�
extern VOID MY_FPS_DRAW(VOID);				//FPS�l��`�悷��֐�
extern VOID MY_FPS_WAIT(VOID);				//FPS�l���v�����A�҂֐�

extern VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����֐�

extern VOID MY_GAME_TITLE(VOID);			//�^�C�g����ʂ̊֐�
extern VOID MY_GAME_PLAY(VOID);			//�v���C��ʂ̊֐�
extern VOID MY_GAME_END(VOID);				//�G���h��ʂ̊֐�

