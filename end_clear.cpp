#include <DxLib.h>
#include "end_clear.h"
#include "global.h"

//########## �G���h��ʂ̊֐� ##########
VOID MY_GAME_END_CLEAR(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)	//�o�b�N�X�y�[�X�[�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
		t_position_title = 0;
		t_position_stage = 0;
		t_position_difficult = 0;
		t_flug = TRUE;
	}

	DrawString(0, 0, "�G���h���(�Q�[���N���A)(�o�b�N�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
}