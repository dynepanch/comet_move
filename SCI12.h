#ifndef __SCI12__
#define __SCI12__

#include "iodefine.h"
#include<machine.h>


#define SCI	SCI12
#define RDR	SCI.RDR
#define TEND	SCI.SSR.BIT.TEND
#define R_STOP	SCI.SCR.BIT.RE = 0
#define R_START	SCI.SCR.BIT.RE = 1

#define BPS(a)		BPS_##a
#define BPS_19200 	SCI.SEMR.BIT.ABCS=1;SCI.BRR =104
#define BPS_38400 	SCI.SEMR.BIT.ABCS=1;SCI.BRR =51
#define BPS_115200 	SCI.SEMR.BIT.ABCS=1;SCI.BRR =17//17
#define BPS_230400 	SCI.SEMR.BIT.ABCS=0;SCI.BRR =5
#define BPS_460800 	SCI.SEMR.BIT.ABCS=0;SCI.BRR =2
#define BPS_921600 	SCI.SEMR.BIT.ABCS=0;SCI.BRR =1
#define ESC_KEY 	(0x1b)//ASCII
#define ENTER_KEY	'\r'
static unsigned char get_buff;
static unsigned char get_buff_m[40];
static unsigned char trans_b_12[100];
static short sci12_error=0;
static int receve_data_num , string_num ,sci12_trance_bit_num ;
static char get_buff_12[40];

extern void INIT_SCI12(void);
extern void int_scr12_txi12(void);
extern void int_scr12_tei12(void);
extern void int_scr12_rxi12(void);
extern void int_scr12_eri12(void);
static void sci12_put_start (void);
extern  void sci12_puts(unsigned char* c);
extern  void sci12_put_data(unsigned char* c,int n);
extern int sci12_gets( volatile unsigned char* p);


#endif