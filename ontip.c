#include "ontip.h"
#include "iodefine.h"

void ontip_timer(void){

	int i=0;
	
	SYSTEM.PRCR.WORD = 0xA503;		//	�������݋��y����d�͒ጸ���[�h�E�N���b�N�����֘A�z
	
	SYSTEM.LOCOCR.BIT.LCSTP = 0;		//	�ᑬ�I���`�b�v�I�V���[�^�̋N��
	for(i=0;i<10000;i++);			//	���肷��܂ő҂�
	SYSTEM.SCKCR3.BIT.CKSEL = 0;		//	�ᑬ�I���`�b�v�ɏ�芷��
	SYSTEM.HOCOCR.BIT.HCSTP = 1;		//	�����I���`�b�v���~
	SYSTEM.SCKCR.LONG = 0x00010000;		//	������ݒ�(�Ƃ肠����PCLKB��2����)
	SYSTEM.HOCOCR2.BIT. HCFRQ = 0;		//	32MHz
	SYSTEM.HOCOCR.BIT.HCSTP	= 0;		//	�������N��
	for(i=0;i<10000;i++);			//	���肷��܂ő҂�
	SYSTEM.SCKCR3.BIT.CKSEL = 1;		//	�����I���`�b�v�ɏ�芷��
	for(i=0;i<10000;i++);
	SYSTEM.LOCOCR.BIT.LCSTP = 1;		//	�ᑬ�I���`�b�v���~
	SYSTEM.MOSCCR.BIT.MOSTP	= 1;		//	���C���N���b�N���~
	SYSTEM.SOSCCR.BYTE	=0x00;		//	�T�u�N���b�N����
	SYSTEM.PRCR.WORD = 0xA500;		//	�������݋֎~

}
