#include <DxLib.h>
#include "title.h"
#include "global.h"

int t_position = 0;

//########## �^�C�g����ʂ̊֐� ##########
VOID MY_GAME_TITLE(VOID)
{
	if (AllKeyState[KEY_INPUT_RETURN] != 0)	//�G���^�[�L�[��������Ă�����
	{
		if (t_position == 0)
		{
			GameSceneNow = (int)GAME_SCENE_STAGECHOICE;	//�V�[�����X�e�[�W�I����ʂɂ���
		}
		else if (t_position == 100)
		{
			GameSceneNow = (int)GAME_SCENE_RANKING;	//�V�[���������L���O��ʂɂ���
		}
	}

	if (AllKeyState[KEY_INPUT_DOWN] == 1 || AllKeyState[KEY_INPUT_UP] == 1)
	{
		if (t_position == 0)
		{
			t_position += 100;
		}
		else if (t_position == 100)
		{
			t_position -= 100;
		}
	}

	DrawGraph(0, 0, BGHandle, TRUE);
	DrawGraph(80, 40, RHandle, TRUE);

	DrawGraph(370, 357 + t_position, THandle, TRUE);

	DrawStringToHandle(400, 350, "START", GetColor(255, 255, 255), choice_FHandle);
	DrawStringToHandle(400, 450, "RANKING", GetColor(255, 255, 255), choice_FHandle);
	
	//DrawString(0, 0, "�^�C�g�����(�G���^�[�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
}
