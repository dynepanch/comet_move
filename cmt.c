#include "cmt.h"

void init_cmt0(void){
	SYSTEM.PRCR.WORD = 0xA503;		//	�������݋��y����d�͒ጸ���[�h�E�N���b�N�����֘A�z
	MSTP(CMT0)=0;				//	�N���b�N�x�~��Ԃ�����
	CMT0.CMCR.BIT.CKS = 0;			//	8������I��
	CMT0.CMCR.BIT.CMIE = 1;			//	���荞�݋���
	CMT0.CMCNT = 0;				//	0����J�E���g�A�b�v
	CMT0.CMCOR = 1000-1;			//	10ms���ƂɃR���x�A�}�b�`
	IPR(CMT0,CMI0) = 12;			//	���x��12�ɐݒ�
	IEN(CMT0,CMI0) = 1;			//	���荞�݋���
	CMT.CMSTR0.BIT.STR0 = 1;		//	�R���x�A�}�b�`�X�^�[�g
	
	SYSTEM.PRCR.WORD = 0xA500;		//	�������݋֎~�y����d�͒ጸ���[�h�E�N���b�N�����֘A�z

}


void init_cmt1(void){
	SYSTEM.PRCR.WORD = 0xA503;		//	�������݋��y����d�͒ጸ���[�h�E�N���b�N�����֘A�z
	MSTP(CMT1)=0;				//	�N���b�N�x�~��Ԃ�����
	CMT1.CMCR.BIT.CKS = 1;			//	32������I��
	CMT1.CMCR.BIT.CMIE = 1;			//	���荞�݋���
	CMT1.CMCNT = 0;				//	0����J�E���g�A�b�v
	CMT1.CMCOR = 25000-1;			//	10ms���ƂɃR���x�A�}�b�`
	IPR(CMT1,CMI1) = 3;			//	���x��3�ɐݒ�
	IEN(CMT1,CMI1) = 1;			//	���荞�݋���
	CMT.CMSTR0.BIT.STR1 = 1;		//	�R���x�A�}�b�`�X�^�[�g
	
	SYSTEM.PRCR.WORD = 0xA500;		//	�������݋֎~�y����d�͒ጸ���[�h�E�N���b�N�����֘A�z

}