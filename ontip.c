#include "ontip.h"
#include "iodefine.h"

void ontip_timer(void){

	int i=0;
	
	SYSTEM.PRCR.WORD = 0xA503;		//	書き込み許可【消費電力低減モード・クロック発生関連】
	
	SYSTEM.LOCOCR.BIT.LCSTP = 0;		//	低速オンチップオシレータの起動
	for(i=0;i<10000;i++);			//	安定するまで待つ
	SYSTEM.SCKCR3.BIT.CKSEL = 0;		//	低速オンチップに乗り換え
	SYSTEM.HOCOCR.BIT.HCSTP = 1;		//	高速オンチップを停止
	SYSTEM.SCKCR.LONG = 0x00010000;		//	高速を設定(とりあえずPCLKBを2分周)
	SYSTEM.HOCOCR2.BIT. HCFRQ = 0;		//	32MHz
	SYSTEM.HOCOCR.BIT.HCSTP	= 0;		//	高速を起動
	for(i=0;i<10000;i++);			//	安定するまで待つ
	SYSTEM.SCKCR3.BIT.CKSEL = 1;		//	高速オンチップに乗り換え
	for(i=0;i<10000;i++);
	SYSTEM.LOCOCR.BIT.LCSTP = 1;		//	低速オンチップを停止
	SYSTEM.MOSCCR.BIT.MOSTP	= 1;		//	メインクロックを停止
	SYSTEM.SOSCCR.BYTE	=0x00;		//	サブクロック動作
	SYSTEM.PRCR.WORD = 0xA500;		//	書き込み禁止

}
