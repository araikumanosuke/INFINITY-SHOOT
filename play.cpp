#include <DxLib.h>
#include "header.h"
#include "global.h"
#include "play.h"

//########## �v���C��ʂ̊֐� ##########
VOID MY_GAME_PLAY(VOID)
{
	if (AllKeyState[KEY_INPUT_DOWN] != 0)	//���L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_END_OVER;	//�V�[�����G���h���(�Q�[���I�[�o�[)�ɂ���
	}

	if (AllKeyState[KEY_INPUT_UP] != 0)	//��L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_END_CLEAR;	//�V�[�����G���h���(�Q�[���N���A)�ɂ���
	}

	DrawString(0, 0, "�v���C���(���L�[(�Q�[���I�[�o�[)�܂��͏�L�[(�Q�[���N���A)�������Ă�������)", GetColor(255, 255, 255));

	return;
}
