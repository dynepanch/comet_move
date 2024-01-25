#ifndef __SCI5__
#define __SCI5__
#include "iodefine.h"
#include<machine.h>


#define SCI	SCI5
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
static unsigned char trans_b_5[100];
static short sci5_error=0;
static int receve_data_num , string_num,sci5_trance_bit_num;
static char get_buff_2[40];

extern void INIT_SCI5(void);
extern void int_scr5_txi5(void);
extern void int_scr5_tei5(void);
extern void int_scr5_rxi5(void);
extern void int_scr5_eri5(void);
static void sci5_put_start (void);
extern  void sci5_puts(unsigned char* c);
extern  void sci5_put(unsigned char* c,int n);
extern  void sci5_put_data(unsigned char* c,int n);
extern int sci5_gets( volatile unsigned char* p);


#endif