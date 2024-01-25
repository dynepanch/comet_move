#ifndef __SCI9__
#define __SCI9__
#include "iodefine.h"
#include<machine.h>


#define SCI	SCI9
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
static unsigned char trans_b_9[100];
static short sci9_error=0;
static int receve_data_num , string_num ,sci9_trance_bit_num;
static char get_buff_2[40];

extern void INIT_SCI9(void);
extern void int_scr9_txi9(void);
extern void int_scr9_tei9(void);
extern void int_scr9_rxi9(void);
extern void int_scr9_eri9(void);
static void sci9_put_start (void);
extern  void sci9_puts(unsigned char* c);
extern  void sci9_put_data(unsigned char* c,int n);
extern int sci9_gets( volatile unsigned char* p);


#endif