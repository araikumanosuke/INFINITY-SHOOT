#include <DxLib.h>
#include "ranking.h"
#include "global.h"

VOID MY_GAME_RANKING(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] == 1)	//�o�b�N�X�y�[�X�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
		s_position_title = 0;
	}

	DrawString(0, 0, "�����L���O���(�o�b�N�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));
}