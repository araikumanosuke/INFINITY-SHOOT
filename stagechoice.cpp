#include <DxLib.h>
#include "stagechoice.h"
#include "global.h"

VOID MY_GAME_STAGECHOICE(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�X�y�[�X�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
	}

	DrawString(0, 0, "�X�e�[�W�I�����(�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));
}