#pragma once
#include <DxLib.h>
#include "header.h"

//FPS�֘A
static int StartTimeFps;						//����J�n����
static int CountFps;							//�J�E���^
static float CalcFps;							//�v�Z����
static int SampleNumFps = GAME_FPS_SPEED;		//���ς����T���v����

extern VOID MY_FPS_UPDATE(VOID);			//FPS�l���v���A�X�V����֐�
extern VOID MY_FPS_DRAW(VOID);				//FPS�l��`�悷��֐�
extern VOID MY_FPS_WAIT(VOID);				//FPS�l���v�����A�҂֐�

