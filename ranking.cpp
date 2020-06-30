#include <DxLib.h>
#include "ranking.hpp"
#include "global.hpp"

int s_position_ranking = 0;

VOID MY_GAME_RANKING(VOID)
{
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);
	DrawStringToHandle(290, 20, "RANKING", GetColor(255, 255, 255), Big_FHandle);
	DrawBox(695, 32, 885, 107, GetColor(255, 255, 255), false);
	DrawStringToHandle(700, 37, "BACK TO TITLE:", GetColor(255, 255, 255), Small_FHandle);
	DrawStringToHandle(700, 77, "BACK SPACE Key", GetColor(255, 255, 255), Small_FHandle);

	if (AllKeyState[KEY_INPUT_UP] == 1)
	{
		switch (s_position_ranking)
		{
		case 0:	//1-NORMAL�̈ʒu�̂Ƃ�
			if (S3_Hard_PlayFlag == true)
			{
				s_position_ranking += 350;
			}
			else if (S3_Normal_PlayFlag == true)
			{
				s_position_ranking += 280;
			}
			else if (S2_Normal_PlayFlag == true)
			{
				s_position_ranking += 140;
			}
			break;

		case 70:	//1-HARD�̈ʒu�̂Ƃ��͍��W����ԏ�ɖ߂�
			s_position_ranking -= 70;
			break;

		case 140:	//2-NORMAL�̈ʒu�̂Ƃ�
			if (S1_Hard_PlayFlag == true)
			{
				s_position_ranking -= 70;
			}
			else if (S1_Hard_PlayFlag == false)
			{
				s_position_ranking -= 140;
			}
			break;

		case 210:	//2-HARD�̈ʒu�̂Ƃ��͍��W���P�i�K��ɂ��炷
			s_position_ranking -= 70;
			break;

		case 280:	//3-NORMAL�̈ʒu�̂Ƃ�
			if (S2_Hard_PlayFlag == true)
			{
				s_position_ranking -= 70;
			}
			else if (S2_Hard_PlayFlag == false)
			{
				s_position_ranking -= 140;
			}
			break;

		case 350:	//3-HARD�̈ʒu�̂Ƃ��͍��W����i�K��ɖ߂�
			s_position_ranking -= 70;
			break;

		default:
			break;
		}
	}
	else if (AllKeyState[KEY_INPUT_DOWN] == 1)
	{
		switch (s_position_ranking)
		{
		case 0:	//1-NORMAL�̈ʒu�̂Ƃ�
			if (S2_Normal_PlayFlag == true)	//2-NORMAL���������Ă���Ƃ�
			{
				if (S1_Hard_PlayFlag == true)	//1-HARD���������Ă���΍��W���P�i�K���ɂ��炷
				{
					s_position_ranking += 70;
				}
				else if (S1_Hard_PlayFlag == false)	//1-HARD���������Ă��Ȃ���΍��W���Q�i�K���ɂ��炷
				{
					s_position_ranking += 140;
				}
			}
			break;

		case 70:	//1-HARD�̈ʒu�̂Ƃ��͍��W���P�i�K���ɂ��炷
			s_position_ranking += 70;
			break;

		case 140:	//2-NORMAL�̈ʒu�̂Ƃ�
			if (S3_Normal_PlayFlag == true)	//3-NORMAL���������Ă���Ƃ�
			{
				if (S2_Hard_PlayFlag == true)	//2-HARD���������Ă���΍��W���P�i�K���ɂ��炷
				{
					s_position_ranking += 70;
				}
				else if (S2_Hard_PlayFlag == false)	//2-HARD���������Ă��Ȃ���΍��W���Q�i�K���ɂ��炷
				{
					s_position_ranking += 140;
				}
			}
			else if (S3_Normal_PlayFlag == false)	//3-NORMAL���������Ă��Ȃ���΍��W����ԏ�ɖ߂�
			{
				s_position_ranking -= 140;
			}
			break;

		case 210:	//2-HARD�̈ʒu�̂Ƃ��͍��W���P�i�K���ɂ��炷
			s_position_ranking += 70;
			break;

		case 280:	//3-NORMAL�̈ʒu�̂Ƃ�
			if (S3_Hard_PlayFlag == true)	//3-HARD���������Ă���΍��W���P�i�K���ɂ��炷
			{
				s_position_ranking += 70;
			}
			else if (S3_Hard_PlayFlag == false)	//3-HARD���������Ă��Ȃ���΍��W����ԏ�ɖ߂�
			{
				s_position_ranking -= 280;
			}
			break;

		case 350:	//3-HARD�̈ʒu�̂Ƃ��͍��W����ԏ�ɖ߂�
			s_position_ranking -= 350;
			break;

		default:
			break;
		}
	}

	DrawGraph(70, 166 + s_position_ranking, SANKAKU.handle, TRUE);

	DrawStringToHandle(100, 160, "1-NORMAL", GetColor(255, 255, 255), Middle_FHandle);
	if (S1_Hard_PlayFlag == true)
	{
		DrawStringToHandle(100, 230, "1-HARD", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S2_Normal_PlayFlag == true)
	{
		DrawStringToHandle(100, 300, "2-NORMAL", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S2_Hard_PlayFlag == true)
	{
		DrawStringToHandle(100, 370, "2-HARD", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S3_Normal_PlayFlag == true)
	{
		DrawStringToHandle(100, 440, "3-NORMAL", GetColor(255, 255, 255), Middle_FHandle);
	}
	if (S3_Hard_PlayFlag == true)
	{
		DrawStringToHandle(100, 510, "3-HARD", GetColor(255, 255, 255), Middle_FHandle);
	}
	
	if (AllKeyState[KEY_INPUT_BACK] == 1)	//�o�b�N�X�y�[�X�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
		s_position_title = 0;
	}

	DrawString(0, 0, "�����L���O���(�o�b�N�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));
}