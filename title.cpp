#include <DxLib.h>
#include "title.hpp"
#include "global.hpp"

int s_position_title = 0;

//########## �^�C�g����ʂ̊֐� ##########
VOID MY_GAME_TITLE(VOID)
{
	if (AllKeyState[KEY_INPUT_RETURN] == 1)	//�G���^�[�L�[��������Ă�����
	{
		if (s_position_title == 0)
		{
			GameSceneNow = (int)GAME_SCENE_STAGECHOICE;	//�V�[�����X�e�[�W�I����ʂɂ���
		}
		else if (s_position_title == 100)
		{
			GameSceneNow = (int)GAME_SCENE_RANKING;	//�V�[���������L���O��ʂɂ���
		}
	}

	if (AllKeyState[KEY_INPUT_DOWN] == 1 || AllKeyState[KEY_INPUT_UP] == 1)
	{
		if (s_position_title == 0)
		{
			s_position_title += 100;
		}
		else if (s_position_title == 100)
		{
			s_position_title -= 100;
		}
	}

	DrawGraph(BG.x, BG.y, BG.handle, TRUE);
	DrawGraph(ROGO.x, ROGO.y, ROGO.handle, TRUE);

	DrawGraph(370, 357 + s_position_title, SANKAKU.handle, TRUE);

	DrawStringToHandle(400, 350, "START", GetColor(255, 255, 255), choice_FHandle);
	DrawStringToHandle(400, 450, "RANKING", GetColor(255, 255, 255), choice_FHandle);
	
	//DrawString(0, 0, "�^�C�g�����(�G���^�[�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
}
