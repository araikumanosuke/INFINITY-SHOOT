#include <DxLib.h>
#include "header.h"
#include "global.h"
#include "play.h"

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
