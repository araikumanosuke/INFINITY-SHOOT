#include <DxLib.h>
#include "end_clear.hpp"
#include "global.hpp"
#include "enemy_init.hpp"

//########## �G���h��ʂ̊֐� ##########
VOID MY_GAME_END_CLEAR(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] == 1)	//�o�b�N�X�y�[�X�[�L�[��������Ă�����
	{
		ENEMY_INIT();
		s_position_title = 0;
		s_position_stage = 0;
		s_position_difficult = 0;
		s_flug = TRUE;
		GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
	}

	DrawString(0, 0, "�G���h���(�Q�[���N���A)(�o�b�N�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
}