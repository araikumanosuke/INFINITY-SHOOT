#include <DxLib.h>
#include "end_over.h"
#include "global.h"

//########## �G���h��ʂ̊֐� ##########
VOID MY_GAME_END_OVER(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)	//�o�b�N�X�y�[�X�[�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
		t_position = 0;
	}

	DrawString(0, 0, "�G���h���(�Q�[���I�[�o�[)(�o�b�N�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
}