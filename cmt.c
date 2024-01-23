#include "cmt.h"

void init_cmt0(void){
	SYSTEM.PRCR.WORD = 0xA503;		//	書き込み許可【消費電力低減モード・クロック発生関連】
	MSTP(CMT0)=0;				//	クロック休止状態を解除
	CMT0.CMCR.BIT.CKS = 0;			//	8周期を選択
	CMT0.CMCR.BIT.CMIE = 1;			//	割り込み許可
	CMT0.CMCNT = 0;				//	0からカウントアップ
	CMT0.CMCOR = 1000-1;			//	10msごとにコンベアマッチ
	IPR(CMT0,CMI0) = 12;			//	レベル12に設定
	IEN(CMT0,CMI0) = 1;			//	割り込み許可
	CMT.CMSTR0.BIT.STR0 = 1;		//	コンベアマッチスタート
	
	SYSTEM.PRCR.WORD = 0xA500;		//	書き込み禁止【消費電力低減モード・クロック発生関連】

}


void init_cmt1(void){
	SYSTEM.PRCR.WORD = 0xA503;		//	書き込み許可【消費電力低減モード・クロック発生関連】
	MSTP(CMT1)=0;				//	クロック休止状態を解除
	CMT1.CMCR.BIT.CKS = 1;			//	32周期を選択
	CMT1.CMCR.BIT.CMIE = 1;			//	割り込み許可
	CMT1.CMCNT = 0;				//	0からカウントアップ
	CMT1.CMCOR = 25000-1;			//	10msごとにコンベアマッチ
	IPR(CMT1,CMI1) = 3;			//	レベル3に設定
	IEN(CMT1,CMI1) = 1;			//	割り込み許可
	CMT.CMSTR0.BIT.STR1 = 1;		//	コンベアマッチスタート
	
	SYSTEM.PRCR.WORD = 0xA500;		//	書き込み禁止【消費電力低減モード・クロック発生関連】

}