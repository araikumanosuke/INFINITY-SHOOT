#include <DxLib.h>
#include "global.hpp"
#include "howto.hpp"

VOID MY_GAME_HOWTO(VOID)
{
	//�w�i�\��
	DrawGraph(BG.x, BG.y, BG.handle, TRUE);

	DrawStringToHandle(310, 40, "How To", GetColor(255, 255, 255), superBig_FHandle);
	DrawStringToHandle(210, 180, "�E�Q�[�����̑���", GetColor(255, 255, 255), small_YU_FHandle);
	DrawStringToHandle(270, 240, "�v���C���[�̈ړ��F�\���L�[", GetColor(255, 255, 255), small_YU_FHandle);
	DrawStringToHandle(270, 300, "�e�̔��ˁF�`�L�[(��������)", GetColor(255, 255, 255), small_YU_FHandle);
	DrawStringToHandle(210, 380, "�E���̑��̑���", GetColor(255, 255, 255), small_YU_FHandle);
	DrawStringToHandle(270, 440, "����F�G���^�[�L�[", GetColor(255, 255, 255), small_YU_FHandle);
	DrawStringToHandle(270, 500, "�߂�F�o�b�N�X�y�[�X�L�[", GetColor(255, 255, 255), small_YU_FHandle);

	if (AllKeyState[KEY_INPUT_BACK] == 1)
	{
		PlaySoundMem(SE_CANCEL.handle, DX_PLAYTYPE_BACK);
		GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
	}
}