#ifndef __VSC3
#define __VSC3

#define C_DEF	0xffff	//定常状態
#define C_LEFT	0x7fff	//←
#define C_DOWN	0xbfff	//↓
#define C_RIGHT	0xdfff	//→
#define C_UP	0xefff	//↑

#define C_START	0xf7ff	//start0
#define C_P_RIG	0xfbff	//右押し込み
#define C_P_LEF	0xfdff	//左押し込み
#define C_SEL	0xfeff	//select

#define C_SQ	0xff7f	//□
#define C_PEC	0xffbf	//×
#define C_CR	0xffdf	//〇
#define C_TR	0xffef	//△

#define C_R1	0xfff7	//R1
#define C_L1	0xfffb	//L1
#define C_R2	0xfffd	//R2
#define C_L2	0xfffe	//L2

//アナログスティック

void CNTR_PUTS(void);


#endif